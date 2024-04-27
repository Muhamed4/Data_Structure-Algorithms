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



* [ ] [Count Number of SubTrees having given Sum](https://www.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1?page=1&category=Recursion&company=Microsoft&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            //Initial Template for C++
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

            // Your are required to complete this function
            int countSubtreesWithSumX(Node* root, int x);

            int main()
            {
                int t;
                cin>>t;
                getchar();
                while (t--)
                {
                    string s;
                    getline(cin,s);
                    Node* root = buildTree(s);
                    
                    int x;
                    cin>>x;
                    getchar();
                    cout << countSubtreesWithSumX(root, x)<<endl;
                }
                return 0;
            }


            // } Driver Code Ends


            //User function Template for C++
            /*
            Structure of the node of the binary tree is as
            struct Node
            {
                int data;
                struct Node* left;
                struct Node* right;
            };
            */

            int countSubtreesWithSumX(Node* root, int X, int& res) {
                if(root == nullptr) return 0;
                int sum = root->data;
                sum += countSubtreesWithSumX(root->left, X, res);
                sum += countSubtreesWithSumX(root->right, X, res);
                if(sum == X) ++res;
                return sum;
            }
            //Function to count number of subtrees having sum equal to given sum.
            int countSubtreesWithSumX(Node* root, int X)
            {
                // Code here
                int res = 0;
                countSubtreesWithSumX(root, X, res);
                return res;
            }


    </details>

---




* [ ] [Generate Parentheses](https://www.geeksforgeeks.org/problems/generate-all-possible-parentheses/1?page=1&category=Recursion&company=Microsoft&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            //Initial Template for C++

            #include <bits/stdc++.h>
            using namespace std;
            vector<string> AllParenthesis(int n) ;


            // } Driver Code Ends
            //User function Template for C++

            // N is the number of pairs of parentheses
            // Return list of all combinations of balanced parantheses
            class Solution
            {
                void generate(int idx, int& n, int open, string& cur, vector<string>& res) {
                    if(idx == n) {
                        if(open == 0) res.push_back(cur);
                        return;
                    }
                    cur += '(';
                    generate(idx + 1, n, open + 1, cur, res);
                    cur.pop_back();
                    if(open) {
                        cur += ')';
                        generate(idx + 1, n, open - 1, cur, res);
                        cur.pop_back();
                    }
                }
                public:
                vector<string> AllParenthesis(int n) 
                {
                    // Your code goes here 
                    vector<string> res;
                    string cur = "";
                    n *= 2;
                    generate(0, n, 0, cur, res);
                    return res;
                }
            };

            //{ Driver Code Starts.


            int main() 
            { 
                int t;
                cin>>t;
                while(t--)
                {
                    int n;
                    cin>>n;
                    Solution ob;
                    vector<string> result = ob.AllParenthesis(n); 
                    sort(result.begin(),result.end());
                    for (int i = 0; i < result.size(); ++i)
                        cout<<result[i]<<"\n";
                }
                return 0; 
            } 

            // } Driver Code Ends

    </details>

---


* [ ] [Subsets](https://www.geeksforgeeks.org/problems/subsets-1613027340/1?page=1&category=Recursion&company=Microsoft&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            //Initial Template for C++

            #include <bits/stdc++.h>
            using namespace std;


            // } Driver Code Ends
            //User function Template for C++

            class Solution
            {
                void sets(int idx, int& n, vector<int>& v, vector<int>& cur, vector<vector<int>>& res) {
                    if(idx == n) {
                        res.push_back(cur);
                        return;
                    }
                    sets(idx + 1, n, v, cur, res);
                    cur.push_back(v[idx]);
                    sets(idx + 1, n, v, cur, res);
                    cur.pop_back();
                }
                public:
                vector<vector<int>> subsets(vector<int>& A)
                {
                    //code here
                    int n = A.size();
                    vector<vector<int>> res;
                    vector<int> cur;
                    sets(0, n, A, cur, res);
                    sort(res.begin(), res.end());
                    //cout << res.size() << endl;
                    return res;
                }
            };

            //{ Driver Code Starts.

            int main()
            {
                int t;
                cin >> t;

                while (t--)
                {
                    int n, x;
                    cin >> n;

                    vector<int> array;
                    for (int i = 0; i < n; i++)
                    {
                        cin >> x;
                        array.push_back(x);
                    }
                    
                    
                    Solution ob;
                    vector<vector<int> > res = ob.subsets(array);

                    // Print result
                    for (int i = 0; i < res.size(); i++) {
                        for (int j = 0; j < res[i].size(); j++)
                            cout << res[i][j] << " ";
                        cout << endl;
                    }

                    
                }

                return 0;
            }
            // } Driver Code Ends

    </details>

---





# BackTracking :


* [ ] [Permutations of a given string](https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1?page=1&category=Recursion,Backtracking&company=Microsoft&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include<bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends
            class Solution
            {
                void permutation(int idx, int& n, string& s, string& cur, vector<string>& res, unordered_map<string, bool>& vis) {
                    if(idx == n) {
                        if(vis.count(cur) == 0) res.push_back(cur);
                        vis[cur] = true;
                        return;
                    }
                    for(int i = 0; i < n;i++) {
                        if(s[i] != '#') {
                            char ch = s[i];
                            cur += ch;
                            s[i] = '#';
                            permutation(idx + 1, n, s, cur, res, vis);
                            cur.pop_back();
                            s[i] = ch;
                        }
                    }
                }
                public:
                    vector<string>find_permutation(string S)
                    {
                        // Code here there
                        int n = S.size();
                        string cur = "";
                        vector<string> res;
                        unordered_map<string, bool> vis;
                        permutation(0, n, S, cur, res, vis);
                        return res;
                    }
            };



            //{ Driver Code Starts.
            int main(){
                int t;
                cin >> t;
                while(t--)
                {
                    string S;
                    cin >> S;
                    Solution ob;
                    vector<string> ans = ob.find_permutation(S);
                    sort(ans.begin(),ans.end());
                    for(auto i: ans)
                    {
                        cout<<i<<" ";
                    }
                    cout<<"\n";
                }
                return 0;
            }

            // } Driver Code Ends

    </details>

---


* [ ] [Rat in a Maze Problem - I](https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1?page=1&category=Recursion,Backtracking&company=Microsoft&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            // Initial template for C++

            #include <bits/stdc++.h>
            using namespace std;


            // } Driver Code Ends
            // User function template for C++

            class Solution{
                int dx[4] = {1, -1, 0, 0};
                int dy[4] = {0, 0, -1, 1};
                bool isValid(int x, int y, int n) {
                    return (x >= 0 && x < n && y >= 0 && y < n);
                }
                void dfs(int x, int y, int& n, string& cur, vector<string>& paths, vector<vector<int>>& grid) {
                    if(!isValid(x, y, n) || grid[x][y] == -1 || grid[x][y] == 0) return;
                    if(x == n - 1 && y == n - 1) {
                        paths.push_back(cur);
                        return;
                    }
                    grid[x][y] = -1;
                    for(int i = 0; i < 4;i++) {
                        int newX = x + dx[i];
                        int newY = y + dy[i];
                        if(newX > x) cur += 'D';
                        else if(newX < x) cur += 'U';
                        else if(newY > y) cur += 'R';
                        else cur += 'L';
                        dfs(newX, newY, n, cur, paths, grid);
                        cur.pop_back();
                    }
                    grid[x][y] = 1;
                }
                public:
                vector<string> findPath(vector<vector<int>> &m, int n) {
                    // Your code goes here
                    vector<string> paths;
                    string cur = "";
                    dfs(0, 0, n, cur, paths, m);
                    return paths;
                }
            };

                


            //{ Driver Code Starts.

            int main() {
                int t;
                cin >> t;
                while (t--) {
                    int n;
                    cin >> n;
                    vector<vector<int>> m(n, vector<int> (n,0));
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            cin >> m[i][j];
                        }
                    }
                    Solution obj;
                    vector<string> result = obj.findPath(m, n);
                    sort(result.begin(), result.end());
                    if (result.size() == 0)
                        cout << -1;
                    else
                        for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
                    cout << endl;
                }
                return 0;
            }
            // } Driver Code Ends

    </details>

---



* [ ] [Rat in a Maze Problem - I](https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1?page=1&category=Recursion,Backtracking&company=Microsoft&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            //Initial template for C++

            #include <bits/stdc++.h>
            using namespace std;


            // } Driver Code Ends
            //User function template for C++

            class Solution {
                int MOD = 1000000007;
                int fpow(int n, int x) {
                    if (x == 0) {
                        return 1;
                    }
                    if (x == 1) {
                        return n % MOD;
                    }
                    int ans = fpow(n, x / 2) % MOD;
                    ans = (ans % MOD) * (ans % MOD) % MOD;
                    if (x & 1) {
                        ans = (ans % MOD) * (n % MOD) % MOD;
                    }
                    return ans;
                }
                void Combination(int idx, int n, int target, vector<int>& A, vector<int> cur, vector<vector<int>>& res,
                                unordered_map<int, bool>& vis, int hashed) {
                    if(idx == n) {
                        if(target == 0 && vis.count(hashed) == false) {
                            vis[hashed] = true;
                            res.push_back(cur);
                        }
                        return;
                    }
                    int temp = target;
                    Combination(idx + 1, n, target, A, cur, res, vis, hashed);
                    while(temp >= A[idx]) {
                        temp -= A[idx];
                        cur.push_back(A[idx]);
                        // Hashing here is useless because we get the different elements but in case there is a duplication, hashing will be useful :)
                        int pos = cur.size() - 1;
                        hashed = ((hashed % MOD) + ((A[idx] * fpow(10, pos)) % MOD) % MOD);
                        Combination(idx + 1, n, temp, A, cur, res, vis, hashed);
                    }
                }
            public:
                //Function to return a list of indexes denoting the required 
                //combinations whose sum is equal to given number.
                vector<vector<int>> combinationSum(vector<int> &A, int B) {
                    // Your code here
                    vector<vector<int>> res;
                    unordered_map<int, bool> vis;
                    sort(A.begin(), A.end());
                    vector<int> cur, newA {A[0]};
                    for(int i = 1; i < A.size();i++) {
                        if(A[i] != A[i - 1]) newA.push_back(A[i]);
                    }
                    int n = newA.size();
                    Combination(0, n, B, newA, cur, res, vis, 0);
                    sort(res.begin(), res.end());
                    return res;
                }
            };


            //{ Driver Code Starts.
            int main(){
                int t;
                cin>>t;
                while(t--){
                    int n;
                    cin>>n;
                    vector<int> A;
                    for(int i=0;i<n;i++){
                        int x;
                        cin>>x;
                        A.push_back(x);
                    }   
                    int sum;
                    cin>>sum;
                    Solution ob;
                    vector<vector<int>> result = ob.combinationSum(A, sum);
                    if(result.size()==0){
                        cout<<"Empty";
                    }
                    for(int i=0;i<result.size();i++){
                        cout<<'(';
                        for(int j=0;j<result[i].size();j++){
                            cout<<result[i][j];
                            if(j<result[i].size()-1)
                                cout<<" ";
                        }
                        cout<<")";
                    }
                    cout<<"\n";
                }
            }	
            // } Driver Code Ends

    </details>

---



* [ ] [Tower Of Hanoi](https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1?page=1&category=Recursion,Backtracking&company=Microsoft&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>

            using namespace std;


            // } Driver Code Ends
            class Solution{
                public:
                // You need to complete this function
                void TowerHanoi(int n, int from, int aux, int to) {
                    if(n == 0) return;
                    TowerHanoi(n - 1, from, to, aux);
                    cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
                    TowerHanoi(n - 1, aux, from, to);
                }

                // avoid space at the starting of the string in "move disk....."
                long long toh(int N, int from, int to, int aux) {
                    // Your code here
                    TowerHanoi(N, from, aux, to);
                    return (1 << N) - 1;
                }

            };

            //{ Driver Code Starts.

            int main() {

                int T;
                cin >> T;//testcases
                while (T--) {
                    
                    int N;
                    cin >> N;//taking input N
                    
                    //calling toh() function
                    Solution ob;
                    
                    cout << ob.toh(N, 1, 3, 2) << endl;
                }
                return 0;
            }



            // } Driver Code Ends

    </details>

---



* [ ] [Largest number in K swaps](https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1?page=1&category=Recursion,Backtracking&company=Microsoft&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;


            // } Driver Code Ends


            class Solution
            {
                void swapStr(int idx, int& n, string& str, int k, string& result) {
                    if(idx == n || k == 0) {
                        result = max(result, str);
                        return;
                    }
                    char c = str[idx];
                    for(int i = idx; i < n;i++) {
                        c = max(c, str[i]);
                    }
                    for(int i = idx; i < n;i++) {
                        if(str[i] == c) {
                            swap(str[idx], str[i]);
                            swapStr(idx + 1, n, str, k - (i != idx), result);
                            swap(str[idx], str[i]);
                        }
                    }
                }
                public:
                //Function to find the largest number after k swaps.
                string findMaximumNum(string str, int k)
                {
                    // code here.
                    int n = str.size();
                    string result = "";
                    swapStr(0, n, str, k, result);
                    return result;
                }
            };

            //{ Driver Code Starts.

            int main()
            {
                int t, k;
                string str;

                cin >> t;
                while (t--)
                {
                    cin >> k >> str;
                    Solution ob;
                    cout<< ob.findMaximumNum(str, k) << endl;
                }
                return 0;
            }

            // } Driver Code Ends

    </details>

---



* [ ] [Unique Subsets](https://www.geeksforgeeks.org/problems/subsets-1587115621/1?page=2&category=Recursion,Backtracking&company=Microsoft&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;


            // } Driver Code Ends
            class Solution
            {
                int MOD = 1000000007;
                int fpow(int n, int x) {
                    if(x == 0) return 1;
                    if(x == 1) return n;
                    int ans = fpow(n, x / 2) % MOD;
                    ans = (ans % MOD) * (ans % MOD);
                    if(x & 1) ans = ((ans % MOD) * n) % MOD;
                    return ans;
                }
                void Subsets(int idx, int n, int hash, vector<int>& v, vector<int>& cur, vector<vector<int>>& result, unordered_map<int, int>&hashed) {
                    if(idx == n) {
                        if(hashed.count(hash) == false) {
                            hashed[hash] = true;
                            result.push_back(cur);
                        }
                        return;
                    }
                    Subsets(idx + 1, n, hash, v, cur, result, hashed);
                    cur.push_back(v[idx]);
                    int pos = cur.size();
                    hash = ((hash % MOD) + (v[idx] * fpow(10, pos) % MOD)) % MOD;
                    Subsets(idx + 1, n, hash, v, cur, result, hashed);
                    cur.pop_back();
                }
                public:
                //Function to find all possible unique subsets.
                vector<vector<int> > AllSubsets(vector<int> arr, int n)
                {
                    // code here 
                    vector<int> cur;
                    vector<vector<int>>result;
                    unordered_map<int, int> hashed;
                    sort(arr.begin(), arr.end());
                    Subsets(0, n, 0, arr, cur, result, hashed);
                    sort(result.begin(), result.end());
                    return result;
                }
            };

            //{ Driver Code Starts.

            int main(){
                int t;
                cin>>t;
                while(t--){
                    int n;
                    cin>>n;
                    vector<int> A;
                    int x;
                    for(int i=0;i<n;i++){
                        cin>>x;
                        A.push_back(x);
                    }
                    Solution obj;
                    vector<vector<int> > result = obj.AllSubsets(A,n);
                    // printing the output
                    for(int i=0;i<result.size();i++){
                        cout<<'(';
                        for(int j=0;j<result[i].size();j++){
                            cout<<result[i][j];
                            if(j<result[i].size()-1)
                                cout<<" ";
                        }
                        cout<<")";
                    }
                    cout<<"\n";
                }
            }   



            // } Driver Code Ends

    </details>

---



* [ ] [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                bool Solve(int row, int col, int n, vector<vector<char>>& board,
                        map<pair<int, char>, bool>& rows,
                        map<pair<int, char>, bool>& cols,
                        map<pair<int, char>, bool>& boxes) {
                    if (row == n - 1 && col == n)
                        return true;
                    if (col == n) {
                        return Solve(row + 1, 0, n, board, rows, cols, boxes);
                    }
                    if (board[row][col] != '.') {
                        return Solve(row, col + 1, n, board, rows, cols, boxes);
                    }
                    bool flag = false;
                    int box = row / 3 * 3 + col / 3;
                    for (char i = '1'; i <= '9'; i++) {
                        if (rows[{row, i}] == false && cols[{col, i}] == false &&
                            boxes[{box, i}] == false) {
                            board[row][col] = i;
                            rows[{row, i}] = true;
                            cols[{col, i}] = true;
                            boxes[{box, i}] = true;
                            flag |= Solve(row, col + 1, n, board, rows, cols, boxes);
                            if (flag == true)
                                break;
                            board[row][col] = '.';
                            rows[{row, i}] = false;
                            cols[{col, i}] = false;
                            boxes[{box, i}] = false;
                        }
                    }
                    return flag;
                }

            public:
                void solveSudoku(vector<vector<char>>& board) {
                    map<pair<int, char>, bool> rows, cols, boxes;
                    for (int i = 0; i < 9; i++) {
                        for (int j = 0; j < 9; j++) {
                            int box = i / 3 * 3 + j / 3;
                            if (board[i][j] != '.') {
                                rows[{i, board[i][j]}] = true;
                                cols[{j, board[i][j]}] = true;
                                boxes[{box, board[i][j]}] = true;
                            }
                        }
                    }
                    Solve(0, 0, 9, board, rows, cols, boxes);
                }
            };

    </details>

---



* [ ] [Combination Sum](https://leetcode.com/problems/combination-sum/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                void backTrack(int idx, int& n, int rem, vector<int>& cand, vector<int>& cur, vector<vector<int>>& res) {
                    if(idx == n || rem == 0) {
                        if(rem == 0) res.push_back(cur);
                        return;
                    }
                    if(rem >= cand[idx]) {
                        cur.push_back(cand[idx]);
                        backTrack(idx, n, rem - cand[idx], cand, cur, res);
                        cur.pop_back();
                    }
                    backTrack(idx + 1, n, rem, cand, cur, res);
                }
            public:
                vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
                    int n = candidates.size();
                    vector<int> cur;
                    vector<vector<int>> res;
                    backTrack(0, n, target, candidates, cur, res);
                    return res;
                }
            };

    </details>

---



* [ ] [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                void backTrack(int idx, int& n, int rem, vector<int>& cand,
                            vector<int>& cur, vector<vector<int>>& res,
                            unordered_map<int, int>& frq) {
                    if (idx == n || rem == 0) {
                        if (rem == 0) {
                            res.push_back(cur);
                        }
                        return;
                    }
                    if(frq[cand[idx]] > 0 && rem >= cand[idx]) {
                        cur.push_back(cand[idx]);
                        frq[cand[idx]]--;
                        backTrack(idx, n, rem - cand[idx], cand, cur, res, frq);
                        frq[cand[idx]]++;
                        cur.pop_back();
                    }
                    backTrack(idx + 1, n, rem, cand, cur, res, frq);
                }

            public:
                vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
                    int n = cand.size(), newN = 0;
                    unordered_map<int, int> frq;
                    vector<int> newCand, cur;
                    vector<vector<int>> res;
                    sort(cand.begin(), cand.end());
                    for (int i = 0; i < n; i++) {
                        if (newCand.empty() || newCand.back() != cand[i]) {
                            newCand.push_back(cand[i]);
                            ++newN;
                        }
                        frq[cand[i]]++;
                    }
                    backTrack(0, newN, target, newCand, cur, res, frq);
                    return res;
                }
            };

    </details>

---


* [ ] [N-Queens II](https://leetcode.com/problems/n-queens-ii/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int backTrack(int idx, int n, unordered_map<int,int>&rows, unordered_map<int,int>& cols,
                            unordered_map<int,int>&dig1, unordered_map<int,int>&dig2) {
                    if(idx == n)
                        return 1;
                    
                    int ret = 0;
                    for(int i = 0; i < n;i++) {
                        if(!rows[idx] && !cols[i] && !dig1[idx + i] && !dig2[idx - i]) {
                            rows[idx] = true;
                            cols[i] = true;
                            dig1[idx + i] = true;
                            dig2[idx - i] = true;
                            ret += backTrack(idx + 1, n, rows, cols, dig1, dig2);
                            rows[idx] = false;
                            cols[i] = false;
                            dig1[idx + i] = false;
                            dig2[idx - i] = false;
                        }
                    }
                    return ret;
                }
            public:
                int totalNQueens(int n) {
                    unordered_map<int, int> rows, cols, dig1, dig2;
                    return backTrack(0, n, rows, cols, dig1, dig2);
                }
            };

    </details>

---


* [ ] [N-Queens](https://leetcode.com/problems/n-queens/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                void backTrack(int idx, int n, string& emptyQueen,
                            unordered_map<int, int>& cols, unordered_map<int, int>& dig1,
                            unordered_map<int, int>& dig2, vector<string>& cur,
                            vector<vector<string>>& res) {
                    if (idx == n) {
                        res.push_back(cur);
                        return;
                    }

                    cur.push_back(emptyQueen);
                    for (int i = 0; i < n; i++) {
                        if (!cols[i] && !dig1[idx + i] && !dig2[idx - i]) {
                            cols[i] = true;
                            dig1[idx + i] = true;
                            dig2[idx - i] = true;
                            cur.back()[i] = 'Q';
                            backTrack(idx + 1, n, emptyQueen, cols, dig1, dig2, cur,
                                    res);
                            cur.back()[i] = '.';
                            cols[i] = false;
                            dig1[idx + i] = false;
                            dig2[idx - i] = false;
                        }
                    }
                    cur.pop_back();
                }

            public:
                vector<vector<string>> solveNQueens(int n) {
                    vector<string> cur;
                    vector<vector<string>> res;
                    unordered_map<int, int> cols, dig1, dig2;
                    string emptyQueen = "";
                    for (int i = 0; i < n; i++)
                        emptyQueen += '.';
                    backTrack(0, n, emptyQueen, cols, dig1, dig2, cur, res);
                    return res;
                }
            };

    </details>

---


* [ ] [Combinations](https://leetcode.com/problems/combinations/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                void combination(int idx, int&n , int k, vector<int>&cur, vector<vector<int>>& res) {
                    if(k == 0) {
                        res.push_back(cur);
                        return;
                    }
                    for(int i = idx; i <= n;i++) {
                        cur.push_back(i);
                        combination(i + 1, n, k - 1, cur, res);
                        cur.pop_back();
                    }
                }
            public:
                vector<vector<int>> combine(int n, int k) {
                    vector<int> cur;
                    vector<vector<int>> res;
                    combination(1, n, k, cur, res);
                    return res;
                }
            };

    </details>

---



* [ ] [Subsets](https://leetcode.com/problems/subsets/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                void subsets(int idx, int n, vector<int>& v, vector<int>& cur, vector<vector<int>>& res) {
                    if(idx == n) {
                        res.push_back(cur);
                        return;
                    }
                    subsets(idx + 1, n, v, cur, res);
                    cur.push_back(v[idx]);
                    subsets(idx + 1, n, v, cur, res);
                    cur.pop_back();
                }
            public:
                vector<vector<int>> subsets(vector<int>& nums) {
                    int n = nums.size();
                    vector<int> cur;
                    vector<vector<int>> res;
                    subsets(0, n, nums, cur, res);
                    return res;
                }
            };

    </details>

---



* [ ] [Subsets II](https://leetcode.com/problems/subsets-ii/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                void subset(int idx, int& n, const vector<int>& v, vector<int>& cur,
                            vector<vector<int>>& res, unordered_map<int, int>& frq) {
                    if(idx == n) {
                        res.push_back(cur);
                        return;
                    }
                    subset(idx + 1, n, v, cur, res, frq);
                    if(frq[v[idx]] > 0) {
                        cur.push_back(v[idx]);
                        frq[v[idx]] -= 1;
                        subset(idx, n, v, cur, res, frq);
                        cur.pop_back();
                        frq[v[idx]] += 1;
                    }
                }

            public:
                vector<vector<int>> subsetsWithDup(vector<int>& nums) {
                    int n = nums.size(), len = 0;
                    vector<int> v, cur;
                    vector<vector<int>> res;
                    unordered_map<int, int> frq;
                    sort(nums.begin(), nums.end());
                    for (int i = 0; i < n; i++) {
                        if (v.empty() || v.back() != nums[i]) {
                            v.push_back(nums[i]);
                            len += 1;
                        }
                        frq[nums[i]] += 1;
                    }
                    subset(0, len, v, cur, res, frq);
                    return res;
                }
            };

    </details>

---



* [ ] [Gray Code](https://leetcode.com/problems/gray-code/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                bool grayCode(int idx, int n, vector<int>& res, unordered_map<int, bool>& vis) {
                    if(idx == n) {
                        int last = res.back();
                        if(!(last & (last - 1))) {
                            return true;
                        }
                        return false;
                    }
                    bool flag = false;
                    bitset<20> bits(res.back());
                    for(int i = 0; i < 20;i++) {
                        bits[i] = (bits[i] ^ 1);
                        int cnt = bits.to_ulong();
                        if(!vis[cnt] && cnt < n) {
                            vis[cnt] = true;
                            res.push_back(cnt);
                            flag |= grayCode(idx + 1, n, res, vis);
                            if(flag == true) break;
                            res.pop_back();
                            vis[cnt] = false;
                        }
                        bits[i] = (bits[i] ^ 1);
                    }
                    return flag;
                }
            public:
                vector<int> grayCode(int n) {
                    vector<int> res = {0};
                    unordered_map<int, bool> vis;
                    vis[0] = true;
                    grayCode(1, 1 << n, res, vis);
                    return res;
                }
            };

    </details>

---



* [ ] [Path Sum II](https://leetcode.com/problems/path-sum-ii/description/)
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
                void backTrack(TreeNode* root, int targetSum, int sum, vector<int>& cur, vector<vector<int>>& res) {
                    if(root == nullptr) return;
                    sum += root->val;
                    cur.push_back(root->val);
                    if(root->left == nullptr && root->right == nullptr) {
                        if(sum == targetSum) res.push_back(cur);
                        cur.pop_back();
                        return;
                    }
                    if(root->left != nullptr)
                        backTrack(root->left, targetSum, sum, cur, res);
                    if(root->right != nullptr)
                        backTrack(root->right, targetSum, sum, cur, res);
                    cur.pop_back();
                }
            public:
                vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
                    vector<int> cur;
                    vector<vector<int>> res;
                    backTrack(root, targetSum, 0, cur, res);
                    return res;
                }
            };

    </details>

---