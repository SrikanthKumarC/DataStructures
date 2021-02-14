#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
    struct node * prev;
};
/*  Struct HEad pull*/
struct node * head = NULL;

void insertBeginning(int item) {
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->data=item;
    temp->next = head;
    temp->prev = NULL;
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
}
void insertAtEnd(int item) {
    struct node * temp, *trav;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = NULL;
    trav = head;
    while(trav->next != NULL) {
        trav = trav->next;
    }
    trav->next = temp;
    temp->prev = trav;
}
void print() {
    struct node * traverse = head, * dump;
    while(traverse != NULL) {
//dump=traverse;
        printf("%d ", traverse->data);
        traverse = traverse->next;
    }
   // while(dump != NULL) {
   //    printf("%d ", dump->data);
   //    dump = dump->prev;
   // }
    printf("\n");
}
void delete() {
    struct node * tempo = head;
    while(tempo->next != NULL) {
        tempo=tempo->next;
    }
    printf("deleted %d\n",tempo->data);
    tempo->prev->next = NULL;
    free(tempo);
}

void deleteBeg() {
    struct node * tempi = head;
    printf("Deleted %d\n", tempi->data );
    head = tempi->next;
    tempi->prev = NULL;
    free(tempi);
}

int main() {
    insertBeginning(234);
    insertBeginning(32);
 insertAtEnd(65);
 print();
 delete();
    insertBeginning(496);
    insertBeginning(642);
    deleteBeg();
    print();
}

