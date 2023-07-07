
//
// Created by muhamed on 22/06/23.
//


#ifndef DATA_STRUCTURE_IMPLEMENTATION_SLOTS_H
#define DATA_STRUCTURE_IMPLEMENTATION_SLOTS_H

#include<stdexcept>

namespace OTHERS
{
    

    template<typename K, typename V>
    class Slots{
        
    private:

        K key;
        V value;

    public:

        Slots(const K& _key, const V& _value){
            this->key = _key;
            this->value = _value;
        }

        const K& getKey() const{
            return this->key;
        }

        V& getValue() {
            return this->value;
        }

        void setValue(const V& _value){
            this->value = _value;
        }
        
    };



    template<typename K, typename V>
    class DeletedSlot: public Slots<K, V>{

    private:

        static DeletedSlot *Killed;

        DeletedSlot(): Slots<K, V>(K(), V()) {}
    
    public:

        static DeletedSlot* getUniqueDeleteEntry(){
            if(Killed == nullptr){
                Killed = new DeletedSlot();
            }
            return Killed;
        }

        // ~DeletedSlot(){
        //     if(Killed != nullptr){
        //         delete Killed;
        //         Killed = nullptr;
        //     }
        // }

    };

    template<typename K, typename V>
    DeletedSlot<K, V> *DeletedSlot<K, V>::Killed = nullptr;

} // namespace OTHERS

#endif // DATA_STRUCTURE_IMPLEMENTATION_SLOTS_H
