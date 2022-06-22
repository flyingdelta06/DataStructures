#ifndef LIST_H_
#define LIST_H_

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct linkedList{
    Node* head;
    int length;
} List;
List* CreateList();
void DeleteList(List*);
void AddFirst(List*, int value);
void AddAt(List*, int value, int index);
void AddLast(List*, int value);
void RemoveFirst(List*);
void RemoveAt(List*, int index);
void RemoveLast(List*);
int GetFirst(List*);
int GetAt(List*, int index);
int GetLast(List*);
void PrintList(List*);

#endif /* LIST_H_ */