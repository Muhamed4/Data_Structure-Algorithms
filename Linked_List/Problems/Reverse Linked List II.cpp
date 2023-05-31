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