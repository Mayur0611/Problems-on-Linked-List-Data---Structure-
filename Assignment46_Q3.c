/*
    Wtrite a program which display product  of all digits of all element
    from singly linear linked list(Don't  consider 0)

       Example:
                Input linkede list: |11|->|20|->|32|->|41|

                Output:  1  2  6  4
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

void DisplayProduct(PNODE head)
{
    int CountNode = 0;
    int iCnt = 0;
    int iDigit = 0;
    int iMult = 1;

    CountNode = Count(head);

    for(iCnt = 1; iCnt <= CountNode; iCnt++)
    {
        
        while(head->data != 0)
        {
            iDigit = head->data % 10;

            if(iDigit != 0)
            {
                iMult = iMult * iDigit;
            }

            head->data = head->data / 10;
        }

        printf("%d\t",iMult);
        iMult = 1;
        head = head->next;
    }
}


int main()
{
    PNODE first = NULL;

    InsertFirst(&first,41);
    InsertFirst(&first, 32);
    InsertFirst(&first, 20);
    InsertFirst(&first, 11);

    printf("Linked List:\n");
    Display(first);
    printf("\n");
    
    printf("Product: " );
    DisplayProduct(first);

}