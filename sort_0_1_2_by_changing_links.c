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

Node * newNode(int data){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Node * sort012(Node *first){
    Node *zeroD = newNode(0);
    Node *oneD = newNode(0);
    Node *twoD = newNode(0);
    
    Node *one = oneD;
    Node *two = twoD;
    Node *zero = zeroD;
    Node *curr = first;
    
    while(curr){
        if(curr->data == 0){
            zero->next = curr;
            zero = zero->next;
        }
        else if(curr->data == 1){
            one->next = curr;
            one = one->next;
        }
        else{
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }
    
    zero->next = (oneD->next) ? oneD->next : twoD->next;
    one->next = twoD->next;
    two->next = NULL;
    first = zeroD->next;
    free(zeroD);
    free(oneD);
    free(twoD);
    return first;
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
    
    first = sort012(first);
    print(first);
    
    
}