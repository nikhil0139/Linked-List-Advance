#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void detect_removeLoop(Node *head)
{

    Node *slow = head;
    Node *fast = head;

    while (slow && fast && fast->next)
    {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            break;
        }
    }
    
    if(slow == fast){

        slow = head;

        while(slow->next!=fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = NULL;
    }
}

void print(struct node *temp){

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    } 
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

    seventh->data = 10;
    seventh->next = third;

    detect_removeLoop(first);

    print(first);
}