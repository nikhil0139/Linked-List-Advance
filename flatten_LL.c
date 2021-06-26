#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *right, *down;
} Node;

void push(Node **head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->right = NULL;
    temp->down = *head;
    *head = temp;
}

void print(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->down;
    }
}

Node *merge(Node *a, Node *b)
{

    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node *result;

    if (a->data < b->data)
    {
        result = a;
        result->down = merge(a->down, b);
    }

    else
    {
        result = b;
        result->down = merge(a, b->down);
    }

    result->right = NULL;
    return result;
}

Node *flatten(Node *root)
{

    if (root == NULL || root->right == NULL)
        return root;

    return merge(root, flatten(root->right));
}

void main()
{

    Node *root = NULL;


    push(&root, 30);
    push(&root, 25);
    push(&root, 20);

    push(&(root->right), 28);
    push(&(root->right), 23);

    push(&(root->right->right), 29);
    push(&(root->right->right), 27);
    push(&(root->right->right), 24);

    root = flatten(root);

    printf("The flatten linked list is : ");

    print(root);
    printf("\n");
}