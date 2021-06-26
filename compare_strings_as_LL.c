#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int c;
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
        temp->c = A[i];
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

int compareLL(Node *a, Node *b)
{
    while (a && b && a->c == b->c)
    {
        a = a->next;
        b = b->next;
    }
    if (a && b)
        return (a->c > b->c) ? 1 : -1;

    if (a && !b)
        return 1;
    if (!a && b)
        return -1;

    return 0;
}

void main()
{

    Node *first = NULL;
    Node *second = NULL;

    first = createLL(first);

    second = createLL(second);

    int flag = compareLL(first, second);

    if (flag == 0)
        printf("Both strings are same.\n");
    if (flag == 1)
        printf("A is ahead B\n");
    if (flag == -1)
        printf("B is ahead A\n");
}
