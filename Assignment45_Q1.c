
/*
  Write a program which displays all elements which are perfect 
  from singly linear linked list:
  

  Example:
           Input linked list: |11|->|28|->|30|->|17|->|41|->|6|->|89|
           
           Output = 28  6

  
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

void DisplayPerfect(PNODE head)
{
    int CountNode = 0;
    int iCnt = 0;
    int iNcnt = 0;
    int iSum = 0;

    CountNode = Count(head);

    for(iCnt = 1; iCnt <= CountNode; iCnt++)
    {
        for(iNcnt = 1; iNcnt < head->data; iNcnt++)
        {
            if(head->data % iNcnt == 0)
            {
                iSum = iSum + iNcnt;
            }
        }

        if(iSum == head->data)
        {
            printf("%d\t",head->data);
        }

        head = head->next;
        iSum = 0;
    }
}

int main()
{
    PNODE first = NULL; 

    InsertFirst(&first,89);
    InsertFirst(&first,6);
    InsertFirst(&first,41);
    InsertFirst(&first,17);
    InsertFirst(&first,28);
    InsertFirst(&first,11);
    
    
    printf("Linked List:\n");
    Display(first);
    printf("\n");

    DisplayPerfect(first);

    return 0;
}