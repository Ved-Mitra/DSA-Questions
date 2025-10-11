#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node* links[26];
    bool flag=false;

    Node()
    {
        for(int i=0;i<26;i++)
            links[i]=nullptr;
    }

    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }

    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }

    Node* get(char ch)
    {
        return links[ch-'a'];
    }

    void setEnd()
    {
        flag=true;
    }

    bool isEnd()
    {
        return flag;
    }

    void setNull(char ch)
    {
        links[ch-'a']=nullptr;
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
private:
    Node* root;

    Node* removeHelper(Node* node,string word,int depth)
    {
        if(!node)
            return nullptr;
        if(depth=word.size())
        {
            if(node->isEnd())
                node->flag=false;
        
            if(node->isEmpty())
            {
                delete node;
                node=nullptr;
            }
            return node;
        }

        int index=word[depth]-'a';
        node->links[index]=removeHelper(node->links[index],word,depth+1);

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
        //O(len)
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            //moves to reference trie
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        //O(len)
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
        //O(len)
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
        Node* node=root;
        vector<Node*> list;
        for(int i=0;i<word.size();i++)
        {
            list.push_back(node);
            Node* ptr=node->get(word[i]);
            node=ptr;
        }
        list.push_back(node);
        for(int i=list.size()-1;i>=0;i--)
        {
            Node* ptr=list[i];
            if(ptr->isEmpty())
                delete ptr;
        }
    }
};

int mian()
{

}