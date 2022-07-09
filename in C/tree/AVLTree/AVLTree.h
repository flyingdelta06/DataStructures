#ifndef AVLTREE_H_
#define AVLTREE_H_

typedef struct Node {
    struct Node * parent;
    struct Node * left;
    struct Node * right;
    unsigned int leftH;
    unsigned int rightH;
    int key;
}
Node;

typedef struct AVLTree {
    struct Node * root;
}
AVLTree;

AVLTree* Create(int* arr);
void Insert(AVLTree * tree, int key);
void Inorder(AVLTree * tree);
void Delete(AVLTree * tree, int key);
__attribute__((weak)) void Picture(AVLTree* tree);

#endif