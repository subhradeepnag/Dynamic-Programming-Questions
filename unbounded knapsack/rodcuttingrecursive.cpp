#include<bits/stdc++.h>
using namespace std;

int cutRod(int price[],int length[],int n)
{
    if(n==0)
    {
        return 0;
    }

    if(length[n-1]<=n)
    {
        return max(price[n-1] + cutRod(price,length,n-length[n-1]), cutRod(price,length,n-1));
    }
    else
    {
        return cutRod(price,length,n-1);
    }
    
}
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; //Price Array
    int size = sizeof(arr)/sizeof(arr[0]);
    int length[size];
    for(int i=0;i<size;i++)
    {
        length[i] = i+1;
    } 
    // Creating a length array [1,2,3,4,5,6,7,8]
    // Price array which is    [1,5,8,9,10,17,17,20]
    cout<<"Maximum Value: "<<cutRod(arr,length,size);
    return 0;
}