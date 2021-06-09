#include<bits/stdc++.h>
using namespace std;

int findWaysToPair(int p)
{
    int t[p+1];
    memset(t,0,sizeof(t));
    for(int i=0;i<=p;i++)
    {
        if(i<=2)
        {
            t[i] = i;
        }
        else
        {
            t[i] = t[i-1] + (i-1) * t[i-2];
        }
    }

    return t[p];

}

int main()
{
    int p = 3; 
    cout << findWaysToPair(p); 
    return 0; 
}