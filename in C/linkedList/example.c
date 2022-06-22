#include "list.h"

int main(){
    List* myList = CreateList();
    PrintList(myList);
    AddFirst(myList, 0);
    AddFirst(myList, 1);
    AddFirst(myList, 2);
    AddFirst(myList, 4);
    AddFirst(myList, 5);
    PrintList(myList);
    AddAt(myList, 3, 3);
    PrintList(myList);
    AddLast(myList, 6);
    PrintList(myList);
    RemoveFirst(myList);
    PrintList(myList);
    RemoveAt(myList, 2);
    PrintList(myList);
    RemoveLast(myList);
    printf("%d\n", GetFirst(myList));
    printf("%d\n", GetAt(myList, 3));
    printf("%d\n", GetLast(myList));
    PrintList(myList);
    DeleteList(myList);
}