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

void insert(Node *first, Node *second, int k)
{

    Node *temp1 = first;
    int i = 1;

    while (i < k)
    {
        temp1 = temp1->next;
        i++;
    }

    Node *root = temp1->next;
    temp1->next = second;

    while (second->next != NULL)
    {
        second = second->next;
    }

    second->next = root;

    

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

void main()
{

    Node *first = NULL;
    Node *second = NULL;
    Node *res = NULL;

    first = createLL_1(first);
    print(first);

    second = createLL_1(second);
    print(second);
    
    insert(first, second, 3);

    print(first);
}
