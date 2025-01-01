/*
  write program which returns largest element from singly
  linear linked list:

  Example:
           Input linked list: |110|->|230|->|320|->|240|

           Output = 320

  
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

int Maximum(PNODE head)
{
    int iMax = head->data;
    int iCnt = 0;
    int CountNode = 0;

    CountNode = Count(head);
    
    for(iCnt = 1; iCnt <= CountNode; iCnt++)
    {
        if(head->data > iMax)
        {
            iMax = head->data;
        }

        head = head->next;
    }

    return iMax;
}


int main()
{
    PNODE first = NULL; 
    int iRet = 0;

    InsertFirst(&first,240);
    InsertFirst(&first,320);
    InsertFirst(&first,230);
    InsertFirst(&first,110);
    
    printf("Linked List:\n");
    Display(first);
    printf("\n");

    iRet = Maximum(first);

    printf("%d is the largest element in Linked List",iRet);

    return 0;
}