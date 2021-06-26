#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createLL_1(Node *head1)
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

Node deleteNafterM(Node *first , int M , int N)
{
    int i;
    Node *temp = NULL;
    Node *curr = first;
    Node *delete = NULL;
    
    while(curr){
    for(i = 1 ; i<M && curr ; i++){
        curr = curr->next;
    }
    if(!curr)    return;
    
    temp = curr->next;
    
    for(i = 1 ; i<=N && temp ; i++){
        delete = temp->next;
        free(temp);
        temp = delete;
    }
    curr->next = temp;
    curr = temp;
    }
}

void print(Node *root)
{
    while (root != NULL)
    {
        printf("%d ", root->data);
        root = root->next;
    }
    printf("\n");
}

void main()
{

    Node *first = NULL;
    
    first = createLL_1(first);
    
    printf("The linked list is : ");
    
    print(first);

    deleteNafterM(first , 2 , 2);

    printf("The linked list after deletion : ");

    print(first);
}
