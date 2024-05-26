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

* [ ] [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/description/) 
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
                int len(TreeNode* root, int& ans){
                    if(root == nullptr)return 0;
                    int mx1 = len(root->left, ans);
                    int mx2 = len(root->right, ans);
                    ans = max(ans, mx1 + mx2);
                    return max(mx1, mx2) + 1;
                }
            public:
                int diameterOfBinaryTree(TreeNode* root) {
                    int ans = 0;
                    len(root, ans);
                    return ans;
                }
            };
        
    </details>

---

* [ ] [Path Sum](https://leetcode.com/problems/path-sum/description/) 
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
                bool Check(TreeNode* root, int sum, int& targetSum){
                    if(root == nullptr)return (sum == targetSum);
                    bool flag = false;
                    sum += root->val;
                    if(root->right == nullptr || root->left != nullptr)flag |= Check(root->left, sum, targetSum);
                    if(root->left == nullptr || root->right != nullptr)flag |= Check(root->right, sum, targetSum);
                    return flag;
                }
            public:
                bool hasPathSum(TreeNode* root, int targetSum) {
                    if(root == nullptr)return false;
                    return Check(root, 0, targetSum);
                }
            };
        
    </details>

---

* [ ] [Largest cycle in a tree](https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/approximate/largest-cycle-in-a-tree-9113b3ab/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            using namespace std;
            typedef long long ll;
            #define endl '\n'

            void Farest_Node(int node, vector<vector<int>>&adj, vector<int>&depth, vector<int>&vis){
                vis[node] = 1;
                for(auto &child: adj[node]){
                    if(!vis[child]){
                        depth[child] = 1 + depth[node];
                        Farest_Node(child, adj, depth, vis);
                    }
                }
            }

            int Wanted_Node(int n, int Farest, vector<vector<int>>&adj){
                int mx = -1, node = -1;
                vector<int>depth(n + 1), vis(n + 1);
                Farest_Node(Farest, adj, depth, vis);
                for(int i = 1; i <= n;i++){
                    if(mx < depth[i]){
                        mx = depth[i];
                        node = i;
                    }
                }
                return node;
            }

            void solve(){
                int n;cin >> n;
                vector<vector<int>>adj(n + 1);
                for(int i = 1; i < n;i++){
                    int u, v;cin >> u >> v;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
                // The solution is to find the farest node from any node then find the farest node from this node
                // this is the prove of this idea :
                // https://stackoverflow.com/questions/20010472/proof-of-correctness-algorithm-for-diameter-of-a-tree-in-graph-theory
                int a = Wanted_Node(n, 1, adj);
                int b = Wanted_Node(n, a, adj);
                cout << a << ' ' << b << endl;
            }

            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int t = 1;
                for(int i = 1; i <= t;i++){
                    solve();
                }
                return 0;
            }
        
    </details>

---

* [ ] [Mancunian And Colored Tree](https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/mancunian-and-colored-tree/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            #include<bits/stdc++.h>
            using namespace std;
            typedef long long ll;
            #define endl '\n'

            int *carr, *res;

            void DFS(int node, vector<vector<int>>&adj, vector<int>&color){

                res[node] = carr[color[node]];
                int past = carr[color[node]];
                carr[color[node]] = node;

                for(auto &child: adj[node]){
                    DFS(child, adj, color);
                    carr[color[node]] = node;
                }

                carr[color[node]] = past;
            }


            void solve(){
                int n, c;cin >> n >> c;
                vector<vector<int>>adj(n + 1);
                vector<int>color(n + 1);
                for(int i = 1; i < n;i++){
                    int x;cin >> x;
                    adj[x].push_back(i + 1);
                }
                for(int i = 1; i <= n;i++){
                    int x;cin >> x;
                    color[i] = x;
                }
                carr = new int[c + 1];
                memset(carr, -1, (c +  1) * sizeof(int));
                res = new int[n + 1];

                DFS(1, adj, color);

                for(int i = 1; i <= n;i++)cout << res[i] << " \n"[i == n];

                delete[] carr;
                delete[] res;
            }

            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int t = 1;
                for(int i = 1; i <= t;i++){
                    solve();
                }
                return 0;
            }
        
    </details>

---


* [ ] [Find a Corresponding Node of a Binary Tree in a Clone of That Tree](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            /**
             * Definition for a binary tree node.
            * struct TreeNode {
            *     int val;
            *     TreeNode *left;
            *     TreeNode *right;
            *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
            * };
            */

            class Solution {
                TreeNode* Res(TreeNode* cloned, TreeNode* target){
                    if(cloned == nullptr)
                        return nullptr;

                    if(cloned->val == target->val){
                        return cloned;
                    }
                    TreeNode* left = Res(cloned->left, target);
                    TreeNode* right = Res(cloned->right, target);
                    if(left != nullptr)return left;
                    else if(right != nullptr)return right;
                    return nullptr;
                }
            public:
                TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
                    return Res(cloned, target);
                }
            };
        
    </details>

---



* [ ] [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/description/) 
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
                int rangeSumBST(TreeNode* root, int low, int high) {
                    if(root == nullptr)
                        return 0;
                    
                    int sum = 0;
                    if(root->val >= low && root->val <= high)
                        sum = root->val;
                    sum += rangeSumBST(root->left, low, high);
                    sum += rangeSumBST(root->right, low, high);
                    return sum;
                }
            };
        
    </details>

---


* [ ] [Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/description/) 
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
                TreeNode* searchBST(TreeNode* root, int val) {
                    if(root == nullptr)
                        return nullptr;

                    if(root->val == val)
                        return root;

                    TreeNode* left = searchBST(root->left, val);
                    TreeNode* right = searchBST(root->right, val);
                    if(left != nullptr)return left;
                    if(right != nullptr)return right;
                    return nullptr;
                }
            };
        
    </details>

---


* [ ] [Pseudo-Palindromic Paths in a Binary Tree](https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24) 
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
                int frq[10]{0};
            public:
                int pseudoPalindromicPaths (TreeNode* root) {
                    frq[root->val]++;
                    int ret = 0;
                    if(root->left == nullptr && root->right == nullptr){
                        int odd = 0;
                        for(int i = 1; i <= 9;i++){
                            odd += (frq[i] % 2);
                        }
                        ret += (odd <= 1);
                    }

                    if(root->left != nullptr)ret += pseudoPalindromicPaths(root->left);
                    if(root->right != nullptr)ret += pseudoPalindromicPaths(root->right);
                    frq[root->val]--;
                    return ret;
                }
            };
        
    </details>

---



* [ ] [Delete Leaves With a Given Value](https://leetcode.com/problems/delete-leaves-with-a-given-value/description/) 
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
            *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
            * right(right) {}
            * };
            */
            class Solution {
            public:
                TreeNode* removeLeafNodes(TreeNode* root, int target) {
                    if(root == nullptr)
                        return nullptr;
                    root->left = removeLeafNodes(root->left, target);
                    root->right = removeLeafNodes(root->right, target);
                    if(root->left == nullptr && root->right == nullptr && root->val == target)
                        return nullptr;
                    return root;
                }
            };
        
    </details>

---