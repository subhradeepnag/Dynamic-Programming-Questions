#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n) {

    int left[n];
    int right[n];
    left[0] = arr[0];
    right[n-1] = arr[n-1];

    for(int i=1;i<n;i++) {
        left[i] = max(left[i-1],arr[i]);
    }
    //0 8 8 8 8 8 10 10 10 10 10 10 10 
    for(int i=n-2;i>=0;i--) {
        right[i] = max(right[i+1],arr[i]);
    }
    //10 10 10 10 10 10 10 3 3 3 3 3 3

    int water = 0;
    for(int i=0;i<n;i++) {

        water+=min(left[i],right[i]) - arr[i];
    }

    cout<<water;
}
int main()
{
    int arr[] = {0,8,0,0,5,0,0,10,0,0,1,1,0,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    solve(arr,n);
}