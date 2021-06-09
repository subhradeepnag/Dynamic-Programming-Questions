#include<bits/stdc++.h>
using namespace std;

unsigned long int catalan(int n)
{
    unsigned long int t[n+1];

    memset(t,0,sizeof(t));

    t[0] = t[1] = 1;

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            t[i]+=t[j]*t[i-j-1];
        }
    }

    return t[n];
}

int main()
{
    for (int i = 0; i < 10; i++)
        cout << catalan(i) << " ";
    return 0;
}