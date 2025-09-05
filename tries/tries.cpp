#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    TrieNode* child[26];
    bool isEndOfWord;
    TrieNode(){
        isEndOfWord = false;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};
class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        }
        void insert(string key){
            TrieNode* pCrawl = root;
            for(int i=0;i<key.length();i++){
                int index = key[i] - 'a';
                if(!pCrawl->child[index]){
                    pCrawl->child[index] = new TrieNode();
                }
                pCrawl = pCrawl->child[index];
            }
            pCrawl->isEndOfWord = true;
        }
        bool search(string key){
            TrieNode* pCrawl = root;
            for(int i=0;i<key.length();i++){
                int index = key[i] - 'a';
                if(!pCrawl->child[index]){
                    return false;
                }
                pCrawl = pCrawl->child[index];
            }
            return (pCrawl != NULL && pCrawl->isEndOfWord);
        }
        bool isEmpty(TrieNode* root){
            for(int i=0;i<26;i++){
                if(root->child[i]) return false;
            }
            return true;
        }
    bool Delete(TrieNode* root, string key, int depth){
        if(!root) return false;
        if(depth == key.size()){
            if(root->isEndOfWord){
                root->isEndOfWord = false;
                return isEmpty(root);
            }
            return false;
        }
        int index = key[depth] - 'a';
        if(root->child[index]){
            bool shouldDeleteCurrentNode = Delete(root->child[index], key, depth + 1);
            if(shouldDeleteCurrentNode){
                delete root->child[index];
                root->child[index] = NULL;
                return (!root->isEndOfWord && isEmpty(root));
            }
        }
        return false;
    }
    void Deleteword(string key){
        Delete(root, key,0);
    }
};
    

int main(){
   Trie t;
    t.insert("hello");
    t.insert("world");
    t.insert("helloworld");
    cout<<t.search("o")<<endl; 
     t.Deleteword("hello");
     cout<<t.search("hello")<<endl; 
     cout<<t.search("hell")<<endl; 
}