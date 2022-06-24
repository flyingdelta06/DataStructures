#ifndef BTREE_H
#define BTREE_H

typedef struct Node {
    struct Node * parent;
    struct Node * left;
    struct Node * right;
    int key;
}
Node;

typedef struct Tree {
    struct Node * root;
}
Tree;

void InsertT(Tree * tree, int key);
void InorderT(Tree * tree);
void Delete(Tree * tree, int key);
__attribute__((weak)) void PictureT(Tree* tree);

#endif /* BTREE_H */