#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;


int checkCLL(Node *head){
    
    if(head == NULL){
        return 1;
    }
    
    Node *node = head->next;
    
    while(node && node!=head){
            node = node->next;
    }
    if(node == head){
        return 1 ;
    }
    return 0;
}
void main()
{
    int num;
    Node *first = (Node *)malloc(sizeof(Node));
    Node *second = (Node *)malloc(sizeof(Node));
    Node *third = (Node *)malloc(sizeof(Node));
    Node *fourth = (Node *)malloc(sizeof(Node));
    Node *fifth = (Node *)malloc(sizeof(Node));
    Node *sixth = (Node *)malloc(sizeof(Node));
    Node *seventh = (Node *)malloc(sizeof(Node));

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 8;
    fourth->next = fifth;

    fifth->data = 9;
    fifth->next = sixth;

    sixth->data = 10;
    sixth->next = seventh;

    seventh->data = 11;
    seventh->next = first;
    
    num = checkCLL(first);
    if(num == 1){
        printf("Yes Linked list is circular.\n");
    }
    if(num==0){
         printf("No Linked list is not circular.\n");
    }
}