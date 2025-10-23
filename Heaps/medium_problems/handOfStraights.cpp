#include <bits/stdc++.h>
using namespace std;

bool isNstraightHand(vector<int> &hand,int groupSize)
{
    int n=hand.size();
    if(n%groupSize!=0)
        return false;
    map<int,int> hash;
    for(int i=0;i<n;i++)
        hash[hand[i]]++;
    while(!hash.empty())
    {
        int curr=hash.begin()->first;
        for(int i=0;i<groupSize;i++)
        {
            if(hash[curr+i]==0)
            {
                return false;
            }
            hash[curr+i]--;
            if(hash[curr+i]<1)
                hash.erase(curr+i);
        }
    }
    return true;
}

int main()
{

}