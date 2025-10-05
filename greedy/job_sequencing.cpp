#include<bits/stdc++.h>
using namespace std;

/*you are given n size 3 array JobID , deadline , profit
you can only perform one job on one day

ID      deadline    profit
1       4           40
2       1           10
3       1           40
4       1           20

max=80
day1--jobID 3
day2--jobID 1
day3--jobID 1
day4--jobID 1

return the jobs done and maximum profit*/


struct job
{
    int id;
    int deadline;
    int profit;
};

bool comp(job w1,job w2)
{
    if(w1.profit>w2.profit)
        return true;
    else if(w1.profit==w2.profit)
    {
        if(w1.deadline<=w2.deadline)
            return true;
        return false;
    }
    return false;
}
vector<int> maxProfit(vector<job> &work)
{
    sort(work.begin(),work.end(),comp);
    int maxDeadline=work[0].deadline;
    int n=work.size();
    for(int i=1;i<n;i++)
        maxDeadline=max(maxDeadline,work[i].deadline);
    vector<int> days(maxDeadline+1,-1);
    int profit=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int i=work[i].deadline;i>=0;i--)
            if(days[i]==-1)
            {
                cnt++;
                days[i]=work[i].id;
                profit+=work[i].profit;
                break;
            }
    }
    return {cnt,profit};
}

int main()
{
    
}