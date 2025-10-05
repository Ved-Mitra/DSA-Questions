#include<bits/stdc++.h>
using namespace std;

/*SHORTEST JOB FIRST (SJF)
scheduling policy that selects waiting process with the smallest execution time to execute next*/

long SJF(vector<int> &arr)
{
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int t=0,wtTime=0;
    for(int i=0;i<n;i++)
    {
        wtTime+=t;
        t+=arr[i];
    }
    return wtTime/n;
}

int main()
{

}