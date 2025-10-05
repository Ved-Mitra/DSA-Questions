#include<bits/stdc++.h>
using namespace std;

/*You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.*/

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    //TC-O(n)
    //SC-O(n)+O9(n-k)
    int n=nums.size();
    vector<int> ans;
    deque<int> st;
    for(int i=0;i<n;i++)
    {
        if(!st.empty() && st.front()<=i-k)
        {
            st.pop_front();
        }
        while(!st.empty() && nums[st.back()]<=nums[i])
            st.pop_back();
        st.push_back(i);
        if(i>=k-1)
            ans.push_back(nums[st.front()]);
    }
    return ans;
}


int main()
{

}