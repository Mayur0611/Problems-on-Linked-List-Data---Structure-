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

class DoublyCL
{
    public:
        PNODE head;
        PNODE tail;
        int iCount;

        DoublyCL()
        {
            head = NULL;
            tail = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(head == NULL && tail == NULL)
            {
                head = newn;
                tail = newn;
                head->prev = head;
                tail->next = head;
            }
            else
            {
                newn->next = head;
                newn->next->prev = newn;
                head = newn;
                head->prev = tail;
                tail->next = head;
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

            if(head == NULL && tail == NULL)
            {
                head = newn;
                tail = newn;
                head->prev = head;
                tail->next = head;
            }
            else
            {
                tail->next = newn;
                newn->prev = tail;
                tail = newn;
                tail->next = head; 
            }

            iCount++;
        }
        
        
        void DeleteFirst()
        {
            if(head == NULL && tail == NULL)
            {
                return;
            }
            else if(head == tail)
            {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else
            {
                PNODE temp = NULL;

                temp = head;
                head = head->next;
                head->prev = tail;
                delete temp;
            }
            iCount--;
        }


        void DeleteLast()
        {
            if(head == NULL && tail == NULL)
            {
                return;
            }
            else if(head == tail)
            {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else
            {
               PNODE temp = NULL;

               temp = tail->prev;
               tail = temp;
               delete tail->next;
               temp->next = head;
            }

            iCount--;
        }
       

        void Display()
        {
            PNODE temp = NULL;

            if(head ==NULL && tail == NULL)
            {
                cout<<"LinkedList is empty";
                return;
            }

            temp = head;

            do
            {
                cout<<"|"<<temp->data<<"|<=>";
                temp = temp->next;
            }while(temp != tail->next);
        }

        int Count()
        {
            return iCount;
        }


        void InsertAtPos(int no, int ipos)
        {
            int CountNode = 0;
            int iCnt = 0;

            PNODE temp = NULL;
            PNODE newn = NULL;

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

                for(iCnt = 1; iCnt < ipos - 1; iCnt++)
                {
                    temp = temp->next;
                }
                newn->next = temp->next;
                newn->next->prev = newn;
                temp->next = newn;
                temp->next->prev = temp;

                iCount++;
            }
        }


        void DeleteAtPos(int ipos)
        {
            
            int CountNode = 0;
            int iCnt = 0;

            PNODE temp = NULL;
            PNODE target = NULL;

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
    DoublyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    obj.InsertAtPos(75,4);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();
    
    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
    
    return 0;
}