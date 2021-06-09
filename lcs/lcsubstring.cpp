#include<bits/stdc++.h>
using namespace std;

int LCSubStr(string X,string Y,int m,int n)
{
    int t[m+1][n+1];
    memset(t,-1,sizeof(t));
    int result = 0;

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
                t[i][j] = t[i-1][j-1] + 1;
                result = max(result,t[i][j]);
            }
            else
            {
                t[i][j] = 0;
            }
        }
    }

    return result;
}

int main()
{
    string X = "OldSite:GeeksforGeeks.org";
    string Y = "NewSite:GeeksQuiz.com";
 
    int m = X.length();
    int n = Y.length();
 
    cout << "Length of Longest Common Substring is "
         << LCSubStr(X, Y, m, n);
    return 0;
}