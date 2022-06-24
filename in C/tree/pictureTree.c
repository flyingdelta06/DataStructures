#include <stdio.h>
#include <stdlib.h>
#include "../stack/stack.h"
#include "binaryTree.h"

typedef stackA Stack;

Stack DefaultStack_def = {.k = 0, .maxSize = 100};

void Picture(Node* a, int height, Stack st){
    int h = height * 3;
    Push(&st, 1);
    if (a) Picture(a->right, height + 1, st);
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
    if (a) Picture(a->left, height + 1, st);
    Pop(&st);
}

void PictureT(Tree* a){
    // Top: right
    // Bottom: left
    Stack m = DefaultStack_def;
    Picture(a->root, 0, m);
}

void takeInput(Tree* a){
    int currInt;
    printf("Enter the numbers: ");
    while (fscanf(stdin, " %d", & currInt) == 1) {
        InsertT(a, currInt);
    }
    InorderT(a);
    getc(stdin);
}

int main() {
    Tree myTree = {
        NULL
    };
    char inp = 'i';
    while (inp != 'e'){
        printf("Operation(i for input, d to delete, e to end, p to print): ");
        scanf("%c", &inp);
        switch(inp){
            case 'i':
            takeInput(&myTree);
            break;
            case 'd':
            printf("To delete: ");
            int toDel;
            scanf("%d", &toDel);
            Delete(&myTree, toDel);
            break;
            case 'p':
            PictureT(&myTree);
            break;
            default:
            break;
        }
    }
    return 0;
}



