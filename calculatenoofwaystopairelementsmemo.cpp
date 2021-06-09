#include<bits/stdc++.h>
using namespace std;

int findWaysToPair(int p)
{
    int t[p+1];
    memset(t,-1,sizeof(t));

    if(p<=2)
    {
        return t[p] = p;
    }
    if(t[p]!=-1)
    {
        return t[p];
    }

    return t[p] =  findWaysToPair(p-1)+ (p-1) * findWaysToPair(p-2);
}

int main()
{
    int p = 3; 
    cout << findWaysToPair(p); 
    return 0; 
}