#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr,int n) {

    if(n == 0) {
        return 0;
    }

    int inc = arr[0];
    int exc = 0;

    for(int i=1;i<n;i++) {

        int temp = inc;
        inc = exc + arr[i];
        exc = max(temp,exc);

        cout<<inc<<" "<<exc<<endl;

    }

    return max(exc,inc);
}

int main() {

    vector<int>arr{75,105,120,75,90,135};
    cout<<solve(arr,arr.size());

    return 0;
}