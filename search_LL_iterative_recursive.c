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

void search_iterative(struct node *root, int key)
{

    while (root != NULL)
    {
        if (root->data == key)
        {
            printf("%d found in the list.\n", key);
            return;
        }
        root = root->next;
    }

    if (root == NULL)
    {
        printf("%d is not in the list.\n", key);
    }
}

int search_recursive(struct node *temp , int key ){

    if(temp == NULL){
        return -1;
    }

    if(temp->data == key){
        return 1;
    }

    search_recursive(temp->next , key);

}

void main(){
    int key;

    createLL();

    printf("Enter the element to be searched in the linked list : ");
    scanf("%d ",&key);

    search_iterative(poly , key);

    int flag = search_recursive(poly , key);

    if(flag == 1){
        printf("%d found in the list recursively.\n");
    }
    else{
        printf("%d is not found in the list recursively.\n");
        
    }
}