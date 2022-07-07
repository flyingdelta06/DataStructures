#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(){
    int arr[] = {1, 3, 6, 10};
    MaxHeap* myHeap = MaxCreate(arr, 4);
    MaxDisplay(myHeap);
    MaxRemove(myHeap);
    MaxDisplay(myHeap);
    MaxAdd(myHeap, 5);
    MaxDisplay(myHeap);
    MaxReplace(myHeap, 2);
    MaxDisplay(myHeap);
    return 0;
}