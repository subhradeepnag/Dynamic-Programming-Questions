#include<bits/stdc++.h>
using namespace std;

int static t[101][101]; // take n and W value based on constraints.

int unboundedKnapsack(int W,int n,int val[],int wt[])
{

    if(n==0 || W==0)
    {
        return 0;
    }
    if(t[n][W]!=-1)
    {
        return t[n][W];
    }

    if(wt[n-1]<=W)
    {
        return t[n][W] = max(val[n-1] + unboundedKnapsack(W-wt[n-1],n,val,wt), unboundedKnapsack(W,n-1,val,wt));
    }
    else
    {
        return t[n][W] = unboundedKnapsack(W,n-1,val,wt);
    }
    
}

int main()
{
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val)/sizeof(val[0]);
    memset(t,-1,sizeof(t)); // Initializing 2D array to -1.
    cout << unboundedKnapsack(W, n, val, wt);
 
    return 0;
}