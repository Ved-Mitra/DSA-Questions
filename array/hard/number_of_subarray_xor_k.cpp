#include<bits/stdc++.h>
using namespace std;

/*
Q. return the number of subarray which will give XOR as k.
*/

int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    int nums[n];
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> nums[i];
    int k;
    cout << "Enter the sum: " ;
    cin >> k;


    int count=0;
    //BRUTE
    //TC-O(N^3)
    //SC-O(1)
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum=0;
            for(int l=i;l<=j;l++)
            {
                sum=sum^nums[l];
            }
            if(sum==k)
                count++;
        }
    }
    cout << count << endl;

    //BETTER
    //TC-O(N^2)
    //SC-O(1)
    count=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum^=nums[j];
            if(sum==k)
                count++;
        }
    }
    cout << count << endl;

    //OPTIMAL
    //focusing---->ending point of subarray
    //TC-O(N log N)
    //SC-O(N)
    count=0;
    map<int,int> hash;
    hash[0]=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum^=nums[i];
        int rem=sum^k;
        count+=hash[rem];
        hash[rem]++;
    }
    cout << count << endl;
}