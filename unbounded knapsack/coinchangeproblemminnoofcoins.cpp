#include<bits/stdc++.h>
using namespace std;

int minCoins(int coins[] ,int n,int sum)
{
    int t[n+1][sum+1];

    for(int i=0;i<=n;i++)
    {
        t[i][0] = 0;
    }
    for(int i=0;i<=sum;i++)
    {
        t[0][i] = INT_MAX-1;
    }
    for(int i=1;i<=sum;i++)
    {
        if(i%coins[0] == 0)
        {
            t[1][i] = i/coins[0]; 
        }
        else
        {
            t[1][i] = INT_MAX-1;
        }
        
    }
    
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coins[i-1]<=j)
            {
                t[i][j] = min(t[i][j-coins[i-1]] + 1, t[i-1][j]);
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
            
        }
    }
    return t[n][sum];
}

int main()
{
    int coins[] =  {9, 6, 5, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    int sum = 11;
    cout << "Minimum coins required is "<< minCoins(coins, m, sum);
    return 0;
}