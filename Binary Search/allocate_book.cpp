#include<bits/stdc++.h>
using namespace std;

/*
Q. array-number of pages on n books
   k- number of books
   each student should get atleast one book otherwise return -1
   each book should be allocated to one student 
   book allocation should be in order given 

   you have to allocate books to k students such that maximum of pages assigned to any student is minimised
*/

int pages_distribute(vector<int>& pages,int limit)
{
    int n=pages.size();
    int student=1,pages_Student=0;
    for(int i=0;i<n;i++)
    {
        if(pages_Student+pages[i]<=limit)
            pages_Student+=pages[i];
        else
        {
            pages_Student=pages[i];
            student++;
        }
    }
    return student;
}
int main()
{
    int n;
    cout << "Enter the size of numsay: " ;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the numsay: " << endl;
    for(int i=0;i<n;i++)
        cin >> nums[i];

    cout << " Enter the students: ";
    int k;
    cin >> k;

    if(k>n)
    {
        cout << "NOT POSSIBLE" << endl;
        return 0;
    }    

    int low=*max_element(nums.begin(),nums.end());
    int high=accumulate(nums.begin(),nums.end(),0);

    while(low<=high)
    {
        int mid=(low+high)/2;
        if(pages_distribute(nums,mid)>k)
            low=mid+1;
        else
            high=mid-1;
    }
    cout << low << endl;
    return 0;
}