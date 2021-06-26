#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void deleteRefNode(Node *delNode){
    Node *temp = delNode->next;
    delNode->data = temp->data;
    delNode->next = temp->next;
    free(temp);
    
}

void print(struct node *root)
{
    while (root != NULL)
    {
        printf("%d ", root->data);
        root = root->next;
    }
    printf("\n");
}


void main()
{

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

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = sixth;

    sixth->data = 6;
    sixth->next = seventh;

    seventh->data = 7;
    seventh->next = NULL;
    
    print(first);
    
    deleteRefNode(sixth);
    
    print(first);

}