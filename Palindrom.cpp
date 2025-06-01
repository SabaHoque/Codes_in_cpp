

#include <iostream>
#include"LL.h"
using namespace std;

          Node* rev(Node* & head)
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
       return head;
   }
   bool ispalindrome(Node* &head)
   {
       Node* t1 = head;
       Node* t2 = head;
       while(t1->next!= NULL && t1->next->next!= NULL)
       {

           t1=t1->next->next;
           t2= t2->next;
       }
       Node* temp = t2->next;
       t2->next = NULL;
       Node* n = rev(temp);
       while(n != NULL)
       {
           if(n->data != head->data)
           {
               return false;
           }
           n= n->next;
           head = head->next;
       }
        return true;
   }


int main()
{
    SLL s;
    s.create(1);
     s.create(2);
      s.create(2);
       s.create(1);
        s.display();

cout<<" "<<endl;
    bool b= ispalindrome(s.head);
    if(b==1)
    {
        cout<<"palindrome"<<endl;
    }
    else
    {
        cout<<"Not palindrome"<<endl;
    }



        return 0;
}


