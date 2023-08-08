//
// Created by muhamed on 1/08/23.
//

#ifndef DATA_STRUCTURE_IMPLEMENTATION_BINARY_SEARCH_TREE_H
#define DATA_STRUCTURE_IMPLEMENTATION_BINARY_SEARCH_TREE_H

#include <iostream>
#include <stdexcept>
#include <stack>
#include <math.h>
#include <limits.h>

namespace DSA
{
    template <typename T>
    class MultiSet
    {
    private:

        struct Node
        {
            T item;
            Node *left;
            Node *right;
            Node() : item(T()), left(nullptr), right(nullptr) {}
            Node(T _item) : item(_item), left(nullptr), right(nullptr) {}
        };

        Node *root;

    public:

        MultiSet();

        MultiSet(const std::initializer_list<T> &initializer);

        ~MultiSet();

        inline void insert(const T& _value);

        Node* NewNode(const T& _value);

        inline int count(const T& _value) const;

        inline void clear();

        inline void print() const;

        inline bool find(const T& _value) const;

        inline int Get_Height();

        inline T Get_Min() const;

        inline T Get_Max() const;

        inline bool IsBinarySearchTree() const;

        inline void erase(const T& _value);

    private:

        inline int Count_Node(const T& _value, const Node* _root);

        inline void Clear(Node* &_root);

        int get_height(const Node* _root);

        inline bool isBinarySearchTree(const Node* _root, const int& mn, const int& mx) const;

        inline void deleteValue(const Node* _root, const T& _value);

    };

    template <typename T>
    MultiSet<T>::MultiSet() : root(nullptr) {}

    template<typename T>
    MultiSet<T>::MultiSet(const std::initializer_list<T>& initializer) : MultiSet() {

        for(auto &it: initializer){
            (*this).insert(it);
        }
    }

    template<typename T>
    MultiSet<T>::~MultiSet(){
        
        (*this).clear();
    }

    template<typename T>
    typename MultiSet<T>::Node* MultiSet<T>::NewNode(const T& _value){

        Node* _root = new Node(_value);

        return _root;
    }

    template<typename T>
    inline int MultiSet<T>::Count_Node(const T& _value, const Node* _root){

        if(_root == nullptr)return 0;
        
        int ret = 0;

        if(_root->item >= _value)ret += Count_Node(_value, _root->left) + (_root->item == _value);
        else ret += Count_Node(_value, _root->right);

        return ret; 
    }

    template<typename T>
    inline void MultiSet<T>::insert(const T& _value){

        Node** temp = &root;

        while((*temp) != nullptr){
            if((*temp)->item >= _value){
                temp = &((*temp)->left);
            }
            else temp = &((*temp)->right);
        }

        *temp = NewNode(_value);
    }

    template<typename T>
    inline int MultiSet<T>::count(const T& _value) const {
        return (*this).Count_Node(_value, (*this).root);
    }

    template<typename T>
    inline void MultiSet<T>::print() const{

        Node* temp = root;

        std::stack<Node*>st;

        while(temp != nullptr || !st.empty()){
            while(temp != nullptr){
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top();
            st.pop();

            std::cout << temp->item << ' ';
            temp = temp->right;
        }
    }

    template<typename T>
    inline void MultiSet<T>::Clear(Node* &_root){

        if(_root == nullptr)return;

        Clear(_root->left);
        Clear(_root->right);

        delete _root;
        _root = nullptr;
    }

    template<typename T>
    inline void MultiSet<T>::clear(){
        this->Clear((*this).root);
    }

    template<typename T>
    inline bool MultiSet<T>::find(const T& _value) const{

        bool _find = false;
        Node* temp = (*this).root;
        while(temp != nullptr){
            if(temp->item == _value){
                _find = true;
                break;
            }
            else if(temp->item > _value) temp = temp->left;
            else temp = temp->right;
        }

        return _find;
    }

    // Height of a Tree is the longest path from the root to any leaf node.
    template<typename T>
    int MultiSet<T>::get_height(const Node* _root){

        if(_root == nullptr){
            return -1;
        }

        return std::max(get_height(_root->left), get_height(_root->right)) + 1;
    }

    template<typename T>
    inline int MultiSet<T>::Get_Height(){

        return (*this).get_height((*this).root);
    }

    template<typename T>
    inline T MultiSet<T>::Get_Min() const{

        Node* temp = (*this).root;

        if(temp == nullptr){
            throw std::runtime_error("There are no elements in the tree...!");
        }

        while(temp->left != nullptr){
            temp = temp->left;
        }

        return temp->item;
    }

    template<typename T>
    inline T MultiSet<T>::Get_Max() const {
        
        Node* temp = (*this).root;

        if(temp == nullptr){
            throw std::runtime_error("There are no elements in the tree...!");
        }

        while(temp->right != nullptr){
            temp = temp->right;
        }

        return temp->item;
    }

    // This funciton works with just numbers, Try to implement it with other data types :)
    template<typename T>
    inline bool MultiSet<T>::isBinarySearchTree(const Node* _root, const int& mn, const int& mx) const{

        if(_root == nullptr)return true;
        if(_root->item < mn || _root->item > mx)return false;

        return isBinarySearchTree(_root->left, mn, _root->item) && isBinarySearchTree(_root->right, _root->item + 1, mx); 
    }

    template<typename T>
    inline bool MultiSet<T>::IsBinarySearchTree() const{
        
        return (*this).isBinarySearchTree((*this).root, INT_MIN, INT_MAX);
    }

    template<typename T>
    inline void MultiSet<T>::deleteValue(const Node* _root, const T& _value){
        
    }
}

#endif // DATA_STRUCTURE_IMPLEMENTATION_BINARY_SEARCH_TREE_H