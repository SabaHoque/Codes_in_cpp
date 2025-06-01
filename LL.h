
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
        Node* head= NULL;
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

       void add(int d)
    {
        Node* n=new Node(d);
        if(head==NULL)
        {
            head=n;
            return;
        }
        Node* t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=n;
    }
         void AddAtbeginning(int d){
            Node* n=new Node(d);
            if(head==NULL)head=n;
            else{
                n->next=head;
                head=n;
            }
        }
        void AddAtAnyPos(int d,int p){
            Node *n=new Node(d);
            if(p==0)AddAtbeginning(d);
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

        public: int sizee()
        {
            int count = 0;
            Node *t = head;
            while(t!= NULL)
            {
                t = t -> next;
                count++;
            }
            return count;
        }
        bool Contains(int d)
        {
        Node *t = head;

        while(t!= NULL){
            if(t-> data == d)
            {
               return true;
            }
            else

            {
                return false;
            }
        }
        }
        bool isEmpty()
    {
        return head==NULL;
    }
   int get(int p)
   {
       if(p==0||p>sizee())
       {
           cout<<"invalid position"<<endl;
           return 0;
       }
       Node* t=head;
       int i=1;
       while(i<p)
       {
           t=t->next;
           i++;
       }
       return t->data;
   }
        int index(int d)
   {
       Node* t=head;
       int i=1;
       while(t!=NULL)
       {
           if(t->data==d)
           {
               return i;
           }
           t=t->next;
           i++;
       }
       return 0;

   }
         void removeAtbeginning(){
            Node *t=head;
            head=head->next;
            delete t;
        }
        void removeAtEnd(){
            Node *t=head,*t1;
            while(t->next!=NULL){
                t1=t;
                t=t->next;
            }
            t1->next=NULL;
            delete t;
        }
        void removeAtAnyPos(int p){
            Node *t=head,*t1;
            for(int i=1;i<p;i++){
                t1=t;
                t=t->next;
            }
            t1->next=t->next;
            delete t;
        }
         void rev()
   {
       Node* t=head->next;
       Node* t1=head;
       while(t!=NULL)
       {
           Node* last=t->next;
           t->next=t1;
           t1=t;
           t=last;
       }
       head->next=NULL;
       head=t1;
   }
   void sortt()
   {
       Node* t = head,*t1;
       for(;t!=NULL;t=t->next)
       {
           for(t1=t->next;t1!=NULL;t1=t1->next)
           {
               if(t1->data<t->data)
               {
                   int t2=t1->data;
                   t->data=t1->data;
                   t1->data=t2;
               }
           }
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
