#include<bits/stdc++.h>
using namespace std;
int robber(vector<int> &a, vector<int> &dp, int n){
    if(n==0) return a[n];
    if(n<0) return 0;
    if(dp[n]!= -1) return dp[n];
    int p = a[n]+robber(a,dp,n-2);
    int notp = robber(a,dp,n-1);
    return dp[n] = max(p , notp);
}
int main(){
    vector<int> a = {1,3,5,6,7};
    int n=a.size();
    vector<int> dp(n,-1);
    cout<<robber(a,dp,n-1);
}