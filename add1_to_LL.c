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

Node *reverse_1(Node *root)
{

    Node *prev = NULL;
    Node *curr = root;
    Node *temp;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node *newNode(int key)
{
    Node *root = (Node *)malloc(sizeof(Node));
    root->data = key;
    root->next = NULL;
    return root;
}

Node * add1ToNode(Node *first)
{

    Node *prev = first;
    Node *temp = NULL;
    int sum, carry = 1;

    while (first != NULL )
    {
        sum = carry + first->data;

        carry = (sum >= 10) ? 1 : 0;

        sum = sum % 10;

        first->data = sum;
        temp = first;
        first = first->next;
    }

    if (carry > 0)
    {
        temp->next = newNode(carry);
    }
    return prev;
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

    first = reverse_1(first);
    
    first = add1ToNode(first);
    
    first = reverse_1(first);

    printf("The linked list is after adding 1 to each node : ");

    print(first);
}
