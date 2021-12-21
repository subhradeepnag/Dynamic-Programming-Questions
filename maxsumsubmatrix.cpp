#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>arr,int size) {

    int row = arr.size();
    int col = arr[0].size();

    int mx = INT_MIN;

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {

            if(i + size <= row && j + size <= col) {
                int sum = 0;
                for(int k=i;k<i+size;k++) {
                    for(int l=j;l<j+size;l++) {
                        sum+=arr[k][l];
                    }
                }

                 mx = max(mx,sum);
            }

        }
    }

    cout<<mx;

}
int main()
{
    vector<vector<int>>arr{{2,4},{5,6},{-3,2}};
    int n = 2;
    solve(arr,n);
}