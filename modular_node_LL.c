#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createLL(Node *head1)
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

int modularNode(Node *head, int k)
{

    if (head == NULL || k <= 0)
    {
        return -1;
    }

    int i = 1;

    Node *mode;

    Node *temp = head;

    while (temp)
    {
        if (i % k == 0)
            mode = temp;

        i++;
        temp = temp->next;
    }

    return mode->data;
}

void main()
{

    Node *first = NULL;

    first = createLL(first);

    int flag = modularNode(first, 3);

    printf("The modular node in the linked list is %d \n", flag);
}