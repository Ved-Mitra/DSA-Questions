#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
    private:
        priority_queue<int,vector<int>,greater<int>> right;
        priority_queue<int> left;
public:
    MedianFinder()
    {

    }
    
    void addNum(int num)
    {
        if(left.empty())
        {
            left.push(num);
            return;
        }
        if(num>left.top())
            right.push(num);
        else
            left.push(num);
        if(right.size()>left.size())
        {
            left.push(right.top());
            right.pop();
        }
        else if(left.size()>right.size()+1)
        {
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian()
    {
        if(left.size()==right.size())
        {
            double ans=((double)left.top()+right.top())/2.0;
            return ans;
        }
        return left.top();
    }
};




int main()
{

}