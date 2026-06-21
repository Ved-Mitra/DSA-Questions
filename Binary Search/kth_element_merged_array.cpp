#include<bits/stdc++.h>
using namespace std;

/*
Q. return the kth of merged sorted array
*/
int kthElement(vector<int> &a, vector<int> &b, int k) 
{
        // code here
    int n1=a.size();
    int n2=b.size();
    if(n1>n2)
        return kthElement(b,a,k);

    int low = max(0, k - n2);
    int high = min(k, n1);
    
    while(low<=high)
    {
        int cut1=(low+high)/2;
        int cut2= k-cut1;
        int l1 = cut1-1<0 ? INT_MIN : a[cut1-1];
        int l2 = cut2-1<0 ? INT_MIN : b[cut2-1];
        int r1 = cut1>=n1 ? INT_MAX : a[cut1];
        int r2 = cut2>=n2 ? INT_MAX : b[cut2];
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
    int k;
    cout << "Enter the kth position: " << endl;
    cin >> k;

    cout << kthElement(nums1,nums2) << '\n';
}
