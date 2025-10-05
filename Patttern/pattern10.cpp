/*
WAP to print the pattern
1      1
12    21
123  321
12344321

*/

#include<iostream>
using namespace std;

int main()
{
    for (int i=1;i<=4;i++)
    {
        for (int j=1;j<=i;j++)
            cout << j;
        for (int k=6-2*(i-1);k>=1;k--)
            cout << " ";
        for (int j=i;j>=1;j--)
            cout << j;
        cout << endl;
    }
}