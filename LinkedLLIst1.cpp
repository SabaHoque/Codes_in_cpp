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
        Node* head;
    public:
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
        void inserAtbeginning(int d){
            Node* n=new Node(d);
            if(head==NULL)head=n;
            else{
                n->next=head;
                head=n;
            }
        }
        void insertAtAnyPos(int d,int p){
            Node *n=new Node(d);
            if(p==0)inserAtbeginning(d);
            else{
                Node *t=head;
                int l=0;
                while(t!=NULL){
                    t=t->next;
                    l++;
                }
                if(p>l)cout<<"Invalid Input"<<'\n';
                else if(p==l) create(d);
                else{
                    Node *t1=head,*t2;
                    for(int i=1;i<p;i++){
                        t2=t1;
                        t1=t1->next;
                    }
                    t2->next=n;
                    n->next=t1;
                }
            }
        }
        void deleteAtbeginning(){
            Node *t=head;
            head=head->next;
            delete t;
        }
        void deleteAtEnd(){
            Node *t=head,*t1;
            while(t->next!=NULL){
                t1=t;
                t=t->next;
            }
            t1->next=NULL;
            delete t;
        }
        void deleteAtAnyPos(int p){
            Node *t=head,*t1;
            for(int i=1;i<p;i++){
                t1=t;
                t=t->next;
            }
            t1->next=t->next;
            delete t;
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

int main(){
    SLL s1;
    s1.create(1);
    s1.create(2);
    s1.create(3);
    s1.create(4);
    s1.inserAtbeginning(7);
    s1.insertAtAnyPos(5,5);
    s1.insertAtAnyPos(6,3);
    s1.deleteAtbeginning();
    s1.deleteAtEnd();
    s1.deleteAtAnyPos(3);
    s1.display();
    return 0;
}
