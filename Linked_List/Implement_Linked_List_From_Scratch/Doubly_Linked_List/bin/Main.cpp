#include <bits/stdc++.h>
using namespace std;

class DoublyLinkedList
{
private:
    struct Node
    {
        int item;
        Node *next;
        Node *prev;
        Node(): item(0), next(nullptr), prev(nullptr) {}
        Node(int val): item(val), next(nullptr), prev(nullptr) {}
    };
    Node *head;
    Node *tail;
    int count;

public:
    DoublyLinkedList(){
        head = tail = nullptr;
        count = 0;
    }

    bool isEmpty(){
        return (first == nullptr);
    }
    
    void insertFirst(int element){
        Node* newNode = new Node(element);
        if(count == 0){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            first = newNode;
        }
        ++count;
    }

    void insertLast(int element){
        Node* newNode = new Node(element);
        if(count == 0){
            head = tail = newNode;
        }
        else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        ++count;
    }

    void insert(int element, int index){
        Node* newNode = new Node(element);
        if(index == 0){
            insertFirst(element);
        }
        else if(index == count){
            insertLast(element);
        }
        else{
            Node* first = head;
            for(int i = 0; i < index - 1;i++){
                first = first->next;
            }
            // [first] [prev->newNode->next] [first->next]
            newNode->next = first->next;
            newNode->prev = first;
            first->next->prev = newNode;
            first->next = newNode;
            ++count;
        }
    }

    void removeFirst(){
        if(count == 0){
            return;
        }
        if(count == 1){
            delete head;
            head = tail = nullptr;
        }
        else{
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            temp = nullptr;
        }
        --count;
    }

    void removeLast(){
        if(count == 0){
            return;
        }
        if(count == 1){
            delete tail;
            head = tail = nullptr;
        }
        else{
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            temp = nullptr;
        }
        --count;
    }

    void remove(int element){
        if(count == 0){
            return;
        }
        if(head->item = element){
            removeFirst();
        }
        else{
            Node* temp = head->next;
            while(temp != nullptr && temp->item != element){
                temp = temp->next;
            }
            if(temp == nullptr){
                return;
            }
            else if(temp == tail){
                removeLast();
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                temp = nullptr;
                --count;
            }
        }
    }

    void Display(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->item <<< ' ';
            temp = temp->next;
        }
        cout << '\n';
    }

    void DisplayReverse(){
        Node* temp = tail;
        while(temp != nullptr){
            cout << temp->item << ' ';
            temp = temp->prev;
        }
        cout << '\n';
    }
};

int main()
{

    cout << "Hello Doubly Linked List" << endl;

    return 0;
}