#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void print(Node *first){
    Node *temp = first;
    do{
        printf("%d " , temp->data);
        temp = temp->next;
    }while(temp!=first);
}

Node * newNode(int data){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertInCLL(Node *first , int num){
    
    Node *head = first;
    Node *prev = NULL;
    Node *temp = newNode (num);
    
    if(head == NULL){
        temp->next  = temp;
        first = temp;
    }
    
    else if(num<= first->data){
        
        while(head->next!=first){
            head = head->next;
        }
        head->next = temp;
        temp->next = first;
        first = temp;
    }
    
    else{
        while(head->next!=first &&  num>= head->next->data){
            head = head->next;
    }
    temp->next = head->next;
    head->next = temp;
    }
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
    
    printf("The linked list is : ");
    print(first);

    printf("Enter the number you want to insert : ");
    scanf("%d" , &num);
    
    insertInCLL(first , num);
    print(first);
}