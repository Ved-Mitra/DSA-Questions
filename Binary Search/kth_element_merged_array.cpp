#include<bits/stdc++.h>
using namespace std;

/*
Q. return the kth of merged sorted array
*/
int main()
{
    int n1,n2;
    cout << "Enter the size of nums 1 and 2 array: " ;
    cin >> n1 >> n2;
    vector<int> nums1(n1);
    vector<int> nums2(n2);
    cout << "Enter the elements of the nums1 array: " << endl;
    for(int i=0;i<n1;i++)
        cin >> nums1[i];
    cout << "Enter the elements of the nums2 array: " << endl;
    for(int i=0;i<n2;i++)
        cin >> nums2[i];
    int k;
    cout << "Enter the kth position: " << endl;
    cin >> k;
    
    int low=max(0,k-n2),high=min(k,n1);
    int left=k;
    int n=n1+n2;
    if(n2>n1)
    {
        swap(nums1,nums2);
    }
    while(low<=high)
    {
        int mid1=(low+high)/2;
        int mid2=left-mid1;
        int l1=INT_MIN, l2=INT_MIN;
        int r1=INT_MAX, r2=INT_MAX;
        if(mid1<n1)
            r1=nums1[mid1];
        if(mid2<n2)
            r2=nums2[mid2];
        if(mid1-1 >=0)
            l1=nums1[mid1-1];
        if(mid2-1>=0)
            l2=nums2[mid2-1];
        if(l1<=r2 && l2<=r1)
        {
            return max(l1,l2);
        }
        else if(l1>r2)
                high=mid1-1;
        else
            low=mid1+1;
    }
    
    return 0;
}