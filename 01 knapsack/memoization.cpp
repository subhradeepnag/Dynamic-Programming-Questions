#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
    return (a > b) ? a : b;
}

int knapSack(int wt[],int val[],int W,int n)
{
    int t[n+1][W+1];

    memset(t,-1,sizeof(t));
    //Base Case
    if(n==0 || W==0)
    {
        return 0;
    }
    if(t[n][W]!=-1)
    {
        return t[n][W];
    }

    if(wt[n-1]> W)
    {
        return t[n][W]=(wt,val,W,n-1);
    }

    else
    {
        return t[n][W]= max(val[n-1]+knapSack(wt,val,W-wt[n-1],n-1),knapSack(wt,val,W,n-1));
    }
    
}

int main()
{
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout << knapSack(wt, val, W, n); 
    return 0; 
}