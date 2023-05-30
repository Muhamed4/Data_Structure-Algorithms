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