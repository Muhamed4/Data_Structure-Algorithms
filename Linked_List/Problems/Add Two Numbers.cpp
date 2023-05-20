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