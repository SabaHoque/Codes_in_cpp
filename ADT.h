
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    void Display()
    {
        cout << data;
    }
};
class Stack{
    public:
    Node* head=NULL,*temp;
    void Push(int data)
    {
        Node* n=new Node(data);
        if(head==NULL)
        {
            head=n;
            return;
        }
       n->next=head;
       head=n;

    }
    void Pop()
    {
        if(head==NULL)
        {
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    int Top()
    {
        if(head==NULL)
        {
            return -1;
        }
        return head->data;
    }
    bool IsEmpty()
    {
        return head==NULL;
    }
    void Destroy()
    {
        if(head==NULL)
        {
            return;
        }
        Node* curr=head;
        while(curr!=NULL)
        {
            Node* temp=head;
            head=head->next;
            delete temp;
            curr=head;
        }
    }
    int Size()
   {
        Node* curr=head;
        int i=0;
       while(curr!=NULL)
       {
           i++;
           curr=curr->next;
       }
       return i;
   }
    void Display(){
        temp = head;
        while (temp != nullptr)
        {
            cout <<temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};
