#include<bits/stdc++.h>
using namespace std;

int least_weight_capacity(vector<int> &arr,int capacity)
{
    int days=0;
    int sum=0;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>capacity)
        {
            days++;
            sum=arr[i];
        }
    }
    return days+1;
}

int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    vector<int> weights(n);
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> weights[i];
    cout << "Enter the days: ";
    int days;
    cin >> days;
    
    if(n==0)
        return 0;
    int sum=0;
    int largest=weights[0];
    for(int i=0;i<n;i++)
    {
        sum+=weights[i];
        if(largest<weights[i])
            largest=weights[i];
    }
    int low=largest,high=sum;
    int capacity=sum;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int req_days=least_weight_capacity(weights,mid);
        if(req_days<=days)
        {
            capacity=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }

}