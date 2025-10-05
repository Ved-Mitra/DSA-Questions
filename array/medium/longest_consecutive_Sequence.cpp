#include<bits/stdc++.h>
using namespace std;

/*
Q. give the longest consecutive sequence
*/

bool linear_search(int arr[],int n,int num)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
            return true;
    }
    return false;
}
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
    //TC-O(N^2)
    //SC-O(1)
    int longest=1;
    for(int i=0;i<n;i++)
    {
        int x=arr[i];
        int count=1;
        while(linear_search(arr,n,x+1))
        {
            x+=1;
            count++;
        }
        longest=max(longest,count);
    }
    cout << longest << endl;


    //BETTER
    sort(arr,arr+n);
    int last_smaller=INT_MIN;
    int count_current=0;
    longest=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==last_smaller-1)
        {
            count_current++;
            last_smaller=arr[i];
        }
        else if(arr[i]!=last_smaller)
        {
            count_current=1;
            last_smaller=arr[i];
        }
        longest=max(longest,count_current);
    }
    cout << longest << endl;


    //OPTIMAL
    //TC-O(N)
    //SC-O(N)
    unordered_set<int> set;
    for(int i=0;i<n;i++)
        set.insert(arr[i]);
    longest=1;
    for(auto it:set)
    {
        if(set.find(it-1)==set.end())
        {
            int count=1;
            int x=it;
            while(set.find(x+1)!=set.end())
            {
                x++;
                count++;
            }
            longest=max(longest,count);
        }
    }
    cout << longest << endl;
}