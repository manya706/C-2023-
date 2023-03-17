#include<bits/stdc++.h>
using namespace std;
bool f(int i, int target,vector<int>& nums, vector<vector<int>> &dp){
    if(target==0) return 1;
    if(i==0) return nums[0]==target;
    if(dp[i][target] != -1) return dp[i][target];
    bool nottake = f(i-1, target,nums, dp);
    bool take = false;
    if(target>=nums[i]) take = f(i-1, target-nums[i], nums, dp);
    return dp[i][target] = nottake | take;
}
bool subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> dp(nums.size(), vector<int> (k+1,-1));
    return f(n-1,k,nums,dp);
}
int main(){
    vector<int>nums = {7,2,3};
    int k =4;
    cout<<subarraySum(nums,k);
}
