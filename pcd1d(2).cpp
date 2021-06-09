#include<bits/stdc++.h>
using namespace std;

int permutationCoeff(int n,int k)
{
    int p = 1;

    for(int i=0;i<k;i++)
    {
        p*=(n-i);
    }
    return p;
}



int main()
{
    int n=5,k=2;
    cout<<"Value of P"<<n<<","<<k<<permutationCoeff(n,k);
    return 0;
}