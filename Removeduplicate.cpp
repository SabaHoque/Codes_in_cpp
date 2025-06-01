

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(){
            data=0;
            next=NULL;
        }
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};

class SLL{

    public:
        Node* head=NULL;
        SLL(){
            head=NULL;
        }
        void create(int d){
            Node* n=new Node(d);
            if(head==NULL)head=n;
            else{
                Node *t=head;
                while(t->next!=NULL){
                    t=t->next;
                }
                t->next=n;
            }
        }

void dup(Node * &head)
{
   Node* t = head;
   while(t!=NULL)
   {
       if(t->next!=NULL && t->next->data==t->data)
   {
       Node * temp = t->next;
       t->next= t->next->next;
       delete temp;
   }
   t=t->next;
   }
}
 void display(){
            Node *t=head;
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
    s.create(1);
     s.create(2);
      s.create(2);
       s.create(4);
        s.create(-1);
        s.display();
        s.dup(s.head);
        s.display();
    return 0;
}
