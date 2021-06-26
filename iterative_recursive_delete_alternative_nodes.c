#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createLL_1(Node *head1)
{
    int num;
    int A[100];
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

void iterative_deleteAltNodes(Node *first){
    
    Node *prev = first;
    Node *node = first->next;
    while( prev && node){
        prev->next = node->next;
        free(node);
        prev = prev->next;
        if(prev){
            node = prev->next;
        }
    }
}
void recursive_deleteAltNodes(Node *first){
    
    if(first == NULL)    return;
    
    Node *node = first->next;
    if(node == NULL)     return;
    first->next = node->next;
    free(node);
    recursive_deleteAltNodes(first->next);
    
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

    first = createLL_1(first);
    
    printf("The linked list is : ");
    print(first);
    
    //iterative_deleteAltNodes(first);
    
    recursive_deleteAltNodes(first);
    
    print(first);
}