
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



        return 0;
}
