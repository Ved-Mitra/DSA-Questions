#include<bits/stdc++.h>
using namespace std;

/*
Q.  return all quadruplets (unique) with sum k
    a1=b!=c!=d
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
    int target;
    cout << "Enter the sum: " ;
    cin >> target;


    //BRUTE
    //TC-O(N^4)
    //SC-O(m) , m-->number of quadruplets
    set<vector<int>> st;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                for(int l=k+1;l<n;l++)
                    if(nums[i]+nums[j]+nums[k]+nums[l]==target)
                    {
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
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
    //TC-O(N^3 * log m) m-->number of quadruplets
    //SC-O(N)
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            set<int> hash;
            for(int k=j+1;k<n;k++)
            {
                int fourth=target-nums[i]-nums[j]-nums[k];
                if(hash.find(fourth)!=hash.end())
                {
                    vector<int> temp={nums[i],nums[j],nums[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hash.insert(nums[k]);
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

    //OPTIMAL
    //2 pointer approach
    //TC-O(N^3)
    //SC-O(m) m-->unique triplets
    sort(nums,nums+n);
    for(int i=0;i<n;i++)
    {
        if(i>0 && nums[i]==nums[i-1])
        continue;
        for(int l=i+1;l<n;l++)
        {
            if(l!=i+1 && nums[l]==nums[l-1])
                continue;
            int j=l+1;
            int k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k]+nums[l];
                if(sum<target)
                {
                    j++;
                }
                else if(sum>target)
                {
                    k--;
                }
                else
                {
                    vector<int> temp={nums[i],nums[l],nums[j],nums[k]};
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
