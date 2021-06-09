#include<bits/stdc++.h>
using namespace std;

int binomialCoeff(int n,int k)
{
    int t[k+1];
    memset(t,0,sizeof(t));

    t[0] = 1;

    for(int i=0;i<=n;i++)
    {
        for(int j=min(i,k);j>0;j--)
        {
            t[j] = t[j-1] +t[j];
        }
    }

    return t[k];
}

int main()
{
    int n = 5, k = 2;
    cout << "Value of C(" << n << ", " << k << ") is "
         << binomialCoeff(n, k);
    return 0;
}