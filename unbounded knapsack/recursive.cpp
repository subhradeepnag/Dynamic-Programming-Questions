#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int W , int n ,int val[], int wt[])
{
    if(n==0 || W==0)
    {
        return 0;
    }

    if(wt[n-1] <= W)
    {
        return max(val[n-1] + unboundedKnapsack(W - wt[n-1],n,val,wt),unboundedKnapsack(W,n-1,val,wt));
    }
    else
    {
        return unboundedKnapsack(W,n-1,val,wt);
    }
    
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