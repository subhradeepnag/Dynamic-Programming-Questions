#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
    return (a > b )? a : b;
}

int knapSack(int W,int wt[],int val[], int n)
{
    int i,j;
    int t[n+1][W+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j] = 0;
            }
            else if(wt[i-1]<=W)
            {
                t[i][j] = max(val[i-1] + t[i-1][W-wt[i-1]],(t[i-1][j]));
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
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout<<knapSack(W, wt, val, n)<<endl;
    return 0; 
}