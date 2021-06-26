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

int rotations(Node *first)
{

    int min = first->data;
    int count = 0;

    while (first)
    {
        if (first->data < min)
            break;

        first = first->next;
        count++;
    }

    return count;
}

void main()
{

    Node *first = NULL;

    first = createLL_1(first);

    int flag = rotations(first);

    printf("Number of rotations in the linked list is %d \n", flag);
}