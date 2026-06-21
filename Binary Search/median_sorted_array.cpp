#include<bits/stdc++.h>
using namespace std;

/*
Q. areturn the median of merged sorted array
*/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int n1=nums1.size();
    int n2=nums2.size();
    if(n1>n2)
        return findMedianSortedArrays(nums2,nums1);

    int low=0,high=n1;
    int n=(n1+n2+1)/2;
    while(low<=high)
    {
        int cut1=(low+high)/2;
        int cut2= n-cut1;
        int l1 = cut1-1<0 ? INT_MIN : nums1[cut1-1];
        int l2 = cut2-1<0 ? INT_MIN : nums2[cut2-1];
        int r1 = cut1>=n1 ? INT_MAX : nums1[cut1];
        int r2 = cut2>=n2 ? INT_MAX : nums2[cut2];
        if(l1>r2)
        {
            high=cut1-1;
        }
        else if(l2>r1)
        {
            low=cut1+1;
        }
        else
        {
            if((n1+n2)%2==0)
                return (max(l1,l2) + min(r1,r2))/2.0;
            else
                return max(l1,l2);
        }
    }
    return -1;
}

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
    

    cout << findMedianSortedArrays(nums1,nums2) << '\n';
}
