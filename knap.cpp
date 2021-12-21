#include<bits/stdc++.h>
using namespace std;

void solve(vector<pair<int,int>>arr,int n,int capacity) {

    int dp[n+1][capacity+1];

    vector<int>val;
    vector<int>wt;

    for(int i=0;i<n;i++) {

        val.push_back(arr[i].first);
        wt.push_back(arr[i].second);
    }


    for(int i=0;i<=n;i++) {
        for(int j=0;j<=capacity;j++) {

            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if(j >= wt[i-1]) {

                dp[i][j] = max(dp[i-1][j],val[i-1] + dp[i-1][j - wt[i-1]]);
            }
            else {

                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[n][capacity];
}
int main()
{
    vector<pair<int,int>>arr{{1,2},{4,3},{5,6},{6,7}};
    int n = arr.size();
    int capacity = 10;
    solve(arr,n,capacity);
}