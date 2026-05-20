#include <bits/stdc++.h>
using namespace std;

//Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start. Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

int minimumMultiplication(vector<int> &arr,int start,int end)
{
    if(start==end)
        return 0;
    int n=arr.size();
    queue<pair<int,int>>pq;
    pq.push({0,start});
    int mod=1e5;
    vector<bool> visited(mod+1,false);
    visited[start]=true;
    while(!pq.empty())
    {
        int val=pq.front().second;
        int steps=pq.front().first;
        pq.pop();
        for(int i=0;i<n;i++)
        {
            int mul=(val*arr[i])%mod;
            if(mul==end)
                return steps+1;
            if(!visited[mul])
            {
                visited[mul]=true;
                pq.push({steps+1,mul});
            }
        }
    }
    return -1;
}


int main()
{

}