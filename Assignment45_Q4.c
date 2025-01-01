
/*
  Write a program which returns addition of all digits of elements from 
  singly linear linked list:
  

  Example:
           Input linked list: |110|->|230|->|20|->|240|->|640|
           
           Output = 2  5  2  6  10

  
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

void SumDigit(PNODE head)
{
    int CountNode = 0;
    int iCnt = 0;
    int iSum = 0;

    CountNode = Count(head);

    for(iCnt = 1; iCnt <= CountNode; iCnt++)
    {
        while(head->data != 0)
        {
            iSum = iSum + (head->data) % 10;

            head->data = head->data / 10;
        }

        printf("%d\t",iSum);
        head = head->next;
        iSum = 0;
    }
}

int main()
{
    PNODE first = NULL;

    InsertFirst(&first,640);
    InsertFirst(&first,240);
    InsertFirst(&first,20);
    InsertFirst(&first,230);
    InsertFirst(&first,110);
    
    printf("Linked List:\n");
    Display(first);
    printf("\n");

    SumDigit(first);

    return 0;
}