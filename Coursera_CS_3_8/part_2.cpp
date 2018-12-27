#include<iostream>
#include<list>
#include<map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,list<int> > pair;
    char command[10]={};
    int id1=0,id2=0,number=0;
    while(n--){
        cin>>command;
        switch(command[0]){
        case 'n':
            cin>>id1;
            pair.insert(make_pair(id1,list<int>() ));
            break;
        case 'a':
            cin>>id1>>number;
            pair[id1].push_back(number);
            break;
        case 'm':
            cin>>id1>>id2;
            pair[id1].merge(pair[id2]);
            break;
        case 'u':
            cin>>id1;
            pair[id1].sort();
            pair[id1].unique();
            break;
        case 'o':
            cin>>id1;
            typename list<int>::const_iterator i;
            if(pair[id1].size()>0){
                pair[id1].sort();
                i=pair[id1].begin();
                cout<<*i;
                i++;
                for(;i!=pair[id1].end();i++)
                    cout<<' '<<*i;
                cout<<endl;
            }
            else cout<<endl;
        }
    }
    return 0;
}