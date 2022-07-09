#include <stdlib.h>
#include <stdio.h>
#include "AVLTree.h"
#include "../../stack/stack.h"

typedef stackA Stack;

Stack DefaultStack_def = {.k = 0, .maxSize = 100};

void PictureT(Node* a, int height, Stack st){
    int h = height * 3;
    Push(&st, 1);
    if (a) PictureT(a->right, height + 1, st);
    Pop(&st);
    int pv = 0;
    if (st.k != 0) printf("   ");
    // Without new lines for null nodes
    // if (a == NULL) printf("");
    // else 
    // End without likes for null nodes
    for (int i = 0; i < st.k; i++){
        if (i != 0) {
            if (pv + st.data[i] == 0) printf("|  ");
            else printf("   ");
        }
        pv = st.data[i];
    }
    // Leaf Nodes
    if (a == NULL) printf("|- nil\n");
    if (a != NULL) printf("|- %d\n", a->key);
    Push(&st, -1);
    if (a) PictureT(a->left, height + 1, st);
    Pop(&st);
}

void Picture(AVLTree* a){
    // Top: right
    // Bottom: left
    Stack m = DefaultStack_def;
    PictureT(a->root, 0, m);
}

int main(){
    int arr[] = {1, 8, 9, 0};
    AVLTree* myTree = Create(arr, 4);
    Insert(myTree, 6);
    Picture(myTree);
    printf("\n");
    Insert(myTree, 5);
    Picture(myTree);
    printf("\n");
    Insert(myTree, 7);
    Picture(myTree);
    printf("\n");
    Insert(myTree, 4);
    Picture(myTree);
    printf("\n");
    Insert(myTree, 3);
    Picture(myTree);
    printf("\n");
    Insert(myTree, 2);
    Picture(myTree);
    printf("\n");
    Insert(myTree, 1);
    Picture(myTree);
    printf("\n");
    Delete(myTree, 6);
    Picture(myTree);
}