#include <bits/stdc++.h>
using namespace std;

//disticnt substring including empty substring


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

   Node* removeHelper(Node* node, string word, int depth)
   {
       if(!node)
           return nullptr;
       if(depth == word.size())
       {
           if(node->isEnd())
               node->flag = false;
       
           if(node->isEmpty())
            {
               delete node;
               node = nullptr;
            }
           return node;
       }

       int index = word[depth] - 'a';
       node->links[index] = removeHelper(node->links[index], word, depth + 1);

       if(node->isEmpty() && !node->isEnd())
       {
           delete node;
           node = nullptr;
       }

       return node;
   }
public:
   Trie()
   {
       root = new Node();
   }

   void insert(string word)
   {
       //O(len)
       Node* node = root;
       for(int i=0; i<word.size(); i++)
       {
           if(!node->containsKey(word[i]))
           {
               node->put(word[i], new Node());
           }
           //moves to reference trie
           node = node->get(word[i]);
       }
       node->setEnd();
   }

   bool search(string word)
   {
       //O(len)
       Node* node = root;
       for(int i=0; i<word.size(); i++)
       {
           if(!node->containsKey(word[i]))
               return false;
           node = node->get(word[i]);
       }
       return node->isEnd();
   }

   bool startsWith(string prefix)
   {
       //O(len)
       Node* node = root;
       for(int i=0; i<prefix.size(); i++)
       {
           if(!node->containsKey(prefix[i]))
               return false;
           node = node->get(prefix[i]);
       }
       return true;
    }

    void remove(string word)
    {
       root = removeHelper(root, word, 0);
    }
};

int distinctSubstring(string s)
{
    int n=s.size();
    int cnt=0;

    //M-1
    // class Trie trie;
    // for(int i=0;i<n;i++)
    // {
    //     string str="";
    //     for(int j=i;j<n;j++)
    //     {
    //         str+=s[j];
    //         if(!trie.search(str))
    //         {
    //             cnt++;
    //             trie.insert(str);
    //         }

    //     }
    // }
    // return cnt;



    //M-2
    Node* root=new Node();
    for(int i=0;i<n;i++)
    {
        Node* node=root;
        for(int j=i;j<n;j++)
        {
            if(!node->containsKey(s[j]))
            {
                cnt++;
                node->put(s[j],new Node());
            }
            node=node->get(s[j]);
        }
    }
    return cnt+1;//for empty substring
}