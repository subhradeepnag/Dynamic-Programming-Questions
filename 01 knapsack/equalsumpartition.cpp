#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(int set[],int n,int sum)
{
    bool subset[n+1][sum+1];

    for(int i=0;i<=n;i++)
    {
        subset[0][i] = false;
    }   
    for(int i=0;i<=n;i++)
    {
        subset[i][0] = true;
    }

    for(int i = 1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(set[i-1]<=j)
            {
                subset[i][j] = subset[i-1][j - set[i-1]] || subset[i-1][j];
            }
            else
            {
                subset[i][j] = subset[i-1][j];
            }
            
        }
    }

    return subset[n][sum];

}

bool equalSumPartiion(int arr[],int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    if(sum%2!=0)
    {
        return false;
    }
    else if (sum%2==0)
    {
        return isSubsetSum(arr,n,sum/2);
    }
}
int main()
{
    int set[] = {1,6,11,5};
    int n = sizeof(set) / sizeof(set[0]);
    if (equalSumPartiion(set, n) == true)
        cout<<"Can be split";
    else
        cout<<"Cannot be split";
    return 0;
}