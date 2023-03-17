#include<bits/stdc++.h>
using namespace std;
void printSub(int i, int arr[], int n, vector<int> &ds){
    if(i>=n){
        for(auto i:ds){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    ds.push_back(arr[i]);
    printSub(i+1, arr, n, ds);
    ds.pop_back();
    printSub(i+1,arr,n,ds);
}
int main(){
    int arr[3] = {3,2,1};
    int n=3;
    vector<int> ds;
    printSub(0,arr,n,ds);
}