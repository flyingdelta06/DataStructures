#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "heap.h"

int defaultKey = 0;
MaxHeap defaultHeap = {.maxSize = 100, .data = {0}, .lastIndex = 0};

void replace(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b =  temp;
}

void MaxAdd(MaxHeap* heap, int key){
    int i = 0;
    for (i = 0; i < heap->maxSize; i++){
        if (heap->data[i] == defaultKey) {
            heap->data[i] = key;
            break;
        }
    }
    int* parent = heap->data + (int) floor((i - 1) / 2);
    while (*parent < key && i > 0){
        replace(parent, heap->data + i);
        i = (int) floor((i - 1) / 2);
        parent = heap->data + (int) floor((i - 1) / 2);
    }
    heap->lastIndex += 1;
}

MaxHeap* MaxCreate(int* arr, int size){
    MaxHeap* newHeap = (MaxHeap*) malloc(sizeof(MaxHeap));
    *newHeap = defaultHeap;
    for (int i = 0; i < size; i++){
        MaxAdd(newHeap, arr[i]);
    }
    return newHeap;
}

void MaxRemove(MaxHeap* heap){
    int outOfPlace = heap->data[heap->lastIndex];
    heap->data[heap->lastIndex] = defaultKey;
    heap->data[0] = outOfPlace;
    int outOfPlaceInd = 0;
    while (outOfPlace < heap->data[2 * outOfPlaceInd + 1] || outOfPlace < heap->data[2 * outOfPlaceInd + 2]){
        if (heap->data[2 * outOfPlaceInd + 1] > heap->data[2 * outOfPlaceInd + 2]) {
            replace(heap->data + outOfPlaceInd, heap->data + (2 * outOfPlaceInd + 1));
            outOfPlaceInd = 2 * outOfPlaceInd + 1;
            }
        else {
            replace(heap->data + outOfPlaceInd, heap->data + (2 * outOfPlaceInd + 2));
            outOfPlaceInd = 2 * outOfPlaceInd + 2;
            }
    }
}

int findMax(MaxHeap* heap){
    return heap->data[0];
}

int MaxReplace(MaxHeap* heap, int key){
    int toReturn = heap->data[0];
    int outOfPlace = key;
    heap->data[0] = outOfPlace;
    int outOfPlaceInd = 0;
    while (outOfPlace < heap->data[2 * outOfPlaceInd + 1] || outOfPlace < heap->data[2 * outOfPlaceInd + 2]){
        if (heap->data[2 * outOfPlaceInd + 1] > heap->data[2 * outOfPlaceInd + 2]) {
            replace(heap->data + outOfPlaceInd, heap->data + (2 * outOfPlaceInd + 1));
            outOfPlaceInd = 2 * outOfPlaceInd + 1;
            }
        else {
            replace(heap->data + outOfPlaceInd, heap->data + (2 * outOfPlaceInd + 2));
            outOfPlaceInd = 2 * outOfPlaceInd + 2;
            }
    }
    return toReturn;
}

int extractMax(MaxHeap* heap){
    int toReturn = heap->data[0];
    int outOfPlace = heap->data[heap->lastIndex];
    heap->data[heap->lastIndex] = defaultKey;
    heap->data[0] = outOfPlace;
    int outOfPlaceInd = 0;
    while (outOfPlace < heap->data[2 * outOfPlaceInd + 1] || outOfPlace < heap->data[2 * outOfPlaceInd + 2]){
        if (heap->data[2 * outOfPlaceInd + 1] > heap->data[2 * outOfPlaceInd + 2]) {
            replace(heap->data + outOfPlaceInd, heap->data + (2 * outOfPlaceInd + 1));
            outOfPlaceInd = 2 * outOfPlaceInd + 1;
            }
        else {
            replace(heap->data + outOfPlaceInd, heap->data + (2 * outOfPlaceInd + 2));
            outOfPlaceInd = 2 * outOfPlaceInd + 2;
            }
    }
    return toReturn;
}

void MaxDisplay(MaxHeap* heap){
    printf("[");
    for (int i = 0; i < heap->maxSize; i++){
        if (heap->data[i] == defaultKey) {
            break;
        } else {
            printf("%d", heap->data[i]);
        }
        if (i + 1 >= heap->maxSize || heap->data[i + 1] == defaultKey) printf("]\n");
        else printf(", ");
    }
}

// void MaxDisplayTree(MaxHeap* heap){
    
// }
