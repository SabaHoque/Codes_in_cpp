
#include <iostream>
using namespace std;
#include"DLL.h"



    int main()
{
   int n;
   int o;
   int p;
   DLL s;
   while(true)
   {
        cout << "0. STOP"<<endl;
        cout << "1. insert at last"<<endl;
        cout << "2. insert at begining"<<endl;
        cout << "3. insert at Any position"<<endl;
        cout << "4. Search the item"<<endl;
        cout << "5. Size of the list"<<endl;
        cout << "6. Is the the list Empty? "<<endl;
        cout << "7. Find the number of that Position"<<endl;
        cout << "8. Return position of the specified element in the list"<<endl;
        cout << "9. delete from first" <<endl;
        cout << "10. delete from last"<<endl;
        cout << "11. delete from at any position" <<endl;
        cout << "12. Reverse the list" << endl;
        cout << "13. Sort in Ascending Order" <<endl;
        cout << "Enter your Option"<<endl;

        cin >> n;
        switch (n) {
             case 0:

                cout << "Exit" << endl;
                return 0;
            case 1:
                cout << "Enter ele: ";
                cin >> o;
                s.add(o);
                break;
            case 2:
                cout << "Enter ele: ";
                cin >> o;
                s.AddAtbeginning(o);
                break;
            case 3:
                cout<<"Enter the position :"<<endl;
                cin>>p;
               cout << "Enter ele: ";
                cin >> o;
                s.AddAtAnyPos(o,p);
                break;

            case 4:
                 cout << "Enter ele: ";
                cin >> o;
                 cout<<s.Contains(o)<<endl;

                break;

            case 5:
                cout<<s.sizee()<<endl;
                break;
            case 6:
               cout<<s.isEmpty()<<endl;
                break;
            case 7:
                   cout<<"Enter the position"<<endl;
                cin>>p;
                cout<< s.get(p)<<endl;
                break;
            case 8:
                  cout << "Enter ele: ";
                cin >> o;
                cout<<s.index(o);
                break;
            case 9:
                s.removeAtbeginning();
                break;
            case 10:
                s.removeAtEnd();
                break;
            case 11:
                cout<<"Enter the position :"<<endl;
                cin>>p;
                s.removeAtAnyPos(p);
                break;
            case 12:
               s.rev();
                break;
             case 13:
               s.sortt();
                break;

            default:
                cout << " Invalid " << endl;
        }
    }
}
