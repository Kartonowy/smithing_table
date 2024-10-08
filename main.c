#include <stdio.h>
#include "list.h"
int main() {
    struct Node* head = createNode(1);

    addLast(head, 2);
    addLast(head, 3);

    addFirst(&head, 0);
    addFirst(&head, -1);

    addAfterN(head, -2, 1);
    addBeforeN(head, 3, 1);
    /// List now: -1 -> 3 -> 0 -> -2 -> 1 -> 2 -> 3

    printf("%d\n", removeLast(head));
    /// List now: -1 -> 3 -> 0 -> -2 -> 1 -> 2

    printf("%d\n", removeFirst(&head));
    /// List now: 3 -> 0 -> -2 -> 1 -> 2

    printf("%d\n", removeAfterN(head, 2));
    /// List now: 3 -> 0 -> -2 -> 2

    printf("%d\n", removeBeforeN(head, 2));
    /// List now: 3 -> 0 -> 2

    printList(head);
}
