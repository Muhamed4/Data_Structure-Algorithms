# Problems :

* [ ] [Merge Sort for Linked List](https://www.geeksforgeeks.org/problems/sort-a-linked-list/1?page=1&category=Merge%20Sort&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <iostream>
            #include <stdio.h>
            #include <stdlib.h>
            #include <bits/stdc++.h>
            using namespace std;

            struct Node {
                int data;
                struct Node* next;
                Node(int x) {
                    data = x;
                    next = NULL;
                }
            };


            // } Driver Code Ends
            /* Structure of the linked list node is as
            struct Node 
            {
                int data;
                struct Node* next;
                Node(int x) { data = x;  next = NULL; }
            };
            */


            class Solution{
                private:
                Node* middle(Node* head){
                    Node* slow = head;
                    Node* fast = head;
                    Node* exact = head;
                    while(fast && fast->next){
                        fast = fast->next->next;
                        exact = slow;
                        slow = slow->next;
                    }
                    return exact;
                }
                
                void assign(Node* &root, Node* &temp, Node* &cur){
                    if(root == nullptr){
                        root = temp = cur;
                    }
                    else{
                        temp->next = cur;
                        temp = temp->next;
                    }
                    cur = cur->next;
                }
                
                Node* Sort(Node* left, Node* right){
                    Node* root = nullptr, *temp = nullptr;
                    while(left || right){
                        if((right != nullptr && left != nullptr)){
                            if((left->data <= right->data))
                                assign(root, temp, left);
                            else
                                assign(root, temp, right);
                        }   
                        else if((left == nullptr))
                            assign(root, temp, right);
                        else 
                            assign(root, temp, left);
                    }
                    
                    return root;
                }
            public:
                //Function to sort the given linked list using Merge Sort.
                Node* mergeSort(Node* head) {
                    // your code here
                    if(head->next == nullptr)
                        return head;
                        
                    Node* mid = middle(head);
                    // left = head, mid = middle(head), right = the node which it's next is nullptr.
                    Node* beginRight = mid->next;
                    mid->next = nullptr;
                    // cout << head->data << ' ' << ((beginRight == nullptr) ? 0 : beginRight->data) << endl;
                    Node* left = mergeSort(head);
                    Node* right = mergeSort(beginRight);
                    return Sort(left, right);
                }
            };


            //{ Driver Code Starts.

            void printList(Node* node) {
                while (node != NULL) {
                    printf("%d ", node->data);
                    node = node->next;
                }
                printf("\n");
            }

            void push(struct Node** head_ref, int new_data) {
                Node* new_node = new Node(new_data);

                new_node->next = (*head_ref);
                (*head_ref) = new_node;
            }

            int main() {
                long test;
                cin >> test;
                while (test--) {
                    struct Node* a = NULL;
                    long n, tmp;
                    cin >> n;
                    for (int i = 0; i < n; i++) {
                        cin >> tmp;
                        push(&a, tmp);
                    }
                    Solution obj;
                    a = obj.mergeSort(a);
                    printList(a);
                }
                return 0;
            }
            // } Driver Code Ends
        
    </details>

---


* [ ] [Merge 2 sorted linked list in reverse order](https://www.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1?page=1&category=Merge%20Sort&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include<bits/stdc++.h>
            using namespace std;

            /* Link list Node */
            struct Node
            {
                int data;
                struct Node* next;
            };

            void print(struct Node *Node)
            {
                while (Node!=NULL)
                {
                    cout << Node->data << " ";
                    Node = Node->next;
                }
            }


            Node *newNode(int data)
            {
                Node *temp = new Node;
                temp->data = data;
                temp->next = NULL;
                return temp;
            }


            // } Driver Code Ends
            /*

            The structure of linked list is the following

            struct Node
            {
                int data;
                Node* next;
            };

            */
            class Solution
            {
                private:
                
                struct Node* reverseLinkedList(Node* root){
                    Node* prev = nullptr, *cur = root, *next = nullptr;
                    while(cur != nullptr){
                        next = cur->next;
                        cur->next = prev;
                        prev = cur;
                        cur = next;
                    }
                    return prev;
                }
                
                void assign(Node* &root, Node* &temp, Node* &cur){
                    if(root == nullptr){
                        root = temp = cur;
                    }
                    else{
                        temp->next = cur;
                        temp = temp->next;
                    }
                    cur = cur->next;
                }
                
                
                public:
                
                struct Node * mergeResult(Node* left, Node* right)
                {
                    // your code goes here
                Node* root = nullptr, *temp = nullptr;
                    while(left || right){
                        if((right != nullptr && left != nullptr)){
                            if((left->data <= right->data))
                                assign(root, temp, left);
                            else
                                assign(root, temp, right);
                        }   
                        else if((left == nullptr))
                            assign(root, temp, right);
                        else 
                            assign(root, temp, left);
                    }
                    
                    return reverseLinkedList(root);
                }  
            };


            //{ Driver Code Starts.

            int main()
            {
                int T;
                cin>>T;
                while(T--)
                {
                    int nA;
                    cin>>nA;
                    int nB;
                    cin>>nB;

                    struct Node* headA=NULL;
                    struct Node* tempA = headA;

                    for(int i=0;i<nA;i++)
                    {
                        int ele;
                        cin>>ele;
                        if(headA==NULL)
                        {
                            headA=tempA=newNode(ele);

                        }else{
                            tempA->next = newNode(ele);
                            tempA=tempA->next;
                        }
                    }

                    struct Node* headB=NULL;
                    struct Node* tempB = headB;


                    for(int i=0;i<nB;i++)
                    {
                        int ele;
                        cin>>ele;
                        if(headB==NULL)
                        {
                            headB=tempB=newNode(ele);

                        }else{
                            tempB->next = newNode(ele);
                            tempB=tempB->next;
                        }
                    }
                    
                    Solution ob;
                    struct Node* result = ob.mergeResult(headA,headB);

                    print(result);
                    cout<<endl;


                }
            }

            // } Driver Code Ends
        
    </details>

---


* [ ] [Digit sum](https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/interesting-number-2-752e7fa2/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            #include <bits/stdc++.h>
            using namespace std;
            typedef long long ll;
            #define endl '\n'

            void MergeSort(int l, int mid, int r, string& str){
                int n1 = mid - l + 1;
                int n2 = r - mid;
                char* left = new char[n1];
                char* right = new char[n2];
                for(int i = 0; i < n1;i++)left[i] = str[l + i];
                for(int i = 0; i < n2;i++)right[i] = str[mid + i + 1];
                int lidx = 0, ridx = 0;
                for(int i = l; i <= r;i++){
                    if(lidx == n1)str[i] = right[ridx++];
                    else if(ridx == n2)str[i] = left[lidx++];
                    else if(left[lidx] < right[ridx])str[i] = left[lidx++];
                    else str[i] = right[ridx++];
                }

                delete[] left;
                delete[] right;
            }

            void Sort(int l, int r, string &str){
                if(l >= r)
                    return;

                int mid = (l + r) / 2;
                Sort(l, mid, str);
                Sort(mid + 1, r, str);
                MergeSort(l, mid, r, str);
            }


            void solve(){
                int n;cin >> n;
                string s;cin >> s;
                int sum1 = 0, sum2 = 0, ans = 0;
                for(int i = 0; i < n;i++) sum1 += (s[i] - '0');
                for(int i = n; i < 2 * n;i++) sum2 += (s[i] - '0');
                int l = 0, r = n;
                if(sum1 > sum2){
                    l = n; 
                    r = 2 * n; 
                    swap(sum1, sum2);
                }
                Sort(l, r - 1, s);
                for(int i = l;i < r;i++){
                    if(sum1 == sum2)break;
                    sum1 -= (s[i] - '0');
                    int dif = min(sum2 - sum1, 9);
                    sum1 += dif;
                    ++ans;
                }

                cout << ans << endl;
            }

            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int t = 1;cin >> t;
                for(int i = 1; i <= t;i++){
                    solve();
                }
                return 0;
            }
        
    </details>

---


* [ ] [Scoring in Exam](https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/scoring-in-exam-1/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            #include <bits/stdc++.h>
            using namespace std;
            typedef long long ll;
            #define endl '\n'

            void MergeSort(int l, int mid, int r, ll* time, ll* score){
                int n1 = mid - l + 1;
                int n2 = r - mid;
                ll *timeleft = new ll[n1];
                ll *scoreleft = new ll[n1];
                ll *timeright = new ll[n2];
                ll *scoreright = new ll[n2];
                for(int i = 0; i < n1;i++){
                    timeleft[i] = time[i + l];
                    scoreleft[i] = score[i + l];
                }
                for(int i = 0; i < n2;i++){
                    timeright[i] = time[i + mid + 1];
                    scoreright[i] = score[i + mid + 1];
                }
                int left = 0, right = 0;
                for(int i = l; i <= r;i++){
                    if(left == n1){
                        time[i] = timeright[right];
                        score[i] = scoreright[right++];
                        continue;
                    }
                    else if(right == n2){
                        time[i] = timeleft[left];
                        score[i] = scoreleft[left++];
                        continue;
                    }
                    if(timeleft[left] < timeright[right]){
                        time[i] = timeleft[left];
                        score[i] = scoreleft[left++];
                    }
                    else{
                        time[i] = timeright[right];
                        score[i] = scoreright[right++];
                    }
                }

                delete[] timeleft;
                delete[] scoreleft;
                delete[] timeright;
                delete[] scoreright;
            }


            void Sort(int l, int r, ll* time, ll* score){
                if(r <= l)
                    return;
                int mid = (l + r) / 2;
                Sort(l, mid, time, score);
                Sort(mid + 1, r, time, score);
                MergeSort(l, mid, r, time, score);
            }

            void solve(){
                int n, t;cin >> n >> t;
                ll *time = new ll[n];
                ll *score = new ll[n];
                for(int i = 0; i < n; i++)cin >> time[i];
                for(int i = 0; i < n;i++)cin >> score[i];
                Sort(0, n - 1, time, score);
                for(int i = 1;i < n;i++){
                    time[i] += time[i - 1];
                    score[i] += score[i - 1];
                }
                while(t--){
                    int k;cin >> k;
                    cout << time[n - 1] - (((n - k - 1) < 0) ? 0 : time[n - k - 1]) << endl;
                }
                delete[] time;
                delete[] score;
            }

            int main(){
                ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                #ifndef ONLINE_JUDGE
                freopen("Input.txt", "r", stdin);
                freopen("Output.txt", "w", stdout);
                #endif
                int t = 1;//cin >> t;
                for(int i = 1; i <= t;i++){
                    solve();
                }
                return 0;
            }
        
    </details>

---



* [ ] [Count Inversions](https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?page=1&category=Sorting&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;


            // } Driver Code Ends
            class Solution{
            public:
                long long Merge(long long *arr, int l, int mid, int r){
                    int sz1 = mid - l + 1;
                    int sz2 = r - mid;
                    long long *arr1 = new long long[sz1];
                    long long *arr2 = new long long[sz2];
                    for(int i = 0; i < sz1;i++)arr1[i] = arr[l + i];
                    for(int i = 0; i < sz2;i++)arr2[i] = arr[mid + i + 1];
                    long long ret = 0;
                    int i = 0, j = 0;
                    for(int k = l; k <= r;k++){
                        if(i < sz1 && j < sz2){
                            if(arr1[i] <= arr2[j]) arr[k] = arr1[i++];
                            else {
                                ret += (sz1 - i);
                                arr[k] = arr2[j++];
                            }
                            continue;
                        }
                        if(i >= sz1) arr[k] = arr2[j++];
                        else if(j >= sz2) arr[k] = arr1[i++];
                    }
                    delete[] arr1;
                    delete[] arr2;
                    return ret;
                }
                long long MergeSort(long long *arr, int l, int r){
                    if(l >= r) return 0;
                    long long ret = 0;
                    int mid = l + (r - l) / 2;
                    ret += MergeSort(arr, l, mid);
                    ret += MergeSort(arr, mid + 1, r);
                    ret += Merge(arr, l, mid, r);
                    return ret;
                }
                long long int inversionCount(long long arr[], long long N)
                {
                    return MergeSort(arr, 0, N - 1);
                }

            };

            //{ Driver Code Starts.

            int main() {
                
                long long T;
                cin >> T;
                
                while(T--){
                    long long N;
                    cin >> N;
                    
                    long long A[N];
                    for(long long i = 0;i<N;i++){
                        cin >> A[i];
                    }
                    Solution obj;
                    cout << obj.inversionCount(A,N) << endl;
                }
                
                return 0;
            }
        
    </details>

---


* [ ] [Triplet Sum in Array](https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1?page=1&category=Sorting&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;


            // } Driver Code Ends
            class Solution{
                public:
                int Partition(int *arr, int l, int r){
                    int pivot = arr[r];
                    int pivotIndex = l;
                    for(int i = l; i < r;i++){
                        if(arr[i] <= pivot){
                            swap(arr[i], arr[pivotIndex]);
                            ++pivotIndex;
                        }
                    }
                    swap(arr[r], arr[pivotIndex]);
                    return pivotIndex;
                }
                void QuickSort(int *arr, int l, int r){
                    if(l >= r)return;
                    int pivot = Partition(arr, l, r);
                    QuickSort(arr, l, pivot - 1);
                    QuickSort(arr, pivot + 1, r);
                }
                //Function to find if there exists a triplet in the 
                //array A[] which sums up to X.
                bool find3Numbers(int A[], int n, int X)
                {
                    QuickSort(A, 0, n - 1);
                    for(int i = 0; i < n - 2;i++){
                        int rem = X - A[i], l = i + 1, r = n - 1, sum = 0;
                        if(X <= 0)break;
                        while(l < r){
                            sum = A[l] + A[r];
                            if(sum == rem)return 1;
                            if(sum > rem) --r;
                            else ++l;
                        }
                    }
                    return 0;
                }

            };

            //{ Driver Code Starts.

            int main()
            {
                int T;
                cin>>T;
                while(T--)
                {
                    int n,X;
                    cin>>n>>X;
                    int i,A[n];
                    for(i=0;i<n;i++)
                        cin>>A[i];
                    Solution ob;
                    cout <<  ob.find3Numbers(A, n, X) << endl;
                }
            }

            // } Driver Code Ends
        
    </details>

---


* [ ] [Find triplets with zero sum](https://www.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1?page=1&category=Sorting&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include<bits/stdc++.h>
            #include<stdlib.h>
            #include<iostream>
            using namespace std;

            // } Driver Code Ends
            /* You are required to complete the function below
            *  arr[]: input array
            *  n: size of array
            */
            class Solution{
            public:
            void BubbleSort(int *a, int n){
                for(int k = 1; k < n;k++){
                    bool flag = true;
                    for(int i = 0; i < n - k;i++){
                        if(a[i] > a[i + 1]){
                            swap(a[i], a[i + 1]);
                            flag = false;
                        }
                    }
                    if(flag)break;
                }
            }
                //Function to find triplets with zero sum.
                bool findTriplets(int arr[], int n)
                { 
                    //Your code here
                    BubbleSort(arr, n);
                    for(int i = 0; i < n - 2;i++){
                        int rem = 0 - arr[i], sum = 0, l = i + 1, r = n - 1;
                        while(l < r){
                            sum = arr[l] + arr[r];
                            if(sum == rem)return 1;
                            if(sum > rem) --r;
                            else ++l;
                        }
                    }
                    return 0;
                }
            };

            //{ Driver Code Starts.
            int main()
            {
                int t;
                cin>>t;
                while(t--){
                    int n;
                    cin>>n;
                    int arr[n]={0};
                    for(int i=0;i<n;i++)
                        cin>>arr[i];
                    Solution obj;
                    if(obj.findTriplets(arr, n))
                        cout<<"1"<<endl;
                    else 
                        cout<<"0"<<endl;
                }
                return 0;
            }
            // } Driver Code Ends
        
    </details>

---


* [ ] [Find All Four Sum Numbers](https://www.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1?page=1&category=Sorting&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;


            // } Driver Code Ends
            // User function template for C++

            class Solution{
                public:
                void SelectionSort(vector<int>&arr, int n){
                    for(int i = 0; i < n - 1;i++){
                        int idx = i, mn = arr[i];
                        for(int j = i + 1; j < n;j++){
                            if(mn > arr[j]){
                                mn = arr[j];
                                idx = j;
                            }
                        }
                        int temp = arr[i];
                        arr[i] = arr[idx];
                        arr[idx] = temp;
                    }
                }
                int hash(int a, int b, int c, int d){
                    return a * 1000 + b * 100 + c * 10 + d;
                }
                // arr[] : int input array of integers
                // k : the quadruple sum required
                vector<vector<int>> fourSum(vector<int> &arr, int k) {
                    // Your code goes here
                    int n = arr.size();
                    SelectionSort(arr, n);
                    vector<vector<int>>ans;
                    set<multiset<int>>res;
                    for(int i = 0; i < n;i++){
                        for(int j = i + 1; j < n;j++){
                            int l = j + 1, r = n - 1, sum = 0, cur = k - arr[i] - arr[j];
                            while(l < r){
                                sum = arr[l] + arr[r];
                                if(sum == cur){
                                    res.insert({arr[i], arr[j], arr[l], arr[r]});
                                    ++l;
                                    --r;
                                }
                                else if(sum > cur) --r;
                                else ++l;
                            }
                        }
                    }
                    for(auto &it: res){
                        vector<int>cnt;
                        for(auto &i: it)cnt.push_back(i);
                        ans.push_back(cnt);
                    }
                    return ans;
                }
            };

            //{ Driver Code Starts.
            int main() {
                int t;
                cin >> t;
                while (t--) {
                    int n, k, i;
                    cin >> n >> k;
                    vector<int> a(n);
                    for (i = 0; i < n; i++) {
                        cin >> a[i];
                    }
                    Solution ob;
                    vector<vector<int> > ans = ob.fourSum(a, k);
                    for (auto &v : ans) {
                        for (int &u : v) {
                            cout << u << " ";
                        }
                        cout << "$";
                    }
                    if (ans.empty()) {
                        cout << -1;
                    }
                    cout << "\n";
                }
                return 0;
            }
            // } Driver Code Ends
        
    </details>

---


* [ ] [Quick Sort](https://www.geeksforgeeks.org/problems/quick-sort/1?page=1&category=Sorting&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <stdio.h>
            #include <bits/stdc++.h>
            using namespace std;

            /* Function to print an array */
            void printArray(int arr[], int size)
            {
                int i;
                for (i=0; i < size; i++)
                    printf("%d ", arr[i]);
                printf("\n");
            }

            // } Driver Code Ends
            class Solution
            {
                public:
                //Function to sort an array using quick sort algorithm.
                void quickSort(int arr[], int low, int high)
                {
                    // code here
                    if(low >= high)return;
                    int pivot = partition(arr, low, high);
                    quickSort(arr, low, pivot - 1);
                    quickSort(arr, pivot + 1, high);
                }
                
                public:
                int partition (int arr[], int low, int high)
                {
                    // Your code here
                    int pivot = arr[high];
                    int idx = low;
                    for(int i = low; i < high;i++){
                        if(arr[i] <= pivot){
                            swap(arr[i], arr[idx]);
                            ++idx;
                        }
                    }
                    swap(arr[idx], arr[high]);
                    return idx;
                }
            };


            //{ Driver Code Starts.
            int main()
            {
                int arr[1000],n,T,i;
                    scanf("%d",&T);
                while(T--){
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                        scanf("%d",&arr[i]);
                    Solution ob;
                    ob.quickSort(arr, 0, n-1);
                    printArray(arr, n);
                }
                return 0;
            }
            // } Driver Code Ends
        
    </details>

---


* [ ] [Bubble Sort](https://www.geeksforgeeks.org/problems/bubble-sort/1?page=1&category=Sorting&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            //Initial Template for C++

            // C program for implementation of Bubble sort
            #include <stdio.h>
            #include <bits/stdc++.h>
            using namespace std;

            // swapping the elements
            void swap(int *xp, int *yp)
            {
                int temp = *xp;
                *xp = *yp;
                *yp = temp;
            }


            // } Driver Code Ends
            //User function Template for C++

            class Solution
            {
                public:
                //Function to sort the array using bubble sort algorithm.
                void bubbleSort(int arr[], int n)
                {
                    // Your code here  
                    for(int i = 0; i < n - 1;i++){
                        for(int j = 0; j < n - i - 1;j++){
                            if(arr[j] > arr[j + 1]){
                                swap(arr[j], arr[j + 1]);
                            }
                        }
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
                int arr[1000],n,T,i;
            
                scanf("%d",&T);
                
                while(T--){
                    
                scanf("%d",&n);
                
                for(i=0;i<n;i++)
                scanf("%d",&arr[i]);
                
                Solution ob;  
                
                ob.bubbleSort(arr, n);
                printArray(arr, n);
                }
                return 0;;
            }
            // } Driver Code Ends
        
    </details>

---


* [ ] [Minimum Swaps to Sort](https://www.geeksforgeeks.org/problems/minimum-swaps/1?page=1&category=Sorting&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include<bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends


            class Solution 
            {
                void MergeSort(vector<int>&arr, int low, int mid, int high){
                    int n1 = mid - low + 1;
                    int n2 = high - mid;
                    int *arr1 = new int[n1];
                    int *arr2 = new int[n2];
                    for(int i = 0; i < n1;i++)arr1[i] = arr[low + i];
                    for(int i = 0; i < n2;i++)arr2[i] = arr[mid + i + 1];
                    int i = 0, j = 0;
                    for(int k = low; k <= high;k++){
                        if(i < n1 && j < n2){
                            if(arr1[i] < arr2[j]) arr[k] = arr1[i++];
                            else arr[k] = arr2[j++];
                            continue;
                        }
                        else if(i < n1)arr[k] = arr1[i++];
                        else arr[k] = arr2[j++];
                    }
                }
                void Sort(vector<int>&arr, int low, int high){
                    if(low >= high)return;
                    int mid = (low + high) / 2;
                    Sort(arr, low, mid);
                    Sort(arr, mid + 1, high);
                    MergeSort(arr, low, mid, high);
                }
                public:
                //Function to find the minimum number of swaps required to sort the array. 
                int minSwaps(vector<int>&nums)
                {
                    // Code here
                    int n = nums.size(), ans = 0;
                    vector<int>cop = nums;
                    vector<int>before(1000006);
                    for(int i = 0; i < n;i++){
                        before[nums[i]] = i;
                    }
                    Sort(cop, 0, n - 1);
                    for(int i = 0; i < n;i++){
                        int j = before[cop[i]];
                        if(i != j){
                            swap(nums[i], nums[j]);
                            before[nums[j]] = j;
                            ++ans;
                        }
                    }
                    return ans;
                }
            };

            //{ Driver Code Starts.
            int main(){
                int tc;
                cin >> tc;
                while(tc--){
                    int n;
                    cin >> n;
                    vector<int>nums(n);
                    for(int i = 0; i < n; i++)
                        cin >> nums[i];
                    Solution obj;
                    int ans = obj.minSwaps(nums);
                    cout << ans <<"\n";
                }
                return 0;
            }
            // } Driver Code Ends
        
    </details>

---


* [ ] [k largest elements](https://www.geeksforgeeks.org/problems/k-largest-elements4206/1?page=2&category=Sorting&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>

            using namespace std;


            // } Driver Code Ends
            //User function template for C++
            class Solution{
            public:	
                vector<int> kLargest(int arr[], int n, int k) {
                    // code here
                    priority_queue<int,vector<int>,greater<int>>b;
                    for(int i = 0; i < n;i++){
                        if(b.size() == k){
                            if(b.top() < arr[i]){
                                b.pop();
                                b.push(arr[i]);
                            }
                        }
                        else b.push(arr[i]);
                    }
                    vector<int>ans;
                    while(!b.empty()){
                        ans.push_back(b.top());
                        b.pop();
                    }
                    reverse(ans.begin(), ans.end());
                    return ans;
                }

            };

            //{ Driver Code Starts.

            int main() {
                int t;
                cin >> t;
                while (t--) {
                    int n, k;
                    cin >> n >> k;
                    int arr[n];
                    for (int i = 0; i < n; i++) {
                        cin >> arr[i];
                    }
                    Solution ob;
                    auto ans = ob.kLargest(arr, n, k);
                    for (auto x : ans) {
                        cout << x << " ";
                    }
                    cout << "\n";
                }
                return 0;
            }

            // } Driver Code Ends
        
    </details>

---


* [ ] [Sort last M elements](https://www.geeksforgeeks.org/problems/sort-last-m-elements--155156/1?page=8&category=Sorting&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include<bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends
            //User function Template for C++

            class Solution {
                void MergeSort(vector<int>&arr, int low, int mid, int high){
                    int n1 = mid - low + 1;
                    int n2 = high - mid;
                    int *arr1 = new int[n1];
                    int *arr2 = new int[n2];
                    for(int i = 0; i < n1;i++)arr1[i] = arr[low + i];
                    for(int i = 0; i < n2;i++)arr2[i] = arr[mid + i + 1];
                    int i = 0, j = 0;
                    for(int k = low; k <= high;k++){
                        if(i < n1 && j < n2){
                            if(arr1[i] <= arr2[j])arr[k] = arr1[i++];
                            else arr[k] = arr2[j++];
                        }
                        else if(i < n1)arr[k] = arr1[i++];
                        else arr[k] = arr2[j++];
                    }
                    delete[] arr1;
                    delete[] arr2;
                }
                void Sort(vector<int>&arr, int low, int high){
                    if(low >= high)return;
                    int mid = (low + high) / 2;
                    Sort(arr, low, mid);
                    Sort(arr, mid + 1, high);
                    MergeSort(arr, low, mid, high);
                }
            public:
                void sortLastMelements(vector<int>&nums, int n, int m) {
                    // Code here
                    Sort(nums, n, n + m - 1);
                }
            };

            //{ Driver Code Starts.
            int main(){
                int tc;
                cin >> tc;
                while(tc--){
                    int n, m;
                    cin >> n >> m;
                    vector<int>nums(n+m);
                    for(auto &i: nums)
                        cin >> i;
                    Solution obj;
                    obj.sortLastMelements(nums, n, m);
                    for(auto i: nums)
                        cout << i << " ";
                    cout << "\n";
                }
                return 0;
            }
            // } Driver Code Ends
        
    </details>

---


* [ ] [Merge Sort](https://www.geeksforgeeks.org/problems/merge-sort/1?page=2&category=Sorting&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <stdio.h>
            #include <bits/stdc++.h>
            using namespace std;



            /* Function to print an array */
            void printArray(int arr[], int size)
            {
                int i;
                for (i=0; i < size; i++)
                    printf("%d ", arr[i]);
                printf("\n");
            }


            // } Driver Code Ends
            class Solution
            {
                public:
                void merge(int arr[], int l, int m, int r)
                {
                    // Your code here
                    int n1 = m - l + 1;
                    int n2 = r - m;
                    int *arr1 = new int[n1];
                    int *arr2 = new int[n2];
                    for(int i = 0; i < n1;i++)arr1[i] = arr[l + i];
                    for(int i = 0; i < n2;i++)arr2[i] = arr[m + i + 1];
                    int i = 0, j = 0;
                    for(int k = l; k <= r;k++){
                        if(i < n1 && j < n2){
                            if(arr1[i] <= arr2[j])arr[k] = arr1[i++];
                            else arr[k] = arr2[j++];
                        }
                        else if(i < n1)arr[k] = arr1[i++];
                        else arr[k] = arr2[j++];
                    }
                    delete[] arr1;
                    delete[] arr2;
                }
                public:
                void mergeSort(int arr[], int l, int r)
                {
                    //code here
                    if(l >= r)return;
                    int mid = (l + r) / 2;
                    mergeSort(arr, l, mid);
                    mergeSort(arr, mid + 1, r);
                    merge(arr, l, mid, r);
                }
            };

            //{ Driver Code Starts.


            int main()
            {
                int n,T,i;

                scanf("%d",&T);

                while(T--){
                
                scanf("%d",&n);
                int arr[n+1];
                for(i=0;i<n;i++)
                scanf("%d",&arr[i]);

                Solution ob;
                ob.mergeSort(arr, 0, n-1);
                printArray(arr, n);
                }
                return 0;
            }
            // } Driver Code Ends
        
    </details>

---


* [ ] [Alien Dictionary](https://www.geeksforgeeks.org/problems/alien-dictionary/1?page=2&category=Sorting&sortBy=submissions) 
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
                void dfs(int node, vector<vector<int>>&adj, vector<bool>&vis, vector<int>&ans){
                    vis[node] = 1;
                    for(auto &child: adj[node]){
                        if(!vis[child])
                            dfs(child, adj, vis, ans);
                    }
                    ans.push_back(node);
                }
                
                void topological_sort(int K, vector<bool>&vis, vector<vector<int>>&adj, vector<int>&ans){
                    for(int i = 0; i < K;i++){
                        if(!vis[i])
                            dfs(i, adj, vis, ans);
                    }
                    reverse(ans.begin(), ans.end());
                }
                public:
                string findOrder(string dict[], int N, int K) {
                    //code here
                    vector<vector<int>>adj(K);
                    vector<bool> vis(K);
                    vector<int>res;
                    for(int i = 1; i < N;i++){
                        int sz = min(dict[i - 1].size(), dict[i].size());
                        for(int j = 0; j < sz;j++){
                            if(dict[i - 1][j] != dict[i][j]){
                                int x = dict[i - 1][j] - 'a';
                                int y = dict[i][j] - 'a';
                                adj[x].push_back(y);
                                break;
                            }
                        }
                    }
                    topological_sort(K, vis, adj, res);
                    string ans = "";
                    for(auto &it: res)ans += (it + 'a');
                    return ans;
                }
            };

            //{ Driver Code Starts.
            string order;
            bool f(string a, string b) {
                int p1 = 0;
                int p2 = 0;
                for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
                    p1 = order.find(a[i]);
                    p2 = order.find(b[i]);
                    //	cout<<p1<<" "<<p2<<endl;
                }

                if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

                return p1 < p2;
            }

            // Driver program to test above functions
            int main() {
                int t;
                cin >> t;
                while (t--) {
                    int N, K;
                    cin >> N >> K;
                    string dict[N];
                    for (int i = 0; i < N; i++) cin >> dict[i];
                    
                    Solution obj;
                    string ans = obj.findOrder(dict, N, K);
                    order = "";
                    for (int i = 0; i < ans.size(); i++) order += ans[i];

                    string temp[N];
                    std::copy(dict, dict + N, temp);
                    sort(temp, temp + N, f);

                    bool f = true;
                    for (int i = 0; i < N; i++)
                        if (dict[i] != temp[i]) f = false;

                    if(f)cout << 1;
                    else cout << 0;
                    cout << endl;
                }
                return 0;
            }

            // } Driver Code Ends
                    
    </details>

---