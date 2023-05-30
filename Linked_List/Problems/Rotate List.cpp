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