#include<bits/stdc++.h>
using namespace std;

int dp[101][101];
int solve(int i,int j,int m,int n) {

    if(i == m-1 && j == n-1) {
        return 1;
    }

    if(i >= m || j >= n) {
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    else {

        return dp[i][j] = solve(i+1,j,m,n) + solve(i,j+1,m,n);

    }
}
int main()
{
    int m = 3;
    int n = 4;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,m,n);
}