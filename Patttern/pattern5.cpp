/*
WAP to print the pattern
    *
   ***
  *****
 *******
*********

*/

#include<iostream>
using namespace std;

int main()
{
    for (int i=0;i<5;i++)
    {
        for (int k=4;k>i;k--)
            cout << " ";
        for (int j=1;j<=(2*i + 1);j++)
            cout << "*";
        cout << endl;
    }
}