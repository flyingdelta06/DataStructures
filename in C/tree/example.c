#include "binaryTree.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    Tree myTree = {
        NULL
    };
    int currInt;
    printf("Enter the numbers: ");
    while (fscanf(stdin, " %d", & currInt) == 1) {
        InsertT( & myTree, currInt);
    }
    InorderT( & myTree);
    getc(stdin);
    PictureT(&myTree);
    int toDelete = 0;
    while (toDelete != -1){
        printf("\nTo delete: ");
        scanf("%d", & toDelete);
        Delete( & myTree, toDelete);
        InorderT( & myTree);
        PictureT(&myTree);
    }
    return 0;
}