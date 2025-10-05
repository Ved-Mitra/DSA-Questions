#include<bits/stdc++.h>
using namespace std;


void subset(vector<int> &arr,vector<vector<int>> &ans)
{
    //TC-O(n * 2^n)
    //SC-O(2^n)
    int n=arr.size();
    for(int i=0;i<(1<<n);i++)  //2^n
    {
        vector<int> subs;
        for(int j=0;j<n;j++)
            if(i & (1<<j)) //ith bit is set
                subs.push_back(arr[j]);
        ans.push_back(subs);
    }
}

int main()
{

}