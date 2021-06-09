#include<bits/stdc++.h>
using namespace std;

int findWaysToPair(int p)
{
    if(p<=2)
    {
        return p;
    }
    else
    {
        return findWaysToPair(p-1) + (p-1) * findWaysToPair(p-2);
    }
}

int main()
{
    int p = 4; 
    cout << findWaysToPair(p); 
    return 0; 
}