#include<bits/stdc++.h>
using namespace std;

/*
Q. every element on the right should be smaller
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

    vector<int> ans;
    //BRUTE
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]<arr[j])
            {
                count=1;
                break;
            }
        }
        if(!count)
            ans.push_back(arr[i]);
    }
    for(auto it:ans)
        cout << it << " ";
    cout << endl;
    ans.clear();

    //OPTIMAL
    int maxx=INT_MIN;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]>maxx)
            ans.push_back(arr[i]);
        maxx=max(maxx,arr[i]);
    }
    for(auto it:ans)
        cout << it << " ";
    cout << endl;
    ans.clear();
}