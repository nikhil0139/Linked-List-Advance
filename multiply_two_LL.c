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

void multiply(Node *a , Node *b){
    int num1 = 0;
    int num2 = 0;
    
    while(a || b){
        if(a){
            num1 = num1 * 10 + a->data;
            a = a->next;
        }
        if(b){
            num2 = num2 * 10 + b->data;
            b = b->next;
        }
    }
    printf("The multiplication is : %d\n" , num1 * num2);
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
    
    multiply(first , second);

}