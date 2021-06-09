#include<bits/stdc++.h>
using namespace std;

int lcs(string X,string Y,int m,int n)
{
    int t[m+1][n+1];
    memset(t,-1,sizeof(t));
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j] = 0;
            }
        }
    }

    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(X[i-1] == Y[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
            {
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[m][n];
}

int main()
{
    string X = "AGGTAB";  
    string Y = "GXTXAYB";  
      
    int m = X.length();  
    int n = Y.length();  
      
    cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;  
}