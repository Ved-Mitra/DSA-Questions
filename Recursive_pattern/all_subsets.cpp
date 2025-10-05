#include<bits/stdc++.h>
using namespace std;


void subsets(vector<int> &nums,vector<vector<int>> &ans)
{
    /*
    is ith bit set or not? 
    (n & (1<<i))!=0
    is same as 101 & 100 = 100 (here set bit for 1 at hundreds place)
               101
             &  10
               000 (here set bit for 0)
    */
    /*
    there are 2^n subsets where n is number of elements in subset

    here how it works:

    example [1,2,3]
             0 1 2

    __|__2__1__0__----> element aat which index to take
    0 |  0  0  0  ----> [[]]
    1 |  0  0  1  ----> [[1]]
    2 |  0  1  0  ----> [[2]]
    3 |  0  1  1  ----> [[1,2]]
    4 |  1  0  0  ----> [[3]]
    5 |  1  0  1  ----> [[1,3]]
    6 |  1  1  0  ----> [[1,2]]
    7 |  1  1  1  ----> [[1,2,3]]

    if 1 ---> take it
       0 ---> dn't take it

    here till 7 as example is [1,2,3]
    
    */
    int n=nums.size();
    int max=pow(2,n)-1;  //or (1<<n)-1 in binary
    for(int i=0;i<=max;i++)
    {
        vector<int> subs;
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
                subs.push_back(nums[j]);
        }
        ans.push_back(subs);
    }
}


int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];
    vector<vector<int>> ans;


    return 0;
}
