/*
  write program which search first occarance of particular elementfrom
  singly linear linked list:
  (Function will return position at which element is found)

  Example:
           Input linked list: |10|->|20|->|30|->|40|->|50|->|30|->|70|
           Input element: 30

           Output = 3

  
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

int SearchFirstOcc(PNODE head, int no)
{
   PNODE temp = NULL;
   int CountNode = 0;
   int iCnt = 0;
   int iCount = 1;

   CountNode = Count(head);

   temp = head;

   for(iCnt = 1; iCnt <= CountNode; iCnt++)
   {
      if(temp->data == no)
      {
        break;
      }
      iCount++;

      temp = temp->next;
   }

    return iCount;
}


int main()
{
    PNODE first = NULL; 
    int iRet = 0;

    InsertFirst(&first,70);
    InsertFirst(&first,30);
    InsertFirst(&first,50);
    InsertFirst(&first,40);
    InsertFirst(&first,30);
    InsertFirst(&first,20);
    InsertFirst(&first,10);
    
    printf("Linked List:\n");
    Display(first);
    printf("\n");

    iRet = SearchFirstOcc(first, 30);

    printf("Element 30 Occars firstly at position:  %d",iRet);

    return 0;
}