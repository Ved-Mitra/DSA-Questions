#include <bits/stdc++.h>
using namespace std;

/*There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.*/

long long minCost(vector<long long> &arr)
{
    int n=arr.size();
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    for(int i=0;i<n;i++)
        pq.push(arr[i]);
    long long ans=0;
    while(pq.size()>1)
    {
        long long n1=pq.top();
        pq.pop();
        long long n2=pq.top();
        pq.pop();
        pq.push(n1+n2);
        ans+=n1+n2;
    }
    return ans;
}



int main()
{

}