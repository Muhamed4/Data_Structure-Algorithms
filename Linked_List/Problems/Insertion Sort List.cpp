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
    int getSize(ListNode* head){
        int size = 0;
        while(head != nullptr){
            head = head->next;
            ++size;
        }
        return size;
    }
    ListNode* getprevNode(ListNode* head, int index){
        if(index == 1)return nullptr;
        if(index == 2)return head;
        for(int i = 1; i <= index - 2;i++){
            head = head->next;
        }
        return head;
    }
    ListNode* insertionSort(ListNode* head){
        if(head->next == nullptr || head->val <= head->next->val)return head;
        ListNode* temp = head->next->next;
        ListNode* cur = head->next;
        head->next = temp;
        cur->next = insertionSort(head);
        return cur;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp = nullptr;
        int size = getSize(head);
        for(int i = size;i >= 1;i--){
            temp = getprevNode(head, i);
            if(temp == nullptr)temp = insertionSort(head);
            else temp->next = insertionSort(temp->next);
        }
        return temp;
    }
};