#include<iostream>
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



class Linked_List{

    struct Node{
        int item;
        Node* next;
        Node(): item(0), next(nullptr) {}
    };
    Node *head;
    Node *tail;
    int _size;
public:
    Linked_List(){
        head = tail = nullptr;
        _size = 0;
    }

    bool isEmpty(){
        return _size == 0;
    }

    void InsertFront(int element){
        Node *newNode = new Node();
        newNode->item = element;
        if(_size == 0){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        ++_size;
    }

    void InsertBack(int element){
        Node* newNode = new Node();
        newNode->item = element;
        if(_size == 0){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        ++_size;
    }

    void Insert_at_Index(int element, int index){
        if(index < 0 || index >= _size){
            throw std::out_of_range("out of range");
        }
        if(index == 0){
            InsertFront(element);
        }
        else if(index == _size){
            InsertBack(element);
        }
        else{
            Node* temp = new Node();
            temp->item = element;
            Node* cur = head;
            for(int i = 0; i < index - 1;i++){
                cur = cur->next;
            }
            temp->next = cur->next;
            cur->next = temp;
            ++_size;
        }
    }

    void DeleteFront(){
        if(head == nullptr){
            throw std::runtime_error("the list is empty");
        }
        else if(_size == 1){
            delete head;
            head = tail = nullptr;
            --_size;
        }
        else{
            Node* temp = head;
            head = temp->next;
            --_size;
            delete temp;
            temp = nullptr;
        }
    }

    void DeleteBack(){
        if(head == nullptr){
            throw std::runtime_error("the list is empty");
        }
        else if(_size == 1){
            delete head;
            head = tail = nullptr;
            --_size;
        }
        else{
            Node* cur = head->next;
            Node* prev = head;
            while(cur != tail){
                prev = cur;
                cur = cur->next;
            }
            delete cur;
            cur = nullptr;
            prev->next = nullptr;
            tail = prev;
            --_size;
        }
    }

    void Remove(int element){
        if(isEmpty()){
            return;
        }
        Node *cur, *prev;
        if(head->item == element){
            cur = head;
            head = head->next;
            delete cur;
            --_size;
            if(--_size == 0)tail = nullptr;
        }
        else{
            cur = head->next;
            prev = head;
            while(cur != nullptr && cur->item != element){
                prev = cur;
                cur = cur->next;
            }
            if(cur != nullptr){
                prev->next = cur->next;
                if(tail == cur){
                    tail = prev;
                }
                delete cur;
                --_size;
            }
        }

    }

    void Reverse(){
        Node* prev, *cur, *next;
        prev = nullptr;
        cur = head;
        next = head->next;
        tail = head;
        while(next != nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    void Print(){
        for(Node* temp = head; temp != nullptr; temp = temp->next){
            cout << temp->item << ' ';
        }
        cout << '\n';
    }
};


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

    return 0;
}