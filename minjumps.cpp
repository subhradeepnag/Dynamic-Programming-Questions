#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int curr,int dest,vector<int>&dp) {

    if(curr == dest) {
        return 0;
    }

    if(dp[curr] != -1) {
        return dp[curr];
    }

    int temp = INT_MAX;

    for(int i=1;i<=arr[curr];i++) {

        if(i + curr > dest) {
            break;
        }

        temp = min(temp,1 + solve(arr,curr + i,dest,dp));
    }

    dp[curr] = temp;

    return temp;

}
int main()
{
    int arr[] = {3,4,2,1,2,3,7,1,1,1,3};
    int n = 11;
    vector<int>dp(n,-1);

    cout<<solve(arr,0,n-1,dp);
    cout<<endl;

}