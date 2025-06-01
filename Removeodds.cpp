
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
          void removeAtbeginning(){
            Node *t=head;
            head=head->next;
            delete t;
        }
        void removeodds(Node*& head)
        {
            Node* t = head;
            Node* n=new Node(-1);
            Node* p =n;
            while(t!=NULL)
            {
                if(t->data%2==0)
                {
                    p->next=t;
                    p=p->next;


                }
                t=t->next;

            }
            if(p->next!=NULL)
            {
                p->next=NULL;
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
    s.create(2);
     s.create(2);
      s.create(3);
       s.create(4);
        s.create(-1);
        s.display();
        cout<<" "<<endl;
        s.removeodds(s.head);
        s.display();

    return 0;
}
