#include <stdio.h>
#include <stdlib.h>

struct node {
    int integer;
    struct node * next;
    struct node * prev;
};

struct node * head = NULL;

void insert(int data) {
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->integer = data;
    temp->next = head;
    temp->prev = NULL;
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
}

// void insertBefore(int data) {
    
// }
void delete() {
    struct node * del = head;
    while(del->next != NULL) {
       del = del->next;
    }
    del->prev->next = NULL;
    // head = del;
    free(del);
} 

void delete_from_beginning() {
   struct node * temp= head;
   printf("Deleted %d\n", temp->integer);
   temp->next->prev = NULL;
   free(temp);
}
void print() {
    printf("Traversal in forward direction \n");
    struct node * temp = head;
    struct node * dump;
    while(temp != NULL) {
        printf("%d ",temp->integer);
        dump = temp;
        temp = temp->next;
    }
    printf("\nTraversal in reverse direction \n");
    while(dump!=NULL) {
        printf("%d ", dump->integer);
        dump=dump->prev;
    }
    printf("\n");
}

int main() {
    insert(32);
    insert(45);
    insert(35);
    insert(64);
    print();
    delete();
    print();
    delete_from_beginning();
    print();
    return 0;
}
