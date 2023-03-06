#include <iostream>
#include "all.h"
int main() {
    int length;
    scanf("%d", &length);
    Node* first = createList(length);
    showList(first);
//    addElement(first,length);
    deleteElementByIndex(first,length);
    showList(first);
    first = reverseList(first, length);
    showList(first);
    getch();
    cleanList(first);
    return 0;
}
