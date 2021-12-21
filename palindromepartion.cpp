#include<bits/stdc++.h>
using namespace std;

int dp[10001][10001];
bool isPalindrome(string str,int i,int j) {

    while(i < j) {

        if(str[i]!=str[j]) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}
int partition(string str,int i,int j) {

    if(i >= j || isPalindrome(str,i,j)) {
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int mn = INT_MAX;

    for(int k=i;k<j;k++) {

        int temp = 1 + partition(str,i,k) + partition(str,k+1,j);

        mn = min(mn,temp);

    }

    return dp[i][j] = mn;

}

int main()
{
    string str = "noonabbad";
    memset(dp,-1,sizeof(dp));
    cout<<partition(str,0,str.size()-1);
}