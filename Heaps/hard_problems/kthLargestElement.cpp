#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(pq.size()<this->k || pq.top()<nums[i])
                pq.push(nums[i]);
            if(pq.size()>k)
                pq.pop();
        }
    }
    
    int add(int val) {
        if(pq.size()<this->k || pq.top()<val)
            pq.push(val);
        if(pq.size()>k)
            pq.pop();
        return pq.top();
    }
};

int main()
{
}