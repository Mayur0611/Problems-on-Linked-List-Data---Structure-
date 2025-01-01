/*
    Wtrite a program which display smallest digits of all element
    from singly linear linked list

       Example:
                Input linkede list: |11|->|250|->|532|->|419|

                Output: 1  0  2  1
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

void DisplaySmall(PNODE head)
{
    int CountNode = 0;
    int iCnt = 0;
    int iDigit = 0;
    int iMin = 0;
    int iCount = 0;
    int iNo = 0;

    CountNode = Count(head);

    for(iCnt = 1; iCnt <= CountNode; iCnt++)
    {
        iNo = head->data;

        while(head->data != 0)
        {
            iCount++;
            iDigit = head->data % 10;

            if(iCount == 1)
            {
                iMin = iDigit;    
            }
            else if(iDigit < iMin)
            {
                iMin = iDigit;
            }

            head->data = head->data / 10;
        }

        printf("Smallest digit from %d is %d\n",iNo,iMin);
        iCount = 0;
        head = head->next;
    }
}


int main()
{
    PNODE first = NULL;

    InsertFirst(&first,419);
    InsertFirst(&first, 532);
    InsertFirst(&first, 250);
    InsertFirst(&first, 11);

    printf("Linked List:\n");
    Display(first);
    printf("\n");
    
    printf("Smallest digits from each elements in Linked list:\n " );
    printf("\n");
    DisplaySmall(first);

}