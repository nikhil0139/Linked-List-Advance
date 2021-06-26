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

int isPallindrome(int s[] , int k){
    int length = k;
    
    for(int i = 0; i<length/2 ; i++){
        if(s[i] != s[length-i-1]){
            return 0;
        }
    }
    return 1;
}
void makeStringOfLL(Node *first){
    int str[100];
    int i = 0;
    while(first){
        str[i] = first->data;
        i++;
        first = first->next;
    }
    
    int d = isPallindrome(str , i);
    
    if(d == 1){
        printf("Given linked list of strings is pallindrome.\n");
    }
    else{
        printf("Given linked list of strings is not pallindrome.\n");
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
    
    makeStringOfLL(first);
}