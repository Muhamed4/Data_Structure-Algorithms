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