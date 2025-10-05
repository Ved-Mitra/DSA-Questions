#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> nums[i];
    cout << "Enter the element: ";
    int x;
    cin >> x;

}

//given a number n the array has elements from 1 to n give the missing number and the repeating number

vector<int> missingRepeatingElement(vector<int> &nums,int n)
{
    int repeat=-1,missing=-1;

    //BETTER
    //TC-O(n)
    //SC-O(n)
    vector<int> hash(n);
    for(int i=0;i<n;i++)
    {
        hash[nums[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(hash[i]==0)
            missing=i;
        else if(hash[i]>1)
            repeat=i;
    }
    return {repeat,missing};


    
    //OPTIMAL-1
    //TC-O(n)
    //SC-O(1)
    int sum1=n*(n+1)/2,sum2=0,sum_sq=0;
    for(int i=0;i<n;i++)
    {
        sum2+=nums[i];
        sum_sq+=(nums[i]*nums[i]);
    }
    int x=sum2-sum1; //x=repeat-missing
    
    int y= sum_sq - (sum1*sum1); //y=repeat^2 - missing^2

    int z=y/x; //z=repeat+missing

    repeat=(x+z)/2;
    missing=z-repeat;
    return {repeat,missing};




    //OPTIMAL-2
    int XOR=0;
    for(int i=0;i<n;i++)
    {
        XOR^=nums[i];  //missing^repeat
        XOR^=(i+1);
    }
    //two different numbers are bound to differ at minimum one bit
    //take the rightmost different bit
    //now the XOR at that bit can be either 1 or 0
    //divide the combined array into two parts i.e. rightmost diffrent bit is 0 or 1
    //NOW all numbers appear twice except missing-once, repeating-thrice on combining the given array and the complete array

    int bitNo=0;
    while(1)
    {
        if(XOR & (1<<bitNo))
            break;
        bitNo++;
    }//instead of the while loop we can write number= XOR & ~(XOR-1)
    //number=(1<<bitNo)
    int xr1=0,xr2=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i] & (1<<bitNo))//bit is 1
        {
            xr1^=nums[i];
        }
        else//bit is 0
        {
            xr2^=nums[i];
        }
        if((i+1) & (1<<bitNo))
        {
            xr1^=(i+1);
        }
        else
        {
            xr2^=(i+1);
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==xr1)
            cnt++;
    }
    if(cnt==2)
    {
        repeat=xr1;
        missing=xr2;
    }
    else
    {
        repeat=xr2;
        missing=xr1;
    }
    return {repeat,missing};
}