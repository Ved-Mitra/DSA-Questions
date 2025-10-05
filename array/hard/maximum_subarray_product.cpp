#include<bits/stdc++.h>
using namespace std;

/*
Q. return the maximum subarray product
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
    
    int max_product=INT_MIN;
    //BRUTE
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int product=1;
            for(int k=i;k<=j;k++)
            {
                product*=nums[k];
            }
            max_product=max(product,max_product);
        }
    }
    cout << max_product << endl;


    //BETTER
    max_product=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int product=1;
        for(int j=0;j<n;j++)
        {
            product*=nums[j];
            max_product=max(product,max_product);
        }
    }
    cout << max_product << endl;

    //OPTIMAL
    //APPROACH-1  --->JAVA
    //APPROACH-2  --->KANADE's 
    //TC-O(N)
    //SC-O(1)
    max_product=INT_MIN;
    int prefix=1,suffix=1;
    for(int i=0;i<n;i++)
    {
        if(prefix==0)
            prefix=1;
        if(suffix==0)
            suffix=1;
        prefix*=nums[i];
        suffix*=nums[n-1-i];
        max_product=max(max_product,max(prefix,suffix));
    }
    cout << max_product << endl;

    return 0;
}