#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createLL_1(Node *head1)
{
    int num, A[100];
    struct node *last = NULL;
    struct node *temp = NULL;

    printf("Enter the number of elements in the linked list : ");
    scanf("%d", &num);
    printf("Enter the values : ");

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &A[i]);

        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = A[i];
        temp->next = NULL;

        if (head1 == NULL)
        {
            head1 = last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
    return head1;
}

Node * middleNodeAsHead(Node *first)
{

    Node *slow = first;
    Node *fast = first;
    Node *prev = NULL;

    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    slow->next = first;
    first = slow;

    return first;
}

void print(Node *first)
{
    while (first)
    {
        printf("%d ", first->data);
        first = first->next;
    }
    printf("\n");
}

void main(){

    Node *first = NULL;

    first = createLL_1(first);

    print(first);

    first = middleNodeAsHead(first);

    print(first);
}