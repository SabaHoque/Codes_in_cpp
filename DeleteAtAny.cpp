
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
        }  void deleteAtAnyPos(int p){
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
    s1.deleteAtAnyPos(3);
    s1.display();
    return 0;
}
