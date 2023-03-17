#include<bits/stdc++.h>
using namespace std;
int f(vector<vector<int>>& matrix, int i , int j, vector<vector<int>>& dp){
        if(j<0 || j>=matrix[0].size()) return 1e9;
        if(i==0) return matrix[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        int s = matrix[i][j] + f(matrix,i-1, j, dp);
        int dl = matrix[i][j] + f(matrix, i-1,j-1,dp);
        int dr = matrix[i][j] + f(matrix, i-1,j+1,dp);
        return dp[i][j] = min(s,min(dl,dr));
    }
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int mini = 1e8;
    for(int j=0;j<m;j++){
        mini = min(mini,f(matrix, n-1,j, dp) );
    }
    // return f(matrix, n-1,m-1, dp);
    return mini;
}
int main(){
    vector<vector<int>> matrix = {{1,3,5},{3,4,5},{3,5,1}};
    cout<<minFallingPathSum(matrix);
}