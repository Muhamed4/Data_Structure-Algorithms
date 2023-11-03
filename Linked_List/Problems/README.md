* [ ] [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/) 
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
                ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
                    ListNode*ans = nullptr, *tail = nullptr;
                    while(l1 != nullptr && l2 != nullptr){
                        ListNode* temp = new ListNode(l1->val + l2->val);
                        if(ans == nullptr){
                            ans = tail = temp;
                        }
                        else{
                            tail->next = temp;
                            tail = temp;
                        }
                        l1 = l1->next;
                        l2 = l2->next;
                    }
                    while(l1 != nullptr){
                        ListNode* temp = new ListNode(l1->val);
                        if(ans == nullptr){
                            ans = tail = temp;
                        }
                        else{
                            tail->next = temp;
                            tail = temp;
                        }
                        l1 = l1->next;
                    }
                    while(l2 != nullptr){
                        ListNode* temp = new ListNode(l2->val);
                        if(ans == nullptr){
                            ans = tail = temp;
                        }
                        else{
                            tail->next = temp;
                            tail = temp;
                        }
                        l2 = l2->next;
                    }
                    ListNode* cur = ans, *prev = nullptr;
                    int res = 0;
                    while(cur != nullptr){
                        res += cur->val;
                        cur->val = res % 10;
                        res /= 10;
                        prev = cur;
                        cur = cur->next;
                    }
                    if(res)prev->next = new ListNode(res);
                    return ans;
                }
            };
        
    </details>

---

* [ ] [Copy List With Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            /*
            // Definition for a Node.
            class Node {
            public:
                int val;
                Node* next;
                Node* random;
                
                Node(int _val) {
                    val = _val;
                    next = NULL;
                    random = NULL;
                }
            };
            */

            class Solution {
            public:
                Node* copyRandomList(Node* head) {
                    map<Node*, Node*>mp;
                    Node* headans = nullptr, *temp = nullptr;
                    Node* oth = head;
                    while(oth != nullptr){
                        Node* newNode = new Node(oth->val);
                        if(headans == nullptr){
                            headans = temp = newNode;
                        }
                        else{
                            temp->next = newNode;
                            temp = temp->next;
                        }
                        mp[oth] = temp;
                        oth = oth->next;
                    }
                    Node *temp2 = headans;
                    while(head != nullptr){
                        if(head->random != nullptr)temp2->random = mp[head->random];
                        head = head->next;
                        temp2 = temp2->next;
                    }
                    return headans;
                }
            };
        
    </details>

---


* [ ] [Insertion Sort List](https://leetcode.com/problems/insertion-sort-list/description/) 
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
                int getSize(ListNode* head){
                    int size = 0;
                    while(head != nullptr){
                        head = head->next;
                        ++size;
                    }
                    return size;
                }
                ListNode* getprevNode(ListNode* head, int index){
                    if(index == 1)return nullptr;
                    if(index == 2)return head;
                    for(int i = 1; i <= index - 2;i++){
                        head = head->next;
                    }
                    return head;
                }
                ListNode* insertionSort(ListNode* head){
                    if(head->next == nullptr || head->val <= head->next->val)return head;
                    ListNode* temp = head->next->next;
                    ListNode* cur = head->next;
                    head->next = temp;
                    cur->next = insertionSort(head);
                    return cur;
                }
            public:
                ListNode* insertionSortList(ListNode* head) {
                    ListNode* temp = nullptr;
                    int size = getSize(head);
                    for(int i = size;i >= 1;i--){
                        temp = getprevNode(head, i);
                        if(temp == nullptr)temp = insertionSort(head);
                        else temp->next = insertionSort(temp->next);
                    }
                    return temp;
                }
            };
        
    </details>

---


* [ ] [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            /**
            * Definition for singly-linked list.
            * struct ListNode {
            *     int val;
            *     ListNode *next;
            *     ListNode(int x) : val(x), next(NULL) {}
            * };
            */
            class Solution {
            public:
                bool hasCycle(ListNode *head) {
                    while(head != nullptr){
                        if(head->val == 1000000)return true;
                        head->val = 1000000;
                        head = head->next;
                    }
                    return false;
                }
            };
        
    </details>

---


* [ ] [Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/) 
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
                vector<int>v;
                void iterate(ListNode* head){
                    if(head == nullptr)return;
                    v.push_back(head->val);
                    iterate(head->next);
                }
            public:
                int pairSum(ListNode* head) {
                    iterate(head);
                    int l = 0, r = (int)v.size() - 1, ans = 0;
                    while(l <= r){
                        ans = max(ans, v[l] + v[r]);
                        ++l; --r;
                    }
                    return ans;
                }
            };
        
    </details>

---


* [ ] [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/description/) 
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
                ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
                    ListNode* SList = nullptr, *temp = nullptr;
                    while(list1 != nullptr && list2 != nullptr){
                        if(list1->val <= list2->val){
                            if(SList == nullptr){
                                SList = temp = list1;
                            }
                            else{
                                temp->next = list1;
                                temp = temp->next;
                            }
                            list1 = list1->next;
                        }
                        else{
                            if(SList == nullptr){
                                SList = temp = list2;
                            }
                            else{
                                temp->next = list2;
                                temp = temp->next;
                            }
                            list2 = list2->next;
                        }
                    }
                    while(list1 != nullptr){
                        if(SList == nullptr){
                            SList = temp = list1;
                        }
                        else {
                            temp->next = list1;
                            temp = temp->next;
                        }
                        list1 = list1->next;
                    }
                    while(list2 != nullptr){
                        if(SList == nullptr){
                            SList = temp = list2;
                        }
                        else {
                            temp->next = list2;
                            temp = temp->next;
                        }
                        list2 = list2->next;
                    }
                    return SList;
                }
            };
        
    </details>

---


* [ ] [Partition List](https://leetcode.com/problems/partition-list/description/) 
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
                ListNode* partition(ListNode* head, int x) {
                    ListNode* head1 = nullptr, *tail1 = nullptr;
                    ListNode* head2 = nullptr, *tail2 = nullptr;
                    while(head != nullptr){
                        if(head->val < x){
                            if(head1 == nullptr){
                                head1 = tail1 = head;
                            }
                            else {
                                tail1->next = head;
                                tail1 = tail1->next;
                            }
                        }
                        else{
                            if(head2 == nullptr){
                                head2 = tail2 = head;
                            }
                            else {
                                tail2->next = head;
                                tail2 = tail2->next;
                            }
                        }
                        head = head->next;
                    }
                    if(tail1 != nullptr)tail1->next = head2;
                    else head1 = tail1 = head2;
                    if(tail2 != nullptr)tail2->next = nullptr;
                    return head1;
                }
            };
        
    </details>

---


* [ ] [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/) 
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
                int frq[222]{0};
                void Freq(ListNode* head){
                    while(head != nullptr){
                        frq[head->val + 100]++;
                        head = head->next;
                    }
                }
            public:
                ListNode* deleteDuplicates(ListNode* head) {
                    Freq(head);
                    ListNode* newHead = nullptr, *temp = nullptr, *oth = nullptr;
                    while(head != nullptr){
                        if(frq[head->val + 100] <= 1){
                            if(newHead == nullptr){
                                newHead = temp = oth = head;
                            }
                            else{
                                temp = head;
                                oth->next = temp;
                                oth = oth->next;
                            }
                            temp = temp->next;
                        }
                        head = head->next;
                    }
                    if(oth != nullptr)
                        oth->next = nullptr;
                    return newHead;
                }
            };
        
    </details>

---


* [ ] [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/) 
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
                int frq[222]{0};
            public:
                ListNode* deleteDuplicates(ListNode* head) {
                    ListNode* oth = nullptr, *temp = head, *cur = nullptr;
                    while(temp != nullptr){
                        if(frq[temp->val + 100] == 0){
                            if(oth == nullptr){
                                oth = temp;
                            }
                            else{
                                oth->next = temp;
                                oth = oth->next;
                            }
                        }
                        frq[temp->val + 100]++;
                        temp = temp->next;
                    }
                    if(oth != nullptr)
                        oth->next = nullptr;
                    return head;
                }
            };
        
    </details>

---


* [ ] [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/description/) 
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
                ListNode* removeElements(ListNode* head, int val) {
                    if(head == nullptr)return head;
                    if(head->val == val)head = removeElements(head->next, val);
                    else head->next = removeElements(head->next, val);
                    return head;
                }
            }; 
        
    </details>

---


* [ ] [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/) 
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
                ListNode* remove(ListNode* head, int index){
                    if(index == 0){
                        head = head->next;
                    }
                    else{
                        ListNode* temp = head;
                        for(int i = 0; i < index - 1;i++){
                            temp = temp->next;
                        }
                        ListNode* cur = temp->next;
                        temp->next = cur->next;
                    }
                    return head;
                }
            public:
                ListNode* removeNthFromEnd(ListNode* head, int n) {
                    ListNode* temp = head;
                    int size = 0;
                    while(temp != nullptr){
                        ++size;
                        temp = temp->next;
                    }
                    int index = size - n;
                    return remove(head, index);
                }
            };
        
    </details>

---


* [ ] [Reorder List](https://leetcode.com/problems/reorder-list/description/) 
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
                void reorderList(ListNode* head) {
                    vector<int>v, vv;
                    ListNode* temp2 = head;
                    while(temp2 != nullptr){
                        v.push_back(temp2->val);
                        temp2 = temp2->next;
                    }
                    int l = 0, r = (int)v.size() - 1;
                    while(l <= r){
                        if(l == r)vv.push_back(v[l]);
                        else vv.push_back(v[l]), vv.push_back(v[r]);
                        ++l, --r;
                    }
                    temp2 = head->next;
                    for(int i = 1;i < vv.size();i++){
                        temp2->val = vv[i];
                        temp2 = temp2->next;
                    }
                }
            };
        
    </details>

---


* [ ] [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/description/) 
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
                pair<ListNode*,ListNode*> Get_head_tail(ListNode* head, int left, int right){
                    int idx = 0;
                    ListNode* first = nullptr, *second = nullptr;
                    while(head != nullptr){
                        if(idx == (left - 1)){
                            first = head;
                        }
                        if(idx == (right - 1)){
                            second = head;
                        }
                        head = head->next;
                        ++idx;
                    }
                    return {first, second};
                }
            public:
                ListNode* reverseBetween(ListNode* head, int left, int right) {
                    if(left == right)return head;
                    pair<ListNode*,ListNode*> head_tail = Get_head_tail(head, left, right);
                    ListNode* first = head_tail.first, *second = head_tail.second, *cur = second->next, *prev = nullptr;
                    if(head != first){
                        prev = head;
                        while(prev->next != first){
                            prev = prev->next;
                        }
                    }
                    for(int i = 1; i <= right - left + 1;i++){
                        ListNode* temp = first->next;
                        first->next = cur;
                        cur= first;
                        first = temp;
                    }
                    if(prev != nullptr){
                        prev->next = cur;
                    }
                    else head = cur;
                    return head;
                }
            };
        
    </details>

---


* [ ] [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/description/) 
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
                ListNode* reverseKGroup(ListNode* head, int k) {
                    ListNode* tail = head;
                    for(int i = 0 ; i < k - 1 && tail != nullptr;i++){
                        tail = tail->next;
                    }
                    if(tail == nullptr)return head;
                    ListNode* prev = reverseKGroup(tail->next, k);
                    ListNode* next = nullptr;
                    ListNode* cur = head;
                    while(cur != tail){
                        next = cur->next;
                        cur->next = prev;
                        prev = cur;
                        cur = next;
                    }
                    cur->next = prev;
                    return cur;
                }
            };
        
    </details>

---


* [ ] [Rotate List](https://leetcode.com/problems/rotate-list/description/) 
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
                pair<ListNode*, int> Get_Tail_Count(ListNode* head){
                    ListNode* prev = nullptr;
                    int count = 0;
                    while(head != nullptr){
                        prev = head;
                        head = head->next;
                        ++count;
                    }
                    return make_pair(prev, count);
                }
            public:
                ListNode* rotateRight(ListNode* head, int k) {
                    pair<ListNode*,int> res = Get_Tail_Count(head);
                    ListNode* tail = res.first;
                    int size = res.second;
                    if(size == 0)return nullptr;
                    k %= size;
                    int last_Node = size - k;
                    ListNode* temp = head;
                    for(int i = 0 ; i < last_Node - 1;i++){
                        temp = temp->next;
                    }
                    tail->next = head;
                    head = temp->next;
                    temp->next = nullptr;
                    return head;
                }
            };
        
    </details>

---