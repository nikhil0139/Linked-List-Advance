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

void iterative_printAltNodes(Node *first){
    int count = 0;
    
    while(first){
        if(count%2 == 0){
            printf("%d " , first->data);
        }
        count++;
        first = first->next;
    }
}
void recursive_printAltNodes(Node *first , int k){
    
    if(!first)    return;
    
    if(k%2 == 0){
        printf("%d " , first->data);
    }
    recursive_printAltNodes(first->next , k+1);
    
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
    
    //iterative_printAltNodes(first);
    
    recursive_printAltNodes(first , 0);
}