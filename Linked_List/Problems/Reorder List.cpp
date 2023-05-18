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
    void reorderList(ListNode* head) {
        vector<int>v, vv;
        ListNode* temp2 = head;
        while(temp2 != nullptr){
            v.push_back(temp2->val);
            temp2 = temp2->next;
        }
        int l = 0, r = (int)v.size() - 1;
        while(l <= r){
            if(l == r)vv.push_back(v[l]);
            else vv.push_back(v[l]), vv.push_back(v[r]);
            ++l, --r;
        }
        temp2 = head->next;
        for(int i = 1;i < vv.size();i++){
            temp2->val = vv[i];
            temp2 = temp2->next;
        }
    }
};