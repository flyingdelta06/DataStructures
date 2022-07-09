#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"

static int getMaxHeight(Node* a){
    if (a->leftH > a->rightH) return a->leftH;
    return a->rightH;
};

static void fixHeight(Node* a){
    a->leftH = 0;
    a->rightH = 0;
    if (a->left) a->leftH = getMaxHeight(a->left) + 1;
    if (a->right) a->rightH = getMaxHeight(a->right) + 1;
}

static int getBalanceFactor(Node* a){
    return (a->leftH - a->rightH);
}

static Node * Search(Node * root, int key) {
    // if (key < root->key) Search(root->left, key);
    // else if (key > root->key) Search(root->right, key);
    // else return root;
    Node * curr = root;
    while (key != curr -> key) {
        if (key < curr -> key) curr = curr -> left;
        else if (key > curr -> key) curr = curr -> right;
    }
    return curr;
}

static Node * getSuccessor(Node * z) {
    Node * currNode = z -> right;
    while (currNode -> left != NULL) {
        currNode = currNode -> left;
    }
    return currNode;
}

static int isRight(Node * a, Node * b) {
    if (a -> right == b) return 1;
    return 0;
}

static Node * newNode(int val, Node * parent, Node * left, Node * right) {
    Node * createdNode = (Node * ) malloc(sizeof(Node));
    createdNode -> key = val;
    createdNode -> parent = parent;
    createdNode -> left = left;
    createdNode -> right = right;
    createdNode -> leftH = 0;
    createdNode -> rightH = 0;
    return createdNode;
}

void rotateRight(AVLTree* tree, Node* a){
    Node* b = a->left;
    if (a->parent == NULL && a->left != NULL){
        // 6 ptrs must be updated
        tree->root = a->left;
        a->left->parent = NULL;
    }
    else {
        if (a == a->parent->right){
            a->parent->right = b;
        } else {
            a->parent->left = b;
        }
        b->parent = a->parent;
    }
    if (b->right != NULL){
        a->left = b->right;
        b->right->parent = a;
    } else {
        a->left = NULL;
    }
    b->right = a;
    a->parent = b;
    fixHeight(a);
    fixHeight(b);
}

void rotateLeft(AVLTree* tree, Node* a){
    Node* b = a->right;
    if (a->parent == NULL && a->right != NULL){
        // 6 ptrs must be updated
        tree->root = b;
        b->parent = NULL;
    }
    else {
        if (a == a->parent->left){
            a->parent->left = b;
        } else {
            a->parent->right = b;
        }
        b->parent = a->parent;
    }
    if (b->left != NULL){
        a->right = b->left;
        b->left->parent = a;
    } else {
        a->right = NULL;
    }
    b->left = a;
    a->parent = b;
    fixHeight(a);
    fixHeight(b);
}

void rebalanceTree(AVLTree* tree, Node* a){
    Node* curr = a;
    while (curr != NULL){
        Node* parent = curr->parent;
        fixHeight(curr);
        int balance = getBalanceFactor(curr);
        // printf("%d, %d -> %d\n", curr->leftH, curr->rightH, balance);
        if (balance == -2){
            // Right Heavy
            int rightBal = getBalanceFactor(curr->right);
            if (rightBal < 0) {
                rotateLeft(tree, curr);
            } else {
                rotateRight(tree, curr->right);
                rotateLeft(tree, curr);
            }
        } else if (balance == 2){
            // Left Heavy
            int leftBal = getBalanceFactor(curr->left);
            if (balance > 0) {
                rotateRight(tree, curr);
            } else {
                rotateLeft(tree, curr->left);
                rotateRight(tree, curr);
            }
        }
        curr = parent;
    }
}

AVLTree* Create(int* arr){
    AVLTree* newTree = (AVLTree*) malloc(sizeof(AVLTree));
    newTree->root = NULL;
}

static void InsertT(AVLTree* tree, Node * a, int key) {
    Node * toInsert = newNode(key, NULL, NULL, NULL);
    Node * currNode = a;
    while (currNode != NULL) {
        if (key <= currNode -> key) {
            if (currNode -> left == NULL) {
                toInsert -> parent = currNode;
                currNode -> left = toInsert;
                break;
            } else currNode = currNode -> left;
        } else {
            if (currNode -> right == NULL) {
                toInsert -> parent = currNode;
                currNode -> right = toInsert;
                break;
            } else currNode = currNode -> right;
        }
    }
    rebalanceTree(tree, toInsert);
}

void Insert(AVLTree * a, int key) {
    if (a -> root) {
        InsertT(a, a -> root, key);
    } else {
        Node * head = newNode(key, NULL, NULL, NULL);
        a -> root = head;
    }
}

static void InorderT(Node * head) {
    if (head -> left) InorderT(head -> left);
    printf("%d ", head -> key);
    if (head -> right) InorderT(head -> right);
}

void Inorder(AVLTree * a) {
    if (!(a -> root)) {
        printf("The tree is empty!\n");
        return;
    }
    InorderT(a -> root);
    printf("\n");
}

void Delete(AVLTree * a, int key) {
    Node * reqNode = Search(a -> root, key);
    if (reqNode -> left != NULL && reqNode -> right != NULL) {
        Node * y = getSuccessor(reqNode);
        if (y == reqNode -> right) {
            if (reqNode -> parent != NULL) {
                y->left = reqNode->left;
                y->left->parent = y;
                if (reqNode -> parent -> right == reqNode) {
                    reqNode -> parent -> right = y;
                }
                else reqNode -> parent -> left = y;
                y->parent = reqNode->parent;
            }
            else {
                a -> root = y;
                y->parent = NULL;
                y -> left = reqNode -> left;
                y->left->parent = y;
            }
        } else {
            Node * r = reqNode -> right;
            Node * x = y -> right;
            r -> left = x;
            if (x != NULL) x -> parent = r;
            y -> right = r;
            if (x != NULL) r -> parent = y;
            y -> left = reqNode -> left;
            y -> left -> parent = y;
            if (reqNode -> parent != NULL) {
                reqNode -> parent -> right = y;
                y->parent = reqNode -> parent;
            }
            else {
                a -> root = y;
                y -> left = reqNode -> left;
                y->left->parent = y;
            }
        }
    } else {
        Node* parent = reqNode->parent;
        if (reqNode -> left || reqNode -> right) {
            Node * subTree = (reqNode -> left) ? reqNode -> left : reqNode -> right;
            if (reqNode -> parent != NULL) {
                if (reqNode -> parent -> right == reqNode) {
                    reqNode -> parent -> right = subTree;
                    subTree->parent = reqNode->parent;
                } else {
                    reqNode -> parent -> left = subTree;
                    subTree->parent = reqNode->parent;
                }
            } else {
                a -> root = subTree;
                subTree->parent = NULL;
            }
        } else {
            if (reqNode -> parent != NULL) {
                if (reqNode -> parent -> right == reqNode) reqNode -> parent -> right = NULL;
                else reqNode -> parent -> left = NULL;
            } else {
                a -> root = NULL;
            }
        }
        rebalanceTree(a, parent);
    }
    free(reqNode);
}

static void PictureT(Node* a, int height){
    int h = height * 3;
    if (a) PictureT(a->right, height + 1);
    printf("|");
    int counter = 1;
    while (h--) {
        if (counter % 3 == 0) printf("|");
        else 
        printf(" ");
        counter += 1;
    }
    // if (a == NULL) printf("   nil\n");
    // else printf("   %d\n", a->key);
    // if (a) Picture(a->left, height + 1);
    if (a == NULL) printf("- nil\n");
    else printf("- %d\n", a->key);
    if (a) PictureT(a->left, height + 1);
}

void Picture(AVLTree* a){
    // Top: right
    // Bottom: left
    PictureT(a->root, 0);
}
