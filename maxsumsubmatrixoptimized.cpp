#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>arr,int size) {

    int row = arr.size();
    int col = arr[0].size();

    int mx = INT_MIN;

    vector<vector<int>>dp(row+1,vector<int>(col+1,0));

    for(int i=1;i<row+1;i++) {
        for(int j=1;j<col+1;j++) {
            dp[i][j] = arr[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    for(int i=1;i<row+1;i++) {
        for(int j=1;j<col+1;j++) {

            int sum = INT_MIN;

            if(i - size >=0 && j - size >= 0) {
                sum = dp[i][j] - dp[i-size][j] - dp[i][j-size] + dp[i-size][j-size];
                mx = max(sum,mx);
            }
        }
    }

    cout<<mx;

}
int main()
{
    vector<vector<int>>arr{{2,4},{5,6},{-3,2}};
    int n = 2;
    solve(arr,n);
}