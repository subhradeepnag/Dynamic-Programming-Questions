#include<bits/stdc++.h>
using namespace std;

string printlcs(string a,string b,int m,int n)
{
    string s;
    int t[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j] = 0;
            }
            else if(a[i-1]==b[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
            {
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    int i = m;
    int j = n;

    while(i>0 && j>0)
    {
        if(a[i-1] == b[j-1])
        {
            s.push_back(a[i-1]);
            i--;
            j--;
        }
        else
        {
            if(t[i][j-1]>t[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }

    reverse(s.begin(),s.end());
    return s;
}

int main()
{
    string a = "acbcf";
    string b = "abcdaf";
    int m = a.length();
    int n = b.length();
    cout<<printlcs(a,b,m,n);
}