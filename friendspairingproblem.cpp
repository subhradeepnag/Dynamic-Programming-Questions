#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int dp[n+1];
    for(int i=0;i<=n;i++)
    {
        if(i<=2)
        {
            dp[i] = i;
        }
        else
        {
            dp[i] = t[i-1] + (n-1) * t[i-2];
            
        }
    }

    return dp[n];
}

int main()
{
    solve();
}