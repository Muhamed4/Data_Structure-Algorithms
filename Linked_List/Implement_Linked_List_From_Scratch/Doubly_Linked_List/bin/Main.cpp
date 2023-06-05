#include <iostream>

#include "Linked_List.hpp"

using namespace DSA::DList;

using namespace std;

template<typename T>
class List{

    struct Node
    {
        T item;
        Node* next;
        Node* prev;
        Node(T element): item(element), next(nullptr), prev(nullptr) {}
    };

    public :

    Node* Get_Node();
};

template<typename T>
typename List<T>::Node* List<T>::Get_Node(){
    Node* temp = new Node(3);
    return temp;
}

int main()
{
    
    
    return 0;
}