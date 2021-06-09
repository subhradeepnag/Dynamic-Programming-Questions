#include<bits/stdc++.h>
using namespace std;

int lcs(string X, string Y,int m,int n)
{
    int t[m+1][n+1];
    memset(t,-1,sizeof(t));

    if(n==0 || m==0)
    {
        return 0;
    }
    if(t[m][n]!=-1)
    {
        return t[m][n];
    }

    if(X[m-1] == Y[n-1])
    {
        return t[m][n] = 1 + lcs(X,Y,m-1,n-1);
    }
    else
    {
        return t[m][n] = max(lcs(X,Y,m,n-1),lcs(X,Y,m-1,n));
    }
}

int main()
{
    string X = "AGGTAB";  
    string Y = "GXTXAYB";  
      
    int m = X.length();  
    int n = Y.length();  
      
    cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;  
}