#include<bits/stdc++.h>
using namespace std;

/*given a value V we want to make change of V into {1,2,5,10,20,50,100,500,1000}
return the minimum number of coins needed to make the change
*/

int minChangeValue(int v)
{
    int cnt=0;
    if(v>=1000)
    {
        int quo=v/1000;
        v=v-(quo*1000);
        cnt+=quo;
    }
    if(v>=500)
    {
        int quo=v/500;
        v=v-(quo*500);
        cnt+=quo;
    }
    if(v>=100)
    {
        int quo=v/100;
        v=v-(quo*100);
        cnt+=quo;
    }
    if(v>=50)
    {
        int quo=v/50;
        v=v-(quo*50);
        cnt+=quo;
    }
    if(v>=20)
    {
        int quo=v/20;
        v=v-(quo*20);
        cnt+=quo;
    }
    if(v>=10)
    {
        int quo=v/10;
        v=v-(quo*10);
        cnt+=quo;
    }
    if(v>=5)
    {
        int quo=v/5;
        v=v-(quo*5);
        cnt+=quo;
    }
    if(v>=2)
    {
        int quo=v/2;
        v=v-(quo*2);
        cnt+=quo;
    }
    if(v>=1)
    {
        v=0;
        cnt+=v;
    }
    return cnt;
}

int main()
{
    cout << minChangeValue(49);
}