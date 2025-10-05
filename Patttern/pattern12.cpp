/*
WAP to print the pattern
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********

*/

#include<iostream>
using namespace std;

int main()
{
    for (int i=5;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
            cout << "*";
        for(int k=0;k<2*(5-i);k++)
            cout << " ";
        for(int j=1;j<=i;j++)
            cout << "*";
        cout << endl;
    }
    for (int i=1;i<=5;i++)
    {
        for(int j=1;j<=i;j++)
            cout << "*";
        for(int k=0;k<2*(5-i);k++)
            cout << " ";
        for(int j=1;j<=i;j++)
            cout << "*";
        cout << endl;
    }
}