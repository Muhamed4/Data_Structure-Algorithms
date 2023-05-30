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