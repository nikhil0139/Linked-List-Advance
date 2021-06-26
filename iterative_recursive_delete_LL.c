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

void iterstive_delete (struct node *root)
{

    struct node *net, *current;

    if (root == NULL)
    {
        printf("Linked list is Empty.\n");
        return;
    }

    else
    {
        while (net != NULL)
        {
            net = root->next;
            free(root);
            root = net;
            printf("Sucessfully deleted.\n");
        }
    }
}

void recursive_delete(struct node *root){
    if(root == NULL)   return;

    else{
        recursive_delete(root->next);
        free(root);
        printf("Successfully deleted.\n");
    }
}



void main()
{

    createLL();

    recursive_delete (poly);

}