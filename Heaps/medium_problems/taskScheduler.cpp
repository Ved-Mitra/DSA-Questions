#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char> &tasks,int n)
{
    int m=tasks.size();
    vector<int> freq(26,0);
    for(int i=0;i<m;i++)
        freq[tasks[i]-'A']++;

    //METHOD-1
    //TC-O(n*log n)
    //SC-O(n)    
    priority_queue<int> pq;
    for(int i=0;i<26;i++)
        if(freq[i]>0)
            pq.push(freq[i]);

    int time=0;
    while(!pq.empty())
    {
        int cycle=n+1;
        vector<int> store;
        int taskCount=0;
        while(cycle-- && !pq.empty())
        {
            if(pq.top()>1)
                store.push_back(pq.top()-1);
            pq.pop();
            taskCount++;
        }

        for(int &x:store)
            pq.push(x);

        time+=(pq.empty()? taskCount:n+1);
    }
    return time;


    //METHOD-2
    //TC-O(n)
    //SC-O(26)
    sort(freq.begin(),freq.end());
    int maxFreq=freq[25]-1;
    int idleSlots=maxFreq*n;
    for(int i=24;i>=0 && freq[i]>0;i--)
    {
        idleSlots-=(min(maxFreq,freq[i]));
    }
    return idleSlots>0?m+idleSlots:m;
}



int main()
{

}