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

void removeDuplicates(Node *head)
{

    Node *current = head;
    Node *temp = NULL;

    while (current->next!=NULL)
    {
        temp = current->next;
        if (current->data == temp->data)
        {
            current->next = temp->next;
            free(temp);
        }
        else
        {
            current = current->next;
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
    printf("\n");
}

void main(){

    Node *first = NULL;

    first = createLL(first);

    print(first);

    removeDuplicates(first);

    print(first);

}