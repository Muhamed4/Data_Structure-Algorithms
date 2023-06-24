/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*>mp;
        Node* headans = nullptr, *temp = nullptr;
        Node* oth = head;
        while(oth != nullptr){
            Node* newNode = new Node(oth->val);
            if(headans == nullptr){
                headans = temp = newNode;
            }
            else{
                temp->next = newNode;
                temp = temp->next;
            }
            mp[oth] = temp;
            oth = oth->next;
        }
        Node *temp2 = headans;
        while(head != nullptr){
            if(head->random != nullptr)temp2->random = mp[head->random];
            head = head->next;
            temp2 = temp2->next;
        }
        return headans;
    }
};