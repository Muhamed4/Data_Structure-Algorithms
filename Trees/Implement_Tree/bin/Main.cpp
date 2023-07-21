#include <bits/stdc++.h>

using namespace std;


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

void Print(BstNode* root){
    if(root == nullptr)return;
    cout << root->data << endl;
    Print(root->left);
    Print(root->right);
}


int main()
{

    BstNode* root = nullptr;
    insert(&root, 15);
    insert(&root, 10);
    insert(&root, 15);
    insert(&root, 54);
    insert(&root, 78);
    insert(&root, 24);
    LevelOrder(root);

    return 0;
}