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


void print(struct node *root)
{
    while (root != NULL)
    {
        printf("%d ", root->data);
        root = root->next;
    }
}

void swapNodes(struct node *head, int X, int Y)
{

    if (X == Y)
        return;

    struct node *prev_X = NULL;
    struct node *curr_X = head;
    struct node *prev_Y = NULL;
    struct node *curr_Y = head;

    while (curr_X && curr_X->data != X)
    {
        prev_X = curr_X;
        curr_X = curr_X->next;
    }

    while (curr_Y && curr_Y->data != Y)
    {
        prev_Y = curr_Y;
        curr_Y = curr_Y->next;
    }

    if (curr_X == NULL || curr_Y == NULL)
    {
        printf("One or both of the given keys are not in the list.\n");
        return;
    }

    if (prev_X != NULL)
    {
        prev_X->next = curr_Y;
    }
    else
    {
        head = curr_Y;
    }

    if (prev_Y != NULL)
    {
        prev_Y->next = curr_X;
    }
    else
    {
        head = curr_X;
    }

    struct node *temp = curr_Y->next;
    curr_Y->next = curr_X->next;
    curr_X->next = temp;

    
    printf("After swapping : ");

    print(poly);
    printf("\n");
}

void main()
{

    int X1, X2;
    createLL();


    printf("Enter the keys you want to swap : ");
    scanf("%d%d", &X1, &X2);

    printf("Before swapping : ");
    print(poly);
    printf("\n");

    swapNodes(poly, X1, X2);


}