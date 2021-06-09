#include<bits/stdc++.h>
using namespace std;

int permutationCoeff(int n,int k)
{
    int t[n+1][k+1];
    memset(t,-1,sizeof(t));

    if(k==0)
    {
        return 1;
    }
    if(k>n)
    {
        return 0;
    }
    if(t[n][k]!=-1)
    {
        return t[n][k];
    }

    return t[n][k] = (k*permutationCoeff(n-1,k-1) + permutationCoeff(n-1,k));
}

int main(){

   int n=5,k=3;
   cout<<"Value of P"<<n<<k<<permutationCoeff(n,k);
   return 0;
}