#include<iostream>
#include<vector>;
#include "BST.h";
using namespace std;
int main()
{
    Node* r= NULL;
    int a[]={20,30,40,50,60,70,80,90};
    BST b;
    for(int i =0;i<8;i++)
    {
        r=b.insert(a[i],r);
    }
     cout<<"inorder "<<endl;
    b.display(r);
    cout<<"preorder "<<endl;
      b.preOrder(r);
      cout<<endl;

    cout<<"postorder "<<endl;
    b.postOrder(r);
    cout<<endl;

    cout<<"height is "<<endl;
    cout<<b.height(r)<<endl;

    cout<<"Path is "<<endl;
    vector<int>v;
    b.path(v,r,50);
    cout<<endl;

    Node* small=b.mini(r);
    cout<<"smallest val "<<endl;
    cout<<small->d<<endl;
     cout<<endl;

    Node* big=b.maxx(r);
    cout<<"largest val "<<endl;
    cout<<big->d<<endl;
    cout<<endl;

    Node* k=b.Search(r,40);
    cout<<"node found"<<endl;
    cout<<k->d<<endl;
    cout<<endl;

    Node* m=b.del(r,90);
    b.display(m);
     cout<<endl;



}

