#include<bits/stdc++.h>
using namespace std;

/*
Q.
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
    //Merge Sort

    //BETTER
    //hashing
    int hash[3]={0};
    for(int i=0;i<n;i++)
        hash[arr[i]]+=1;
    for(int i=0;i<hash[0];i++)
        arr[i]=0;
    for(int i=0;i<hash[1];i++)
        arr[i+hash[0]]=1;
    for(int i=0;i<hash[2];i++)
        arr[i+hash[0]+hash[1]]=2;
    

    //OPTIMAL
    /*
    (DUTCH NATIONAL FLAG ALGORITHM)
    three pointer (low,mid,high)
    the given array is divided in regions with these pointers
    [0...... low-1]    ---> 0   extreme left
    [low.... mid-1]    ---> 1
  - [mid......high]    ---> random (0/1/2) unsorted
  | [high+1....n-1]    ---> 2 extreme right
  |
  ->arr[mid]=0   : swap low and mid then mid++,low++
    arr[mid]=1   : no swapping, mid++
    arr[mid]=2   : swap mid and high ,then high--
    */
    //TC-O(N)
    //SC-O(1)
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[high],arr[mid]);
            high--;
        }
    }
}