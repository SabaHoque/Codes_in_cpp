#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void insertAtAnyPos(struct Node** head, int d, int pos) {

    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = d;
    n->next = NULL;

    if (pos == 0) {
        n->next = *head;
        *head= n;
        return;
    }


    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }


    n->next = temp->next;
    temp->next = n;
}

void modifyAtPos(struct Node* head, int pos, int n) {

    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }


    temp->data = n;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtAnyPos(&head, 1, 0);
    insertAtAnyPos(&head, 2, 1);
    insertAtAnyPos(&head, 4, 2);
    insertAtAnyPos(&head, 3, 3);

    printf("Original linked list: ");
    printList(head);


    modifyAtPos(head, 2, 5);

    printf("Modified linked list: ");
    printList(head);

    return 0;
}
