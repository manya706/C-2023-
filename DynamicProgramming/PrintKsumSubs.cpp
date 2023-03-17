#include<bits/stdc++.h>
using namespace std;
void printSub(int i, int arr[], int n, vector<int> &ds, int k, int sum){
    if(i == n){
        if(sum == k){
            for(auto it : ds) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    ds.push_back(arr[i]);
    sum += arr[i];

    printSub(i+1, arr, n, ds, k,sum);

    sum -= arr[i];
    ds.pop_back();
    
    printSub(i+1,arr,n,ds,k,sum);
}
int main(){
    int arr[3] = {1,2,1};
    int n=3;
    int k =2;
    int sum=0;
    vector<int> ds;
    printSub(0,arr,n,ds,k,sum);
}