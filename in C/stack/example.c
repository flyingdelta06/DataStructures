#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main(){
    stackA* myStack = createStackA();
    Push(myStack, 5);
    Push(myStack, 6);
    Push(myStack, 7);
    Push(myStack, 8);
    Push(myStack, 9);
    PrintStackA(myStack);
    printf("%d\n", Pop(myStack));
    PrintStackA(myStack);
    return 0;
}