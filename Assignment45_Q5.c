
/*
  Write a program which returns second maximum element from 
  singly linear linked list:
  

  Example:
           Input linked list: |110|->|230|->|320|->|240|
           
           Output =240

  
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

int SecMaximum(PNODE head)
{
    int iCnt = 0;
    int CountNode = 0;
    PNODE ftemp = NULL;
    PNODE stemp = NULL;

    ftemp = head;
    stemp = head;

   
    CountNode = Count(head);

    int ifMax = ftemp->data;
    for(iCnt = 1; iCnt <= CountNode; iCnt++)
    {
        if(ftemp->data > ifMax)
        {
            ifMax = ftemp->data;
        }

        ftemp = ftemp->next;
    }

    iCnt = 0;
    int isMax = stemp->data;
    for(iCnt = 1; iCnt <= CountNode; iCnt++)
    {
        if(stemp->data > isMax && stemp->data != ifMax)
        {
            isMax = stemp->data;
        }

        stemp = stemp->next;
    }

    return isMax;

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

    iRet = SecMaximum(first);

    printf("Second maximum element in Linked List: %d",iRet);


    return 0;
}