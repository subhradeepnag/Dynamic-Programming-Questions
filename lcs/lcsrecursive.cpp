#include<bits/stdc++.h>
using namespace std;

int lcs(string X,string Y,int m,int n)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    if(X[m-1] == Y[n-1])
    {
        return 1+lcs(X,Y,n-1,m-1);
    }
    else
    {
        return max(lcs(X,Y,m-1,n),lcs(X,Y,m,n-1));
    }
}

int main()
{
    string X = "AGGTAB";  
    string Y = "GXTXAYB";  
      
    int m = X.length();  
    int n = Y.length();  
      
    cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;  
      
    return 0; 
}