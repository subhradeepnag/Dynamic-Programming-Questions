#include<bits/stdc++.h>
using namespace std;

int binomialCoeff(int n,int k)
{
    int t[n+1][k+1];
    memset(t,-1,sizeof(t));

    if(n < k)
    {
        return t[n][k] = 0;
    }
    if(k==0 || n==0)
    {
        return t[n][k] = 1;
    }

    if(t[n][k]!=-1)
    {
        return t[n][k];
    }

    return t[n][k] = binomialCoeff(n-1,k-1) + binomialCoeff(n-1,k);
}

int main()
{
    int n = 5, k = 2;
    cout << "Value of C(" << n << ", " << k << ") is "
         << binomialCoeff(n, k);
    return 0;
}