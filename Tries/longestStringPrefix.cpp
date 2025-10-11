#include <bits/stdc++.h>
using namespace std;

/*Ninja developed a love for arrays and strings so this time his teacher gave him an array of strings, 'A' of size 'N'. Each element of this array is a string. The teacher taught Ninja about prefixes in the past, so he wants to test his knowledge.

A string is called a complete string if every prefix of this string is also present in the array 'A'. Ninja is challenged to find the longest complete string in the array 'A'. If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None".*/


class Node
{
    public:
    Node* links[26];
    bool flag;

    public:
    Node()
    {
        for(int i=0;i<26;i++)
            links[i]=nullptr;
        flag=false;
    }

    bool containsKey(char ch)
    {
        return (links[ch-'a']!=nullptr);
    }

    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    
    Node* get(char ch)
    {
        return links[ch-'a'];
    }

    bool isEnd()
    {
        return flag;
    }

    void setEnd()
    {
        flag=true;
    }

    bool isEmpty()
    {
        for(int i=0;i<26;i++)
            if(links[i]!=nullptr)
                return false;
        return true;
    }
};

class Trie
{
    public:
    Node* root;

    Node* removeHealper(string word,Node* node,int depth)
    {
        if(node==nullptr)
            return nullptr;
        if(depth==word.size())
        {
            if(node->isEnd())
                node->flag=false;

            if(node->isEmpty())
            {
                delete node;
                return nullptr;
            }
        }

        int index=word[depth]-'a';
        node->links[index]=removeHealper(word,node->links[index],depth+1);

        if(node->isEmpty() && !node->isEnd())
        {
            delete node;
            node=nullptr;
        }

        return node;
    }

    public:
    Trie()
    {
        root=new Node();
    }

    void insert(string word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
                node->put(word[i],new Node());
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
                return false;
            node=node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node* node=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!node->containsKey(prefix[i]))
                return false;
            node=node->get(prefix[i]);
        }
        return true;
    }

    void remove(string word)
    {
        root=removeHealper(word,root,0);
    }

    bool checkIfPrefixExists(string word)
    {
        bool fl=true;
        Node* node=root;
        for(int i=0;i<word.size() && fl;i++)
        {
            if(node->containsKey(word[i]))
            {
                node=node->get(word[i]);
                if(!node->isEnd())
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};


string completeString(vector<string> &arr)
{
    //TC-O(n* len)

    int n=arr.size();
    Trie trieRoot;
    for(int i=0;i<n;i++)
        trieRoot.insert(arr[i]);

    string ans="";
    for(int i=0;i<n;i++)
    {
        if(trieRoot.checkIfPrefixExists(arr[i]))
        {
            ans=arr[i];
        }
        else if(arr[i].size()==ans.size() && arr[i]<ans)
        {
            ans=arr[i];
        }
    }
}













int main()
{

}