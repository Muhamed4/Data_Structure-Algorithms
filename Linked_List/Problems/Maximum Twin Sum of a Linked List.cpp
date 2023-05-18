




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
    vector<int>v;
    void iterate(ListNode* head){
        if(head == nullptr)return;
        v.push_back(head->val);
        iterate(head->next);
    }
public:
    int pairSum(ListNode* head) {
        iterate(head);
        int l = 0, r = (int)v.size() - 1, ans = 0;
        while(l <= r){
            ans = max(ans, v[l] + v[r]);
            ++l; --r;
        }
        return ans;
    }
};