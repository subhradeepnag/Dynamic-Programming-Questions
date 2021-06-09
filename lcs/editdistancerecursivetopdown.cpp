#include<bits/stdc++.h>
using namespace std;

int min(int x,int y,int z)
{
    return min(min(x,y),z);
}

int editDist(string s1,string s2,int m,int n)
{
    int t[m+1][n+1];
    memset(t,0,sizeof(t));

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i == 0)
            {
                t[i][j] = j;
            }
            else if(j == 0)
            {
                t[i][j] = i;
            }
            else if(s1[i-1] == s2[j-1])
            {
                t[i][j] = t[i-1][j-1];
            }
            else
            {
                t[i][j] = 1 + min(t[i][j-1],t[i-1][j],t[i-1][j-1]);
            }
        }
    }

    return t[m][n];
}

int main()
{
    string str1 = "sunday";
    string str2 = "saturday";
 
    cout << editDist(str1, str2, str1.length(),
                     str2.length());
}