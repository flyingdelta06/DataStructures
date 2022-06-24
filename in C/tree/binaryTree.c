#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

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
    return createdNode;
}

static void Insert(Node * a, int key) {
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
}

static void Inorder(Node * head) {
    if (head -> left) Inorder(head -> left);
    printf("%d ", head -> key);
    if (head -> right) Inorder(head -> right);
}

void InsertT(Tree * a, int key) {
    if (a -> root) {
        Insert(a -> root, key);
    } else {
        Node * head = newNode(key, NULL, NULL, NULL);
        a -> root = head;
    }
}

void InorderT(Tree * a) {
    if (!(a -> root)) {
        printf("The tree is empty!\n");
        return;
    }
    Inorder(a -> root);
    printf("\n");
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

void Delete(Tree * a, int key) {
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
    } else if (reqNode -> left || reqNode -> right) {
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
    free(reqNode);
}

static void Picture(Node* a, int height){
    int h = height * 3;
    if (a) Picture(a->right, height + 1);
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
    if (a) Picture(a->left, height + 1);
}

void PictureT(Tree* a){
    // Top: right
    // Bottom: left
    Picture(a->root, 0);
}
