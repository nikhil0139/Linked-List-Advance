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

int detectLoop(Node *head)
{

    Node *slow = head;
    Node *fast = head;

    while (slow && fast && fast->next)
    {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            printf("Loop is found in the linked list at %d.\n" , slow->data);
            return 1;
        }
    }
    return 0;
}

void makeLoopAtKthPos(Node *first , int k){
    Node *temp = first;
    
    for(int i = 1 ; i < k ; i++){
        temp = temp->next;
    }
    
    Node *root = temp;
    
    while(temp->next){
        temp = temp->next;
    }
    temp->next = root;
    
    int j = detectLoop(first);
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

    first = createLL_1(first);
    
    printf("The linked list is : ");
    print(first);
    
    printf("Enter the k-th value on which you want to make loop : ");
    scanf("%d" , &k);
    
    makeLoopAtKthPos(first , k);
}