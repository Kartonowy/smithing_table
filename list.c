#include <stdio.h>
#include <stdlib.h>

typedef int Data;
struct Node {
    Data data;
    struct Node* next;
};


/// Allocs new memory space the size of Node
/// This is proper way instead of doing pointer without malloc
///
/// the result from malloc is casted to pointer so to avoid pointers
/// everywhere. cheers
struct Node* createNode(Data value)  {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = value;
    new->next = NULL;
    return new;
}

/// Moves to last node and appends new node at the end
void addLast(struct Node* head, Data value) {
    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    struct Node* new = createNode(value);
    last->next = new;
}

/// Moving whole list forward a node and placing new value as new node
///
/// Has to accept pointer to pointer to change head inplace instead of 
/// returning a new value
void addFirst(struct Node** head_ptr, Data value) {
    struct Node* new = createNode(value);
    new->next = *head_ptr;
    *head_ptr = new;
}



// Printing by iterating with formatting like:
// x -> y -> z
void printList(struct Node* head) {
    struct Node* iter = head;
    while (iter->next != NULL) {
        printf("%d -> ", iter->data);
        iter = iter->next;
    }
    printf("%d\n", iter->data);
}
