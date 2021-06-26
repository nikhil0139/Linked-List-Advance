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

int nodeValue(struct node *root, int index)
{

    for (int i = 0; (i < index && root != NULL); i++)
    {
        root = root->next;
    }

    if (root == NULL)
    {
        return -1;
    }
    else
    {
        return root->data;
    }
}

void main()
{
    int index;

    createLL();

    printf("Enter the index which you want to get : ");
    scanf("%d ", &index);

    int y = nodeValue(poly, index);

    if (y == -1)
    {
        printf("The given index is not present in the linked list.\n");
    }
    else
    {
        printf("The value of node at index %d is %d.\n", index, y);
    }
}