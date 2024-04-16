# Recursion :

* [ ] [Level order traversal in spiral form](https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1?page=1&category=Recursion&company=Microsoft&sortBy=submissions)
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
            // Utility function to create a new Tree Node
            Node* newNode(int val)
            {
                Node* temp = new Node;
                temp->data = val;
                temp->left = NULL;
                temp->right = NULL;

                return temp;
            }

            vector<int> findSpiral(Node *root);

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


            int main() {
                int t;
                string  tc;
                getline(cin,tc);
                t=stoi(tc);
                while(t--)
                {
                    string s;
                    getline(cin,s);
                    Node* root = buildTree(s);

                    vector<int> vec = findSpiral(root);
                    for(int x : vec)
                    cout<<x<<" ";
                    cout << endl;
                }
                return 0;
            }



            // } Driver Code Ends


            /* A binary tree node has data, pointer to left child
            and a pointer to right child  
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

            int maxLevel(Node* root) {
                if(root == nullptr) return 0;
                int ret = 1;
                ret += max(maxLevel(root->left), maxLevel(root->right));
                return ret;
            }

            void Spiral(Node* root, vector<vector<int>>& res, int level) {
                if(root == nullptr) return;
                res[level].push_back(root->data);
                Spiral(root->left, res, level + 1);
                Spiral(root->right, res, level + 1);
            }

            //Function to return a list containing the level order traversal in spiral form.
            vector<int> findSpiral(Node *root)
            {
                //Your code here
                int level = maxLevel(root);
                vector<vector<int>> res(level);
                vector<int> ans;
                Spiral(root, res, 0);
                for(int i = 0; i < level;i++) {
                    int sz = res[i].size();
                    int idx = 0;
                    if(i % 2 == 0) idx = sz - 1;
                    while(idx >= 0 && idx < sz) {
                        ans.push_back(res[i][idx]);
                        (i % 2 == 1 ? ++idx : --idx);
                    }
                }
                return ans;
            }

        
    </details>

---


* [ ] [Lucky Numbers](https://www.geeksforgeeks.org/problems/lucky-numbers2911/1?page=1&category=Recursion&company=Microsoft&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            //Initial Template for C++


            #include <bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends
            //User-function template for C++

            // Complete the function
            // n: Input n
            // Return True if the given number is a lucky number else return False

            class Solution{
                bool checkLucky(int n, int x) {
                    if(n < x) return true;
                    bool flag = false;
                    if(n % x != 0) {
                        flag |= checkLucky(n - n / x, x + 1);
                    }
                    return flag;
                }
            public:
                bool isLucky(int n) {
                    return checkLucky(n, 2);
                }
            };

            //{ Driver Code Starts.
            signed main(){
                int T;
                cin>>T;
                while(T--){
                    int n;
                    cin>>n;
                    Solution obj;
                    //calling isLucky() function
                    if(obj.isLucky(n))
                        cout<<"1\n";//printing "1" if isLucky() returns true
                    else
                        cout<<"0\n";//printing "0" if isLucky() returns false
                }
                
            }
            // } Driver Code Ends

    </details>

---



* [ ] [Sort a stack](https://www.geeksforgeeks.org/problems/sort-a-stack/1?page=1&category=Recursion&company=Microsoft&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include<bits/stdc++.h>
            using namespace std;

            class SortedStack{
            public:
                stack<int> s;
                void sort();
            };

            void printStack(stack<int> s)
            {
                while (!s.empty())
                {
                    printf("%d ", s.top());
                    s.pop();
                }
                printf("\n");
            }

            int main()
            {
            int t;
            cin>>t;
            while(t--)
            {
                SortedStack *ss = new SortedStack();
                int n;
                cin>>n;
                for(int i=0;i<n;i++)
                {
                int k;
                cin>>k;
                ss->s.push(k);
                }
                ss->sort();
                printStack(ss->s);
            }
            }
            // } Driver Code Ends


            /*The structure of the class is
            class SortedStack{
            public:
                stack<int> s;
                void sort();
            };
            */

            /* The below method sorts the stack s 
            you are required to complete the below method */

            int sortStack(stack<int>& st, int compare) {
                if(st.empty()) return -1;
                int top = st.top();
                st.pop();
                if(top > compare) {
                    return top;
                }
                int ret = sortStack(st, top);
                if(ret > top || ret == -1) {
                    st.push(top);
                }
                else {
                    st.push(ret);
                    ret = top;
                }
                return ret;
            }
            void SortedStack :: sort()
            {
                //Your code here
                int ret = 0;
                do {
                    ret = sortStack(s, INT_MAX);
                    if(ret != -1) s.push(ret);
                    //   cout << ret << ' ' << s.size() << endl;
                } while(ret != -1);
            }

    </details>

---




* [ ] [Pascal Triangle](https://www.geeksforgeeks.org/problems/pascal-triangle0652/1?page=1&category=Recursion&company=Microsoft&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends
            // #define ll long long
            #define MOD 1000000007

            class Solution{
            public:
                vector<long long> nthRowOfPascalTriangle(int n) {
                    // code here
                    if(n == 1) {
                        vector<long long> pascal {1};
                        return pascal;
                    }
                    vector<long long> pascal = nthRowOfPascalTriangle(n - 1);
                    vector<long long> nextPascal {1};
                    for(int i = 1; i < pascal.size(); i++) {
                        long long result = ((pascal[i] % MOD) + (pascal[i - 1] % MOD)) % MOD;
                        nextPascal.push_back(result);
                    }
                    nextPascal.push_back(1);
                    return nextPascal;
                }
            };


            //{ Driver Code Starts.


            void printAns(vector<long long> &ans) {
                for (auto &x : ans) {
                    cout << x << " ";
                }
                cout << "\n";
            }

            int main() {
                int t;
                cin >> t;
                while (t--) {
                    int n;
                    cin >> n;
                    Solution ob;
                    auto ans = ob.nthRowOfPascalTriangle(n);
                    printAns(ans);
                }
                return 0;
            }

            // } Driver Code Ends

    </details>

---



* [ ] [Josephus problem](https://www.geeksforgeeks.org/problems/josephus-problem/1?page=1&category=Recursion&company=Microsoft&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;



            // } Driver Code Ends
            /*You are required to complete this method */

            class Solution
            {
                public:
                int josephus(int n, int k)
                {
                    if(n == 1) return 1;
                    return (josephus(n - 1, k) + k - 1) % n + 1;
                }
            };



            //{ Driver Code Starts.

            int main() {
                
                int t;
                cin>>t;//testcases
                while(t--)
                {
                    int n,k;
                    cin>>n>>k;//taking input n and k
                    
                    //calling josephus() function
                    Solution ob;
                    cout<<ob.josephus(n,k)<<endl;
                }
                return 0;
            }
            // } Driver Code Ends

    </details>

---




* [ ] [Print Pattern](https://www.geeksforgeeks.org/problems/print-pattern3549/1?page=1&category=Recursion&company=Microsoft&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            // Initial Template for C++

            #include <bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends
            // User function Template for C++

            class Solution{
                void pattern(int N, vector<int> &res) {
                    if(N <= 0) {
                        res.push_back(N);
                        return;
                    }
                    res.push_back(N);
                    pattern(N - 5, res);
                    res.push_back(N);
                }
            public:
                vector<int> pattern(int N){
                    // code here
                    vector<int> res;
                    pattern(N, res);
                    return res;
                }
            };

            //{ Driver Code Starts.

            int main(){
                int t;
                cin>>t;
                while(t--){
                    int N;
                    cin>>N;
                    
                    Solution ob;
                    vector<int> ans = ob.pattern(N);
                    for(int u: ans)
                        cout<<u<<" ";
                    cout<<"\n";
                }
                return 0;
            }
            // } Driver Code Ends

    </details>

---



* [ ] [Find the string in grid](https://www.geeksforgeeks.org/problems/find-the-string-in-grid0111/1?page=1&category=Recursion&company=Microsoft&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include<bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends
            class Solution {
                int dx[8] {1, -1, 0, 0, 1, 1, -1, -1};
                int dy[8] {0, 0, 1, -1, 1, -1, 1, -1};
                bool isValid(int x, int y, int n, int m) {
                    return (x >= 0 && x < n && y >= 0 && y < m);
                }
                bool search(int x, int y, int& n, int& m, int& dir, int idx, string& word, vector<vector<char>>& grid) {
                    if(idx == word.size()) return true;
                    if(!isValid(x, y, n, m) || grid[x][y] != word[idx]) return false;
                    bool flag = false;
                    int newX = dx[dir] + x;
                    int newY = dy[dir] + y;
                    flag |= search(newX, newY, n, m, dir, idx + 1, word, grid);
                    return flag;
                }
            public:
                vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
                    int n = grid.size();
                    int m = grid[0].size();
                    vector<vector<int>> res;
                    for(int i = 0; i < n;i++) {
                        for(int j = 0; j < m;j++) {
                            for(int dir = 0; dir < 8;dir++) {
                                if(search(i, j, n, m, dir, 0, word, grid) == true) {
                                    res.push_back(vector<int>{i, j});
                                    break;
                                }
                            }
                        }
                    }
                    return res;
                }
            };

            //{ Driver Code Starts.
            int main(){
                int tc;
                cin >> tc;
                while(tc--){
                    int n, m;
                    cin >> n >> m;
                    vector<vector<char>>grid(n, vector<char>(m,'x'));
                    for(int i = 0; i < n; i++){
                        for(int j = 0; j < m; j++)
                            cin >> grid[i][j];
                    }
                    string word;
                    cin >> word;
                    Solution obj;
                    vector<vector<int>>ans = obj.searchWord(grid, word);
                    if(ans.size() == 0)
                    {
                        cout<<"-1\n";
                    }
                    else
                    {
                        for(auto i: ans){
                        for(auto j: i)
                            cout << j << " ";
                        cout << "\n";
                        }
                    }
                    
                    
                }
                return 0;
            }
            // } Driver Code Ends

    </details>

---



