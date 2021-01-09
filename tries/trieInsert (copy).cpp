//Search and insert in trie
#include<iostream>
#include<string>

using namespace std;

const int alphabetSize = 26;

struct TrieNode {
    TrieNode *children[alphabetSize];
    bool isEndOfWord;
};

class Trie {

    public:
    TrieNode *getNode() {
        TrieNode *pnode = new TrieNode;
        pnode->isEndOfWord = false;
        for(int i = 0; i < alphabetSize; i++) {
            pnode->children[i] = NULL;
        }
        return pnode; 
    }

    void insert(TrieNode *root, string key) {
        
        TrieNode *pCrawl = root;
        for(int i = 0; i < key.size(); i++) {
            int index = key[i] - 'a';
            if(!pCrawl->children[index])
                pCrawl->children[index] = getNode();
            pCrawl = pCrawl->children[index];
        }

        pCrawl->isEndOfWord = true;
    }

    bool search(TrieNode *root, string key) {
        TrieNode *pCrawl = root;
        for(int i = 0; i < key.size(); i++) {
            int index = key[i] - 'a';
            if(!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl != NULL && pCrawl->isEndOfWord);
    }

    bool checkIsLeaf(TrieNode *node) {
        if(node->isEndOfWord != false)
            return true;
        return false;
    }

    void display(TrieNode *root, char str[], int level) {
        if(checkIsLeaf(root)) {
            str[level] = '\0';
            cout << str << endl;
        }
        for(int i = 0; i < alphabetSize; i++) {
            if(root->children[i]) {
                str[level] =  i + 'a';
                display(root->children[i], str, level+1);
            }
        }
    }
};

int main() {

    string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
    Trie trieObject;

    TrieNode *root = trieObject.getNode(); 
  
    for (int i = 0; i < n; i++) 
        trieObject.insert(root, keys[i]); 
  
    trieObject.search(root, "the")? cout << "Yes\n" : 
                         cout << "No\n"; 
    trieObject.search(root, "these")? cout << "Yes\n" : 
                           cout << "No\n"; 
    trieObject.search(root, "Deepak")? cout << "Yes\n" : 
                         cout << "No\n"; 

    char str[50];

    cout << "Displaying the content of trie" << endl;
    trieObject.display(root, str, 0);
    return 0; 

}