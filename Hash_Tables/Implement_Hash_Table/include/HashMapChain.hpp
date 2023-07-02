
//
// Created by muhamed on 22/06/23.
//


#ifndef DATA_STRUCTURE_IMPLEMENTATION_HASHTABLE_H
#define DATA_STRUCTURE_IMPLEMENTATION_HASHTABLE_H

#include<stdexcept>

namespace DSA
{
    template<typename K, typename V>
    class Unordered_map{

    private:

        struct Node
        {
        private:
            K key;
            V value;
            Node* next;

        public:

            Node(K _key, V _value): key(_key), value(_value), next(nullptr) {}

            const K& getKey() const { return this->key; }

            V& getValue() { return this->value; }

            Node* getNext() const { return next; }

            void setValue(V _value) { this->value = _value; }

            void setNext(Node* _next) { this->next = _next; }

            // ~Node(){
            //     Node* head = this;
            //     while(head != nullptr){
            //         Node* temp = head;
            //         head = head->getNext();
            //         delete temp;
            //         temp = nullptr;
            //     }
            // }
        };

        Node **table;
        int _size;
        int _capacity;




        float getLoadFactor(){
            return (float)(this->_size + 1) / (float)(this->_capacity);
        }


        void rehashing(){
            int oldCapacity = this->_capacity;
            this->_capacity = oldCapacity * 2;
            Node** newTable = this->table;
            table = new Node* [this->_capacity]{nullptr};

            for(int i = 0; i < oldCapacity;i++){
                Node* head = newTable[i];
                while(head != nullptr){
                    int hashIndex = hashFunction(head->getKey());
                    Node* newNode = new Node(head->getKey(), head->getValue());
                    newNode->setNext(this->table[hashIndex]);
                    table[hashIndex] = newNode;
                    
                    Node* temp = head;
                    head = head->getNext();
                    delete temp;
                    temp = nullptr;
                }
                // delete newTable[i];
            }

            delete[] newTable;

        }

        void increment_size(){
            ++this->_size;
        }

        void decrement_size(){
            --this->_size;
        }


    public:

        Unordered_map(){
            this->_capacity = 1;
            this->_size = 0;
            this->table = new Node* [_capacity]{nullptr};
        }


        // Any hash funcion that have these properties :'
        // 1- Efficiently Computable.
        // 2- Should uniformly distribute the keys.
        // 3- Should minimize collisions.
        // 4- Should have a low load factor (number of items in the table divided by the size of the table).

        // In this function we will work with just a (string) key.
        int hashFunction(std::string key){
            int hashValue = 0;
            long long sum = 0, factor = 51;

            for(int i = 0;i < (int)key.size();i++){
                sum = ((sum % this->_capacity) + (((int)key[i]) * factor) % this->_capacity) % this->_capacity;
            }
            hashValue = sum;
            return hashValue;
        }


        void add(K key, V value){

             while(this->getLoadFactor() > 0.5f){
                 this->rehashing();
             }

            int hashIndex = hashFunction(key);
            // std::cout << hashIndex << ' '<< this->_capacity << std::endl;

            Node* head = table[hashIndex];
            while(head != nullptr){
                if(head->getKey() == key){
                    head->setValue(value);
                    return;
                }
                head = head->getNext();
            }

            Node* newNode = new Node(key, value);
            newNode->setNext(table[hashIndex]);
            table[hashIndex] = newNode;
            this->increment_size();
        }

        bool exist(K key){
            int hashIndex = hashFunction(key);

            Node* head = table[hashIndex];
            while(head != nullptr){
                if(head->getKey() == key){
                    return true;
                }
                head = head->getNext();
            }

            return false;
        }


        V& get(K key){
            return (*this)[key];
        }

        V& operator[](const K& key){
            int hashIndex = hashFunction(key);

            Node* head = table[hashIndex];
            while(head != nullptr){
                if(head->getKey() == key){
                    return head->getValue();
                }
                head = head->getNext();
            }

            throw std::runtime_error("This Key is Not Exist ...!");
        }


        void remove(K key){
            int hashIndex = hashFunction(key);
            // std::cout << hashIndex << std::endl;

            Node* head = table[hashIndex];
            if(head == nullptr){
                throw std::runtime_error("This Key is Not Exist ...!");
            }
            if(head->getKey() == key){
                Node* temp = head;
                table[hashIndex] = head->getNext();
                delete temp;
                temp = nullptr;
                this->decrement_size();
                return;
            }
            while(head->getNext() != nullptr && head->getNext()->getKey() != key){
                head = head->getNext();
            }
            if(head->getNext() != nullptr && head->getNext()->getKey() == key){
                Node* temp = head->getNext();
                head->setNext(temp->getNext());
                delete temp;
                temp = nullptr;
                this->decrement_size();
            }

        }



        ~Unordered_map(){
            for(int i = 0; i < this->_capacity;i++){
                delete table[i];
            }
            delete[] table;
        }
    };

} // namespace DSA

#endif // DATA_STRUCTURE_IMPLEMENTATION_HASHTABLE_H
