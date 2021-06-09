#include<bits/stdc++.h>
using namespace std;

int min(int x,int y,int z)
{
    return min(min(x,y),z);
}

int editDist(string s1,string s2,int m,int n)
{
    int t[m+1][n+1];
    memset(t,-1,sizeof(t));

    if(m==0)
    {
        return t[m][n] = n;
    }
    if(n==0)
    {
        return t[m][n] = m;
    }
    if(t[m][n]!=-1)
    {
        return t[m][n];
    }

    if(s1[m-1] == s2[n-1])
    {
        return t[m][n] = editDist(s1,s2,m-1,n-1);
    }
    else{

        return t[m][n] =  1 + min(editDist(s1,s2,m-1,n),editDist(s1,s2,m,n-1),editDist(s1,s2,m-1,n-1));
    }

}

int main()
{
    string str1 = "sunday";
    string str2 = "saturday";
 
    cout << editDist(str1, str2, str1.length(),
                     str2.length());
}