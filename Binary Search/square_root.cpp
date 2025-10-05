#include<bits/stdc++.h>
using namespace std;

//return floor of square of number

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
    
    int low=1,high=n;
    int ans=1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(mid*mid<=n)
        {
            ans=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }
        cout << ans << endl;
}