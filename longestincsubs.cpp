#include<bits/stdc++.h>
using namespace std;


void lis(int arr[],int n) {

    vector<pair<int,int>> dp(n);

    for(int i=0;i<n;i++) {
        dp[i].first = 1;
        dp[i].second = -1;
    }

    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {

            if(arr[i] > arr[j] && dp[i].first < dp[j].first + 1) {
                dp[i].first = dp[j].first + 1;
                dp[i].second = j;
            }
        }
    }
    int mx = INT_MIN;
    int idx = -1;
    int it;
    int t = -1;
    for(it=0;it<dp.size();it++) {

        if(dp[it].first > mx) {
            t = it;
            mx = dp[it].first;
            idx = dp[it].second;
        }
        
    }
    
    // cout<<mx<<" "<<idx<<endl;
    // cout<<dp[idx].first<<endl;
    int par = idx;
    vector<int>ans;
    ans.push_back(arr[t]);
    while(true) {
        ans.push_back(arr[par]);
        par = dp[par].second;

        if(par <= 0 || dp[par].first == 1) {
            ans.push_back(arr[par]);
            break;
        }
    }
    
    reverse(ans.begin(),ans.end());
    for(auto it:ans) {
        cout<<it<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[] = {5,7,-24,12,10,2,3,12,5,6,35};
    int n = 11;

    lis(arr,n);
}
