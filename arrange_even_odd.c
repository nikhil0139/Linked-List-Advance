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

void arrangeEvenOdd(Node *first)
{
    int i;
    Node *odd = first;
    Node *even = first->next;
    Node *even1 = even;
    
    while(1){
        if(!odd || !even || !(even->next)){
            odd->next = even1;
            break;
        }
        odd->next = even->next;
        odd = even->next;
        
        if(odd->next == NULL){
            even->next = NULL;
            odd->next = even1;
            break;
        }
        even->next = odd->next;
        even = odd->next;
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

    arrangeEvenOdd(first);

    printf("The linked list after rearranging  : ");

    print(first);
}