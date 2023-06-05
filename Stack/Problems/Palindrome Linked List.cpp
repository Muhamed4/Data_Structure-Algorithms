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
    ListNode* middle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != nullptr){
            fast = fast->next;
            if(fast != nullptr){
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode *prev = nullptr, *cur = head, *next = nullptr;
        while(cur != nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)return true;
        ListNode* mid = middle(head);
        ListNode* temp1 = head, *temp2 = reverse(mid->next);
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->val != temp2->val)return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};