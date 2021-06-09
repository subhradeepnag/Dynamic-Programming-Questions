#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int W, int n,int val[],int wt[])
{
    int t[n+1][W+1];
    memset(t,0,sizeof(t));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(wt[i-1]<=j)
            {
                t[i][j] = max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
            
        }
    }
    return t[n][W];
}

int main()
{
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val)/sizeof(val[0]);
 
    cout << unboundedKnapsack(W, n, val, wt);
 
    return 0;
}