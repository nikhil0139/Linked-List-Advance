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

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void iterative_pairwiseSwap(Node *head)
{
    while (head && head->next)
    {
        swap(&(head->data), &(head->next->data));
        head = head->next->next;
    }
}

void recursive_pairwiseSwap(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;
    else
    {
        swap(&(head->data), &(head->next->data));
        recursive_pairwiseSwap(head->next->next);
    }
}

void print(struct node *root)
{
    while (root != NULL)
    {
        printf("%d ", root->data);
        root = root->next;
    }
}
void main()
{

    Node *first = NULL;

    first = createLL_1(first);

    printf("The linked list before swapping is : ");
    print(first);
    printf("\n");

    iterative_pairwiseSwap(first);
    //recursive_pairwiseSwap(first);

    printf("The linked list after swapping is : ");
    print(first);
    printf("\n");
}