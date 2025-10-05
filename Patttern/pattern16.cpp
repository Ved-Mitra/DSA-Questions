/*
WAP to print the pattern
    1
   101
  10101
 1010101
101010101
 1010101
  10101
   101
    1

*/

#include<iostream>
using namespace std;

int main()
{
    for (int i=1;i<=5;i++)
    {
        int k;
        for(k=1;k<=(5-i);k++)
            cout << " ";
        for (;k<=4+i;k++)
        {
            if ((i+k)%2==0)
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }
    for (int i=4;i>=1;i--)
    {
        int k;
        for(k=1;k<=(5-i);k++)
            cout << " ";
        for (;k<=4+i;k++)
        {
            if ((i+k)%2==0)
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }
}