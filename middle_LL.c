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

int middleData_1(struct node *head)
{

    int count = 0;
    struct node *root = head;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    for (int i = 0; i < count / 2; i++)
    {
        root = root->next;
    }

    return root->data;
}

int middleData_2(struct node *head)
{

    struct node *root = head;
    struct node *temp = head;

    while (temp && temp->next)
    {
        temp = temp->next->next;
        root = root->next;
    }

    return root->data;
}

int middleData_3(struct node *head)
{

    int count = 0;
    struct node *root = head;

    while (head != NULL)
    {
        if (count % 2 != 0)
            root = root->next;

        count++;
        head = head->next;
    }

    return root->data;
}

void main()
{
    createLL();

    printf("The middle element of the linked list is %d \n", middleData_1(poly));

    printf("The middle element of the linked list is %d \n", middleData_2(poly));

    printf("The middle element of the linked list is %d \n", middleData_3(poly));
}