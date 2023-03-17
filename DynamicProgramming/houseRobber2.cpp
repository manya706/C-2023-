#include<bits/stdc++.h>
using namespace std;
int robberSO(vector<int> &nums){
    
        int n=nums.size();
        int p=nums[0];
        int p2=0;
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1){
                take+=p2;
            }
            int nottake = 0+p;
            int cur=max(take,nottake);
            p2=p;
            p=cur;
        }
        return p;
    
}
int robber2(vector<int> &a, vector<int> &dp, int n){
    if(n==0) return a[n];
    if(n<0) return 0;
    if(dp[n]!= -1) return dp[n];
    int p = a[n]+robber2(a,dp,n-2);
    int notp = robber2(a,dp,n-1);
    return dp[n] = max(p , notp);
}
int main(){
    vector<int> a = {1,2,3,1};
    int n=a.size();
    vector<int> temp1 ; //contains all elements except first
    vector<int>temp2; //contains all elements except last
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(a[i]);
        if(i!=n-1) temp2.push_back(a[i]);
    }
    int n1 = temp1.size();
    int n2= temp2.size();
    vector<int> dp(n,-1);
    int c = max(robber2(temp1,dp,n1-1), robber2(temp2,dp,n2-1));
    cout<<c;
}