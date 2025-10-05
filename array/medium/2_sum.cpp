#include<bits/stdc++.h>
using namespace std;
/*
Q. array has element that constitute the sum return the elements
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
    cout << "Enter the sum: " << endl;
    int sum;
    cin >> sum;
    int i,j;

    //BRUTE
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==sum)
                break;
        }
    }
    cout << arr[i] << " " << arr[j] << endl;


    //BETTER
    map<int,int> hash;
    for(i=0;i<n;i++)
        hash[arr[i]]+=1;
    for(i=0;i<n;i++)
    {
        int n1=arr[i];
        int n2=sum-n1;
        if(hash.find(n2)!=hash.end())
            break;
    }
    cout << arr[i] << " " << sum-arr[i] << endl;


    //OPTIMAL
    sort(arr,arr+n);
    int left=0,right=n-1;
    while(left<right)
    {
        int sum_now=arr[left]+arr[right];
        if(sum_now<sum)
            left++;
        else if(sum_now>sum)
            right--;
        else
            break;
    }
    cout << arr[left] << " " << arr[right] << endl;

    return 0;
}