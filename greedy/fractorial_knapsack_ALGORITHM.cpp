#include<bits/stdc++.h>
using namespace std;

/*You are given an array containing a pair of integers {value,weight} and an integer W which shows the maximum weight the bag can hold you have to maximise the value of weights the bag can hold

Example:
arr=[(100,20),(60,10),(100,50),(200,50)] , W = 90

Answer: 380

Solution:
now the bag has: (100,20) , (60,10) , (100,50)
W=     90           70         60        10

Bag can hold now only 10 weight now taking fraction of weight from (200,50)
50 --- 200
1  ---   4
10 ---  40
now the bag has: (100,20) , (60,10) , (100,50) , (40,10)
W=     90           70         60        10         0

total = 300 (wrong)

CORRECT : (100,20) , (60,10) , (200,50) , (20,10)

*/

int maxWeight(vector<pair<int,int>> &weight, int w)
{
    int n=weight.size();
    vector<int> ratio(n);
    for(int i=0;i<n;i++)//value:weight ratio
        ratio[i]=weight[i].first/weight[i].second;
    sort(ratio.begin(),ratio.end());
    int value=0;
    for(int i=n-1;i>=0 && w>0;i--)
    {
        if(w<weight[i].second)
        {
            value+=(w*(weight[i].second/weight[i].first));
            w=0;
        }
        else
        {
            w-=weight[i].second;
            value+=weight[i].first;
        }
    }
    return value;
}


int main()
{

}