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

