#include<bits/stdc++.h>
using namespace std;

static bool comp(vector<int>&b1,vector<int>&b2) {

    return b1[2] < b2[2];
}
void solve(vector<vector<int>>disks,int n) {

    vector<vector<int>>ans;

    sort(disks.begin(),disks.end(),comp);

    vector<pair<int,int>>dp(n);

    for(int i=0;i<n;i++) {

        dp[i] = make_pair(disks[i][2],-1);
    }

    for(int i=1;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(disks[j][0] < disks[i][0] && disks[j][1] < disks[i][1] && disks[j][2] < disks[i][2] && dp[j].first + disks[i][2] > dp[i].first) {
                dp[i].first = dp[j].first + disks[i][2];
                dp[i].second = j;
            }
        }
    }

    int mx = INT_MIN;
    int mx_i = -1;

    for(int i=0;i<n;i++) {
        if(mx < dp[i].first) {
            mx = dp[i].first;
            mx_i = i;
        }
    }

    ans.push_back(disks[mx_i]);
    int parent = dp[mx_i].second;

    while(parent != -1) {
        ans.push_back(disks[parent]);
        parent = dp[parent].second;
    }

    reverse(ans.begin(),ans.end());

    for(int i=0;i<ans.size();i++) {
        for(int j=0;j<3;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


}

int main()
{
    vector<vector<int>>disks{{2,1,2},{3,2,3},{2,2,8},{2,3,4},{1,3,4},{4,4,5}};
    int n = disks.size();

    solve(disks,n);
}