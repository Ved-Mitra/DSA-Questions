#include <bits/stdc++.h>
using namespace std;

int recursiveHelper(vector<int> &nums,int i,int sum,int len,int arrSum)
{
    //len --> length of subset 1
    //arrSum --> sum of array elements
    if(i==0 && len==nums.size()/2)
        return 0;
    else if(i==0)
        return nums[0];

    int take=1e9,notTake=1e9;
    
    if(len<nums.size()/2)
        take=sum + recursiveHelper(nums,i-1,sum+nums[i],len+1,arrSum);
    else
        notTake=sum + recursiveHelper(nums,i-1,sum,len,arrSum); 

    return min(abs(2*take - arrSum),abs(2*notTake - arrSum));
}

int minDiff_Memoization(vector<int> &nums)
{
    int n=nums.size();
    int sum=accumulate(nums.begin(),nums.end(),0);

    return recursiveHelper(nums,n-1,0,0,sum);
}

int minDiff_Tabulation(vector<int> &nums)
{
    int n=nums.size();

}

int minDiff_SC(vector<int> &nums)
{

}



int main()
{
    
}