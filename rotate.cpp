#include<iostream>
#include "LL.h"
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

    void rot(Node* &head,int k)
    {
        Node* t = head;
        int i =1;
        while(i!= k)
        {
            t=t->next;
            i++;
        }
        Node* temp = t-> next;
        t-> next= NULL;
        Node* n = rev(temp);
        Node* p = temp;
        while(p->next!= NULL)
        {
            p=p->next;
        }
        p-> next= n;
        head = temp;
    }

int main()
{
    SLL s;
    s.create(1);
     s.create(2);
      s.create(3);
       s.create(4);
        s.display();
         cout<<" "<<endl;
    rot(s.head,2);
    s.display();

return 0;
}
