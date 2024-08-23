
//
// Created by muhamed on 22/06/23.
//


#ifndef DATA_STRUCTURE_IMPLEMENTATION_HASHTABLE_H
#define DATA_STRUCTURE_IMPLEMENTATION_HASHTABLE_H

#include<stdexcept>
#include "Slots.hpp"

using namespace OTHERS;

namespace DSA
{
    

    template<typename K, typename V>
    class Unordered_map{
        
    private:

        Slots<K, V> **table;

        int __size;

    public:

        Unordered_map(int _size){
            table = new Slots<K, V>* [_size]{nullptr};
            (*this).__size = _size;
        }

        // Any hash function that have these properties :'
        // 1- Efficiently Computable.
        // 2- Should uniformly distribute the keys.
        // 3- Should minimize collisions.
        // 4- Should have a low load factor (number of items in the table divided by the size of the table).

        // In this function we will work with just a (string) key.
        int hashFunction(const std::string& key){
            int hashValue = 0;
            long long sum = 0, factor = 51;

            for(int i = 0;i < (int)key.size();i++){
                sum = ((sum % this->__size) + (((int)key[i]) * factor) % this->__size) % this->__size;
            }
            hashValue = sum;
            return hashValue;
        }

        void add(const K& _key, const V& _value){

            int hashIndex = hashFunction(_key);
            int initialIndex = -1;
            int indexOfDeleteEntry = -1;

            while(hashIndex != initialIndex && (table[hashIndex] == DeletedSlot<K,V>::getUniqueDeleteEntry() || (table[hashIndex] != nullptr && table[hashIndex]->getKey() != _key))){
                
                if(initialIndex == -1){
                    initialIndex = hashIndex;
                }

                if(table[hashIndex] == DeletedSlot<K, V>::getUniqueDeleteEntry() && indexOfDeleteEntry == -1){
                    indexOfDeleteEntry = hashIndex;
                }

                hashIndex = (hashIndex + 1) % this->__size;

            }

            if(table[hashIndex] == nullptr){
                table[hashIndex] = new Slots<K, V>(_key, _value);
            }
            else if(table[hashIndex]->getKey() == _key){
                table[hashIndex]->setValue(_value);
            }
            else if(indexOfDeleteEntry != -1){
                table[indexOfDeleteEntry] = new Slots<K, V>(_key, _value);
            }

        }

        bool exist(const K& _key){

            int hashIndex = hashFunction(_key);
            int initialIndex = -1;

            while(hashIndex != initialIndex && (table[hashIndex] == DeletedSlot<K, V>::getUniqueDeleteEntry() || table[hashIndex] != nullptr)){

                if(initialIndex == -1){
                    initialIndex = hashIndex;
                }
                
                if(table[hashIndex]->getKey() == _key){
                    return true;
                }

                // linear prob ... move to next element
                hashIndex = (hashIndex + 1) % (*this).__size;
            }

            return false;
        }

        V& get(const K& _key){
            return (*this)[_key];
        }

        V& operator[](const K& _key){

            int hashIndex = hashFunction(_key);
            int initialIndex = -1;

            // while did not back to start position (except initialization start)  and (deleted OR available but not me)
            while(hashIndex != initialIndex && (table[hashIndex] == DeletedSlot<K, V>::getUniqueDeleteEntry() || (table[hashIndex] != nullptr && table[hashIndex]->getKey() != _key))){
                
                if(initialIndex == -1){
                    initialIndex = hashIndex;
                }

                // linear prob ... move to next element
                hashIndex = (hashIndex + 1) % (*this).__size;
            }

            if(hashIndex == initialIndex){
                throw std::runtime_error("The map is Full ...!");
            }
            
            if(table[hashIndex] == nullptr){
                this->add(_key, V());
            }


            return table[hashIndex]->getValue(); 
        }

        void remove(const K& _key){
            int hashIndex = hashFunction(_key);
            int initialIndex = -1;

            while(hashIndex != initialIndex && (table[hashIndex] == DeletedSlot<K,V>::getUniqueDeleteEntry() || (table[hashIndex] != nullptr && table[hashIndex]->getKey() != _key))){
                
                if(initialIndex == -1){
                    initialIndex = hashIndex;
                }


                hashIndex = (hashIndex + 1) % this->__size;

            }

            if(hashIndex != initialIndex && table[hashIndex] != nullptr){
                delete table[hashIndex];
                table[hashIndex] = DeletedSlot<K, V>::getUniqueDeleteEntry();
            }
        }

        ~Unordered_map(){
            for(int i = 0; i < (*this).__size;i++){
                if(table[i] != nullptr && table[i] != DeletedSlot<K, V>::getUniqueDeleteEntry()){
                    delete table[i];
                }
            }
            delete [] table;
        }

    };

} // namespace DSA

#endif // DATA_STRUCTURE_IMPLEMENTATION_HASHTABLE_H
