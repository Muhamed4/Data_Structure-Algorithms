#include <bits/stdc++.h>
#include "Linked_List.hpp"
using DSA::List;
using namespace std;

// class Node{
//     public:
//     int data;
//     Node* Next;
//     Node(): data(0), Next(nullptr) {}
//     // Node(int _data): data(_data), Next(nullptr) {}
//     Node(int _data): Node(_data, nullptr) {}
//     Node(int _data, Node* _next): data(_data), Next(_next) {}
// };
// Node* head;
// Node* Insert(Node* head, int data){
//     // Node* temp = new Node(data);
//     // temp->Next = head;
//     // head = temp;
//     head = new Node(data, head);
//     return head;
// }
// // void Print(Node* head){
// //     Node* temp = head;
// //     while(temp != nullptr){
// //         cout << temp->data << ' ';
// //         temp = temp->Next;
// //     }
// //     cout << '\n';
// // }
// Node* Delete(Node* head, int n){
//     Node* temp = head;
//     if(n == 1){
//         head = temp->Next;
//         delete temp;
//         return head;
//     }
//     for(int i = 0 ; i < n - 2;i++){
//         temp = temp->Next;
//     }
//     Node* temp2 = temp->Next;
//     temp->Next = temp2->Next;
//     delete temp2;
//     return head;
// }


// void Print(Node* head){
//     for(Node* temp = head; temp != nullptr; temp = temp->Next){
//         cout << temp->data << ' ';
//     }
// }

// void ReversePrint(Node* head){
//     if(head == nullptr)return;
//     ReversePrint(head->Next);
//     cout << head->data << endl;
// }

// void ReverseRecursion(Node* p){
//     if(p->Next == nullptr){
//         head = p;
//         return;
//     }
//     ReverseRecursion(p->Next);
//     Node* temp = p->Next;
//     temp->Next = p;
//     p->Next = nullptr;
// }

// Node* ReverseIterative(Node* head){
//     Node *current, *prev, *next;
//     current = next = head;
//     prev = nullptr;
//     while(current != nullptr){
//         next = current->Next;
//         current->Next = prev;
//         prev = current;
//         current = next;
//     }
//     head = prev;
//     return head;
// }

// void DeleteWithValue(Node* head, int data){ 
//     if(head == nullptr)return;
//     if(head->data == data){
//         head = head->Next;
//         return;
//     }
//     Node* cur = head;
//     while(cur->Next != nullptr){
//         if(cur->Next->data == data){
//             cur->Next = cur->Next->Next;
//             return;
//         }
//         cur = cur->Next;
//     }
// }




// Doubly Linked List

struct Node{
    int data;
    Node* next;
    Node* prev;
};
Node* head;

Node* GetNewNode(int element){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void InsertAtHead(int element){
    Node* newNode = GetNewNode(element);
    if(head == nullptr){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;

}

int main(){

    list<int> lis {1, 2, 3, 4, 5};
    lis.push_back(6);
    lis.push_front(0);
    lis.erase(lis.begin());
    lis.assign(10, 2);
    for(auto it: lis)cout << it << ' ';
    cout << endl; 
  
    return 0;
}