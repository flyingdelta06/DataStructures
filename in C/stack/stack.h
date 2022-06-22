#ifndef STACK_H
#define STACK_H
// #include "list.h"
 
typedef struct stackA {
    unsigned int maxSize;
    unsigned int k; // Where the new element gets inserted
    int data[100];
} stackA;

// typedef struct stackL {
//     unsigned int k;
//     List data;
// } stackL;

stackA* createStackA();
void Push(stackA*, int value);
int Pop(stackA*);
void Display(stackA*);
int Peek(stackA*);
int isEmpty(stackA*);
void PrintStackA(stackA*);


// stackL* createStackL();
// void Push(stackL*, int value);
// int Pop(stackL*);
// void Display(stackL*);
// int Peek(stackL*);
// int isEmpty(stackL*);
// void PrintStackA(stackL*);

#endif /* STACK_H */
