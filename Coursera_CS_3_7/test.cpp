#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
bool isdigit(const string& data){
    for(int i=0;i<data.size();i++){
        if ((int)data[i]<48||(int)data[i]>57)
            return false;
    }
    int tmp = atoi(data.c_str());
    if(tmp<=99999 &&tmp>=0)
        return true;
    else
        return false;
}
int main(){
    string counter;
    cin>>counter;
    cout<<isdigit(counter)<<endl;
    return 0;
}