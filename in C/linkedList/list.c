#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List* CreateList(){
    List* newList = malloc(sizeof(List));
    *newList = (List) {.head = NULL, .length = 0};
    return newList;
}

void DeleteList(List* a){
    Node* temp = a->head;
    while (temp->next){
        Node* toDel = temp;
        temp = temp->next;
        free(toDel);
    }
    free(a);
}

static Node* getPvNode(List* a, int index){
    if (index == 0 || index == a->length + 1) return NULL;
    index -= 1;
    index = ((index < 0)? index + (a->length): index);
    int ind = 0;
    Node* temp = a->head;
    while (ind != index){
        temp = temp->next;
        ind++;
    }
    return temp;
}

static Node* getNode(List* a, int index){
    index = ((index < 0)? index + (a->length): index);
    int ind = 0;
    Node* temp = a->head;
    while (ind != index){
        temp = temp->next;
        ind++;
    }
    return temp;
}

static Node* getNextNode(List* a, int index){
    if (index == -1 || index == a->length - 1) return NULL;
    index += 1;
    index = ((index < 0)? index + (a->length): index);
    int ind = 0;
    Node* temp = a->head;
    while (ind != index){
        temp = temp->next;
        ind++;
    }
    return temp;
}

static Node* newNode(int val){
    Node* createdNode = (Node*) malloc(sizeof(Node));
    createdNode->data = val;
    createdNode->next = NULL;
    return createdNode;
}

void AddFirst(List* a, int val){
    if (a->length == 0) {
        Node* toInsert = newNode(val);
        a->head = toInsert;
        a->length += 1;
        return;
    }
    Node* toInsert = newNode(val);
    toInsert->next = a->head;
    a->head = toInsert;
    a->length = a->length + 1;
}

void AddAt(List* a, int val, int index){
    if (a->length == 0) {
        Node* toInsert = newNode(val);
        a->head = toInsert;
        a->length += 1;
        return;
    }
    Node* toInsert = newNode(val);
    Node* pvNode = getPvNode(a, index);
    Node* nextNode = getNode(a, index);
    if (pvNode) pvNode->next = toInsert;
    if (nextNode) toInsert->next = nextNode;
    a->length += 1;
}

void AddLast(List* a, int val){
    if (a->length == 0) {
        Node* toInsert = newNode(val);
        a->head = toInsert;
        a->length += 1;
        return;
    }
    Node* toInsert = newNode(val);
    Node* first = getNode(a, -1);
    first->next = toInsert;
    a->length += 1;
}

void RemoveFirst(List* a){
    if (a->length == 0) return;
    else if (a->length == 1) {
        free(getNode(a, 0));
        a->head = NULL;
        a->length -= 1;
        return;
    }
    Node* last = getNode(a, 0);
    a->head = last->next;
    free(last);
    a->length -= 1;
}

void RemoveAt(List* a, int index){
    if (a->length == 0) return;
    Node* pvNode = getPvNode(a, index);
    Node* currNode = getNode(a, index);
    if (!pvNode) {
        pvNode = a->head;
        }
    if (currNode) pvNode->next = currNode->next;
    else pvNode->next = NULL;
    free(currNode);
    a->length -= 1;
}

void RemoveLast(List* a){
    if (a->length == 0) return;
    else if (a->length == 1) {
        free(getNode(a, 0));
        a->head = NULL;
        a->length -= 1;
        return;
    }
    Node* last = getNode(a, -1);
    Node* pvNode = getNode(a, -2);
    pvNode->next = NULL;
    free(last);
    a->length -= 1;
}

int GetFirst(List* a){
    return a->head->data;
}

int GetAt(List* a, int index){
    Node* myNode = getNode(a, index);
    return myNode->data;
}

int GetLast(List* a){
    Node* last = getNode(a, -1);
    return last->data;
}

void PrintList(List* a){
    if (a->length == 0) {
        printf("The list is empty...\n");
        return;
    }
    Node* k = a->head;
    while (k->next){
        printf("%d, ", k->data);
        k = k->next;
    } printf("%d\n", k->data);
}

