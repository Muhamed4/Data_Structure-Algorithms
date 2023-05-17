#include<iostream>
#include "Linked_List.hpp"
using DSA::List;
using namespace std;

struct Node{
    int data;
    Node* Next;
    Node(): data(0), Next(nullptr) {}
    Node(int _data): data(_data), Next(nullptr) {}
};
Node* head;
Node* Insert(Node* head, int data){
    Node* temp = new Node(data);
    temp->Next = head;
    head = temp;
    return head;
}
// void Print(Node* head){
//     Node* temp = head;
//     while(temp != nullptr){
//         cout << temp->data << ' ';
//         temp = temp->Next;
//     }
//     cout << '\n';
// }
Node* Delete(Node* head, int n){
    Node* temp = head;
    if(n == 1){
        head = temp->Next;
        delete temp;
        return head;
    }
    for(int i = 0 ; i < n - 2;i++){
        temp = temp->Next;
    }
    Node* temp2 = temp->Next;
    temp->Next = temp2->Next;
    delete temp2;
    return head;
}


void Print(Node* head){
    if(head == nullptr)return;
    cout << head->data << endl;
    Print(head->Next);
}

void ReversePrint(Node* head){
    if(head == nullptr)return;
    ReversePrint(head->Next);
    cout << head->data << endl;
}

void ReverseRecursion(Node* p){
    if(p->Next == nullptr){
        head = p;
        return;
    }
    ReverseRecursion(p->Next);
    Node* temp = p->Next;
    temp->Next = p;
    p->Next = nullptr;
}

Node* ReverseIterative(Node* head){
    Node *current, *prev, *next;
    current = next = head;
    prev = nullptr;
    while(current != nullptr){
        next = current->Next;
        current->Next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void DeleteWithValue(Node* head, int data){
    if(head == nullptr)return;
    if(head->data == data){
        head = head->Next;
        return;
    }
    Node* cur = head;
    while(cur->Next != nullptr){
        if(cur->Next->data == data){
            cur->Next = cur->Next->Next;
            return;
        }
        cur = cur->Next;
    }
}

int main(){

    Node* head = nullptr;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8);
    DeleteWithValue(head, 6);
    ReversePrint(head);
    
    return 0;
}
