#include<bits/stdc++.h>
using namespace std;

int binomialCoeff(int n,int k)
{
    int t[n+1][k+1];
    memset(t,0,sizeof(t));

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=min(i,k);j++)
        {
            if(i==0 || j==0)
            {
                t[i][j] = 1;
            }
            else
            {
                t[i][j] = t[i-1][j-1] + t[i-1][j];
            }
        }
    }

    return t[n][k];

}

int main()
{
    int n = 5, k = 2;
    cout << "Value of C(" << n << ", " << k << ") is "
         << binomialCoeff(n, k);
    return 0;
}