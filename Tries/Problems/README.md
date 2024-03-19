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