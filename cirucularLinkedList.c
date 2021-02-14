#include <stdio.h>
#include <stdlib.h>
// circular singly linked list
struct node {
    int data;
    struct node * next;
};

struct node * head = NULL;
struct node * tail = NULL;

//insert at beginning
void insert(int last) {
    struct node * test = (struct node *)malloc(sizeof(struct node));
    test->data = last;
    printf("inserted = %d\n", test->data);
    if (head == NULL) {
        head = test;
        tail = test;
    } else {
       test->next=head;
       head = test;
       tail->next=head;
    }
}
void insertAtEnd(int last) {
    struct node * test = (struct node *)malloc(sizeof(struct node));
    test->data = last;
    printf("inserted at last = %d\n", test->data);
    tail->next = test;
    test->next = head;
    tail = test;
}
// delete at last
void delete() {
    struct node * test=head;
    head = head->next;
    test->next = head;
    test->next = NULL;
    printf("Deleted-> %d\n", test->data);
    free(test);
}

// Traverse and print
void print() {
    struct node * test = head;
    if (test != NULL) {
        do {printf(" %d ", test->data);
        test = test->next;} while( test != head);

    }
}

int main() {
    insert(234);
    insert(23);
    insertAtEnd(324);
    insertAtEnd(654);
    insert(534);
    delete();
    insert(465);
    print();
    return 0;
}
