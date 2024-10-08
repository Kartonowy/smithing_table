#include <stdio.h>
#include "list.h"
int main() {
    struct Node* head = createNode(1);

    addLast(head, 13);
    addLast(head, 69);

    addFirst(&head, 0);
    addFirst(&head, 123);

    printList(head);
}
