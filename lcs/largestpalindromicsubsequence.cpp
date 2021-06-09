#include<bits/stdc++.h>
using namespace std;

int LCS(string a,string b,int m,int n)
{
    int t[m+1][n+1];
    memset(t,-1,sizeof(t));

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j] = 0;
            }
            else if(a[i-1] == b[j-1])
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

string reverseS(string s)
{
    reverse(s.begin(),s.end());
    
}

int LPS(string a,int m)
{
    
    return LCS(a,reverse(a.begin(),a.end()),m,m);
    
}

int main()
{
    string a = "agbcba";
    int m = a.length();
    cout<<LPS(a,m);
}