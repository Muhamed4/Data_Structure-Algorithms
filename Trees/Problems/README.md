# Problems :

* [ ] [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int maxDepth(TreeNode* root) {
                    if(root == NULL) return 0;
                    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
                }
            };
        
    </details>

---

* [ ] [Check Completeness of a Binary Tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            /**
             * Definition for a binary tree node.
            * struct TreeNode {
            *     int val;
            *     TreeNode *left;
            *     TreeNode *right;
            *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
            *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
            * };
            */
            class Solution {
            public:
                bool isCompleteTree(TreeNode* root) {
                    queue<TreeNode*>bfs;
                    bfs.push(root);
                    while(bfs.front() != nullptr){
                        TreeNode* temp = bfs.front();
                        bfs.push(temp->left);
                        bfs.push(temp->right);
                        bfs.pop();
                    }
                    while(!bfs.empty() && bfs.front() == nullptr)bfs.pop();
                    return bfs.empty();
                }
            };
        
    </details>

---

* [ ] [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/?source=submission-ac) 
    * <details>
        <summary> Solution </summary>

        ```c++
            /**
             * Definition for a binary tree node.
            * struct TreeNode {
            *     int val;
            *     TreeNode *left;
            *     TreeNode *right;
            *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
            *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
            * };
            */
            class Solution {
            public:
                vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
                    vector<vector<int>>ans;
                    queue<TreeNode*>bfs;
                    if(root != nullptr)bfs.push(root);
                    bool flag = false;
                    while(!bfs.empty()){
                        ans.push_back(vector<int>());
                        queue<TreeNode*>temp;
                        while(!bfs.empty()){
                            ans.back().push_back(bfs.front()->val);
                            if(bfs.front()->left != nullptr)temp.push(bfs.front()->left);
                            if(bfs.front()->right != nullptr)temp.push(bfs.front()->right);
                            bfs.pop();
                        }
                        if(flag)reverse(ans.back().begin(), ans.back().end());
                        flag ^= true;
                        bfs = temp;
                    }
                    return ans;
                }
            };
        
    </details>

---

* [ ] [Root Equals Sum of Children](https://leetcode.com/problems/root-equals-sum-of-children/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            /**
            * Definition for a binary tree node.
            * struct TreeNode {
            *     int val;
            *     TreeNode *left;
            *     TreeNode *right;
            *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
            *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
            * };
            */
            class Solution {
            public:
                bool checkTree(TreeNode* root) {
                    return (root->val == (root->left->val + root->right->val));
                }
            };
        
    </details>

---

* [ ] [Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            /**
            * Definition for a binary tree node.
            * struct TreeNode {
            *     int val;
            *     TreeNode *left;
            *     TreeNode *right;
            *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
            *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
            * };
            */
            class Solution {
            public:
                int sumOfLeftLeaves(TreeNode* root) {
                    if(root == nullptr)return 0;
                    TreeNode* temp = root->left;
                    if(temp != nullptr && temp->left == nullptr && temp->right == nullptr){
                        return temp->val + sumOfLeftLeaves(root->right);
                    }
                    else return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
                }
            };
        
    </details>

---


