#include<bits/stdc++.h>
using namespace std;

void solve(string str1,string str2) {

    int m = str1.length();
    int n = str2.length();

    int dp[m+1][n+1];

    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {

                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    // cout<<dp[m][n];

    string res;
    int i = m;
    int j = n;
    while(i >= 0 && j >= 0) {

        if(str1[i-1] == str2[j-1]) {
            res+=str1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(res.begin(),res.end());
    cout<<res;
}
int main()
{
    string str1 = "ZXVVYZW";
    string str2 = "XKYKZPW";

    solve(str1,str2);
}