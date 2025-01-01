/*
    Wtrite a program which display  all palindrome elements of singly linked list

       Example:
                Input linkede list: |11|->|28|->|17|->|414|->|6|->|89|

                Output: 11  6  414
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

void DisplayPallindrome(PNODE head)
{
    int CountNode = 0;
    int iCnt = 0;
    int iDigit = 0;
    int iFirst = 0;
    int iLast = 0;
    int iNo = 0;
    int iCount = 0;

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
                iFirst = iDigit;
            }

            head->data = head->data / 10;
        }

        iCount = 0;
        iLast = iDigit;

        if(iFirst == iLast)
        {
            printf("%d\t",iNo);
        }

        head = head->next;  
    }
}


int main()
{
    PNODE first = NULL;

    InsertFirst(&first, 89);
    InsertFirst(&first, 6);
    InsertFirst(&first, 414);
    InsertFirst(&first, 17);
    InsertFirst(&first, 28);
    InsertFirst(&first, 11);

    printf("Linked List:\n");
    Display(first);
    printf("\n");
    
    printf("Pallindromes:\n");
    DisplayPallindrome(first);

}