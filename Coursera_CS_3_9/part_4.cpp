#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
int str2int(string data){
    stringstream stream;
    stream.clear();
    stream.str("");
    int result;
    stream.str(data);
    stream>>result;
    stream.clear();
    stream.str("");
    return result;
}
string int2str(int data){
    stringstream stream;
    stream.clear();
    stream.str("");
    string result="";
    stream<<data;
    result = stream.str();
    stream.clear();
    stream.str("");
    return result;
}

bool isdigit(const string& data){
    for(int i=0;i<data.size();i++){
        if ((int)data[i]<48||(int)data[i]>57)
            return false;
    }
    int tmp = str2int(data);
    if(tmp<=99999 &&tmp>=0)
        return true;
    else
        return false;
}

int find(string* data);
int rfind(string* data);
string copy(string* data);
string add(string* data);

int find(string* data){
    string tmp1,tmp2,S;
    int N;
    cin>>tmp1;
    if(tmp1=="copy"){
        S = copy(data);
    }else if(tmp1=="add"){
        S = add(data);
    }else{
        S = tmp1;
    }
    cin>>tmp2;
    if(tmp2=="find"){
        N = find(data);
    }else if(tmp2=="rfind"){
        N = rfind(data);
    }else{
        N = str2int(tmp2);
    }
    int result;
    if (data[N-1].find(S) !=string::npos)
        result = data[N-1].find(S);
    else
        result = data[N-1].length();
    return result;
}
int rfind(string* data){
    string tmp1,tmp2,S;
    int N;
    cin>>tmp1;
    if(tmp1=="copy"){
        S = copy(data);
    }else if(tmp1=="add"){
        S = add(data);
    }else{
        S = tmp1;
    }
    cin>>tmp2;
    if(tmp2=="find"){
        N = find(data);
    }else if(tmp2=="rfind"){
        N = rfind(data);
    }else{
        N = str2int(tmp2);
    }
    int result;
    if (data[N-1].rfind(S)!=string::npos)
        result = data[N-1].rfind(S);
    else
        result = data[N-1].length();
    return result;
}
string copy(string* data){
    string tmp1,tmp2,tmp3;
    int N,X,L;
    cin>>tmp1;
    if(tmp1=="find"){
        N = find(data);
    }else if(tmp1=="rfind"){
        N = rfind(data);
    }else{
        N = str2int(tmp1);
    }
    cin>>tmp2;
    if(tmp2=="find"){
        X = find(data);
    }else if(tmp2=="rfind"){
        X = rfind(data);
    }else{
        X = str2int(tmp2);
    }
    cin>>tmp3;
    if(tmp3=="find"){
        L = find(data);
    }else if(tmp3=="rfind"){
        L = rfind(data);
    }else{
        L = str2int(tmp3);
    }
    string result = data[N-1].substr(X,L);
    return result;
}
string add(string* data){
    string tmp1,tmp2,S1,S2;
    int tmp_int1=NULL;
    int tmp_int2=NULL;
    cin>>tmp1;
    if(tmp1=="copy"){
        S1 = copy(data);
    }else if(tmp1=="add"){
        S1 = add(data);
    }else{
        S1 = tmp1;
    }
    cin>>tmp2;
    if(tmp2=="copy"){
        S2 = copy(data);
    }else if(tmp2=="add"){
        S2 = copy(data);
    }else{
        S2 = tmp2;
    }
    if(isdigit(S1)){
            tmp_int1 = str2int(S1);
        }
    if(isdigit(S2)){
            tmp_int2 = str2int(S2);
        }
    if (tmp_int1!=NULL && tmp_int2!=NULL){
        int result = tmp_int1 + tmp_int2;
        string re = int2str(result);
        return re;
    }else{
        string re = S1 + S2;
        return re;
    }
}

int main(){
    int counter;
    cin>>counter;
    string data[counter];
    for(int i=0;i<counter;i++){
        cin>>data[i];
    }
    string tmp="";
    while(tmp!="over"){
        cin>>tmp;
        if(tmp=="insert"){
            string tmp1,tmp2,tmp3,S;
            int N,X;
            cin>>tmp1;
            if (tmp1=="copy"){
                S = copy(data);
            }else if (tmp1=="add"){
                S = add(data);
            }else
                S = tmp1;
            cin>>tmp2;
            if (tmp2=="find"){
                N = find(data);
            }else if(tmp2=="rfind"){
                N = rfind(data);
            }else{
                N = str2int(tmp2);
            }
            cin>>tmp3;
            if (tmp3=="find"){
                X = find(data);
            }else if(tmp3=="rfind"){
                X = rfind(data);
            }else{
                X = str2int(tmp3);
            }
            data[N-1].insert(X, S);
        }
        else if(tmp=="reset"){
            string tmp1,tmp2,S;
            int N;
            cin>>tmp1;
            if (tmp1=="copy"){
                S = copy(data);
            }else if(tmp1=="add"){
                S = add(data);
            }else{
                S = tmp1;
            }
            cin>>tmp2;
            if (tmp2=="find"){
                N = find(data);
            }else if(tmp2=="rfind"){
                N = rfind(data);
            }else{
                N = str2int(tmp2);
            }
            data[N-1] = S;
        }
        else if(tmp=="print"){
            int index;
            cin>>index;
            cout<<data[index-1]<<endl;
        }
        else if(tmp=="printall"){
            for(int i=0;i<counter;i++){
                cout<<data[i]<<endl;
            }
        }
    }
    return 0;
}