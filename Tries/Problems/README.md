# Problems :

* [ ] [Insert and Search in a Trie](https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1?page=1&category=Trie&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            // Initial function template for C++

            #include <bits/stdc++.h>

            using namespace std;

            // Alphabet size (# of symbols)
            #define ALPHABET_SIZE (26)

            // Converts key current character into index
            // use only 'a' through 'z' and lower case
            #define CHAR_TO_INDEX(c) ((int)c - (int)'a')

            // trie node
            struct TrieNode {
                struct TrieNode *children[ALPHABET_SIZE];

                // isLeaf is true if the node represents
                // end of a word
                bool isLeaf;
            };

            // Returns new trie node (initialized to NULLs)
            struct TrieNode *getNode(void) {
                struct TrieNode *pNode = NULL;

                pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));

                if (pNode) {
                    int i;

                    pNode->isLeaf = false;

                    for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
                }

                return pNode;
            }


            // } Driver Code Ends
            // User function template for C++

            // trie node
            /*
            struct TrieNode {
                struct TrieNode *children[ALPHABET_SIZE];

                // isLeaf is true if the node represents
                // end of a word
                bool isLeaf;
            };
            */
            class Solution
            {
                public:
                    //Function to insert string into TRIE.
                    void insert(struct TrieNode *root, string key)
                    {
                        // code here
                        TrieNode* currentNode = root;
                        for(auto &ch: key){
                            if(currentNode->children[ch - 'a'] == nullptr){
                                currentNode->children[ch - 'a'] = getNode();
                            }
                            currentNode = currentNode->children[ch - 'a'];
                        }
                        currentNode->isLeaf = true;
                    }
                    
                    //Function to use TRIE data structure and search the given string.
                    bool search(struct TrieNode *root, string key) 
                    {
                        // code here
                        TrieNode* currentNode = root;
                        for(auto &ch: key){
                            if(currentNode->children[ch - 'a'] == nullptr)
                                return false;
                            currentNode = currentNode->children[ch - 'a'];
                        }
                        return currentNode->isLeaf;
                    }
            };

            //{ Driver Code Starts.

            // Driver
            int main() {
                // freopen("input.txt", "r", stdin);
                // freopen("output.txt", "w", stdout);
                int t;
                cin >> t;
                while (t--) {
                    // Input keys (use only 'a' through 'z' and lower case)
                    int n;
                    cin >> n;
                    string keys[n];

                    for (int i = 0; i < n; i++) {
                        cin >> keys[i];
                    }
                    
                    Solution obj;
                    struct TrieNode *root = getNode();
                    // Construct trie
                    for (int i = 0; i < n; i++) obj.insert(root, keys[i]);

                    string abc;

                    cin >> abc;
                    // Search for different keys

                    if (obj.search(root, abc))
                        cout << "1\n";
                    else
                        cout << "0\n";
                    // char ex;
                    // cin >> ex;
                    // cout << ex << "\n";
                }
                return 0;
            }
            // } Driver Code Ends
        
    </details>

---


* [ ] [Unique rows in boolean matrix](https://www.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1?page=1&category=Trie&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include<bits/stdc++.h>
            using namespace std;
            #define MAX 1000

            vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


            // } Driver Code Ends

            struct TrieNode {
                TrieNode* children[2];
                bool isVisited;
                TrieNode() {
                    isVisited = false;
                    children[0] = nullptr;
                    children[1] = nullptr;
                }
            };

            class Solution
            {
                public:
                // #define MAX 1000
                vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
                {
                    //Your code here
                    TrieNode* root = new TrieNode();
                    vector<vector<int>>ans;
                    for(int i = 0; i < row;i++){
                        vector<int> v;
                        for(int j = 0; j < col;j++){
                            v.push_back(M[i][j]);
                        }
                        insert(root, v, col);
                    }
                    for(int i = 0; i < row;i++){
                        vector<int> v;
                        for(int j = 0; j < col;j++){
                            v.push_back(M[i][j]);
                        }
                        if(search(root, v, col)) ans.push_back(v);
                    }
                    return ans;
                }
                
                void insert(TrieNode* root, vector<int>& v, int& n){
                    TrieNode* currentNode = root;
                    for(int i = 0; i < n;i++){
                        if(currentNode->children[v[i]] == nullptr){
                            currentNode->children[v[i]] = new TrieNode();
                        }
                        currentNode = currentNode->children[v[i]];
                    }
                }
                
                bool search(TrieNode* root, vector<int>& v, int& n){
                    TrieNode* currentNode = root;
                    for(int i = 0; i < n;i++){
                        currentNode = currentNode->children[v[i]];
                    }
                    bool Visited = !currentNode->isVisited;
                    currentNode->isVisited = true;
                    return Visited;
                }
            };

            //{ Driver Code Starts.

            int main()
            {
                int T;
                cin>>T;
                while(T--)
                {
                    int n,m;
                    cin>>n>>m;
                    int a[MAX][MAX];
                    for(int i=0;i<n;i++)
                    for(int j=0;j<m;j++)
                    cin>>a[i][j];
                    Solution ob;
                    vector<vector<int>> vec = ob.uniqueRow(a,n,m);
                    for(int i = 0;i<vec.size();i++){
                        for(int x : vec[i]){
                            cout<<x<<" ";
                        }
                        cout<<"$";
                    }
                    cout<<endl;
                }
            }

            // } Driver Code Ends
        
    </details>

---



* [ ] [Word Boggle](https://www.geeksforgeeks.org/problems/word-boggle4143/1?page=1&category=Trie&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            // Initial template for C++

            #include <bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends

            struct TrieNode {
                TrieNode* children[60];
                string Word;
                bool End;
                TrieNode() {
                    Word = "";
                    End = false;
                    for(int i = 0; i < 60;i++){
                        children[i] = nullptr;
                    }
                }
            };

            class Solution {
                
                int dx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
                int dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};
                
                void insert(TrieNode* root, string& key){
                    TrieNode* currentNode = root;
                    for(auto &ch: key){
                        if(currentNode->children[ch - 'A'] == nullptr){
                            currentNode->children[ch - 'A'] = new TrieNode();   
                        }
                        currentNode = currentNode->children[ch - 'A'];
                    }
                    currentNode->End = true;
                    currentNode->Word = key;
                }
                
                bool search(TrieNode* root, string& key){
                    TrieNode* currentNode = root;
                    for(auto &ch: key){
                        if(currentNode->children[ch - 'A'] == nullptr){
                            return false;
                        }
                        currentNode = currentNode->children[ch - 'A'];
                    }
                    return currentNode != nullptr && currentNode->End > 0;
                }
                
                bool deleteKey(TrieNode* root, string& key){
                    TrieNode* currentNode = root;
                    for(auto &ch: key){
                        if(currentNode->children[ch - 'A'] == nullptr){
                            return false;
                        }
                        currentNode = currentNode->children[ch - 'A'];
                    }
                    if(currentNode != nullptr && currentNode->End > 0){
                        currentNode->End = false;
                        return true;
                    }
                    return false;
                }
                
                bool isValid(int x, int y, int n, int m){
                    return (x >= 0 && x < n && y >= 0 && y < m);
                }
                
                void dfs(int x, int y, int& n, int& m, TrieNode* root, vector<vector<char>>& board, vector<string>& ans){
                    if(!isValid(x, y, n, m) || board[x][y] == '#' || root->children[board[x][y] - 'A'] == nullptr)
                        return;
                    if(root->children[board[x][y] - 'A']->End){
                        ans.push_back(root->children[board[x][y] - 'A']->Word);
                        root->children[board[x][y] - 'A']->End = false;
                    }
                    char ch = board[x][y];
                    board[x][y] = '#';
                    for(int i = 0; i < 8;i++){
                        int newX = x + dx[i];
                        int newY = y + dy[i];
                        dfs(newX, newY, n, m, root->children[ch - 'A'], board, ans);
                    }
                    board[x][y] = ch;
                }
            public:
                vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
                    // Code here
                    int n = board.size();
                    int m = board[0].size();
                    vector<string> ans;
                    TrieNode* root = new TrieNode();
                    for(auto &str: dictionary){
                        insert(root, str);
                    }
                    for(int i = 0; i < n;i++){
                        for(int j = 0; j < m;j++){
                            dfs(i, j, n, m, root, board, ans);
                        }
                    }
                    return ans;
                }
            };

            //{ Driver Code Starts.

            int main() {
                int t;
                cin >> t;
                while (t--) {
                    int N;
                    cin >> N;
                    vector<string> dictionary;
                    for (int i = 0; i < N; ++i) {
                        string s;
                        cin >> s;
                        dictionary.push_back(s);
                    }
                    
                    int R, C;
                    cin >> R >> C;
                    vector<vector<char> > board(R);
                    for (int i = 0; i < R; i++) {
                        board[i].resize(C);
                        for (int j = 0; j < C; j++) cin >> board[i][j];
                    }
                    Solution obj;
                    vector<string> output = obj.wordBoggle(board, dictionary);
                    if (output.size() == 0)
                        cout << "-1";
                    else {
                        sort(output.begin(), output.end());
                        for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
                    }
                    cout << endl;
                }
            }

            // } Driver Code Ends
        
    </details>

---


* [ ] [Word Break](https://leetcode.com/problems/word-break/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            struct TrieNode {
                bool isWord;
                unordered_map<char, TrieNode*> children;
                TrieNode() : isWord(false), children(unordered_map<char, TrieNode*>()) {}
            };

            class Solution {
                void insert(TrieNode* root, string& key){
                    for(auto &ch: key){
                        if(root->children.find(ch) == root->children.end()){
                            root->children[ch] = new TrieNode();
                        }
                        root = root->children[ch];
                    }
                    root->isWord = true;
                }

                // it's a valid function but take exponential time (time limit).
                bool isExist(int idx, int& n, string& str, TrieNode* root, TrieNode* cur){
                    if(idx == n){
                        return root == cur;
                    }
                    bool flag = false;
                    if(cur->children.find(str[idx]) != cur->children.end()){
                        flag |= isExist(idx + 1, n, str, root, cur->children[str[idx]]);
                        if(cur->children[str[idx]]->isWord) flag |= isExist(idx + 1, n, str, root, root);
                    }
                    return flag;
                }
            public:
                bool wordBreak(string& s, vector<string>& wordDict) {
                    int n = s.size();
                    TrieNode* root = new TrieNode();
                    for(auto &str: wordDict){
                        insert(root, str);
                    }
                    vector<bool> dp(n);
                    for(int i = 0; i < n;i++){
                        if(!i || dp[i - 1]){
                            TrieNode* currentNode = root;
                            for(int j = i; j < n;j++){
                                if(currentNode->children.find(s[j]) == currentNode->children.end()){
                                    break;
                                }
                                if(currentNode->children[s[j]]->isWord) dp[j] = true;
                                currentNode = currentNode->children[s[j]];
                            }
                        }
                    }
                    return dp[n - 1];
                }
            };
        
    </details>

---


* [ ] [Word Break II](https://leetcode.com/problems/word-break-ii/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            struct TrieNode {
                bool isWord;
                string Word;
                unordered_map<char, TrieNode*> children;
                TrieNode() : isWord(false), Word(""), children(unordered_map<char, TrieNode*>()) {}
            };

            class Solution {
                void insert(TrieNode* root, string& key){
                    for(auto &ch: key){
                        if(root->children.find(ch) == root->children.end()){
                            root->children[ch] = new TrieNode();
                        }
                        root = root->children[ch];
                    }
                    root->isWord = true;
                    root->Word = key;
                }

                void isExist(int idx, int& n, string& str,string word, vector<string>& ans, TrieNode* root, TrieNode* cur){
                    if(idx == n){
                        if(root == cur && word.size()){
                            word.pop_back();
                            ans.push_back(word);
                        }
                        return;
                    }
                    if(cur->children.find(str[idx]) != cur->children.end()){
                        isExist(idx + 1, n, str, word, ans, root, cur->children[str[idx]]);
                        if(cur->children[str[idx]]->isWord) {
                            word += cur->children[str[idx]]->Word + ' ';
                            isExist(idx + 1, n, str, word, ans, root, root);
                        }
                    }
                }
            public:
                    vector<string> wordBreak(string s, vector<string>& wordDict) {
                        int n = s.size();
                        TrieNode* root = new TrieNode();
                        for(auto &str: wordDict){
                            insert(root, str);
                        }
                        vector<string> ans;
                        isExist(0, n, s, "", ans, root, root);
                        return ans;
                    }
            };
        
    </details>

---


* [ ] [Word Search II](https://leetcode.com/problems/word-search-ii/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            struct TrieNode {
                TrieNode* children[26];
                bool isWord;
                string Word;
                TrieNode() {
                    isWord = false;
                    Word = "";
                    for(int i = 0; i < 26;i++){
                        children[i] = nullptr;
                    }
                }
            };

            class Solution {
                int dx[4] = {1, -1, 0, 0};
                int dy[4] = {0, 0, 1, -1};
                void insert(TrieNode* root, string& key){
                    TrieNode* current = root;
                    for(auto &ch: key){
                        if(current->children[ch - 'a'] == nullptr){
                            current->children[ch - 'a'] = new TrieNode();
                        }
                        current = current->children[ch - 'a'];
                    }
                    current->isWord = true;
                    current->Word = key;
                }
                bool isValid(int x, int y, int n, int m){
                    return (x >= 0 && x < n && y >= 0 && y < m);
                }
                void dfs(int x, int y, int n, int m, TrieNode* root, vector<vector<char>>& board, vector<string>& res){
                    if(!isValid(x, y, n, m) || board[x][y] == '#' || root->children[board[x][y] - 'a'] == nullptr) return;
                    char ch = board[x][y];
                    if(root->children[ch - 'a']->isWord){
                        root->children[ch - 'a']->isWord = false;
                        res.push_back(root->children[ch - 'a']->Word);
                    }
                    board[x][y] = '#';
                    for(int i = 0; i < 4;i++){
                        int newX = x + dx[i];
                        int newY = y + dy[i];
                        dfs(newX, newY, n, m, root->children[ch - 'a'], board, res);
                    }
                    board[x][y] = ch;
                }
            public:
                vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
                    int n = board.size();
                    int m = board[0].size();
                    vector<string> res;
                    TrieNode* root = new TrieNode();
                    for(auto &str: words){
                        insert(root, str);
                    }
                    for(int i = 0; i < n;i++){
                        for(int j = 0; j < m;j++){
                            dfs(i, j, n, m, root, board, res);
                        }
                    }
                    return res;
                }
            };
        
    </details>

---



* [ ] [Word Search](https://leetcode.com/problems/word-search/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            struct TrieNode {
                TrieNode* children[60];
                bool isEnd;
                TrieNode() {
                    isEnd = false;
                    for(int i = 0; i < 60;i++){
                        children[i] = nullptr;
                    }
                }
            };

            class Solution {
                int dx[4] = {1, -1, 0, 0};
                int dy[4] = {0, 0, 1, -1};
                void insert(TrieNode* root, string& key){
                    TrieNode* current = root;
                    for(auto &ch: key){
                        if(current->children[ch - 'A'] == nullptr){
                            current->children[ch - 'A'] = new TrieNode();
                        }
                        current = current->children[ch - 'A'];
                    }
                    current->isEnd = true;
                }
                bool isValid(int x, int y, int n, int m){
                    return (x >= 0 && x < n && y >= 0 && y < m);
                }
                bool dfs(int x, int y, int n, int m, TrieNode* root, vector<vector<char>>&board) {
                    if(!isValid(x, y, n, m) || board[x][y] == '#' || root->children[board[x][y] - 'A'] == nullptr) 
                        return false;
                    char ch = board[x][y];
                    board[x][y] = '#';
                    if(root->children[ch - 'A']->isEnd) return true;
                    bool flag = false;
                    for(int i = 0; i < 4;i++){
                        int newX = x + dx[i];
                        int newY = y + dy[i];
                        flag |= dfs(newX, newY, n, m, root->children[ch - 'A'], board);
                    }
                    board[x][y] = ch;
                    return flag;
                }
            public:
                bool exist(vector<vector<char>>& board, string word) {
                    int n = board.size();
                    int m = board[0].size();
                    TrieNode* root = new TrieNode();
                    insert(root, word);
                    for(int i = 0; i < n;i++){
                        for(int j = 0; j < m;j++){
                            if(dfs(i, j, n, m, root, board)) return true;
                        }
                    }
                    return false;
                }
            };
        
    </details>

---



* [ ] [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            struct TrieNode {
                TrieNode* children[26];
                bool isEnd;
                TrieNode() {
                    isEnd = false;
                    for(int i = 0; i < 26;i++){
                        children[i] = nullptr;
                    }
                }
            };
            class Trie {
                TrieNode* root;
            public:
                Trie() {
                    root = new TrieNode();
                }
                
                void insert(string word) {
                    TrieNode* currentNode = root;
                    for(auto &ch: word){
                        if(currentNode->children[ch - 'a'] == nullptr){
                            currentNode->children[ch - 'a'] = new TrieNode();
                        }
                        currentNode = currentNode->children[ch - 'a'];
                    }
                    currentNode->isEnd = true;
                }
                
                bool search(string word) {
                    TrieNode* currentNode = root;
                    for(auto &ch: word){
                        if(currentNode->children[ch - 'a'] == nullptr)
                            return false;
                        currentNode = currentNode->children[ch - 'a'];
                    }
                    return currentNode->isEnd;
                }
                
                bool startsWith(string prefix) {
                    TrieNode* currentNode = root;
                    for(auto &ch: prefix){
                        if(currentNode->children[ch - 'a'] == nullptr)
                            return false;
                        currentNode = currentNode->children[ch - 'a'];
                    }
                    return true;
                }
            };

            /**
            * Your Trie object will be instantiated and called as such:
            * Trie* obj = new Trie();
            * obj->insert(word);
            * bool param_2 = obj->search(word);
            * bool param_3 = obj->startsWith(prefix);
            */
        
    </details>

---



* [ ] [Most frequent word in an array of strings](https://www.geeksforgeeks.org/problems/most-frequent-word-in-an-array-of-strings3528/1?page=1&category=Trie&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            // Initial template for C++

            #include <bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends
            // User function template for C++
            struct TrieNode {
                TrieNode* children[26];
                int End;
                TrieNode() {
                    End = 0;
                    for(int i = 0; i < 26;i++){
                        children[i] = nullptr;
                    }
                }
            };
            class Solution
            {
                void insert(TrieNode* root, string& key, int& mx){
                    TrieNode* current = root;
                    for(auto &ch: key){
                        if(current->children[ch - 'a'] == nullptr){
                            current->children[ch - 'a'] = new TrieNode();   
                        }
                        current = current->children[ch - 'a'];
                    }
                    current->End++;
                    mx = max(mx, current->End);
                }
                void search(TrieNode* root, string& key, int& mx, string& ans){
                    TrieNode* current = root;
                    for(auto &ch: key){
                        current = current->children[ch - 'a'];
                    }
                    if(current->End == mx){
                        ans = key;
                    }
                }
                public:
                //Function to find most frequent word in an array of strings.
                string mostFrequentWord(string arr[], int n) 
                {
                    // code here
                    TrieNode* root = new TrieNode();
                    int mx = 0;
                    string ans = "";
                    unordered_map<string, bool> vis;
                    for(int i = 0; i < n;i++){
                        insert(root, arr[i], mx);
                    }
                    for(int i = 0; i < n;i++){
                        if(!vis[arr[i]]) search(root, arr[i], mx, ans);
                        vis[arr[i]] = 1;
                    }
                    return ans;
                }
            };

            //{ Driver Code Starts.
            int main() {
                int t;
                cin >> t;
                while (t--) {
                    int n;
                    cin >> n;

                    string arr[n];
                    for (int i = 0; i < n; i++) cin >> arr[i];
                    Solution obj;
                    cout << obj.mostFrequentWord(arr, n) << endl;
                }
                return 0;
            }

            // } Driver Code Ends
        
    </details>

---



* [ ] [Prefix match with other strings](https://www.geeksforgeeks.org/problems/prefix-match-with-other-strings/1?page=1&category=Trie&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            //Initial template for C++

            #include<bits/stdc++.h> 
            using namespace std; 

            // } Driver Code Ends
            //User function Template for C++
            struct TrieNode {
                TrieNode* children[26];
                int prefix;
                TrieNode() {
                    for(int i = 0; i < 26;i++){
                        children[i] = nullptr;
                    }
                    prefix = 0;
                }
            };
            class Solution{
                void insert(TrieNode* root, string& key){
                    TrieNode* current = root;
                    for(auto &ch: key){
                        if(current->children[ch - 'a'] == nullptr){
                            current->children[ch - 'a'] = new TrieNode();   
                        }
                        current->children[ch - 'a']->prefix++;
                        current = current->children[ch - 'a'];
                    }
                }
                int search(TrieNode* root, string& key, int k){
                    if(k > key.size()) return 0;
                    TrieNode* current = root;
                    for(int i = 0; i < k;i++){
                        if(current->children[key[i] - 'a'] == nullptr) {
                            return 0;
                        }   
                        current = current->children[key[i] - 'a'];
                    }
                    return current->prefix;
                }
            public:
                int klengthpref(string arr[], int n, int k, string str){    
                    TrieNode* root = new TrieNode();
                    for(int i = 0; i < n;i++){
                        insert(root, arr[i]);
                    }
                    return search(root, str, k);
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
                    string arr[n];
                    for(int i=0;i<n;i++)
                    {
                        string s;
                        cin>>arr[i];
                        
                    }
                    int k;
                    cin>>k;
                    string str;
                    cin>>str;
                    
                    Solution ob;
                    cout << ob.klengthpref(arr, n, k, str) << endl;
                }
                return 0; 
            } 

            // } Driver Code Ends
        
    </details>

---