#include<bits/stdc++.h>
using namespace std;

/*We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.*/

vector<int> asteroidCollision(vector<int> &asteroids)
{
    //OPTIMAL--ME
    //TC-O(4n)
    //SC-O(n)
    int n=asteroids.size();
    stack<int> st;
    vector<int> ans;
    int i=0;
    while(i<n)//O(n)
    {
        if(asteroids[i]<0)
        {
            int size=-1*asteroids[i];
            while(!st.empty() && size>st.top() && st.top()>0)//O(n)
            {
                st.pop();
            }
            if(st.empty() || st.top()<0)
                st.push(asteroids[i]);
            if(st.top()==size)
                st.pop();
        }
        else
            st.push(asteroids[i]);
        i++;
    }
    while(!st.empty())//O(n)
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());//O(n)
    return ans;


    //OPTIMAL--STRIVER
    //TC-O(2n)
    //SC-O(n)
    vector<int> ans2;
    for(int i=0;i<n;i++)
    {
        if(asteroids[i]>0)
            ans2.push_back(asteroids[i]);
        else
        {
            while(!ans2.empty() && ans2.back()>0 && ans2.back()<abs(asteroids[i]))
            {
                ans2.pop_back();
            }
            if(!ans2.empty() && ans2.back()==asteroids[i])
                ans2.pop_back();
            else if(ans2.empty() || ans2.back()<0)
                ans2.push_back(asteroids[i]);

        }
    }
    return ans2;
}

int main()
{

}