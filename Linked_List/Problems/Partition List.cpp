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