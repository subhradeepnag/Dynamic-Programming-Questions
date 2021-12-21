#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n,int target) {

    int res = 0;
    for(int i=n-1;i>=0;i--) {

        if(target >= arr[i]) {

            int temp = target/arr[i];
            cout<<temp<<" ";
            res = res + temp;

            target = target - arr[i]*temp;

        }
    }

    cout<<res;
}
int main() {

    int arr[] = {1,5,10};
    int n = 3;

    int target = 7;

    solve(arr,n,target);
}