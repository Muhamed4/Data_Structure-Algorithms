class LinkedHashEntry
{
private:
    int key;
    int value;
    LinkedHashEntry *next;

public:
    LinkedHashEntry(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }

    int getKey()
    {
        return this->key;
    }

    int getValue()
    {
        return this->value;
    }

    void setValue(int value)
    {
        this->value = value;
    }

    LinkedHashEntry *getNext()
    {
        return this->next;
    }

    void setNext(LinkedHashEntry *next)
    {
        this->next = next;
    }
};

const int TABLE_SIZE = 128;

class HashMap
{
private:
    LinkedHashEntry **table;

public:
    HashMap(){
        table = new LinkedHashEntry *[TABLE_SIZE];
        for(int i = 0; i < TABLE_SIZE;i++){
            table[i] = nullptr;
        }
    }

    int get(int key){
        int hash = (key % TABLE_SIZE);
        if(table[hash] == nullptr){
            return -1;
        }
        LinkedHashEntry *entry = table[hash];
        while(entry != nullptr && entry->getKey() != key){
            entry = entry->getNext();
        }
        if(entry == nullptr) return -1;
        return entry->getValue();
    }

    void put(int key, int value){
        int hash = (key % TABLE_SIZE);
        if(table[hash] == nullptr){
            table[hash] = new LinkedHashEntry(key, value);
            return;
        }
        LinkedHashEntry *entry = table[hash];
        while(entry->getNext() != nullptr){
            if(entry->getKey() == key){
                entry->setValue(value);
                return;
            }
            entry = entry->getNext();
        }
        if(entry->getKey() == key){
            entry->setValue(value);
        }
        else entry->setNext(new LinkedHashEntry(key, value));
    }

    void remove(int key){

        int hash = (key % TABLE_SIZE);
        
        if(table[hash] != nullptr){
            LinkedHashEntry *prevEntry = nullptr;
            LinkedHashEntry *entry = table[hash];

            while(entry->getNext() != nullptr && entry->getKey() != key){
                prevEntry = entry;
                entry = entry->getNext();
            }

            if(entry->getKey() == key){
                if(prevEntry == nullptr){
                    LinkedHashEntry *nextEntry = entry->getNext();
                    delete entry;
                    table[hash] = nextEntry;
                }
                else{
                    LinkedHashEntry *next = entry->getNext();
                    prevEntry->setNext(next);
                    delete entry;
                }
            }
        }
    }

    ~HashMap(){
        for(int i = 0; i < TABLE_SIZE;i++){
            LinkedHashEntry *prevEntry = nullptr;
            LinkedHashEntry *entry = table[i];
            while(entry != nullptr){
                prevEntry = entry;
                entry = entry->getNext();
                delete prevEntry;
            }
        }
        delete[] table;
    }
};