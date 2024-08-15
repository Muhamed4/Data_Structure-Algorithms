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



* [ ] [Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/description/) 
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
                TreeNode* insertIntoBST(TreeNode* root, int val) {
                    if(root == nullptr) {
                        root = new TreeNode(val);
                        return root;
                    }
                    if(val < root->val) root->left = insertIntoBST(root->left, val);
                    else root->right = insertIntoBST(root->right, val);
                    return root;
                }
            };
        
    </details>

---




* [ ] [Create Binary Tree From Descriptions](https://leetcode.com/problems/create-binary-tree-from-descriptions/description/) 
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
                TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
                    unordered_map<int, TreeNode*> relation, parent;
                    TreeNode* root = nullptr, *ch = nullptr;
                    for(auto &edge: descriptions) {
                        int par = edge[0], child = edge[1], isLeft = edge[2];
                        TreeNode* p = relation[par];
                        TreeNode* c = relation[child];
                        if(p == nullptr) p = new TreeNode(par);
                        if(c == nullptr) c = new TreeNode(child);
                        if(isLeft == true) p->left = c;
                        else p->right = c;
                        relation[par] = p;
                        relation[child] = c;
                        parent[child] = p;
                        ch = c;
                    }
                    while(ch != nullptr) {
                        root = ch;
                        ch = parent[ch->val];
                    }
                    return root;
                }
            };
        
    </details>

---





* [ ] [Delete Nodes And Return Forest](https://leetcode.com/problems/delete-nodes-and-return-forest/description/) 
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
                TreeNode* toDelete(TreeNode*& root, unordered_map<int, bool>& mark, vector<TreeNode*>& res) {
                    if(root == nullptr) return nullptr;
                    root->left = toDelete(root->left, mark, res);
                    root->right = toDelete(root->right, mark, res);
                    if(mark[root->val] == true) {
                        if(root->left != nullptr)
                            res.push_back(root->left);
                        if(root->right != nullptr)
                            res.push_back(root->right);
                        root = nullptr;
                    }
                    return root;
                }
            public:
                vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
                    vector<TreeNode*> res;
                    unordered_map<int, bool> mark;
                    for(auto &deleted: to_delete)
                        mark[deleted] = true;
                    toDelete(root, mark, res);
                    if(root != nullptr)
                        res.push_back(root);
                    return res;
                }
            };
        
    </details>

---



* [ ] [All Possible Full Binary Trees](https://leetcode.com/problems/all-possible-full-binary-trees/) 
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
                unordered_map<int, vector<TreeNode*>> memo;
                vector<TreeNode*> buildFullBinaryTree(int n) {
                    if(!(n & 1))
                        return {};
                    if(n == 1) {
                        return {new TreeNode()};
                    }
                    if(memo.find(n) != memo.end())
                        return memo[n];
                    vector<TreeNode*> Final;
                    for(int left = 1; left < n;++left) {
                        int right = n - left - 1;
                        if((left & 1) && (right & 1)) {
                            vector<TreeNode*> retLeft = buildFullBinaryTree(left);
                            vector<TreeNode*> retRight = buildFullBinaryTree(right);
                            
                            
                            int n = retLeft.size();
                            int m = retRight.size();
                            for(int i = 0; i < n;i++) {
                                for(int j = 0; j < m;j++) {
                                    TreeNode* root = new TreeNode();
                                    root->left = retLeft[i];
                                    root->right = retRight[j];
                                    Final.push_back(root);
                                }
                            }
                        }
                    }
                    memo[n] = Final;
                    return Final;
                }
            public:
                vector<TreeNode*> allPossibleFBT(int n) {
                    return buildFullBinaryTree(n);        
                }
            };
        
    </details>

---





* [ ] [Check for BST](https://www.geeksforgeeks.org/problems/check-for-bst/1?page=1&category=Tree,Binary%20Search%20Tree&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;
            #define MAX_HEIGHT 100000

            // Tree Node
            struct Node {
                int data;
                Node* left;
                Node* right;

                Node(int val) {
                    data = val;
                    left = right = NULL;
                }
            };


            // } Driver Code Ends
            class Solution {
                bool isBST(Node* root, int mn, int mx) {
                    if(root == nullptr) 
                        return true;
                    if(root->data < mn || root->data > mx)
                        return false;
                    bool ret = true;
                    ret &= isBST(root->left, mn, root->data - 1);
                    ret &= isBST(root->right, root->data + 1, mx);
                    return ret;
                }
            public:
                // Function to check whether a Binary Tree is BST or not.
                bool isBST(Node* root) {
                    // Your code here
                    return isBST(root, INT_MIN, INT_MAX);
                }
            };


            //{ Driver Code Starts.

            // Function to Build Tree
            Node* buildTree(string str) {
                // Corner Case
                if (str.length() == 0 || str[0] == 'N')
                    return NULL;

                // Creating vector of strings from input
                // string after spliting by space
                vector<string> ip;

                istringstream iss(str);
                for (string str; iss >> str;)
                    ip.push_back(str);

                // Create the root of the tree
                Node* root = new Node(stoi(ip[0]));

                // Push the root to the queue
                queue<Node*> queue;
                queue.push(root);

                // Starting from the second element
                int i = 1;
                while (!queue.empty() && i < ip.size()) {

                    // Get and remove the front of the queue
                    Node* currNode = queue.front();
                    queue.pop();

                    // Get the current node's value from the string
                    string currVal = ip[i];

                    // If the left child is not null
                    if (currVal != "N") {

                        // Create the left child for the current node
                        currNode->left = new Node(stoi(currVal));

                        // Push it to the queue
                        queue.push(currNode->left);
                    }

                    // For the right child
                    i++;
                    if (i >= ip.size())
                        break;
                    currVal = ip[i];

                    // If the right child is not null
                    if (currVal != "N") {

                        // Create the right child for the current node
                        currNode->right = new Node(stoi(currVal));

                        // Push it to the queue
                        queue.push(currNode->right);
                    }
                    i++;
                }

                return root;
            }

            void inorder(Node* root, vector<int>& v) {
                if (root == NULL)
                    return;

                inorder(root->left, v);
                v.push_back(root->data);
                inorder(root->right, v);
            }

            int main() {

                int t;
                string tc;
                getline(cin, tc);
                t = stoi(tc);
                while (t--) {
                    string s;
                    getline(cin, s);
                    // if (s[0] == '9') {
                    //     cout << "false\n";
                    //     return 0;
                    // }
                    Node* root = buildTree(s);
                    Solution ob;
                    if (ob.isBST(root))
                        cout << "true\n";

                    else
                        cout << "false\n";
                }
                return 0;
            }

            // } Driver Code Ends
        
    </details>

---






* [ ] [Left View of Binary Tree](https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1?page=1&category=Tree,Binary%20Search%20Tree&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;

            // Tree Node
            struct Node
            {
                int data;
                Node* left;
                Node* right;
            };

            vector<int> leftView(struct Node *root);

            // Utility function to create a new Tree Node
            Node* newNode(int val)
            {
                Node* temp = new Node;
                temp->data = val;
                temp->left = NULL;
                temp->right = NULL;

                return temp;
            }


            // Function to Build Tree
            Node* buildTree(string str)
            {
                // Corner Case
                if(str.length() == 0 || str[0] == 'N')
                    return NULL;

                // Creating vector of strings from input
                // string after spliting by space
                vector<string> ip;

                istringstream iss(str);
                for(string str; iss >> str; )
                    ip.push_back(str);

                // for(string i:ip)
                //     cout<<i<<" ";
                // cout<<endl;
                // Create the root of the tree
                Node* root = newNode(stoi(ip[0]));

                // Push the root to the queue
                queue<Node*> queue;
                queue.push(root);

                // Starting from the second element
                int i = 1;
                while(!queue.empty() && i < ip.size()) {

                    // Get and remove the front of the queue
                    Node* currNode = queue.front();
                    queue.pop();

                    // Get the current node's value from the string
                    string currVal = ip[i];

                    // If the left child is not null
                    if(currVal != "N") {

                        // Create the left child for the current node
                        currNode->left = newNode(stoi(currVal));

                        // Push it to the queue
                        queue.push(currNode->left);
                    }

                    // For the right child
                    i++;
                    if(i >= ip.size())
                        break;
                    currVal = ip[i];

                    // If the right child is not null
                    if(currVal != "N") {

                        // Create the right child for the current node
                        currNode->right = newNode(stoi(currVal));

                        // Push it to the queue
                        queue.push(currNode->right);
                    }
                    i++;
                }

                return root;
            }


            int main() {
                int t;
                scanf("%d ",&t);
                while(t--)
                {
                    string s;
                    getline(cin,s);
                    Node* root = buildTree(s);
                    vector<int> vec = leftView(root);
                    for(int x : vec)
                    cout<<x<<" ";
                    cout << endl;
                }
                return 0;
            }


            // } Driver Code Ends


            /* A binary tree node

            struct Node
            {
                int data;
                struct Node* left;
                struct Node* right;
                
                Node(int x){
                    data = x;
                    left = right = NULL;
                }
            };
            */

            //Function to return a list containing elements of left view of the binary tree.
            vector<int> leftView(Node *root)
            {
                // Your code here
                vector<int> res;
                queue<Node*> bfs;
                if(root != nullptr) 
                    bfs.push(root);
                while(!bfs.empty()) {
                    int sz = bfs.size();
                    res.push_back(bfs.front()->data);
                    for(int i = 0; i < sz;i++) {
                        auto node = bfs.front();
                        bfs.pop();
                        if(node->left != nullptr)
                            bfs.push(node->left);
                        if(node->right != nullptr)
                            bfs.push(node->right);
                    }
                }
                return res;
            }

        
    </details>

---






* [ ] [Diameter of a Binary Tree](https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1?page=1&category=Tree,Binary%20Search%20Tree&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;

            /* A binary tree node has data, pointer to left child
            and a pointer to right child */
            struct Node {
                int data;
                struct Node* left;
                struct Node* right;
            };
            Node* newNode(int val) {
                Node* temp = new Node;
                temp->data = val;
                temp->left = NULL;
                temp->right = NULL;
                return temp;
            }
            Node* buildTree(string str) {
                // Corner Case
                if (str.length() == 0 || str[0] == 'N') return NULL;

                // Creating vector of strings from input
                // string after spliting by space
                vector<string> ip;

                istringstream iss(str);
                for (string str; iss >> str;) ip.push_back(str);

                // Create the root of the tree
                Node* root = newNode(stoi(ip[0]));

                // Push the root to the queue
                queue<Node*> queue;
                queue.push(root);

                // Starting from the second element
                int i = 1;
                while (!queue.empty() && i < ip.size()) {

                    // Get and remove the front of the queue
                    Node* currNode = queue.front();
                    queue.pop();

                    // Get the current node's value from the string
                    string currVal = ip[i];

                    // If the left child is not null
                    if (currVal != "N") {

                        // Create the left child for the current node
                        currNode->left = newNode(stoi(currVal));

                        // Push it to the queue
                        queue.push(currNode->left);
                    }

                    // For the right child
                    i++;
                    if (i >= ip.size()) break;
                    currVal = ip[i];

                    // If the right child is not null
                    if (currVal != "N") {

                        // Create the right child for the current node
                        currNode->right = newNode(stoi(currVal));

                        // Push it to the queue
                        queue.push(currNode->right);
                    }
                    i++;
                }

                return root;
            }


            // } Driver Code Ends
            /* Tree node structure  used in the program

            struct Node
            {
                int data;
                struct Node* left;
                struct Node* right;

                Node(int x){
                    data = x;
                    left = right = NULL;
                }
            }; */

            class Solution {
            public:
                int diameter(Node* root, int& res) {
                    if(root == nullptr)
                        return -1;
                    int left = diameter(root->left, res);
                    int right = diameter(root->right, res);
                    res = max(res, left + right + 2 + 1);
                    return max(left, right) + 1;
                }
                // Function to return the diameter of a Binary Tree.
                int diameter(Node* root) {
                    // Your code here
                    int res = 0;
                    diameter(root, res);
                    return res;
                }
            };

            //{ Driver Code Starts.

            /* Driver program to test size function*/
            int main() {
                int t;
                scanf("%d\n", &t);
                while (t--) {
                    string s;
                    getline(cin, s);
                    Node* root = buildTree(s);
                    Solution ob;
                    cout << ob.diameter(root) << endl;
                }
                return 0;
            }

            // } Driver Code Ends
        
    </details>

---






* [ ] [Sum Tree](https://www.geeksforgeeks.org/problems/sum-tree/1?page=1&category=Tree,Binary%20Search%20Tree&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;

            struct Node
            {
                int data;
                struct Node *left;
                struct Node *right;
            };
            // Utility function to create a new Tree Node
            Node* newNode(int val)
            {
                Node* temp = new Node;
                temp->data = val;
                temp->left = NULL;
                temp->right = NULL;
                
                return temp;
            }
            // Function to Build Tree
            Node* buildTree(string str)
            {   
                // Corner Case
                if(str.length() == 0 || str[0] == 'N')
                        return NULL;
                
                // Creating vector of strings from input 
                // string after spliting by space
                vector<string> ip;
                
                istringstream iss(str);
                for(string str; iss >> str; )
                    ip.push_back(str);
                    
                // Create the root of the tree
                Node* root = newNode(stoi(ip[0]));
                    
                // Push the root to the queue
                queue<Node*> queue;
                queue.push(root);
                    
                // Starting from the second element
                int i = 1;
                while(!queue.empty() && i < ip.size()) {
                        
                    // Get and remove the front of the queue
                    Node* currNode = queue.front();
                    queue.pop();
                        
                    // Get the current node's value from the string
                    string currVal = ip[i];
                        
                    // If the left child is not null
                    if(currVal != "N") {
                            
                        // Create the left child for the current node
                        currNode->left = newNode(stoi(currVal));
                            
                        // Push it to the queue
                        queue.push(currNode->left);
                    }
                        
                    // For the right child
                    i++;
                    if(i >= ip.size())
                        break;
                    currVal = ip[i];
                        
                    // If the right child is not null
                    if(currVal != "N") {
                            
                        // Create the right child for the current node
                        currNode->right = newNode(stoi(currVal));
                            
                        // Push it to the queue
                        queue.push(currNode->right);
                    }
                    i++;
                }
                
                return root;
            }


            // } Driver Code Ends
            /*  Tree node
            struct Node
            {
                int data;
                Node* left, * right;
            }; */

            // Should return true if tree is Sum Tree, else false
            class Solution
            {
                int isSumTree(Node* root, bool& Ok) {
                    if(root->left == nullptr && root->right == nullptr)
                        return root->data;
                    int left = 0, right = 0;
                    if(root->left != nullptr)
                        left = isSumTree(root->left, Ok);
                    if(root->right != nullptr)
                        right = isSumTree(root->right, Ok);
                    Ok &= ((left + right) == root->data);
                    return left + right + root->data;
                }
                public:
                bool isSumTree(Node* root)
                {
                    // Your code here
                    bool Ok = true;
                    isSumTree(root, Ok);
                    return Ok;
                }
            };

            //{ Driver Code Starts.

            int main()
            {

                int t;
                scanf("%d ",&t);
                while(t--)
                {
                    string s;
                    getline(cin,s);
                    Node* root = buildTree(s);
                    Solution ob;
                    cout <<ob.isSumTree(root) << endl;
                }
                return 1;
            }
            // } Driver Code Ends
        
    </details>

---





* [ ] [Vertical Order Traversal of a Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/) 
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
                void traverse(TreeNode* root, int row, int col, map<pair<int,int>, multiset<int>>& vertical) {
                    if(root == nullptr)
                        return;
                    vertical[{row, col}].insert(root->val);
                    traverse(root->left, row + 1, col - 1, vertical);
                    traverse(root->right, row + 1, col + 1, vertical);
                }
            public:
                vector<vector<int>> verticalTraversal(TreeNode* root) {
                    vector<vector<int>> res;
                    map<pair<int,int>, multiset<int>> vertical;
                    map<int, vector<int>> before;
                    traverse(root, 0, 0, vertical);
                    for(auto &it: vertical) {
                        for(auto vals: it.second)
                            before[it.first.second].push_back(vals);
                    }
                    for(auto &it: before) {
                        res.push_back(vector<int>());
                        for(auto vals: it.second)
                            res.back().push_back(vals);
                    }
                    return res;
                }
            };
        
    </details>

---





* [ ] [Delete a node from BST](https://www.geeksforgeeks.org/problems/delete-a-node-from-bst/1?page=2&category=Tree,Binary%20Search%20Tree&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;
            #define MAX_HEIGHT 100000

            // Tree Node
            struct Node {
                int data;
                Node* left;
                Node* right;

                Node(int val) {
                    data = val;
                    left = right = NULL;
                }
            };

            struct Node* deleteNode(struct Node* root, int key);

            // Function to Build Tree
            Node* buildTree(string str) {
                // Corner Case
                if (str.length() == 0 || str[0] == 'N') return NULL;

                // Creating vector of strings from input
                // string after spliting by space
                vector<string> ip;

                istringstream iss(str);
                for (string str; iss >> str;) ip.push_back(str);

                // Create the root of the tree
                Node* root = new Node(stoi(ip[0]));

                // Push the root to the queue
                queue<Node*> queue;
                queue.push(root);

                // Starting from the second element
                int i = 1;
                while (!queue.empty() && i < ip.size()) {

                    // Get and remove the front of the queue
                    Node* currNode = queue.front();
                    queue.pop();

                    // Get the current node's value from the string
                    string currVal = ip[i];

                    // If the left child is not null
                    if (currVal != "N") {

                        // Create the left child for the current node
                        currNode->left = new Node(stoi(currVal));

                        // Push it to the queue
                        queue.push(currNode->left);
                    }

                    // For the right child
                    i++;
                    if (i >= ip.size()) break;
                    currVal = ip[i];

                    // If the right child is not null
                    if (currVal != "N") {

                        // Create the right child for the current node
                        currNode->right = new Node(stoi(currVal));

                        // Push it to the queue
                        queue.push(currNode->right);
                    }
                    i++;
                }

                return root;
            }

            void inorder(Node* root, vector<int>& v) {
                if (root == NULL) return;

                inorder(root->left, v);
                v.push_back(root->data);
                inorder(root->right, v);
            }

            int main() {

                int t;
                string tc;
                getline(cin, tc);
                t = stoi(tc);
                while (t--) {
                    string s;
                    getline(cin, s);
                    Node* root1 = buildTree(s);
                    getline(cin, s);
                    int k = stoi(s);
                    root1 = deleteNode(root1, k);
                    vector<int> v;
                    inorder(root1, v);
                    for (auto i : v) cout << i << " ";
                    cout << endl;
                }
                return 0;
            }
            // } Driver Code Ends


            // Function to delete a node from BST.
            Node *deleteNode(Node *root, int X) {
                // your code goes here
                if(root == nullptr)
                    return root;
                if(root->data == X) {
                    Node* successor = nullptr;
                    if(root->left != nullptr && root->right != nullptr) {
                        Node* nextPlace = root->left;
                        while(nextPlace->right != nullptr)
                            nextPlace = nextPlace->right;
                        swap(root->data, nextPlace->data);
                        root->left = deleteNode(root->left, X);
                        
                        successor = root;
                    }
                    else if(root->left != nullptr)
                        successor = root->left;
                    else if(root->right != nullptr)
                        successor = root->right;
                    
                    return successor;
                }
                
                if(root->data > X)
                    root->left = deleteNode(root->left, X);
                else 
                    root->right = deleteNode(root->right, X);
                return root;
            }

        
    </details>

---





* [ ] [Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii/description/) 
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
                vector<TreeNode*> BST(int left, int right) {
                    if(left > right)
                        return {nullptr};
                    if(left == right)
                        return {new TreeNode(right)};
                        
                    vector<TreeNode*> res;
                    for(int i = left; i <= right;i++) {

                        vector<TreeNode*> leftNodes = BST(left, i - 1);
                        vector<TreeNode*> rightNodes = BST(i + 1, right);

                        for(auto &leftNode: leftNodes) {
                            for(auto &rightNode: rightNodes) {
                                TreeNode* root = new TreeNode(i);
                                root->left = leftNode;
                                root->right = rightNode;
                                res.push_back(root);
                            }
                        }
                    }

                    return res;
                }
            public:
                vector<TreeNode*> generateTrees(int n) {
                    return BST(1, n);
                }
            };
        
    </details>

---




* [ ] [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/description/) 
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
                void inorder(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& last) {
                    if(root == nullptr)
                        return;
                    inorder(root->left, first, second, last);
                    if(root->val < last->val) {
                        if(first == nullptr)
                            first = last;
                        second = root;
                    }
                    last = root;
                    inorder(root->right, first, second, last);
                }
            public:
                void recoverTree(TreeNode* root) {
                    TreeNode* first = nullptr, *second = nullptr, *last = new TreeNode(INT_MIN);
                    inorder(root, first, second, last);
                    swap(first->val, second->val);
                }
            };
        
    </details>

---




* [ ] [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/) 
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
                int lowestAncestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& res) {
                    if(root == nullptr)
                        return 0;
                    int ret = ((root->val == p->val) || (root->val == q->val));
                    ret += lowestAncestor(root->left, p, q, res);
                    ret += lowestAncestor(root->right, p, q, res);
                    if(ret == 2 && res == nullptr)
                        res = root;
                    return ret;
                }
            public:
                TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
                    TreeNode* res = nullptr;
                    lowestAncestor(root, p, q, res);
                    return res;
                }
            };
        
    </details>

---





* [ ] [Serialize and Deserialize BST](https://leetcode.com/problems/serialize-and-deserialize-bst/description/) 
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
            class Codec {
                void serialize(TreeNode* root, string& res) {
                    if(!res.empty())
                        res += '-';
                    if(root == nullptr) {
                        res += 'N';
                        return;
                    }
                    res += to_string(root->val);
                    serialize(root->left, res);
                    serialize(root->right, res);
                }

                TreeNode* deserialize(int& idx, int n, string& data) {
                    if(idx >= n )
                        return nullptr;
                    if(data[idx] == 'N') {
                        idx += 2;
                        return nullptr;
                    }
                    string num = "";
                    while(isdigit(data[idx])) {
                        num += data[idx];
                        idx += 1;
                    }
                    idx += 1;
                    TreeNode* root = new TreeNode(stoi(num));
                    root->left = deserialize(idx, n, data);
                    root->right = deserialize(idx, n, data);
                    return root;
                }
            public:

                // Encodes a tree to a single string.
                string serialize(TreeNode* root) {
                    string res = "";
                    serialize(root, res);
                    return res;
                }

                // Decodes your encoded data to tree.
                TreeNode* deserialize(string data) {
                    // 2-1-N-N-3-N-N
                    int n = data.size(), idx = 0;
                    return deserialize(idx, n, data);
                }
            };

            // Your Codec object will be instantiated and called as such:
            // Codec* ser = new Codec();
            // Codec* deser = new Codec();
            // string tree = ser->serialize(root);
            // TreeNode* ans = deser->deserialize(tree);
            // return ans;
        
    </details>

---






* [ ] [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/description/) 
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
                TreeNode* deleteNode(TreeNode* root, int key) {
                    if(root == nullptr)
                        return root;
                    if(root->val == key) {
                        if(root->left != nullptr && root->right != nullptr) {
                            TreeNode* temp = root->left;
                            while(temp->right != nullptr)
                                temp = temp->right;
                            swap(root->val, temp->val);
                            root->left = deleteNode(root->left, key);
                        }
                        else if(root->left != nullptr)
                            root = root->left;
                        else
                            root = root->right;
                    }
                    else if(root->val > key)
                        root->left = deleteNode(root->left, key);
                    else
                        root->right = deleteNode(root->right, key);
                    return root;
                }
            };
        
    </details>

---






* [ ] [Convert BST to Greater Tree](https://leetcode.com/problems/convert-bst-to-greater-tree/description/) 
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
                void convertBST(TreeNode* root, int& sum) {
                    if(root == nullptr)
                        return;
                    convertBST(root->right, sum);
                    sum += root->val;
                    root->val = sum;
                    convertBST(root->left, sum);
                }
            public:
                TreeNode* convertBST(TreeNode* root) {
                    int sum = 0;
                    convertBST(root, sum);
                    return root;
                }
            };
        
    </details>

---




* [ ] [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/) 
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
                bool findTarget(TreeNode* root, int target, unordered_map<int, bool>& vis) {
                    if (root == nullptr)
                        return false;
                    if (vis[target - root->val] == true)
                        return true;
                    bool find = false;
                    vis[root->val] = true;
                    find |= findTarget(root->left, target, vis);
                    find |= findTarget(root->right, target, vis);
                    return find;
                }
            public:
                bool findTarget(TreeNode* root, int k) {
                    unordered_map<int, bool> vis;
                    return findTarget(root, k, vis);
                }
            };
        
    </details>

---





* [ ] [Trim a Binary Search Tree](https://leetcode.com/problems/trim-a-binary-search-tree/description/) 
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
                TreeNode* trimBST(TreeNode* root, int low, int high) {
                    if(root == nullptr)
                        return root;
                    if(root->val >= low && root->val <= high) {
                        root->left = trimBST(root->left, low, high);
                        root->right = trimBST(root->right, low, high);
                    }
                    else if(root->val < low)
                        root = trimBST(root->right, low, high);
                    else
                        root = trimBST(root->left, low, high);
                    return root;
                }
            };
        
    </details>

---



* [ ] [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class KthLargest {
                struct Node {
                    int val;
                    Node* left;
                    Node* right;
                    Node(int _val) : val(_val), left(nullptr), right(nullptr) {}
                };

                Node* root;
                int kthElement;

                void search(Node* _root, int& index, int& kth) {
                    if(_root == nullptr)
                        return;
                    search(_root->right, index, kth);
                    index += 1;
                    if(index == kthElement) {
                        kth = _root->val;
                        return;
                    }
                    search(_root->left, index, kth);
                }

                Node* add(Node* _root, int _val) {
                    if(_root == nullptr) {
                        return new Node(_val);
                    }
                    if(_root->val >= _val)
                        _root->left = add(_root->left, _val);
                    else
                        _root->right = add(_root->right, _val);
                    return _root;
                }
            public:
                KthLargest(int k, vector<int>& nums) {
                    root = nullptr;
                    kthElement = k;
                    for(auto &_val: nums)
                        root = add(root, _val);
                }
                
                int add(int val) {
                    int index = 0, kth = -1;
                    root = add(root, val);
                    search(root, index, kth);
                    return kth;
                }
            };

            /**
            * Your KthLargest object will be instantiated and called as such:
            * KthLargest* obj = new KthLargest(k, nums);
            * int param_1 = obj->add(val);
            */
        
    </details>

---




* [ ] [Minimum Distance Between BST Nodes](https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/) 
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
                int minDiffInBST(TreeNode* root) {
                    if(root == nullptr)
                        return INT_MAX;
                    int ret = INT_MAX;
                    ret = minDiffInBST(root->left);
                    ret = ret = min(ret, minDiffInBST(root->right));
                    TreeNode* tempLeft = root->left, *tempRight = root->right;
                    while(tempLeft != nullptr && tempLeft->right != nullptr)
                        tempLeft = tempLeft->right;
                    while(tempRight != nullptr && tempRight->left != nullptr)
                        tempRight = tempRight->left;
                    if(tempLeft != nullptr)
                        ret = min(ret, root->val - tempLeft->val);
                    if(tempRight != nullptr)
                        ret = min(ret, tempRight->val - root->val);
                    return ret;
                }
            };
        
    </details>

---




* [ ] [Increasing Order Search Tree](https://leetcode.com/problems/increasing-order-search-tree/description/) 
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
                void inOrder(TreeNode* root, TreeNode*& newRoot, TreeNode*& temp) {
                    if(root == nullptr)
                        return;
                    inOrder(root->left, newRoot, temp);
                    if(newRoot == nullptr)
                        newRoot = temp = new TreeNode(root->val);
                    else {
                        temp->right = new TreeNode(root->val);
                        temp = temp->right;
                    }
                    inOrder(root->right, newRoot, temp);
                }
            public:
                TreeNode* increasingBST(TreeNode* root) {
                    TreeNode* newRoot = nullptr, *temp = nullptr;
                    inOrder(root, newRoot, temp);
                    return newRoot;
                }
            };
        
    </details>

---