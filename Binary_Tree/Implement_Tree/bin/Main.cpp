#include <bits/stdc++.h>
#include "../include/Binary_Search_Tree.hpp"

using namespace std;
using namespace DSA;

struct BstNode
{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void insert(BstNode** root, int data){
    if(*root == nullptr){
        *root = GetNewNode(data);
    }
    else if(data <= (*root)->data){
        insert(&(*root)->left, data);
    }
    else{
        insert(&(*root)->right, data);
    }
}
bool search(BstNode* root, int data){
    if(root == nullptr)return false;
    if(root->data == data)return true;
    else if(root->data <= data)return search(root->left, data);
    return search(root->right, data);
}

int FindMin(BstNode* root){
    if(root == nullptr){
        return INT_MAX;
    }
    return min(root->data, FindMin(root->left));
}

int FindMax(BstNode* root){
    if(root == nullptr){
        return INT_MIN;
    }
    return max(root->data, FindMax(root->right));
}

int FindHeight(BstNode* root){
    if(root == nullptr){
        return -1;
    }
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

// Binary Tree (Level Order Traversal).
void LevelOrder(BstNode* root){
    queue<BstNode*>bfs;
    bfs.push(root);
    while(!bfs.empty()){
        BstNode* currNode = bfs.front();
        bfs.pop();
        if(currNode == nullptr)continue;
        cout << currNode->data << ' ';
        bfs.push(currNode->left);
        bfs.push(currNode->right);
    }
    cout << '\n';
}

// Binary Tree (Preorder Traversal).
// Space Complexity is O(h).
void PreOrder(BstNode* root){
    if(root == nullptr)return;
    cout << root->data << ' ';
    PreOrder(root->left);
    PreOrder(root->right);
}

// Binary Tree (InOrder Traversal).
void InOrder(BstNode* root){
    if(root == nullptr)return;
    InOrder(root->left);
    cout << root->data << ' ';
    InOrder(root->right);
}

// Binary Tree (PostOrder).
void PostOrder(BstNode* root){
    if(root == nullptr)return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << ' ';
}

bool IsBinarySearchTree(BstNode* root, int minValue, int maxValue){
    if(root == nullptr)return true;
    if(root->data < minValue || root->data > maxValue)return false;
    return IsBinarySearchTree(root->left, minValue, root->data) && IsBinarySearchTree(root->right,
        root->data + 1, maxValue);
}

BstNode* Delete(BstNode* root, int data){
    if(root == nullptr)return root;
    else if(data < root->data)root->left = Delete(root->left, data);
    else if(data > root->data)root->right = Delete(root->right, data);
    else{
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
        }
        else if(root->left == nullptr || root->right == nullptr){
            BstNode* temp = root;
            root = (root->left == nullptr) ? root->right : root->left;
            delete temp;
            temp = nullptr;
        }
        else{
            int minValue = FindMin(root->right);
            root->data = minValue;
            root->right = Delete(root->right, minValue);
        }
    }
    return root;
}

BstNode* Findmin(BstNode* root){
    if(root == nullptr)return nullptr;
    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}

// BstNode* Getsuccessor(BstNode* root, int data){
//     BstNode* cur = Find(root, data);
//     if(cur == nullptr)return nullptr;
//     if(cur->right != nullptr){
//         return Findmin(cur->right);
//     }
//     else{
//         BstNode* successor = nullptr;
//         BstNode* ancestor = root;
//         while(ancestor != nullptr){
//             if(cur->data <= ancestor->data){
//                 successor = ancestor;
//                 ancestor = ancestor->left;
//             }
//             else ancestor = ancestor->right;
//         }
//         return successor;
//     }
// }

void Inorder_Without_Recursion(BstNode* root){
    stack<BstNode*>st;
    BstNode* cur = root;
    while(cur != nullptr || !st.empty()){
        while(cur != nullptr){
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        cout << cur->data << " ";
        cur = cur->right;
    }
}


int main()
{
    MultiSet<int>st{1, 2, 3, 4};
    
    st.print();


    return 0;
}