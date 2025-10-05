#include <bits/stdc++.h>
using namespace std;

/*Given two integer arrays nums1 and nums2 and an integer k, return the maximum k valid sum combinations from all possible sum combinations using the elements of nums1 and nums2.



A valid sum combination is made by adding one element from nums1 and one element from nums2. Return the answer in non-increasing order.*/

vector<int> maxSumCombinations(vector<int> &nums1, vector<int> &nums2, int k)
{
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    int n=nums1.size();
    int i=n-1,j=n-1;


    // MAY FALL AT SOME POINTS
    //GREEDY APPROACH    
    vector<int> ans(k);
    int index=0;
    while(i>=0 && j>=0 && index<k)
    {
        int sum=nums1[i]+nums2[j];
        ans[index++]=sum;
        int sum1=nums1[i];
        if(j!=0)
            sum1+=nums2[j-1];
        int sum2=nums2[j];
        if(i!=0)
            sum2+=nums1[i-1];
        if(sum1>sum2)
            j--;
        else
            i--;
    }
    return ans;

    //MAX HEAP APPROACH
    int n = nums1.size();
    std::vector<int> result;

    // Step 2: Create a max-heap to store {sum, {index1, index2}}.
    // The default priority_queue is a max-heap.
    std::priority_queue<std::pair<int, std::pair<int, int>>> maxHeap;

    // Step 3: Use a set to track visited pairs of indices to avoid duplicates.
    std::set<std::pair<int, int>> visited;

    // Step 4: Initialize the heap with the largest possible sum combination.
    int i = n - 1;
    int j = n - 1;
    int initialSum = nums1[i] + nums2[j];
    maxHeap.push({initialSum, {i, j}});
    visited.insert({i, j});

    // Step 5: Loop until we have found k combinations or the heap is empty.
    while (result.size() < k && !maxHeap.empty()) {
        // Pop the current largest sum combination from the heap.
        std::pair<int, std::pair<int, int>> top = maxHeap.top();
        maxHeap.pop();

        int currentSum = top.first;
        int idx1 = top.second.first;
        int idx2 = top.second.second;

        // Add the sum to our result vector.
        result.push_back(currentSum);

        // From the current combination (idx1, idx2), we can form two new candidates:
        // 1. (idx1 - 1, idx2)
        // 2. (idx1, idx2 - 1)
        
        // Candidate 1:
        if (idx1 > 0) {
            std::pair<int, int> nextPair1 = {idx1 - 1, idx2};
            // If we haven't processed this pair of indices before...
            if (visited.find(nextPair1) == visited.end()) {
                int nextSum = nums1[idx1 - 1] + nums2[idx2];
                maxHeap.push({nextSum, nextPair1});
                visited.insert(nextPair1);
            }
        }

        // Candidate 2:
        if (idx2 > 0) {
            std::pair<int, int> nextPair2 = {idx1, idx2 - 1};
            // If we haven't processed this pair of indices before...
            if (visited.find(nextPair2) == visited.end()) {
                int nextSum = nums1[idx1] + nums2[idx2 - 1];
                maxHeap.push({nextSum, nextPair2});
                visited.insert(nextPair2);
            }
        }
    }

    return result;
}

int main()
{
}