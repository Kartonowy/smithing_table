#ifndef LIST_H
#define LIST_H
typedef int Data;
struct Node {
    Data data;
    struct Node* next;
};

struct Node* createNode(Data value);

void addFirst(struct Node** head_ptr, Data value);
void addLast(struct Node* head, Data value);
void addAfterN(struct Node* head, Data value, int n);
void addBeforeN(struct Node* head, Data value, int n);

int removeFirst(struct Node** head);
int removeLast(struct Node* head);
int removeAfterN(struct Node* head);
int removeBeforeN(struct Node* head);

void printList(struct Node* head);
#endif
