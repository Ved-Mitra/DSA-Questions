#include<bits/stdc++.h>
using namespace std;

/*
Q. return the max profit from the array chose a sell day and a buy day for stock, buy day should be before sell day
*/

int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int profit=0,cost=0;
    int minn=arr[0];
    for(int i=0;i<n;i++)
    {
        cost=arr[i]-minn;
        profit=max(profit,cost);
        minn=min(arr[i],minn);
    }
    cout << profit << endl;
    return 0;
}