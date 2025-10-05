#include<bits/stdc++.h>
using namespace std;

//return floor of square of number


int func(int mid,int n,int m)
{
    //return 1 if ==n
    //reutrn 0 if < n
    //return 2 if > n
    long long ans=1;
    for(int i=1;i<=n;i++)
    {
        ans*=mid;
        if(ans>m)
            return 2;
    }
    if(ans==m)
        return 1;
    return 0;
}
int main()
{
    /*
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> nums[i];*/
    cout << "Enter the number: ";
    int n;
    cin >> n;
    
    cout << " enter the root: ";
    int root;
    cin >> root;

    int low=1,high=n;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int midN=func(mid,root,n);
        if(midN==n)
            ans=mid;
        else if (midN==0)
            low=mid+1;
        else  
            high=mid-1;
    }

    cout << ans << endl;
}