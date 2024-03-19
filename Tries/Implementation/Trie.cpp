#include <iostream>
using namespace std;



class TrieNode {
private:
    struct Node {
        Node* child[26];
        int wordEndCnt;

        Node() {
            wordEndCnt = 0;
            for(int i = 0; i < 26;i++){
                child[i] = nullptr;
            }
        }        
    };

    Node* root;

public:

    TrieNode() : root(new Node()) { }

    void insert(string key){
        Node* currentNode = root;
        for(auto& c: key){
            if(currentNode->child[c - 'a'] == nullptr){
                Node* newNode = new Node();
                currentNode->child[c - 'a'] = newNode;
            }
            currentNode = currentNode->child[c - 'a'];
        }
        currentNode->wordEndCnt++;
    }

    bool Search_key(string key) {
        Node* currentNode = root;
        for(auto& c: key){
            if(currentNode->child[c - 'a'] == nullptr) 
                return false;

            currentNode = currentNode->child[c - 'a'];
        }
        return currentNode->wordEndCnt > 0;
    }
};

// struct TrieNode {
//     TrieNode* child[26];
//     int wordEndCnt;

//     TrieNode() {
//         wordEndCnt = 0;
//         for(int i = 0; i < 26;i++){
//             child[i] = nullptr;
//         }
//     }
// };

// TrieNode* insert(TrieNode* root, string key){
//     TrieNode* currentNode = root;
//     for(auto& c: key){
//         if(currentNode->child[c - 'a'] == nullptr){
//             TrieNode* newNode = new TrieNode();
//             currentNode->child[c - 'a'] = newNode;
//         }
//         currentNode = currentNode->child[c - 'a'];
//     }
//     currentNode->wordEndCnt++;
//     return root;
// }

// bool Search_key(TrieNode* root, string key) {
//     TrieNode* currentNode = root;
//     for(auto& c: key){
//         if(currentNode->child[c - 'a'] == nullptr) 
//             return false;

//         currentNode = currentNode->child[c - 'a'];
//     }
//     return currentNode->wordEndCnt > 0;
// }

int main(){

    TrieNode trie;

    trie.insert("cats");
    trie.insert("dog");
    trie.insert("sand");
    trie.insert("and");
    trie.insert("cat");

    cout << trie.Search_key("sand") << endl;
    cout << trie.Search_key("caty") << endl;
    cout << trie.Search_key("dog") << endl;

    // TrieNode* root = new TrieNode();

    // root = insert(root, "cats");
    // root = insert(root, "dog");
    // root = insert(root, "sand");
    // root = insert(root, "and");
    // root = insert(root, "cat");

    // cout << Search_key(root, "sand") << endl;
    // cout << Search_key(root, "caty") << endl;
    // cout << Search_key(root, "dog") << endl;

    return 0;
}