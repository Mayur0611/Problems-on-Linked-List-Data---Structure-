#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL
{
    public:
        PNODE head;
        int iCount;

        DoublyLL()
        {
            head = NULL;
            iCount = 0;
        }

        void Display()
        {
            PNODE temp = NULL;

            temp = head;

            cout<<"Elements of LinkedList:\n";

            while(temp != NULL)
            {
                cout<<"|"<<temp->data<<"|<=>";
                temp = temp->next;
            }

            cout<<"NULL\n";
        }
        
        int Count()
        {
            return iCount;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                newn->next = head;
                head->prev= newn;
                head = newn;
            }

            iCount++;  
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                PNODE temp = NULL;

                temp = head;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newn;
                newn->prev = temp;
            }

            iCount++;
        }

        void InsertAtPos(int no, int ipos)
        {
            int CountNode = 0;
            int iCnt = 0;

            PNODE newn = NULL;
            PNODE temp = NULL;

            CountNode = Count();

            if(ipos < 1 || ipos > CountNode + 1)
            {
                cout<<"Invalid position";
                return;
            }

            if(ipos == 1)
            {
                InsertFirst(no);
            }
            else if(ipos == CountNode + 1)
            {
                InsertLast(no);
            }
            else
            {
                newn = new NODE;
                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                temp = head;

                for(iCnt = 1; iCnt < ipos -1; iCnt++)
                {
                    temp = temp->next;
                }
                newn->next = temp->next;
                temp->next->prev = newn;
                temp->next = newn;
                newn->prev = temp;

                iCount++;
            }
        }

        void DeleteFirst()
        {
            if(head == NULL)
            {
                return;
            }
            else if(head->next == NULL)
            {
                delete head;
                head = NULL;
            }
            else
            {
                head = head->next;
                delete head->prev;
                head->prev = NULL;
            }

            iCount --;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(head == NULL)
            {
                return;
            }
            else if(head->next == NULL)
            {
                delete head;
                head = NULL;
            }
            else
            {
                temp = head;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = NULL;
            }

            iCount--;
        }

        void DeleteAtPos(int ipos)
        {
            int CountNode = 0;
            int iCnt = 0;

            PNODE target = NULL;
            PNODE temp = NULL;

            CountNode = Count();

            if(ipos < 1 || ipos > CountNode)
            {
                cout<<"Invalid position";
                return;
            }

            if(ipos == 1)
            {
               DeleteFirst();
            }
            else if(ipos == CountNode)
            {
              DeleteLast();
            }
            else
            {
                temp = head;

                for(iCnt = 1; iCnt < ipos - 1; iCnt++)
                {
                    temp = temp->next;
                }
                target = temp->next;
                temp->next = target->next;
                target->next->prev = temp;
                delete target;

                iCount--;   
            }
        }
};

int main()
{
    DoublyLL dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    
    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

        
    dobj.InsertAtPos(75,4);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are (InsertAtPos): "<<iRet<<"\n";

    dobj.DeleteFirst();

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are (DeleteFirst): "<<iRet<<"\n";

    dobj.DeleteLast();

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are (DeleteLast): "<<iRet<<"\n";

    dobj.DeleteAtPos(4);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements are (DeleteAtPos): "<<iRet<<"\n";

    return 0;
}
