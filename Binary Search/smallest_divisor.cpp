#include<bits/stdc++.h>
using namespace std;

int result(vector<int> &arr,int divisor)
{
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=ceil((double)arr[i]/(double)divisor);
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> nums[i];
    cout << "Enter the threshold: ";
    int threshold;
    cin >> threshold;
    int largest=nums[0];
    for(int i=0;i<n;i++)
        if(largest<nums[i])
            largest=nums[i];
    int low=1,high=largest;
    int divisor=0;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int sum=result(nums,mid);
        if(sum>threshold)
            low=mid+1;
        else
        {
            divisor=mid;
            high=mid-1;
        }
    }
    cout << divisor << endl;

}
    