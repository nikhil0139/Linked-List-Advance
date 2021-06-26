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

int nonRepeatingElement(Node *first){
    Node *temp = first;
    int count[20] = {0};
    
    while(temp){
        count[temp->data]++;
        temp = temp->next;
    }
    
    while(first){
        if(count[first->data] == 1){
            printf("The first non repeating element is %d\n" , first->data);
            break;
        }
        first = first->next;
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
    
    Node *first = NULL;

    first = createLL_1(first);
    
    printf("The linked list is : ");
    print(first);
    
    nonRepeatingElement(first);
    
}