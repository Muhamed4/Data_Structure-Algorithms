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

