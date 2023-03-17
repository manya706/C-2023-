#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    bool found = false;
    for(int i=0;i<n-1;i++){
        if(s[i]=='M' && (s[i+1]=='U' || s[i+1]=='?')){
            found = true;
            break;
        }
        
    }
    if(found){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}
