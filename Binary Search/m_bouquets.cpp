#include<bits/stdc++.h>
using namespace std;
int adjacent_flowers_bloomed(vector<int> &flowers,int day,int k)
{
    int n=flowers.size();
    int adjacent=0;
    int bouquets=0;
    for(int i=0;i<n;i++)
    {
        if(flowers[i]<=day)
            adjacent++;
        else
            adjacent=0;
        if(adjacent==k)
        {
            bouquets++;
            adjacent=0;
        }
    }
    return bouquets;
}
int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    vector<int> bloomDay(n);
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> bloomDay[i];
    cout << "Enter the number of bouquets: ";
    int m;
    cin >> m;

    cout << "Enter k adjacent flowers: ";
    int k;
    cin >> k;

    long long total_flowers=m*(long long)k;
    if(total_flowers>n)
        return -1;
    int largest=bloomDay[0];
    int smallest=bloomDay[0];
    for(int i=0;i<n;i++)
    {
        if(largest<bloomDay[i])
            largest=bloomDay[i];
        if(smallest>bloomDay[i])
            smallest=bloomDay[i];
    }
    int days=1;
    int low=smallest,high=largest;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int bouquets=adjacent_flowers_bloomed(bloomDay,mid,k);
        if(bouquets>=m)
        {
            days=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return days;

}
    