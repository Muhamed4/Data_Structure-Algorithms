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