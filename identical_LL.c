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

int iterative_identical(Node *a , Node *b){
    while(a && b){
        if(a->data != b->data)  return 0;
        a = a->next;
        b= b->next;
    }
    if(!a && !b)  return 1;
    
    return 0;
}

int recursive_identical(Node *a , Node *b){
    if(!a && !b)   return 1;
    
    if(a && b){
        return ((a->data == b->data) && recursive_identical(a->next , b->next));
    }
    return 0;
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
    int k;
    Node *first = NULL;
    Node *second = NULL;

    first = createLL_1(first);
    second = createLL_1(second);
    
    printf("The linked list 1 is : ");
    print(first);
    
    printf("The linked list 2 is : ");
    print(second);
    
    //k =  iterative_identical(first , second);
    
    k =  recursive_identical(first , second);
    
    if(k==1){
        printf("Given linked lists are identical.\n");
    }
    else{
        printf("Given linked lists are not identical.\n");
    }
    
    
    
}