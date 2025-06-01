
#include<iostream>
using namespace std;

class Node
{
public :
    int data;
    Node* next;
    Node()
    {
        data=0;
        next = NULL;

    }
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

class SLL
{   public:
    Node *head = NULL;

    void create(int d)
    {   Node * n = new Node(d);
        if(head == NULL)
            head = n;
        else
        {
            Node* t = head;
            while(t->next!= NULL)
            {
                t=t->next;
            }
             t->next = n;
        }
    }
    void display()
    {    Node *t=head;
            while(t!=NULL){
                cout<<t->data<<' ';
                t=t->next;
            }
            cout<<'\n';
    }
    void swapp(Node *pos1 ,Node *pos2)
    {
        Node* l=0;
        bool flag = false;
        Node* t=head;
        while(t!=NULL)
        {
            if(l==pos1)
            {
                pos1=t;
                t=t->next;
                l++;
            }
            if(l==pos2)
            {
                pos2=t;
                t=pos1->data;
                pos1->data=pos2->data;
                pos2->data=t;
                flag = true;
            }
            else
            {
                t=t->next;
                l++;
            }

        }
        return flag;
    }
    };
    int main()
{
    SLL s;
    s.create(10);
     s.create(20);
      s.create(30);
       s.create(40);
        s.create(50);
        s.display();
        cout<<s.swapp(3,4)<<endl;
        s.display();


        return 0;
}
