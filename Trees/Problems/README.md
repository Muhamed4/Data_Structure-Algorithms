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

