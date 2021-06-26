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

void sort(Node *head)
{
    int count[3] = {0, 0, 0};
    Node *ptr = head;

    while (ptr != NULL)
    {
        count[ptr->data]++;
        ptr = ptr->next;
    }

    ptr = head;
    int i = 0;

    while (ptr != NULL)
    {

        if (count[i] == 0)
            i++;
        else
        {
            ptr->data = i;
            count[i]--;
            ptr = ptr->next;
        }
    }
}

void print(Node *root)
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

    Node *first = NULL;

    first = createLL(first);

    sort(first);

    printf("The Sorted linked list is : ");
    print(first);
}