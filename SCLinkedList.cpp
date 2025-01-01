#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyCL
{
    public:
        PNODE head;
        PNODE tail;
        int iCount;

        SinglyCL()
        {
            head = NULL;
            tail = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn  = NULL;

            newn = new NODE;
            newn->data = no;
            newn->next = NULL;

            if(head == NULL && tail == NULL)
            {
                head = newn;
                tail = newn;
                tail->next = head;
            }
            else
            {
                newn->next = head;
                head = newn;
                tail->next = head;
            }
            iCount++;
        }
        

        void InsertLast(int no)
        {
            
            PNODE newn  = NULL;

            newn = new NODE;
            newn->data = no;
            newn->next = NULL;

            if(head == NULL && tail == NULL)
            {
                head = newn;
                tail = newn;
                tail->next = head;
            }
            else
            {
                tail->next = newn;
                tail = newn;
                tail->next = head;
            }
            iCount++;
        }


        void DeleteFirst()
        {
            PNODE  temp = NULL;

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
                temp = head;

                head = temp->next;
                tail->next = head;
                delete temp;

                iCount--;
            }
        }


        void DeleteLast()
        {
            PNODE  temp = NULL;

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
                temp = head;

                while(temp->next != tail)
                {
                    temp = temp->next;
                }
                delete temp->next;
                tail = temp;
                temp->next = head;   

                iCount--;
            }
        }
        

        void Display()
        {
            PNODE temp = NULL;

            if(head == NULL & tail == NULL)
            {
                cout<<"LinkedList is empty";
                return;
            }

            temp = head;

            do
            {
                cout<<"|"<<temp->data<<"|->";
                temp = temp->next;
            }while(temp != tail->next);

            cout<<"\n";
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
                cout<<"Invalid Position";
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

                temp = head;

                for(iCnt = 1; iCnt < ipos - 1; iCnt++)
                {
                    temp = temp->next;
                }
                newn->next = temp->next;
                temp->next = newn;

                iCount++;
            }
        }

        void DeleteAtPos(int ipos)
        {
            int CountNode = 0;
            int iCnt = 0;

            PNODE temp = NULL;
            PNODE target= NULL;

            CountNode = Count();

            if(ipos < 1 || ipos > CountNode)
            {
                cout<<"Invalid Position";
                return;
            }

            if(ipos == 1)
            {
                DeleteFirst();
            }
            else if(ipos == CountNode )
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
                delete target;
               
                iCount--;
            }
        }
};

int main()
{
    SinglyCL obj;
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