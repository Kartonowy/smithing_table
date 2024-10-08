#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

/// As of writing, it WONT panic if n is out of bounds or something 
/// unexpected occurs 
void addAfterN(struct Node *head, Data value, int n) {
    struct Node* iter = head;
    while ( n != 0) {
        iter= iter->next;   
        n -= 1;
    }
    
    struct Node* temp = iter->next;
    iter->next = createNode(value);
    iter->next->next = temp;
}

void addBeforeN(struct Node *head, Data value, int n) {
    struct Node* iter = head;
    while ( n != 1) {
        iter= iter->next;   
        n -= 1;
    }
    
    struct Node* temp = iter->next;
    iter->next = createNode(value);
    iter->next->next = temp;
}

/// REMOVALS

int removeLast(struct Node *head) {
    struct Node* last = head;
    if (last == NULL) {
        return 0;
    }
    if (last->next == NULL) {
        return last->data;
    }

    while (last->next->next != NULL) {
        last = last->next;
    }

    int value = last->next->data;
    last->next = NULL;

    return value;
}

int removeFirst(struct Node** head_ptr) {
    struct Node* temp = *head_ptr;
    *head_ptr = temp->next;
    return temp->data;
}

int removeAfterN(struct Node *head, int n) {
    struct Node* iter = head;
    while ( n != 0) {
        iter= iter->next;   
        n -= 1;
    }
    
    struct Node* temp = iter->next->next;
    int value = iter->next->data;
    free(iter->next);
    iter->next = temp;
    return value;
}


int removeBeforeN(struct Node *head, int n) {
    struct Node* iter = head;
    while ( n != 1) {
        iter= iter->next;   
        n -= 1;
    }
    
    struct Node* temp = iter->next->next;
    int value = iter->next->data;
    free(iter->next);
    iter->next = temp;
    return value;
}
