#include<bits/stdc++.h>
using namespace std;

void explainPair()
{
    pair<int,int> p1={1,3};
    pair<int,double> p2={1,3.0};

    cout<<p1.first<<" "<<p1.second << endl;

    pair<int,pair<int,int>> p3={1,{2,3}};
    cout << p3.first << " " << p3.second.second << " "<< p3.second.first << endl;

    pair<int,int> arr[]={{1,2}, {3,4}, {5,6}};
    cout << arr[1].second << endl;
}
void explainVector() //similar to array but dynamic in nature
{
    vector<int> v1; //create an empty container v={}

    v1.push_back(1); //v={1}
    v1.emplace_back(2); //v={1,2}, faster than push_back 

    vector<pair<int,int>> v2;

    v2.push_back({1,2});
    v2.emplace_back(1,2);

    vector<int> v3{5,100}; //create a container as of 5 elements as 100 {100,100,100,100,100}
    v3.push_back(1); // {100,100,100,100,100,1}

    vector<int> v4(5); //create a container of 5 elements with no value (0 or garbage value, depends on compiler)

    vector<int> v5(v3); //copy the container v3 into v5
    
    //accessing a vector
    vector<int> v6={20,10,5,4,6};
    //M-1
    cout << v6[0] <<" " << v6.at(0);
    cout << v6.back() << " "; //access the element at back
    //M-2 (iterator)
    vector<int>::iterator it = v6.begin();//iterator points at memory address
    it++;
    cout << *(it) << " "; //v6[1]
    it+=2;
    cout << *(it) << " "; //v6[3]
    vector<int>::iterator it=v6.end(); //points at end memory address v6[5] i.e. memory address just next to size of vector container
    /*NEVER USED*/vector<int>::iterator it=v6.rend(); //reverse-end: points at memory address just before v6[0]
    /*NEVER USED*/vector<int>::iterator it=v6.rbegin(); //reverse-begin: points at v6[4] i.e. at the last element position, but if i do it++ it will point to v6[3]

    //loops
    for(vector<int>::iterator it=v6.begin();it!=v6.end();it++)
        cout << *(it) << " ";
    cout<< endl;
    for(auto it=v6.begin();it!=v6.end();it++) //auto: automatically assign a vector iterator according to the data type
        cout << *(it) << " ";
    cout<< endl;
    for(auto it:v6) //Automatically iterates (not a vector iterator)
        cout << it <<" ";

    //Vector operation
    vector<int> v7={1,2,3,4,5,6,7};
    //erase function
    /*erase: 1.either give memory address to be erased
             2.either use iterator*/
    v7.erase(v7.begin()+1); //v7={1,3,4,5,6,7}
    v7.erase(v7.begin()+2,v7.begin()+4); //starts from v7[3] erases till v7[5](excluding the end element), v7={1,3,6,7}
    
    //Insert function (takes very much time i.e. COSTLIER TO USE)
    vector<int> v8(2,100); //v8={100,100}
    v8.insert(v8.begin(),300); //v8={300,100,100}
    v8.insert(v8.begin()+1,2,10); //v8={300,10,10,100,100}, insert two 100 elements

    //Copying function
    vector<int> copy(2,50); //copy={50,50}
    v8.insert(v8.begin(),copy.begin(),copy.end()); //v8={50,50,300,10,10,100,100}

    //Size of vector
    cout << v8.size(); // 7

    //remove last element
    v8.pop_back();//removes/pops out the last element v8={50,50,300,10,10,100}

    //swap vectors
    vector<int>v9(2,100);
    vector<int>v10(3,50);
    v9.swap(v10); //v9={50,50,50}  v10={100,100}

    //erase the entire vector
    v9.clear(); //v9={}

    //checks wthether the vector is empty or not
    cout << v9.empty(); //returns boolean value, here True
}
void explainList()
{
    list<int> l1;
    l1.push_back(2); //l1={2}
    l1.emplace_back(4); //l1={2,4}
    l1.push_front(5); //l1={5,2,4} very cheap in terms of time complexity
    l1.emplace_front(6); //l1={6,5,2,4}

    //rest functions are same as vectors
    //begin,end,rbegin,clear,insert,size,swap

    for(auto it:l1)
        cout << it <<" ";
}
void explainDeque()
{
    deque<int>dq;
    dq.push_back(1); // {1}
    dq.emplace_back(2); // {1,2}
    dq.push_front(0); // {0,1,2}
    dq.emplace_front(3); // {3,0,1,2}

    dq.pop_front(); // {0,1,2}
    dq.pop_back(); // {0,1}

    dq.back(); //access element at back
    dq.front();

    //rest functions are same as vectors
    //begin,end,rbegin,clear,insert,size,swap

    for(auto it:dq)
        cout << it <<" ";
}
void explainStack() // LIFO- last in first out
{
    //Generic three functions i.e. most used (push,top,pop)
    //All functions are of Time complexity O(1)
    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {2,1}
    st.push(3);
    st.push(3); // {3,3,2,1}
    st.emplace(5); // {5,3,3,2,1}
    int l=st.size();

    cout << st.top(); //prints 5 "** st[2] is INVALID"

    st.pop(); // removes first element, st looks like {3,3,2,1}

    cout << st.top(); // 3
    cout << st.size(); // 4
    cout << st.empty() ; // False

    stack<int> st1,st2; // swapping
    st1.swap(st2);
}
void explainQueue() // FIFO- first in first out
{
    queue<int> q;
    q.push(1); // {1}
    q.push(2); /// {1,2}
    q.emplace(4); // {1,2,4}
    int l=q.size();

    q.back()+=5; // {1,2,9}
    cout << q.back(); // prints 9
    cout << q.front(); //prints 1

    q.pop(); // {2,9}
    cout << q.front(); // prints 2
    //size,swap and empty same as stack
}
void explainPriority() // elements are arranged in descending order according to lexographically (ASCII code)
{
    //Data is not stored linearly but in order but shown as stored in descending order
    //MAXIMUM HEAP
    priority_queue<int> pq;

    /*Time complexity of functions
    push() : O(log N)
    top():   O(1)
    pop():   O(log N)
    */
    pq.push(5); // {5}
    pq.push(2); // {2,5}
    pq.push(10); // {10,5,2}
    pq.emplace(8); // {10,8,5,2}

    cout << pq.top(); // prints 10

    pq.pop(); // {8,5,2}
    cout << pq.top(); // prints 8

    //size,swap and empty functions same as Queue
    
    //MINIMUM HEAP: A pririoty queue that stores minimum element at top i.e. in ascending order
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); // {5}
    pq.push(2); // {2,5}
    pq.push(8); // {2,5,8}
    pq.emplace(10); // {2,5,8,10}

    cout << pq.top(); //prints 2
}
void explainSet()// stores in sorted (a tree is maintained)(ascending, largest number at top) order and is unique
{
    /*Time complexity
    erase(elements value): O(log N)
    erase(element address): O(1)
    EVERYELSE FUNCTION TAKES O(log N)
    */
    set<int> st;
    st.insert(1); //{1}
    st.emplace(2); //{1,2}
    st.insert(2); //{1,2}
    st.insert(4); //{1,2,4}
    st.insert(3); //{1,2,3,4}

    //functionality of insert in vectors can also be used, that only increases efficiency
    //begin(), end(), rbegin(), rend(), size(), empty() and swap() are same as those of above

    auto it=st.find(3); //returns iterator points to the address
    auto it=st.find(6); //returns st.end() iterator i.e. points to memory just after the last elements memory address

    st.erase(3); //{1,2,4}, logarithmic time

    int cnt=st.count(1); //set is unique elements so the values returned are either 1 or 0
    
    auto it=st.find(1);
    st.erase(it); // {2,4}, constant time

    set<int> st2={1,2,3,4,5,6,7};
    auto it1=st2.find(2);
    auto it2=st2.find(5);
    st2.erase(it1,it2); // {1,5,6,7}, lower and upper bound works in the same way

    //The rest functions are same as vectors

    //This is the syntax
    auto it=st2.lower_bound(2);
    auto it=st.upper_bound(3);
}
void explainMultiset()
{
    //everything is same as set 
    // only stores duplicate values

    multiset<int> ms;
    ms.insert(1); //{1}
    ms.insert(1); // {1,1}
    ms.insert(1); //{1,1,1}

    ms.erase(1); //all 1's erased

    int cnt=ms.count(1);

    //only a single 1 is erased
    ms.erase(ms.find(1)); //first occurrence of 1

    //erase all 1's
    ms.erase(ms.find(1), ms.find(1) + (2));

    //rest all functions are same
}
void explainUnorderedset()
{
    //TIME Complexity is O(1)
    //WORST case (once in a blue moon) O(N)
    unordered_set<int> ust;
    //lower and upper bound function does not works, rest all functions are same
    // it doesn't stores in any particular order, IT HAS BETTER COMPLEXITY THAN SET IN MOST CASES, EXCEPT SOME WHEN COLLISION HAPPENS
}
void explainMap() //map <key data type,value data type>
{
    //map stores unique keys in sorted order
    //SORTED KEY
    //Works in O(log N)
    map<int,int> mp1;
    map<int,pair<int,int>> mp2;
    map<pair <int,int>,int> mp3;

    mp1[1]=2; //key 1, value 2
    mp1.emplace(3,1); // key 3, value 1
    mp1.insert({2,4});
    //mp1= [{1,2}, {2,4}, {3,1}]

    mp2[1]={2,3};
    mp3[{2,3}]=10; //key {2,3}, value 10

    for(auto it:mp1)
    {
        cout << it.first << " " << it.second << endl;
    }

    cout << mp1[1]; // prints 2
    cout << mp1[5]; // prints 0 or NULL

    auto it=mp1.find(3); // gives memory address of key
    cout << (*(it)).second; // prints 1

    auto it=mp1.find(5); // as 5 is not there so it points to mp1.end() i.e. the memory address just after the last element

    //This is the syntax
    auto it=mp1.lower_bound(2);
    auto it=mp1.upper_bound(3);

    //erase, swap, size, empty are same as above    
}
void explainMultimap()
{
    //everything same as map, onlt it stores multiple keys
    //only mp[key] cannot be used
}
void explainUnorderdmap()
{
    //same as set and unordered set difference
    //key can only be individual data type, like pair, vectors, etc. not allowed
    //works in O(1) in average and best case
    // in worst case O(N)
}
bool comp(pair<int,int> p1, pair<int,int> p2)//comparator returns boolean
{
    //in comparator just pick up two items only
    //comparator parameters are based on the type of data you are comparing
    if(p1.second<p2.second)
        return true;
    if(p1.second>p2.second)
        return false;
    if(p1.first>p2.first)
        return true;
    return false;
}
void explainExtra()
{
    //sort(starting iterator, end iterator), excluding end memory address
    //not map
    //ascending order
    vector<int>v;
    int arr[10];
    int *a;
    int n=10;
    sort(a,a+n);
    sort(v.begin(),v.end());
    //descending order
    sort(a,a+n,greater<int>()); //greater-a comparator

    //sort in my way
    //Q.sort in increasing order of second element if second is same sort in descending order of first element
    pair<int,int> a[]={{1,2}, {2,1}, {4,1}};
    //sort(a,a+n,comp); //comp: comparator
    //answer: {4,1} ,{2,1}, {1,2}
    sort(a[0],a[2],comp);

    
    int num1=7;//binary = 111
    int cnt=__builtin_popcount(num1);//returns set bits, gives 3, i.e. number of 1's

    long long num2=76578657867;
    int cnt=__builtin_popcountll(num2);

    //to have every permutation 
    //123, 132, 213, 231, 321, 312, NULL(false)
    string s="123";
    //if string is s="231", the pemutations would be 231, 312, 321, NULL(false)
    //so if you want all permutations then use s in sorted order
    do
    {
        cout<< s << endl;
    }while(next_permutation(s.begin(),s.end()));

    //returns max element between the memory address assigned
    int max1=*max_element(a,a+n);
}
int main()
{
    return 0;
}