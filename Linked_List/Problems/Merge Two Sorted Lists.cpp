


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