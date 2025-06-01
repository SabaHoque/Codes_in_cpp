

#include<iostream>
#include<vector>;
using namespace std;

class Node{
    public:
       int d;
       Node*l;
       Node*ri;
Node(int d)
{
    this->d=d;
    this->ri=NULL;
    this->l=NULL;
}

};
class BST
{public:
    Node*insert(int d,Node*r)
    {
        if(r==NULL)
        {
            Node*p = new Node(d);
            r=p;
        }
        else if(d>=r->d)
        {
            r->ri =insert(d,r->ri);
        }
        else
        {
            r->l =insert(d,r->l);

        }
        return r;
    }
    void preOrder(Node *r)
    {
        if (r!= NULL)
        {
            cout<<r->d;
            preOrder(r->l);
            preOrder(r->ri);
        }
    }
     void inOrder(Node *r)
    {
        if (r!= NULL)
        {
            preOrder(r->l);
            cout<<r->d;
            preOrder(r->ri);
        }
    }
     void postOrder(Node *r)
    {
        if (r!= NULL)
        {
            preOrder(r->l);
            preOrder(r->ri);
            cout<<r->d;
        }
    }
    Node*Search(Node *r,int item)
    {
        if(r!=NULL)
        {
            if(r->d==item)
            {
                return r;
            }
             else if(r->d>item)
             {
               return Search(r->ri,item);
             }
             else
             {
                 return Search(r->l,item);
             }
        }
    }
      Node* fin(Node* &r)
     {
         while(r->l!=NULL)
         {
             r=r->l;
         }
         return r;
     }
    Node *mini(Node* r)
    {
        if(r->l==NULL)
        {
            return r;
            return mini(r->l);
        }
    }
     Node *maxx(Node* r)
    {

         if(r==NULL)
         {
             return NULL;
         }
         while(r->ri!=NULL)
         {
             r=r->ri;
         }
         return r;
    }
   Node* del(Node* &r,int d)
     {
         if(r==NULL)
         {
             return NULL;
         }
         else if(r->d>d)
         {
             r->l=del(r->l,d);
         }
         else if(r->d<d)
         {
             r->ri=del(r->ri,d);
         }
         else if(r->d==d)
         {
             if(r->l==NULL)
             {
                 Node* t=r;
                 delete t;
                 return r->ri;

             }
             if(r->ri==NULL)
             {
                 Node* t=r;
                 delete t;
                 return r->l;

             }
             else
             {
                 Node* t= fin(r->ri);
                 r->d=t->d;
                 r->ri=del(r->ri,t->d);

             }
         }
         return r;
     }
    int height(Node *r)
    {
        if(r==NULL)
        {
            return 0;
        }

int left;
int right;
left = height(r-> l);
right = height(r -> ri);

return max(left,right)+1;
    }
  void spath(Node* root,int start,int end,vector<int> &v)
     {
         if(root==NULL)
         {
             return;
         }
         if(root->d==start)
         {

             path(v,root,end);
         }
         else if(root->d>start)
         {
             spath(root->l,start,end,v);
         }
         else
         {
             spath(root->ri,start,end,v);
         }
     }
     void path(vector<int> &v,Node* root,int end)
     {
         if(root==NULL)
         {
             return;
         }
         v.push_back(root->d);
         if(root->d==end)
         {
             for(int i=0;i<v.size();i++)
             {
                 cout<<v[i]<<" ";
             }
         }
         else if(root->d>end)
         {
             path(v,root->l,end);
         }
         else
         {
             path(v,root->ri,end);
         }

     }


    void display(Node* r)
    {
         if(r==NULL)
         {
             return;
         }
         display(r->l);
         cout<<r->d<<endl;
         display(r->ri);
    }
};



