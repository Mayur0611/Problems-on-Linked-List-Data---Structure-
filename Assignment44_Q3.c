/*
  write program which returns addition of all elements from singly
  linear linked list:

  Example:
           Input linked list: |10|->|20|->|30|->|40|

           Output = 100

  
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        newn->next = *head;
        *head = newn;
    }
}

void Display(PNODE head)
{
    while(head != NULL)
    {
        printf("|%d|->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int Count(PNODE head)
{
    int iCount  = 0;
    
    while(head != NULL)
    {
        iCount++;
        head = head->next;
    }

    return iCount;
}

int Addition(PNODE head)
{
    int iSum = 0;
    int iCnt = 1;
    int CountNode = 0;
    

    CountNode = Count(head);

    for(iCnt = 1; iCnt <=  CountNode; iCnt++)
    {
        iSum =iSum +  head->data;
        head = head->next;
    }

    return iSum;
}


int main()
{
    PNODE first = NULL; 
    int iRet = 0;

    InsertFirst(&first,40);
    InsertFirst(&first,30);
    InsertFirst(&first,20);
    InsertFirst(&first,10);
    
    printf("Linked List:\n");
    Display(first);
    printf("\n");

    iRet = Addition(first);

    printf("Addition of elements in Linked List =  %d",iRet);

    return 0;
}