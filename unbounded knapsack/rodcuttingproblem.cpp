#include<bits/stdc++.h>
using namespace std;

int cutRod(int price[],int size)
{
    int length[size];
    // Creating a length array [1,2,3,4,5,6,7,8]
    // Price array which is    [1,5,8,9,10,17,17,20]
    for(int i=0;i<size;i++)
    {
        length[i] = i+1;
    }
    int t[size+1][size+1];
    memset(t,0,sizeof(t));

    for(int i=1;i<=size;i++)
    {
        for(int j=1;j<=size;j++)
        {
            if(length[i-1]<=j) // We check if the current length is less or equal to the Length available
            {
                t[i][j] = max(price[i-1] + t[i][j - length[i-1]],t[i-1][j]);
            }
            else //We check if the current length is greater than the length available
            {
                t[i][j] = t[i-1][j];
            }
            
        }
    }
    return t[size][size];
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; //Price Array
    int size = sizeof(arr)/sizeof(arr[0]); 
    cout<<"Maximum Value: "<<cutRod(arr, size);
    return 0;
}