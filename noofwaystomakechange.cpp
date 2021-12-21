#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int target,int n) {

    int dp[n+1][target+1];

    for(int j=0;j<=target;j++) {
        dp[0][j] = 0;
    }

    for(int i=0;i<=n;i++) {
        dp[i][0] = 1;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=target;j++) {

            if(j >= arr[i-1]) {

                dp[i][j] = dp[i-1][j] + dp[i][j-arr[i-1]];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=target;j++) {

            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<dp[n][target];
}
int main() 
{
    int arr[] = {1,5};
    int n = 2;

    int target = 6;

    solve(arr,target,n);
}