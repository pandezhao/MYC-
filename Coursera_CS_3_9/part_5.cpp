#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
#include <stdlib.h>
using namespace std;
int main(){
    map<int, int> data;
    vector<int> ID1;
    vector<int> ID2;
    data.insert(pair<int, int>(1000000000, 1));
    int number;
    cin>>number;
    for(int i=0;i<number;i++){
        int ID_tmp, power_tmp;
        cin>>ID_tmp>>power_tmp;
        data.insert(pair<int, int>(power_tmp, ID_tmp));
        pair<map<int,int>::iterator,map<int,int>::iterator> ret= data.equal_range(power_tmp);
        ID1.push_back(ID_tmp);
        if (ret.second!=data.end() && ret.first!=data.begin()){
            ret.first--;
            if(abs((ret.second->first - power_tmp)<abs(ret.first->first - power_tmp))){
                ID2.push_back(ret.second->second);
            }else{
                ID2.push_back(ret.first->second);
            }
        }else if(ret.second!=data.end()){
            ID2.push_back(ret.second->second);
        }else{
            ret.first--;
            ID2.push_back((ret.first->second));
        }
    }
    for(int i=0;i<number;i++){
        cout<<ID1[i]<<' '<<ID2[i]<<endl;
    }
    return 0;
}