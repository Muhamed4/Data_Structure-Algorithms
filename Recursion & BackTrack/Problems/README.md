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



