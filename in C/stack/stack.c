#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


// With Array

stackA defaultstackA = {100, 0};

stackA* createStackA(){
    stackA* newstackA = (stackA*) malloc(sizeof(stackA));
    *newstackA = defaultstackA;
    return newstackA;
}

void Push(stackA* a, int val){
    if (a->k == a->maxSize) {
        printf("The stackA is full!");
        return;
    }
    (a->data)[(a->k)++] = val;
}

int Pop(stackA* a){
    if (a->k == 0) {
        printf("The stackA is empty!");
        return 0;
    }
    a->k -= 1;
    return (a->data)[(a->k)];
}

void Display(stackA* a){
    if (a->k == 0) {
        printf("The stackA is empty!");
        return;
    }
    for (int currK = 0; currK < a->k - 1; currK++){
        printf("%d, ", (a->data)[currK]);
    }
    printf("%d", (a->data)[a->k - 1]);
}

int Peek(stackA* a){
    return (a->data)[a->k - 1];
}

int isEmpty(stackA* a){
    if (a->k == 0) return 1;
    return 0;
}

void PrintStackA(stackA* a){
    for (int i = 0; i < a->k - 1; i++){
        printf("%d, ", (a->data)[i]);
    } printf("%d\n", a->data[a->k - 1]);
}

// With Linked List