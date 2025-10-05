#include<bits/stdc++.h>
using namespace std;

void largest(int arr[],int n)
{
    int largest=arr[0];
    for(int i=0;i<n;i++)
    {
        if(largest<arr[i])
        {
            largest=arr[i];
        }
    }
    cout << "Largest element is: " << largest << endl;
    return;
}
void second_largest(int arr[],int n)
{
    int largest=arr[0];
    for(int i=0;i<n;i++)
    {
        if(largest<arr[i])
        {
            largest=arr[i];
        }
    }
    int slargest;
    //just assigning value to slargest
    for(int i=0;i<n;i++)
        if(largest!=arr[i])
        {
            slargest=arr[i];
            break;
        }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>slargest && arr[i]!=largest)
        {
            slargest=arr[i];
        }
    }
    cout << "second largest element is: " << slargest << endl;
}
void second_Smallest(int arr[],int n)
{
    int smallest=arr[0];
    for(int i=0;i<n;i++)
    {
        if(smallest>arr[i])
        {
            smallest=arr[i];
        }
    }
    int ssmallest;
    //just assigning value to slargest
    for(int i=0;i<n;i++)
        if(smallest!=arr[i])
        {
            ssmallest=arr[i];
            break;
        }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>ssmallest && arr[i]!=smallest)
        {
            ssmallest=arr[i];
        }
    }
    cout << "second smallest element is: " << ssmallest << endl;
}
void check_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=arr[i+1])//taking sorted to be in ascending order
        {}
        else
        {
            cout << "False";
            return;
        }
    }
    cout << "True";
    return;
}
void remove_duplicates(int arr[],int n)//from sorted array
{
    //Method-1 use set (unique and sorted)
    //method-2
    int i=0;
    for(int j=0;j<n;j++)
    {
        if(arr[i] != arr[j])
        {
            arr[i+1]=arr[j];
            i++;
        }
    }
}
void rotate_array_left(int arr[] , int n)
{
    int x;
    cout << "Enter the position to shift the array : ";
    cin >> x;
    x=x%n;
    for(int i=0;i<x;i++)
    {
        int temp=arr[0];
        for(int j=0;j<n-1;j++)
        {
            arr[j]=arr[j+1];
        }
        arr[n-1]=temp;
    }
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    return;

    /*
    METHOD-2
    TC-O(N)
    SC-O(N)
    int temp[x];
    for(int i=0;i<x;i++)
        temp[i]=arr[i];
    for(int i=x;i<n;i++)
        arr[i-x]=arr[i];
    for(int i=0;i<x;i++)
        arr[n-x+i]=temp[i];
    */

    /*
    METHOD-3
    TC-O(N)
    SC_O(1)
    reverse(arr,arr+x); //TC-O(x)
    reverse(arr+x,arr+n); //TC-O(N-x)
    reverse(arr,arr+n); //TC-O(N)
    */
}
void rotate_array_right(int arr[], int n)
{
    int k,x;
    cout << "Enter the position to shift the array : ";
    cin >> k;
    x=k%n;
    for(int i=0;i<x;i++)
    {
        int temp=arr[n-1];
        for(int j=n-1;j>0;j--)
        {
            arr[j]=arr[j-1];
        }
        arr[0]=temp;
    }
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    return;
}
void move_zeroes(int arr[],int n)
{
    /*
    //METHOD-1(BRUTE)
    TC-O(N)
    SC-O(N)
    int number_of_zeroes=0,index=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
            number_of_zeroes++;
        else
        {
            arr[index]=arr[i];
            index++;
        }
    }
    for(int i=n-1;i>=0 && number_of_zeroes>0;i--,number_of_zeroes--)
    {
        arr[i]=0;
    }
    */

    //METHOD-2
    int j=-1; 
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[j],arr[i]);
            j++;
        }
    }
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    return;
}
void linear_search(int arr[],int n)
{
    int number;
    cout << "Enter the number to be searched: ";
    cin >> number;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==number)
        {
            cout << "found at " << i << endl;
            return;
        }
    }
    cout << "not found" << endl;
    return;
}
void union_sorted_array(int arr1[],int arr2[],int n1, int n2)
{
    /*
    TC-O(n1+n2)
    SC-O(n1+n2)
    */
    int i=0,j=0;
    vector<int> union_array;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            if(union_array.size()==0 || union_array.back()!=arr1[i])
                union_array.push_back(arr1[i]);
            i++;
        }
        else
        {
            if(union_array.size()==0 || union_array.back()!=arr2[j])
                union_array.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n1)
    {
        if(union_array.size()==0 || union_array.back()!=arr1[i])
            union_array.push_back(arr1[i]);
        i++;
    }
    while(j<n2)
    {
        if(union_array.size()==0 || union_array.back()!=arr2[j])
             union_array.push_back(arr2[j]);
        j++;
    }
    for(auto it:union_array)
        cout << it << " ";
    return;
}
void intersection_sorted_array(int arr1[],int arr2[], int n1, int n2)
{
    /*
    //METHOD-1(BRUTE)
    vector<int> intersection_array;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(arr1[i]==arr2[j])
            {
                intersection_array.push_back(arr1[i]);
            }
            if(arr1[i]<arr2[j])
                break;
        }
    }
    for(auto it:intersection_array)
        cout << it << " ";
    */

    //METHOD-2(OPTIMAL)
    int i=0,j=0;
    vector<int> intersection_array;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
            i++;
        else if(arr2[j]<arr1[i])
            j++;
        else
        {
            intersection_array.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    for(auto it:intersection_array)
        cout << it << " ";
    return;
}
void missing_number(int arr[],int n)
{
    //array is sorted
    int limit;
    cout << "Enter the limit N of number: ";
    cin >> limit;
    /*
    //METHOD-1(BETTER)
    TC-O(N)
    SC-O(N)
    int hash[n+1]={0};
    for(int i=0;i<n;i++)
        hash[arr[i]]+=1;
    for(int i=1;i<limit;i++)
        if(hash[i]==0)
            cout << "The missing elements is: " << i+1 << endl;
    */

    //METHOD-3(OPTIMAL)(sum method)
    //TC-O(N)
    //SC-O(1)
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    int sum_of_n_numbers=limit*(limit+1)/2;
    cout << "The missing elements is: " << sum_of_n_numbers-sum << endl;

    //METHOD-4(OPTIMAL)(XOR)
    //0^1=1
    //1^1=0
    int xor1=0,xor2=0;
    for(int i=0;i<n;i++)
    {
        xor1^=(i+1);
        xor2^=arr[i];
    }
    xor1^=(n+1);
    int answer=xor1^xor2;
    cout << "The missing elements is: " << answer<< endl;
    return;
}
void max_consecutive_ones(int arr[], int n)//{1,0,1,1,1,0,1}
{
    int count=0,max_consecutive=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
            count++;
        else
            count=0;
        if(count>max_consecutive)
            max_consecutive=count;
    }
    cout << "Maximum consecutive 1's : " << max_consecutive << endl;
    return;
}
void number_appears_once(int arr[],int n)
{
    //arr is sorted
    //only one element appears once all appear twice
    //BETTER SOLUTION --- MAP HASHING map<long long,int>mpp
    //METHOD-BETTER
    /*
    TC-O(N log M)+O(N/2 + 1)
    */
    map<long long,int> mpp;
    for(int i=0;i<n;i++)//TC-O(N log M), M=N/2 + 1
        mpp[arr[i]]++;
    for(auto it:mpp)//TC-O(N/2 +1)
    {
        if(it.second==1)
        {
            cout << it.first;
            break;
        }
    }

    //METHOD-OPTIMAL(XOR)
    /*
    TC-O(N)
    */
    int XOR=0;
    for(int i=0;i<n;i++)
    {
        XOR^=arr[i];
    }
    cout << XOR;
    return;
}

int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    rotate_array_right(arr,n);
    return 0;
}