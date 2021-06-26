#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *poly = NULL;

void createLL()
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

        if (poly == NULL)
        {
            poly = last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
}

int iterativeLength(struct node *root)
{

    int count1 = 0;
    while (root != NULL)
    {
        count1++;
        root = root->next;
    }
    return count1;
}

int recursiveLength(struct node *root)
{
    if (root != NULL)
    {
        return 1 + recursiveLength(root->next);
    }
}

void main()
{

    createLL();

    printf("The length of linked list by iterative is : %d\n", iterativeLength(poly));

    printf("The length of linked list by recursive is : %d\n", recursiveLength(poly));
}