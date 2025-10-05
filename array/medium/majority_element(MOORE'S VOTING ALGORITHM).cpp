#include<bits/stdc++.h>
using namespace std;
/*
Q. find the element that appears more than n/2 times
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
    //count variable

    //BETTER
    //HASHING

    //OPTIMAL
    //MOORE'S VOTING ALGORITHM
    int count=0,element=arr[0];
    for(int i=0;i<n;i++)
    {
        if(count==0)
        {
            count=1;
            element=arr[i];
        }
        else if(arr[i]==element)
            count++;
        else
            count--;
    }
    count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element)
            count++;
    }
    if(count>n/2)
        cout << element << endl;
    else
        cout << "No such element exists" << endl;
}