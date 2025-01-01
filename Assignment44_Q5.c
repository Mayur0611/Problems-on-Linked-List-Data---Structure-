/*
  write program which returns largest element from singly
  linear linked list:

  Example:
           Input linked list: |110|->|230|->|20|->|240|->|640|

           Output = 20

  
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

int Minimum(PNODE head)
{
    int iMin = head->data;
    int iCnt = 0;
    int CountNode = 0;

    CountNode = Count(head);
    
    for(iCnt = 1; iCnt <= CountNode; iCnt++)
    {
        if(head->data < iMin)
        {
            iMin= head->data;
        }

        head = head->next;
    }

    return iMin;
}


int main()
{
    PNODE first = NULL; 
    int iRet = 0;

    InsertFirst(&first,640);
    InsertFirst(&first,240);
    InsertFirst(&first,20);
    InsertFirst(&first,230);
    InsertFirst(&first,110);
    
    printf("Linked List:\n");
    Display(first);
    printf("\n");

    iRet = Minimum(first);

    printf("%d is the smallest element in Linked List",iRet);

    return 0;
}