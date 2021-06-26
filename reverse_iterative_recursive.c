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

void iterativeReverse(struct node *root){

    struct node *prev = NULL;
    struct node *curr = root;
    struct node *temp;

    while(curr!=NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    poly = prev;
}

void recursiveReverse(struct node *head){

    if(head==NULL)   return;

    else{
        recursiveReverse(head->next);
        printf("%d ",head->data);
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


void main(){
    createLL();

    printf("By recursive reverse the linked list is : ");

    recursiveReverse(poly);
    
    printf("\n"); 

     printf("By iterative reverse the linked list is : ");

    iterativeReverse(poly);

    print(poly);

    printf("\n");


}