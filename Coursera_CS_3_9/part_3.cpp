#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int Orders;
    string order;
    cin>>Orders;
    set<int> first;
    multiset<int> second;
    for (int i=0;i<Orders;i++){
        cin>>order;
        if (order=="add"){
            int tmp;
            cin>>tmp;
            first.insert(tmp);
            second.insert(tmp);
            cout<<second.count(tmp)<<endl;
        }else if(order=="del"){
            int tmp;
            cin>>tmp;
            cout<<second.count(tmp)<<endl;
            second.erase(tmp);
        }else if(order=="ask"){
            int tmp;
            cin>>tmp;
            if (first.count(tmp)==0)
                cout<<"0 ";
            else
                cout<<"1 ";
            cout<<second.count(tmp)<<endl;
        }
    }
    return 0;
}