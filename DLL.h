
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next,*p;
        Node(){
            data=0;
            p=NULL;
            next=NULL;
        }
        Node(int data){
            this->data=data;
            this->p=NULL;
            this->next=NULL;

        }
};

class DLL{
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
                n->p = t;
            }
        }

       void add(int d)
    {
        Node* n=new Node(d);
        n-> data = d;
        n-> next = NULL;
        n-> p = NULL;
        if(head==NULL)
        {
            head=n;
        }
        else
            {
        Node* t=head;
        while(t->next!=NULL)
        {
            t=t->next;
            }
            t->next=n;
            n->p = t;

        }
    }
         void AddAtbeginning(int d){
            Node* n=new Node(d);
             if(head==NULL)
        {
            head=n;
        }
        else
        {
           n->next = head;
           head->p =n;
           head = n;
        }
        }
        void AddAtAnyPos(int d,int p){
            Node *n=new Node(d);

            if(p==0)AddAtbeginning(d);
            else{
                Node *t=head,*t1;
                for(int i = 1;i<p;i++)
                {
                    t1=t;
                    t=t->next;
                }
                t1->next=n;
                n->p = t1;
                n->next = t;
                t->p = n;
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
            head->p = NULL;
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
            Node *t=head,*t1=t->next;
            for(int i=1;i<p;i++){
                t1=t;
                t=t->next;
            }
            t->next=t1->next;
            t1-> next-> p = t;
            delete t;
        }
         void rev()
   {
       Node* t=head->next;
       Node* t1=head;
       Node* t2=head->next->next;
       while(t!=NULL)
       {
           if(t1->p == NULL)
           {
               t1->p=t;
               t1->next=NULL;

           }
           t->next = t1;
           t-> p = t2;
           t1=t;
           t=t2;
           if(t2!= NULL)
           {
               t2= t2->next;
           }
       }
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
