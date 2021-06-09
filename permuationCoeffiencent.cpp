#include<bits/stdc++.h>
using namespace std;

//Returns value of P(n,k)
int permutationCoeff(int n,int k){
    //Base cases
    if(k==0){
        return 1;
    }
    if(k>n){
        return 0;
    }
    //Recursive call
    return (k*permutationCoeff(n-1,k-1)+permutationCoeff(n-1,k));
}

int main(){

   int n=5,k=2;
   cout<<"Value of P"<<n<<k<<permutationCoeff(n,k);
   return 0;
}
