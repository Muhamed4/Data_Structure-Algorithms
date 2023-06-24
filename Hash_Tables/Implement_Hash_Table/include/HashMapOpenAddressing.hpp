
class HashEntry
{
private:
    int key;
    int value;

public:
    HashEntry(int key, int value)
    {
        this->key = key;
        this->value = value;
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
};

class DeleteEntry : public HashEntry
{
private:
    static DeleteEntry *entry;
    DeleteEntry() : HashEntry(-1, -1) {}

public:
    static DeleteEntry *getUniqueDeleteEntry()
    {
        if (entry == nullptr)
        {
            entry = new DeleteEntry();
        }
        return entry;
    }
};

DeleteEntry *DeleteEntry::entry = nullptr;

const int TABLE_SIZE = 128;

class HashMap
{
private:
    HashEntry **table;
public:

    HashMap(){
        table = new HashEntry *[TABLE_SIZE];
        for(int i = 0; i < TABLE_SIZE;i++){
            table[i] = nullptr;
        }
    }

    int get(int key){
        int hash = (key % TABLE_SIZE);
        int initialHash = -1;

        // while did not back to start position (except initialization start)  and (deleted OR available but not me)
        while(hash != initialHash && (table[hash] == DeleteEntry::getUniqueDeleteEntry() || 
            (table[hash] != nullptr && table[hash]->getKey() != key))){

            if(initialHash == -1){
                initialHash = hash;
            }    

            hash = (hash + 1) % TABLE_SIZE;   // linear prob .. move to next element
        }

        if(table[hash] == nullptr || hash == initialHash) 
            return -1;
        else 
            return table[hash]->getValue();
    }


    void put(int key, int value){
        int hash = (key % TABLE_SIZE);
        int initialHash = -1;
        int indexOfDeleteEntry = -1;

        while(hash != initialHash && (table[hash] == DeleteEntry::getUniqueDeleteEntry() ||
            (table[hash] != nullptr && table[hash]->getKey() != key))){
            
            if(initialHash == -1)
                initialHash = hash;
            
            if(table[hash] == DeleteEntry::getUniqueDeleteEntry())
                indexOfDeleteEntry = hash;

            hash = (hash + 1) % TABLE_SIZE;
        }

        if((table[hash] || initialHash == hash) && indexOfDeleteEntry != -1)
            table[indexOfDeleteEntry] = new HashEntry(key, value);
        else if(initialHash != hash)
            if(table[hash] != DeleteEntry::getUniqueDeleteEntry() && table[hash] != nullptr && 
                table[hash]->getKey() == key)
                table[hash]->setValue(value);
            else
                table[hash] = new HashEntry(key, value);
    }

    void remove(int key){
        int hash = key % TABLE_SIZE;
        int initialHash = -1;

        while(hash != initialHash && (table[hash] == DeleteEntry::getUniqueDeleteEntry() || 
            (table[hash] != nullptr && table[hash]->getKey() != key))){

            if(initialHash == -1)
                initialHash = hash;

            hash = (hash + 1) % TABLE_SIZE;
        }

        if(initialHash != hash && table[hash] != nullptr){
            delete table[hash];
            table[hash] = DeleteEntry::getUniqueDeleteEntry();
        }
    }

    ~HashMap(){
        for(int i = 0; i < TABLE_SIZE;i++){
            if(table[i] != nullptr && table[i] != DeleteEntry::getUniqueDeleteEntry()){
                delete table[i];
            }
        }
        delete[] table;
    }
};

