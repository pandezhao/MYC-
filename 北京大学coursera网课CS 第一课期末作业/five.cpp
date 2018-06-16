#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
    char a[10],b[10];
    while(scanf("%s%s",a,b)!=EOF){
        int i,t=0;
        char c;
        //printf("%s%s",a,b);
        for(c=a[0],i=0;i<strlen(a);i++){
           if(c<a[i]){c=a[i];t=i;}
        }
        for(i=0;i<strlen(a);i++)
        {   cout<<a[i];
            if(i==t)cout<<b[0]<<b[1]<<b[2];
        }
        cout<<endl;
    }
        return 0;
}
