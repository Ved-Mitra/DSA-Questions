#include<bits/stdc++.h>
using namespace std;

/*
Q. array has coordinates of gas stations, place k staions in this array so that max distance between gas stations is minimised 
   stations can be placed at decimals also
*/
int number_of_gas_stations_required(long double distance,vector<int> &arr)
{
    int cnt=0;
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        int number_in_between=((arr[i]-arr[i-1])/distance);
        if((arr[i]-arr[i-1])/distance == number_in_between*distance)
            number_in_between++;
        cnt+=number_in_between;
    }
    return cnt;
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

    cout << " Enter the gas stations: ";
    int k;
    cin >> k;

    //BRUTE
    //TC-O(K*N)
    vector<int> how_many_placed(n-1,0);
    for(int gas=1;gas<=k;gas++)
    {
        long double max_section=-1;
        int max_index=-1;
        for(int i=0;i<n-1;i++)
        {
            long double diff=nums[i+1]-nums[i];
            long double section_length=diff/(how_many_placed[i]+1);
            if(max_section<section_length)
            {
                max_section=section_length;
                max_index=i;
            }
        }
        how_many_placed[max_index]++;
    }
    long double max_ans=-1;
    for(int i=0;i<n-1;i++)
    {
        long double section_length=(long double)(nums[i+1]-nums[i])/(long double)(how_many_placed[i]+1);
        max_ans=max(max_ans,section_length);
    }
    cout << max_ans << endl;


    //BETTER
    //TC-O(K*log N) + O(N*log N)
    //SC-O(N-1)
    priority_queue<pair<long double,int>> pq;
    for(int i=0;i<n-1;i++)
    {
        pq.push({nums[i-1]-nums[i],i});
    }
    for(int gas=1;gas<=k;gas++)
    {
        auto tp=pq.top();
        pq.pop();
        int section_index=tp.second;
        how_many_placed[section_index]++;
        long double initial_diff=nums[section_index+1]-nums[section_index];
        long double new_section=initial_diff/(long double)(how_many_placed[section_index]+1);
        pq.push({new_section,section_index});
    }
    cout << pq.top().first << endl;


    //OPTIMAL
    //TC-O(N*log2 N)
    long double low=0;
    long double high=0;
    for(int i=0;i<n-1;i++)
    {
        high=max(high,(long double)(nums[i+1]-nums[i]));
    }
    long double diff= 1e-6;
    while(high-low>diff)
    {
        long double mid=(low+high)/(2.0);
        int cnt = number_of_gas_stations_required(mid,nums);
        if(cnt>k)
        {
            low=mid;
        }
        else
            high=mid;
    }
    cout << high << endl;

    return 0;
}