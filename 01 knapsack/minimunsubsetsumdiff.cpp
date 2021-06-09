#include<bits/stdc++.h>
using namespace std;

int findMin(int arr[],int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }

    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = true;
    }
    for(int i=0;i<=n;i++)
    {
        dp[0][i] = false;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }
    int half_sum = sum/2;
    vector<int>v;
    for(int i=0;i<=sum/2;i++)
    {
        if(dp[n][i] == true)
        {
            v.push_back(i);
        }
    }
    int mn = INT_MAX;
    for(int i=0;i<v.size();i++)
    {
        mn = min(mn,sum-2*v[i]);
    }
    return mn;

}

int main()
{
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The minimum difference between 2 sets is "
         << findMin(arr, n);
    return 0;
}