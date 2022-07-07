#ifndef HEAP_H_
#define HEAP_H_

typedef struct MaxHeap{
    int data[100];
    int maxSize;
    int lastIndex;
} MaxHeap;

MaxHeap* MaxCreate(int* arr, int size); // Creates a MaxHeap from an array of size 'size'
void MaxAdd(MaxHeap* heap, int key); // Insert an element into the heap
void MaxRemove(MaxHeap* heap); // Remove the max element from the heap
int findMax(MaxHeap* heap); // Get the max element
int MaxReplace(MaxHeap* heap, int key); // Get the max element and insert a new element
int extractMax(MaxHeap* heap); // pop
void MaxDisplay(MaxHeap* heap); // Print the heap as a list
// void MaxDisplayTree(MaxHeap* heap); // Display as a tree

#endif