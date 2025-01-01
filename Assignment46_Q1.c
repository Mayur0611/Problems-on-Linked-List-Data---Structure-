/*
    Wtrite a program which reverse each element of singly linked list

       Example:
                Input linkede list: |11|->|28|->|17|->|41|->|6|->|89|

                Output:  |11|-> |82|-> |71|-> |141|-> |6|-> |98|
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

void Reverse(PNODE head)
{
    int CountNode = 0;
    int iCnt = 0;
    int iDigit = 0;

    CountNode = Count(head);

    for(iCnt = 1; iCnt <= CountNode; iCnt++)
    {
        printf("|");
        while(head->data != 0)
        {
            iDigit = head->data % 10;

            printf("%d",iDigit);

            head->data = head->data / 10;
        }

        printf("|->");
        head = head->next;
    }

    printf("NULL");
}


int main()
{
    PNODE first = NULL;

    InsertFirst(&first, 89);
    InsertFirst(&first, 6);
    InsertFirst(&first, 41);
    InsertFirst(&first, 17);
    InsertFirst(&first, 28);
    InsertFirst(&first, 11);

    printf("Linked List:\n");
    Display(first);
    printf("\n");
    
    printf("Reverse Linked List:\n");
    Reverse(first);

}