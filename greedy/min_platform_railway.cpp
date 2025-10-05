#include<bits/stdc++.h>
using namespace std;

/*you are given n trains with arrival time and departure time,
return the minimum number of platform required

900 -- 9:00
time in 24hr format
*/

int minimumNumberOfPlatform(vector<int> &arrival,vector<int> &departure)
{
    //OPTIMAL-ME
    int n=arrival.size();
    vector<pair<int,int>> train(n);
    for(int i=0;i<n;i++)
    {
        train[i]={arrival[i],departure[i]};
    }
    sort(train.begin(),train.end());
    int platform=0;
    priority_queue<int,vector<int>,greater<int>> pq;//min heap
    for(int i=0;i<n;i++)
    {
        while(!pq.empty() && pq.top()<=train[i].first)
        {
            pq.pop();
        }
        pq.push(train[i].second);
        platform=max(platform,(int)pq.size());
    }
    return platform;

    //OPTIMAL-STRIVER
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int plat_needed = 0, max_platforms = 0;
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        // If next train arrives before the current one departs,
        // need a new platform
        if (arrival[i] <= departure[j])
        {
            plat_needed++;
            i++;
        }
        else
        {
            // A train has departed, free a platform
            plat_needed--;
            j++;
        }
        max_platforms = max(max_platforms, plat_needed);
    }
    return max_platforms;
}


int main()
{

}