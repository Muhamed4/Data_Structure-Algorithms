# Problems :

* [ ] [Maximum Product of Two Elements in an Array](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                pair<int,int> TwoMax(priority_queue<int>&big){
                    int firstMax = big.top();
                    big.pop();
                    int secondMax = big.top();
                    return {firstMax, secondMax};
                }
            public:
                int maxProduct(vector<int>& nums) {
                    priority_queue<int> big;
                    for(auto &it: nums)big.push(it);

                    pair<int,int>twomax = TwoMax(big);
                    return (twomax.first - 1) * (twomax.second - 1);
                }
            };
        
    </details>

---

* [ ] [Delete Greatest Value in Each Row](https://leetcode.com/problems/delete-greatest-value-in-each-row/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int deleteGreatestValue(vector<vector<int>>& grid) {

                    int n = (int)grid.size();
                    int m = (int)grid[0].size();
                    int ans = 0;
                    vector<int>_max(m, 0);
                    for(int i = 0; i < n;i++){
                        priority_queue<int> big;
                        for(int j = 0; j < m;j++){
                            big.push(grid[i][j]);
                        }
                        int idx = m - 1;
                        while(!big.empty()){
                            _max[idx] = max(_max[idx], big.top());
                            --idx;
                            big.pop();
                        }
                    }

                    for(auto &it: _max)ans += it;

                    return ans;
                }
            };
        
    </details>

---


* [ ] [The K Weakest Rows in a Matrix](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
                    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>big;
                    for(int i = 0; i < mat.size();i++){
                        int cnt = 0;
                        for(int j = 0; j < mat[i].size();j++){
                            cnt += mat[i][j];
                        }
                        big.push({cnt, i});
                    }
                    vector<int>ans;
                    while(k--){
                        ans.push_back(big.top().second);
                        big.pop();
                    }
                    return ans;
                }
            };
        
    </details>

---


* [ ] [Take Gifts From the Richest Pile](https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                long long pickGifts(vector<int>& gifts, int k) {

                    long long ans = 0;
                    priority_queue<int>big;
                    for(auto &it: gifts)big.push(it);
                    while(!big.empty() && k--){
                        int remove = big.top();
                        big.pop();
                        int x = sqrt(remove);
                        big.push(x);
                    }

                    while(!big.empty()){
                        ans += big.top();
                        big.pop();
                    }

                    return ans;
                }
            };
        
    </details>

---


* [ ] [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int lastStoneWeight(vector<int>& stones) {
                    priority_queue<int>big;
                    for(auto &it: stones)big.push(it);
                    while(big.size() > 1){
                        int y = big.top();
                        big.pop();
                        int x = big.top();
                        big.pop();
                        y -= x;
                        big.push(y);
                    }
                    return big.top();
                }
            };
        
    </details>

---


* [ ] [Find Kth Largest XOR Coordinate Value](https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int kthLargestValue(vector<vector<int>>& matrix, int k) {
                    priority_queue<int>big;
                    int m = matrix.size();
                    int n = matrix[0].size();
                    int xor_ = 0;
                    vector<vector<int>>xorPre(m + 2, vector<int>(n + 2));
                    for(int i = 0; i < m;i++){
                        for(int j = 0; j < n;j++){
                            xorPre[i + 1][j + 1] = ((xorPre[i][j + 1] ^ xorPre[i + 1][j]) ^ xorPre[i][j]);
                            xorPre[i + 1][j + 1] ^= matrix[i][j];
                            big.push(xorPre[i + 1][j + 1]);
                        }
                    }
                    while(k > 1 && --k)big.pop();
                    return big.top();
                }
            };
        
    </details>

---


* [ ] [Maximum Score From Removing Stones](https://leetcode.com/problems/maximum-score-from-removing-stones/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int maximumScore(int a, int b, int c) {
                    priority_queue<int>big;
                    big.push(a); big.push(b); big.push(c);
                    int ans = 0;
                    while(!big.empty() && big.size() > 1){
                        int aa = big.top();
                        big.pop();
                        int bb = big.top();
                        big.pop();
                        ++ans;
                        --aa; --bb;
                        if(aa)big.push(aa);
                        if(bb)big.push(bb);
                    }

                    return ans;
                }
            };
        
    </details>

---




* [ ] [Heap Sort](https://www.geeksforgeeks.org/problems/heap-sort/1?page=1&category=Heap&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            // C++ program for implementation of Heap Sort
            #include <bits/stdc++.h>
            using namespace std;


            // } Driver Code Ends
            // The functions should be written in a way that array become sorted 
            // in increasing order when heapSort() is called.

            class Solution
            {
                public:
                //Heapify function to maintain heap property.
                void heapify(int arr[], int n, int i)  
                {
                    // Your Code Here
                    int idx = i;
                    int left = 2 * i + 1;
                    int right = 2 * i + 2;
                    if(left < n && arr[i] < arr[left])
                        i = left;
                    if(right < n && arr[i] < arr[right])
                        i = right;
                    if(i != idx) {
                        swap(arr[i], arr[idx]);
                        heapify(arr, n, i);
                    }
                
                }

                public:
                //Function to build a Heap from array.
                void buildHeap(int arr[], int n)  
                { 
                    // Your Code Here
                    for(int i = n - 1; i >= 0;i--)
                        heapify(arr, n, i);
                }

                
                public:
                //Function to sort an array using Heap Sort.
                void heapSort(int arr[], int n)
                {
                    //code here
                    buildHeap(arr, n);
                    for(int i = 0; i < n;i++) {
                        swap(arr[0], arr[n - i - 1]);
                        heapify(arr, n - i - 1, 0);
                    }
                    
                }
            };




            //{ Driver Code Starts.

            /* Function to print an array */
            void printArray(int arr[], int size)
            {
                int i;
                for (i=0; i < size; i++)
                    printf("%d ", arr[i]);
                printf("\n");
            }

            // Driver program to test above functions
            int main()
            {
                int arr[1000000],n,T,i;
                scanf("%d",&T);
                while(T--){
                scanf("%d",&n);
                for(i=0;i<n;i++)
                scanf("%d",&arr[i]);
                Solution ob;
                ob.heapSort(arr, n);
                printArray(arr, n);
                }
                return 0;
            }

            // } Driver Code Ends
        
    </details>

---



* [ ] [Is Binary Tree Heap](https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1?page=1&category=Heap&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;

            // Tree Node
            struct Node {
                int data;
                Node *left;
                Node *right;

                Node(int val) {
                    data = val;
                    left = right = NULL;
                }
            };

            // Function to Build Tree
            Node *buildTree(string str) {
                // Corner Case
                if (str.length() == 0 || str[0] == 'N') return NULL;

                // Creating vector of strings from input
                // string after spliting by space
                vector<string> ip;

                istringstream iss(str);
                for (string str; iss >> str;) ip.push_back(str);

                // Create the root of the tree
                Node *root = new Node(stoi(ip[0]));

                // Push the root to the queue
                queue<Node *> queue;
                queue.push(root);

                // Starting from the second element
                int i = 1;
                while (!queue.empty() && i < ip.size()) {

                    // Get and remove the front of the queue
                    Node *currNode = queue.front();
                    queue.pop();

                    // Get the current Node's value from the string
                    string currVal = ip[i];

                    // If the left child is not null
                    if (currVal != "N") {

                        // Create the left child for the current Node
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

                        // Create the right child for the current Node
                        currNode->right = new Node(stoi(currVal));

                        // Push it to the queue
                        queue.push(currNode->right);
                    }
                    i++;
                }

                return root;
            }


            // } Driver Code Ends
            // User Function template for C++

            // Structure of node
            /*struct Node {
                int data;
                Node *left;
                Node *right;

                Node(int val) {
                    data = val;
                    left = right = NULL;
                }
            };*/

            class Solution {
                bool isComplete(Node* tree, vector<int>& arr) {
                    queue<Node*> levelOrder;
                    levelOrder.push(tree);
                    while(levelOrder.front() != nullptr) {
                        Node* temp = levelOrder.front();
                        levelOrder.push(temp->left);
                        levelOrder.push(temp->right);
                        arr.push_back(temp->data);
                        levelOrder.pop();
                    }
                    while(!levelOrder.empty() && levelOrder.front() == nullptr)
                        levelOrder.pop();
                    return levelOrder.empty();
                }
            public:
                bool isHeap(struct Node* tree) {
                    // code here
                    vector<int> arr;
                    bool isBinaryHeap = isComplete(tree, arr);
                    int n = arr.size();
                    for(int i = 0; i < n;i++) {
                        int left = 2 * i + 1;
                        int right = 2 * i + 2;
                        if(left < n && arr[i] < arr[left])
                            isBinaryHeap = false;
                        if(right < n && arr[i] < arr[right])
                            isBinaryHeap = false;
                    }
                    return isBinaryHeap;
                }
            };

            //{ Driver Code Starts.

            int main() {
                int tc;
                scanf("%d ", &tc);
                while (tc--) {
                    string treeString;
                    getline(cin, treeString);
                    Solution ob;
                    Node *root = buildTree(treeString);
                    if (ob.isHeap(root))
                        cout << 1 << endl;
                    else
                        cout << 0 << endl;
                }

                return 0;
            }
            // } Driver Code Ends
        
    </details>

---





* [ ] [Binary Heap Operations](https://www.geeksforgeeks.org/problems/operations-on-binary-min-heap/1?page=1&category=Heap&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            // Initial Template for C++

            #include <bits/stdc++.h>
            using namespace std;
            typedef long long int ll;

            // Structure for Min Heap
            struct MinHeap {
                int *harr;
                int capacity;
                int heap_size;

                // Constructor for Min Heap
                MinHeap(int c) {
                    heap_size = 0;
                    capacity = c;
                    harr = new int[c];
                }

                ~MinHeap() { delete[] harr; }

                int parent(int i) { return (i - 1) / 2; }

                int left(int i) { return (2 * i + 1); }

                int right(int i) { return (2 * i + 2); }

                void MinHeapify(int); // Implemented in user editor
                int extractMin();
                void decreaseKey(int i, int new_val);
                void deleteKey(int i);
                void insertKey(int k);
            };

            // Position this line where user code will be pasted.

            // Driver code
            int main() {
                int t;
                cin >> t;

                while (t--) {
                    ll a;
                    cin >> a;
                    MinHeap h(a);
                    for (ll i = 0; i < a; i++) {
                        int c;
                        int n;
                        cin >> c;
                        if (c == 1) {
                            cin >> n;

                            h.insertKey(n);
                        }
                        if (c == 2) {
                            cin >> n;
                            h.deleteKey(n);
                        }
                        if (c == 3) {
                            cout << h.extractMin() << " ";
                        }
                    }
                    cout << endl;
                    // delete h.harr;
                    h.harr = NULL;
                }
                return 0;
            }

            // } Driver Code Ends


            /*The structure of the class is
            struct MinHeap
            {
                int *harr;
                int capacity, heap_size;
                MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
                int extractMin();
                void deleteKey(int i);
                void insertKey(int k);
                int parent(int i);
                int left(int i);
                int right(int i);
            };*/



            //Function to extract minimum value in heap and then to store 
            //next minimum value at first index.
            int MinHeap::extractMin() 
            {
                // Your code here
                if(heap_size == 0)
                    return -1;
                swap(harr[0], harr[heap_size - 1]);
                this->heap_size -= 1;
                this->MinHeapify(0);
                return harr[heap_size];
            }

            //Function to delete a key at ith index.
            void MinHeap::deleteKey(int i)
            {
                // Your code here
                if(i >= heap_size)
                    return;
                swap(harr[i], harr[heap_size - 1]);
                this->heap_size -= 1;
                this->MinHeapify(i);
                this->decreaseKey(i, harr[i]);
                
            }

            //Function to insert a value in Heap.
            void MinHeap::insertKey(int k) 
            {
                // Your code here
                this->heap_size += 1;
                this->decreaseKey(heap_size - 1, k);
            }

            //Function to change value at ith index and store that value at first index.
            void MinHeap::decreaseKey(int i, int new_val) 
            {
                harr[i] = new_val;
                while (i != 0 && harr[parent(i)] > harr[i]) {
                    swap(harr[i], harr[parent(i)]);
                    i = parent(i);
                }
            }

            /* You may call below MinHeapify function in
            above codes. Please do not delete this code
            if you are not writing your own MinHeapify */
            void MinHeap::MinHeapify(int i) 
            {
                int l = left(i);
                int r = right(i);
                int smallest = i;
                if (l < heap_size && harr[l] < harr[i]) smallest = l;
                if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
                if (smallest != i) {
                    swap(harr[i], harr[smallest]);
                    MinHeapify(smallest);
                }
            }
        
    </details>

---




* [ ] [Kth largest element in a stream](https://www.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1?page=1&category=Heap&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends
            class Solution {
            public:
                vector<int> kthLargest(int k, int arr[], int n) {
                    // code here
                    vector<int> res;
                    priority_queue<int, vector<int>, greater<int>> Klargest;
                    for(int i = 0; i < n;i++) {
                        Klargest.push(arr[i]);
                        if(Klargest.size() > k)
                            Klargest.pop();
                        if(Klargest.size() < k)
                            res.push_back(-1);
                        else
                            res.push_back(Klargest.top());
                    }
                    return res;
                }
            };

            //{ Driver Code Starts.
            int main() {
                int t;
                cin >> t;
                while (t--) {
                    int k,n;
                    cin>>k>>n;
                    int arr[n];
                    for(int i=0; i<n; i++)
                        cin>>arr[i];

                    Solution ob;
                    vector<int> v = ob.kthLargest(k,arr,n);
                    for(int i : v)
                        cout<<i<<" ";
                    cout<<endl;
                }
                return 0;
            }
            // } Driver Code Ends
        
    </details>

---



* [ ] [Maximum Subsequence Score](https://leetcode.com/problems/maximum-subsequence-score/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
                    int n = nums1.size();
                    long long res = 0, sum = 0;
                    vector<pair<int, int>> v;
                    priority_queue<int, vector<int>, greater<int>> pq;
                    for(int i = 0; i < n;i++) 
                        v.push_back({nums2[i], nums1[i]});
                    sort(v.rbegin(), v.rend());
                    for(int i = 0; i < k;i++) {
                        sum += v[i].second;
                        pq.push(v[i].second);
                    }
                    res = 1ll*v[k - 1].first * sum;
                    for(int i = k; i < n;i++) {
                        sum -= pq.top();
                        sum += v[i].second;
                        pq.pop();
                        pq.push(v[i].second);
                        res = max(res, 1ll*v[i].first * sum);
                    }
                    return res;
                }
            };
                    
    </details>

---


* [ ] [Smallest Range Covering Elements from K Lists](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                vector<int> smallestRange(vector<vector<int>>& nums) {
                    int n = nums.size(), mx = INT_MIN;
                    int left = 0, right = INT_MAX, smallestLen = INT_MAX;
                    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
                                        greater<pair<int, pair<int, int>>>> pq;
                    for(int i = 0; i < n;i++) {
                        mx = max(mx, nums[i][0]);
                        pq.push({nums[i][0], {i, 0}});
                    }
                    while(!pq.empty()) {
                        auto smallest = pq.top();
                        pq.pop();
                        int len = mx - smallest.first;
                        if(len < smallestLen) {
                            smallestLen = len;
                            left = smallest.first;
                            right = mx;
                        }
                        if(smallest.second.second == (nums[smallest.second.first].size() - 1)) break;
                        int val = nums[smallest.second.first][smallest.second.second + 1];
                        pq.push({val, {smallest.second.first, smallest.second.second + 1}});
                        mx = max(mx, val);
                    }
                    return {left, right};
                }
            };
                    
    </details>

---



* [ ] [Maximal Score After Applying K Operations](https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                long long maxKelements(vector<int>& nums, int k) {
                    long long res = 0;
                    priority_queue<int> pq;
                    for(auto &it: nums) pq.push(it);
                    while(!pq.empty() && k > 0) {
                        int val = pq.top();
                        pq.pop();
                        res += val;
                        pq.push((val / 3) + (val % 3 != 0));
                        k -= 1;
                    }
                    return res;
                }
            };
                    
    </details>

---





* [ ] [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            /**
            * Definition for singly-linked list.
            * struct ListNode {
            *     int val;
            *     ListNode *next;
            *     ListNode() : val(0), next(nullptr) {}
            *     ListNode(int x) : val(x), next(nullptr) {}
            *     ListNode(int x, ListNode *next) : val(x), next(next) {}
            * };
            */
            class Solution {
            public:
                ListNode* mergeKLists(vector<ListNode*>& lists) {
                    ListNode* head = nullptr, *temp = nullptr;
                    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> heap;
                    for(auto &node: lists) {
                        if(node != nullptr)
                            heap.push({node->val, node});
                    }
                    while(!heap.empty()) {
                        auto [val, node] = heap.top();
                        heap.pop();
                        if(head == nullptr)
                            head = temp = node;
                        else {
                            temp->next = node;
                            temp = temp->next;
                        }
                        node = node->next;
                        if(node != nullptr)
                            heap.push({node->val, node});
                    }
                    return head;
                }
            };
                    
    </details>

---




* [ ] [Minimum Platforms](https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1?page=1&company=Microsoft&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                vector<pair<int, int>> ConvertInputToSeconds(vector<int>& arr, vector<int>& dep) {
                    int sz = arr.size();
                    vector<pair<int, int>> Conversion;
                    for(int i = 0; i < sz;i++)
                        Conversion.push_back({arr[i], dep[i]});
                    sort(Conversion.begin(), Conversion.end());
                    return Conversion;
                }
            public:
                // Function to find the minimum number of platforms required at the
                // railway station such that no train waits.
                int findPlatform(vector<int>& arr, vector<int>& dep) {
                    // Your code here
                    int res = 0;
                    vector<pair<int, int>> arrivalAndDeparture = ConvertInputToSeconds(arr, dep);
                    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> maxTrains;
                    for(auto &times: arrivalAndDeparture) {
                        int arrive = times.first;
                        int departure = times.second;
                        while(!maxTrains.empty()) {
                            int curDeparture = maxTrains.top().first;
                            int curArrive = maxTrains.top().second;
                            if(arrive > curDeparture) {
                                maxTrains.pop();
                            }
                            else break;
                        }
                        maxTrains.push({departure, arrive});
                        res = max(res, (int)maxTrains.size());
                    }
                    return res;
                }
            };
                    
    </details>

---




* [ ] [Find Score of an Array After Marking All Elements](https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                long long findScore(vector<int>& nums) {
                    int n = nums.size();
                    long long score = 0;
                    unordered_set<int> vis;
                    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
                    for(int i = 0; i < n;i++)
                        pq.push(make_pair(nums[i], i));
                    while(!pq.empty()) {
                        while(!pq.empty() && vis.count(pq.top().second) == true)
                            pq.pop();
                        if(!pq.empty()) {
                            auto [val, index] = pq.top();
                            pq.pop();
                            score += val;
                            vis.insert(index + 1);
                            vis.insert(index - 1);
                        }
                    }
                    return score;
                }
            };
                    
    </details>

---