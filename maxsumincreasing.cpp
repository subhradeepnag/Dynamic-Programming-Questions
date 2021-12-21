#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n) {

    int dp[n];

    for(int i=0;i<n;i++) {
        dp[i] = arr[i];
    }

    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {

            if(arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) {
                dp[i] = dp[j] + arr[i];
            }
        }
    }

    int mx = arr[0];
    for(auto it:dp) {
        mx = max(it,mx);
    }
    cout<<mx;
}
int main()
{
    int arr[] = {10,70,20,30,50,11,30};
    int n = 7;

    solve(arr,n);
}