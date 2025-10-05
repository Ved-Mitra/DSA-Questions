/*
WAP to print the pattern
   A
  ABA
 ABCBA
ABCDCBA

*/

#include<iostream>
using namespace std;

int main()
{
    for (int i=1;i<=4;i++)
    {
        for(int k=3;k>=i;k--)
            cout << " ";
        for(char j='A';j<=(i+64);j++)
            cout << j;
        for(char j=(i+63);j>='A';j--)
            cout << j;
        cout << endl;
    }
}