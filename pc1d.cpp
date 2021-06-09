#include<bits/stdc++.h>
using namespace std;

int permutationCoeff(int n, int k)
{
   int fact[n+1];
   fact[0] = 1;
   for(int i=1;i<=n;i++)
   {
      fact[i] = i * fact[i-1];
   }
   return fact[n]/fact[n-k];
     
}


int main(){

   int n=5,k=2;
   cout<<"Value of P "<<n<<","<<k<<" "<<permutationCoeff(n,k);
   return 0;
}