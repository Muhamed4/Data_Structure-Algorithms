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