#include<bits/stdc++.h>
using namespace std;

/*
Q. the array has half positive and half negative numbers, return array with alternative positive and negative elements such that relative order remains same.(array has even elements)
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
    
    //BRUTE
    //create two arrays with +ve and -ve elements

    //OPTIMAL
    vector<int> ans(n,0);
    int positive=0,negative=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            ans[negative]=arr[i];
            negative+=2;
        }
        else
        {
            ans[positive]=arr[i];
            positive+=2;
        }
    }
    for(auto it:ans)
        cout << it << " ";
    cout <<  endl;
    return 0;
}