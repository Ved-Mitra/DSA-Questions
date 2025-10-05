#include<bits/stdc++.h>
using namespace std;

/*
Q.  return all triplet (unique) with sum zero
    i!=j!=k
*/

int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    int nums[n];
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> nums[i];

    //BRUTE
    // 3-loops
    //TC-O(N^3)
    //SC-O(1)
    set<vector<int>> st;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    for(auto it1:ans)
    {
        for(auto it2:it1)
        {
            cout << it2 << ",";
        }
        cout << endl;
    }
    ans.clear();
    st.clear();

    //BETTER
    //hashing
    //arr[k]=-(arr[i]+arr[j])
    //TC-O(N^2 * log M)  M-->elements in hash
    //SC-O(N)
    for(int i=0;i<n;i++)
    {
        set<int> hash;
        for(int j=i+1;j<n;j++)
        {
            int third=-nums[i]-nums[j];
            if(hash.find(third)!=hash.end())
            {
                vector<int> temp={nums[i],nums[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hash.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    for(auto it1:ans)
    {
        for(auto it2:it1)
        {
            cout << it2 << ",";
        }
        cout << endl;
    }
    ans.clear();
    st.clear();


    //OPTIMAL
    //2 pointer approach
    //TC-O(N log N)+ O(N^2)
    //SC-O(m) m-->unique triplets
    sort(nums,nums+n);
    for(int i=0;i<n;i++)
    {
        if(i>0 && nums[i]==nums[i-1])
        continue;
        int j=i+1;
        int k=n-1;
        while(j<k)
        {
            int sum=nums[i]+nums[j]+nums[k];
            if(sum<0)
            {
                j++;
            }
            else if(sum>0)
            {
                k--;
            }
            else
            {
                vector<int> temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1])
                    j++;
                while(j<k && nums[k]==nums[k+1])
                    k--;
            }
        }
    }
    for(auto it1:ans)
    {
        for(auto it2:it1)
        {
            cout << it2 << ",";
        }
        cout << endl;
    }
}