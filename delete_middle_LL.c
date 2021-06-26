#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createLL(Node *head1)
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


int deleteMiddle(Node *head){

    if(head == NULL)   return -1;

    if(head->next == NULL){
        free(head);
        return -1;
    }

    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;

    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    int y = slow->data;
    prev->next = slow->next;
    free(slow);

    return y;
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


void main(){

    Node *first = NULL;
    first = createLL(first);

    print(first);

    printf("The deleted node is %d \n",deleteMiddle(first));

    print(first);
}