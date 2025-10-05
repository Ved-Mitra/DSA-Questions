#include<bits/stdc++.h>
using namespace std;


//NSEs -- next smaller elements
vector<int> numberOfNSEs(vector<int> &nums)
{
    int n=nums.size();
    int i=n-1;
    stack<int> st;
    vector<int> ans(n,-1);
    while(i>=0)
    {
        while(!st.empty() && nums[i]<st.top())
            st.pop();
        if(!st.empty())
            ans[i]=st.top();
        st.push(nums[i]);
        i--;
    }
    return ans;
}

int main()
{

}