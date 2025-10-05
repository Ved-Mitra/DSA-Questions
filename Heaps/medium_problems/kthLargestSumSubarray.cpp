#include <bits/stdc++.h>
using namespace std;

/*You have been given an array/list of N integers. Now you are supposed to find the Kth largest sum of the subarray .
Please note that a subarray is the sequence of consecutive elements of the array.
*/



long long countSubarray(vector<int> &prefixSum,int mid_sum)
{
    //already reaceiving prefixSum array so just need to make a merge sort tree

    //we need to find this
    //prefixSum[i]≤prefixSum[j]−mid
    //We can iterate j from 1 to N and, for each prefixSum[j], count how many previous prefixSum[i] satisfy this condition. 

    vector<int> temp=prefixSum;
    int n=temp.size();
    return mergeSortAndCount(temp,0,n-1,mid_sum);
}
long long mergeSortAndCount(vector<int> &prefix_sums,int left,int right,int min_sum)
{
    // Base case: If there's only one element or less, no pairs can be formed.
    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;
    long long count = 0;

    // 1. CONQUER: Recursively count in left and right halves
    count += mergeSortAndCount(prefix_sums, left, mid, min_sum);
    count += mergeSortAndCount(prefix_sums, mid + 1, right, min_sum);

    // 2. COMBINE: Count "cross-pairs" where one element is in the left half
    // and the other is in the right half.
    // We are looking for pairs (i, j) with i < j such that:
    // prefix_sums[j] - prefix_sums[i] >= min_sum
    // OR prefix_sums[i] <= prefix_sums[j] - min_sum
    int p1 = left;
    for (int j = mid + 1; j <= right; ++j) {
        while (p1 <= mid && prefix_sums[p1] <= prefix_sums[j] - min_sum) {
            p1++;
        }
        count += (p1 - left);
    }

    // 3. MERGE: Perform the standard merge step to sort the current range
    std::vector<long long> sorted_temp;
    sorted_temp.reserve(right - left + 1);
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (prefix_sums[i] < prefix_sums[j]) {
            sorted_temp.push_back(prefix_sums[i++]);
        } else {
            sorted_temp.push_back(prefix_sums[j++]);
        }
    }
    while (i <= mid) sorted_temp.push_back(prefix_sums[i++]);
    while (j <= right) sorted_temp.push_back(prefix_sums[j++]);

    // Copy the sorted elements back into the original array
    for (int k = 0; k < sorted_temp.size(); ++k) {
        prefix_sums[left + k] = sorted_temp[k];
    }

    return count;
}


int getKthLargest(vector<int> &arr,int k)
{
    int n=arr.size();
    
    //BRUTE
    //TC-O(N^2 * log N^2)
    vector<int> Sum;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            Sum.push_back(sum);
        }
    }
    sort(Sum.begin(),Sum.end());
    return Sum[Sum.size()-1-k];

    //BETTER
    //TC-O(N^2 log k)
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            if(pq.size()<k ||pq.top()<sum)
                pq.push(sum);
            if(pq.size()>k)
                pq.pop();
        }
    }
    return pq.top();


    //OPTIMAL
    //learn FENWICK TREE / MERGE SORT TREE 
    //HERE DONE BY MERGE SORT TREE

    int low=0;//sum of minimum possible subarray in array
    int high=0;//maximum possible subarray sum
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
            high+=arr[i];
        else
            low+=arr[i];
    }
    vector<int> prefixSum(n,0);//for count subarray function
    prefixSum[0]=arr[0];
    for(int i=1;i<n;i++)
        prefixSum[i]=prefixSum[i-1]+arr[i];

    int ans=0;

    while(low<=high)
    {
        int mid=(low+high)/2;
        long long count=countSubarray(prefixSum,mid);
        if(count>=k)
        {
            ans=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }

    return ans;
}



int main()
{
    
}