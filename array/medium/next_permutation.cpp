#include<bits/stdc++.h>
using namespace std;

/*
Q. Find the next permutation(next permutation after arranging all permutation in ascending order) of inputed array
*/

int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    vector<int> arr(n,0);
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    //BRUTE
    //1.Generate all permutation
    //2.Linear search
    //3.Next permutation

    //BETTER
    next_permutation(arr.begin(),arr.end());//SDL
    for(int i=0;i<n;i++)
        cout << arr[i];

    //OPTIMAL
    /*
    1. find last breakpoint i.e. arr[i]<arr[i+1]
    2. find element in region i+1-->n such that arr[j]>arr[i] but it is smallest in the given region (swap smallest with arr[i])
    3. Try to placing the rest in ascending order
    */
    //TC-O(N)
    //SC-O(1)
    int index=-1;
    //1.
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])
        {
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        reverse(arr.begin(),arr.end());
        for(auto it:arr)
            cout << it << " ";
        cout << endl;
    }
    //2.
    for(int i=n-1;i>index;i--)
    {
        if(arr[i]>arr[index])
        {
            swap(arr[i],arr[index]);
            break;
        }
    }
    //3.
    reverse(arr.begin()+index+1,arr.end());

}