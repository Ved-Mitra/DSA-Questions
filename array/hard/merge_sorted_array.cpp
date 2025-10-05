#include<bits/stdc++.h>
using namespace std;

/*
Q. return the array with all overlapping subintervals merged
*/

int main()
{
    int n;
    cout << "Enter the size of array 1 : " ;
    cin >> n;
    vector<int> nums1(n);
    cout << "Enter the elements of the array 1 : " << endl;
    for(int i=0;i<n;i++)
        cin >> nums1[i];
    int m;
    cout << "Enter the size of array 2 : " ;
    cin >> m;
    vector<int> nums2(m);
    cout << "Enter the elements of the array 2 : " << endl;
    for(int i=0;i<m;i++)
        cin >> nums2[i];
    
    
    //BRUTE
    //TC-O(m+n)
    //SC-O(n+m)
    int i=0,j=0;
    vector<int> ans(n+m,0);
    int index=0;
    while(i<m && j<n)
    {
        if(nums1[i]<nums2[j])
        {
            ans[index++]=nums1[i++];
        }
        else
        {
            ans[index++]=nums2[j++];
        }
    }
    while(i<m)
    {
        ans[index++]=nums1[i++];
    }
    while(j<n)
    {
        ans[index++]=nums2[j++];
    }
    //nums1.clear();
    //nums1=ans;
    ans.clear();

    //OPTIMAL
    //APPROACH-1
    //TC-O(min(n,m))+O(n log n)+O(m log m)
    //SC-O(1)
    int left=n-1;
    int right=0;
    while(left>=0 && right<m)
    {
        if(nums1[left]>nums2[right])
        {
            swap(nums1[left],nums2[right]);
            left--;
            right++;
        }
        else 
            break;
    }
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());

    //APPROACH-2(gap method)
    //shell sort technique
    //TC-O(log n+m)+O(n+m)
    int len=m+n;
    int gap=(len/2)+(len%2); //gap=ceil(len/2)
    while(gap>0)
    {
        int left=0;
        int right=left+gap;
        while(right<len)
        {
            //arr1 and arr2
            if(left<n && right>=n)
            {
                if(nums1[left]>nums2[right-n])
                    swap(nums1[left],nums2[right-n]);
            }
            //arr2 and arr2
            else if(left>=n)
            {
                if(nums1[left-n]>nums2[right-n])
                    swap(nums1[left-n],nums2[right-n]);
            }
            //arr1 and arr1
            else
            {
                if(nums1[left]>nums2[right])
                    swap(nums1[left],nums2[right]);
            }
            left++;
            right++;
        }
        if(gap==1)
            break;
        gap=(gap/2)+(gap%2); //gap=ceil(gap/2)
    }

    return 0;
}