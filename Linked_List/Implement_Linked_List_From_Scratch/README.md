# Singly Linked List


    ```c++
        #ifndef DATA_STRUCTURE_IMPLEMENTATION_List_H
        #define DATA_STRUCTURE_IMPLEMENTATION_List_H

        #include<stdexcept>

        namespace DSA
        {

            template<typename T>
            class List{

                private:

                    struct Node{
                        T item;
                        Node* next;
                        Node(T element) : item(element), next(nullptr) {}
                    };

                    Node *head;
                    Node *tail;
                    int _size;

                public:

                    List();

                    ~List();

                    int size() const;

                    bool empty() const;

                    T value_at(int index) const;

                    void push_front(T element);

                    T pop_front();

                    void push_back(T element);

                    T pop_back();

                    T front();

                    T back();

                    void insert(int index, T element);

                    void erase(int index);

                    T value_n_from_end(int index);

                    void reverse();

                    void remove_value(T value);

                    T Get_Value(int index);

                private:

                    void increment_size();

                    void decrement_size();
            };

            template<typename T>
            List<T>::List() : head(nullptr), tail(nullptr), _size(0) {}

            template<typename T>
            void List<T>::increment_size(){
                ++(*this)._size;
            }

            template<typename T>
            void List<T>::decrement_size(){
                --(*this)._size;
            }

            template<typename T>
            int List<T>::size() const{
                return (*this)._size;
            }

            template<typename T>
            bool List<T>::empty() const{
                return this->head == nullptr;
            }

            template<typename T>
            T List<T>::value_at(int index) const{
                if(index < 0 || index >= this->size()){
                    throw std::out_of_range("the index is out of the range");
                }
                Node* temp = head;
                for(int i = 0 ; i < index;i++){
                    temp = temp->next;
                }
                return temp->item;
            }

            template<typename T>
            void List<T>::push_front(T element){
                Node* temp = new Node(element);
                if(head == nullptr){
                    head = tail = temp;
                }
                else{
                    temp->next = head;
                    head = temp;
                }
                (*this).increment_size();
            }

            template<typename T>
            T List<T>::pop_front(){
                T value;
                if(head == nullptr){
                    throw std::runtime_error("There are no elements in the List");
                }
                else if(head == tail){
                    value = head->item; 
                    delete head;
                    head = tail = nullptr;
                }
                else{
                    value = head->item;
                    Node *temp = head;
                    head = head->next;
                    delete temp;
                    temp = nullptr;
                }
                (*this).decrement_size();
                return value;
            }

            template<typename T>
            void List<T>::push_back(T element){
                Node *temp = new Node(element);
                if(head == nullptr){
                    head = tail = temp;
                }
                else{
                    tail->next = temp;
                    tail = temp;
                }
                (*this).increment_size();
            }

            template<typename T>
            T List<T>::pop_back(){
                T value;
                if(head == nullptr){
                    throw std::runtime_error("There are no elements in the List");
                }
                if(head == tail){
                    value = head->item;
                    delete head;
                    head = tail = nullptr;
                }
                else{
                    value = tail->item;
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
                }
                (*this).decrement_size();
                return value;
            }

            template<typename T>
            T List<T>::front(){
                if(head == nullptr){
                    throw std::runtime_error("The List is empty");
                }
                return (*this).head->item;
            }

            template<typename T>
            T List<T>::back(){
                if(head == nullptr){
                    throw std::runtime_error("The List is empty");
                }
                return (*this).tail->item;
            }

            template<typename T>
            void List<T>::insert(int index, T element){
                if(index < 0 || index > (*this).size()){
                    throw std::out_of_range("The index is out of the range");
                }
                if(index == 0){
                    (*this).push_front(element);
                }
                else if(index == (*this).size()){
                    (*this).push_back(element);
                }
                else{
                    Node* temp = new Node(element);
                    Node* prev = head;
                    for(int i = 0; i < index - 1;i++){
                        prev = prev->next;
                    }
                    Node* Next = prev->next;
                    prev->next = temp;
                    temp->next = Next;
                    (*this).increment_size();
                }
            }

            template<typename T>
            void List<T>::erase(int index){
                if(index < 0 || index >= (*this).size()){
                    throw std::runtime_error("You are trying to erase a value at index that does not in the range");
                }
                if(index == 0){
                    (*this).pop_front();
                }
                else if(index == (*this).size() - 1){
                    (*this).pop_back();
                }
                else{
                    Node* prev = head;
                    for(int i = 0; i < index - 1;i++){
                        prev = prev->next;
                    }
                    Node* temp = prev->next;
                    prev->next = temp->next;
                    delete temp;
                    (*this).decrement_size();
                }
            }

            template<typename T>
            T List<T>::value_n_from_end(int index){
                if(index < 0 || index >= (*this).size()){
                    throw std::out_of_range("The index is out of the range");
                }
                int actual_index = (*this).size() - index;
                Node* temp = head;
                for(int i = 0; i < actual_index;i++){
                    temp = temp->next;
                }
                return temp->item;
            }

            template<typename T>
            void List<T>::reverse(){
                if(head == nullptr){
                    throw std::runtime_error("There are no elements");
                }
                Node* prev = nullptr;
                Node* cur = head;
                Node *next = head->next;
                tail = head;
                while (next != nullptr){
                    next = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = next;
                }
                head = prev;
            }

            template<typename T>
            void List<T>::remove_value(T value){
                if(head == nullptr){
                    return;
                }
                Node *cur, *prev;
                if(head->item == value){
                    cur = head;
                    head = head->next;
                    delete cur;
                    if((*this).size() == 1){
                        tail = nullptr;
                    }
                }
                else{
                    prev = head;
                    cur = head->next;
                    while(cur != nullptr && cur->item != value){
                        prev = cur;
                        cur = cur->next;
                    }
                    if(cur != nullptr){
                        prev->next = cur->next;
                        if(cur == tail){
                            tail = prev;
                        }
                        delete cur;
                    }
                }
                (*this).decrement_size();
            }

            template<typename T>
            T List<T>::Get_Value(int index){
                if(index < 0 || index >= (*this).size()){
                    throw std::out_of_range("The index is out of the range");
                }

                Node* temp = head;
                for(int i = 0; i < index;i++){
                    temp = temp->next;
                }
                return (*temp).item;
            }

            template<typename T>
            List<T>::~List(){
                Node* temp = head;
                while(temp != nullptr){
                    Node* Next = temp->next;
                    delete temp;
                    temp = Next;
                }
                head = tail = temp = nullptr;
            }


        } // namespace DSA

        #endif // DATA_STRUCTURE_IMPLEMENTATION_List_H



        // index = 3
        //
        //  0  1  2  3  4  5
        // [] [] [] [] [] []
        //          ^
        //          |
        //
        // actual index = size - index;
        // actual index = 6 - 3 = 3;


# Doubly Linked List

```c++

        #ifndef DATA_STRUCTURE_IMPLEMENTATION_DDList_H
        #define DATA_STRUCTURE_IMPLEMENTATION_DDList_H

        #include<stdexcept>

        namespace DSA
        {
            template<typename T>
            class DList{

                private:

                    struct Node
                    {
                        T item;
                        Node* next;
                        Node* prev;
                        Node(T element): item(element), next(nullptr), prev(nullptr) {}
                    };

                    Node* head;
                    Node* tail;
                    int _size;

                public:

                    DList();

                    ~DList();

                    int size() const;

                    bool empty() const;

                    T value_at(int index) const;

                    void push_front(T element);

                    T pop_front();

                    void push_back(T element);

                    T pop_back();

                    T front();

                    T back();

                    void insert(int index, T element);

                    void erase(int index);

                    T value_n_from_end(int index);

                    void reverse();

                    void remove(T element);

                    T Get_Value(int index);

                private:

                    void increment_size();

                    void decrement_size();

                    Node* Get_Node_at_index(int index);
                    
            };


            template<typename T>
            DList<T>::DList(): head(nullptr), tail(nullptr), _size(0) {}

            template<typename T>
            void DList<T>::increment_size(){
                ++(*this)._size;
            }

            template<typename T>
            void DList<T>::decrement_size(){
                --(*this)._size;
            }

            template<typename T>
            typename DList<T>::Node* DList<T>::Get_Node_at_index(int index){
                Node* prev = head;
                // index = 2
                // [] [] [] [] []
                for(int i = 0 ; i < index - 1;i++){
                    prev = prev->next;
                }
                return prev;
            }

            template<typename T>
            int DList<T>::size() const{
                return (*this)._size;
            }

            template<typename T>
            bool DList<T>::empty() const{
                return (*this).head == nullptr; 
            }

            template<typename T>
            T DList<T>::value_at(int index) const{
                if(index < 0 || index >= (*this).size()){
                    throw std::out_of_range("the index is out of the range");
                }
                Node* temp = head;
                for(int i = 0; i < index;i++){
                    temp = temp->next;
                }
                return (*temp).item;
            }

            template<typename T>
            void DList<T>::push_front(T element){
                Node* newNode = new Node(element);
                if(head == nullptr){
                    head = tail = newNode;
                }
                else{
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                }
                (*this).increment_size();
            }

            template<typename T>
            T DList<T>::pop_front(){
                T value;
                if(head == nullptr){
                    throw std::runtime_error("There are no elements in the DList");
                }
                else if(head == tail){
                    value = head->item;
                    delete head;
                    head = tail = nullptr;
                }
                else{
                    value = head->item;
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                    head->prev = nullptr;
                    temp = nullptr;
                }
                (*this).decrement_size();
                return value;
            }

            template<typename T>
            void DList<T>::push_back(T element){
                Node* newNode = new Node(element);
                if(head == nullptr){
                    head = tail = newNode;
                }
                else{
                    tail->next = newNode;
                    newNode->prev = tail;
                    tail = newNode;
                }
                (*this).increment_size();
            }

            template<typename T>
            T DList<T>::pop_back(){
                T value;
                if(head == nullptr){
                    throw std::runtime_error("There are no elements in the DList");
                }
                if(head == tail){
                    value = head->item;
                    delete head;
                    head = tail = nullptr;
                }
                else{
                    value = tail->item;
                    Node* temp = tail->prev;
                    delete tail;
                    tail = temp;
                    tail->next = nullptr;
                }
                (*this).decrement_size();
                return value;
            }

            template<typename T>
            T DList<T>::front(){
                if(head == nullptr){
                    throw std::runtime_error("The DList is empty");
                }
                return (*this).head->item;
            }

            template<typename T>
            T DList<T>::back(){
                if(head == nullptr){
                    throw std::runtime_error("The DList is empty");
                }
                return (*this).tail->item;
            }

            template<typename T>
            void DList<T>::insert(int index, T element){
                if(index < 0 || index > (*this).size()){
                    throw std::out_of_range("The index is out of the range");
                }
                if(index == 0){
                    (*this).push_front(element);
                }
                else if(index == (*this).size()){
                    (*this).push_back(element);
                }
                else{
                    Node* temp = new Node(element);
                    Node* prev = (*this).Get_Node_at_index(index);
                    Node* Next = prev->next;
                    prev->next = temp;
                    temp->prev = prev;
                    temp->next = Next;
                    Next->prev = temp;
                    (*this).increment_size();
                }
            }

            template<typename T>
            void DList<T>::erase(int index){
                if(index < 0 || index >= (*this).size()){
                    throw std::runtime_error("You are trying to erase a value at index that does not in the range");
                }
                if(index == 0){
                    (*this).pop_front();
                }
                else if(index == (*this).size() - 1){
                    (*this).pop_back();
                }
                else{
                    Node* prev = (*this).Get_Node_at_index(index);
                    Node* temp = prev->next;
                    prev->next = temp->next;
                    temp->next->prev =  prev;
                    delete temp;
                    temp = nullptr;
                    (*this).decrement_size();
                }
            }

            template<typename T>
            T DList<T>::value_n_from_end(int index){
                if(index < 0 || index >= (*this).size()){
                    throw std::out_of_range("The index is out of the range");
                }
                // index = 2
                // [] [] [] [] []
                Node* temp = tail;
                for(int i = 0; i < index - 1;i++){
                    temp = temp->prev;
                }
                return (*temp).item;
            }

            template<typename T>
            void DList<T>::reverse(){
                Node* temp = head;
                while(temp != nullptr){
                    Node* swapNode = temp->prev;
                    temp->prev = temp->next;
                    temp->next = swapNode;
                    swapNode = nullptr;
                    temp = temp->prev;
                }
                temp = head;
                head = tail;
                tail = temp;
                temp = nullptr;
            }

            template<typename T>
            void DList<T>::remove(T element){

                if((*this).size() == 0){
                    return;
                }
                
                if(head->item == element){
                    (*this).pop_front();
                }
                else{
                    Node* temp = head;
                    while(temp != nullptr && temp->item != element){
                        temp = temp->next;
                    }
                    if(temp == tail){
                        (*this).pop_back();
                    }
                    else if(temp != nullptr){
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        delete temp;
                        temp = nullptr;
                        (*this).decrement_size();
                    }
                }
            }

            template<typename T>
            T DList<T>::Get_Value(int index){
                if(index < 0 || index >= (*this).size()){
                    throw std::out_of_range("The index is out of the range");
                }

                Node* temp = head;
                for(int i = 0; i < index;i++){
                    temp = temp->next;
                }
                return (*temp).item;
            }

            template<typename T>
            DList<T>::~DList(){
                Node* temp = head;
                while(temp != nullptr){
                    Node* Next = temp->next;
                    delete temp;
                    temp = Next;
                }
                head = tail = temp = nullptr;
            }

        } // namespace DSA

        #endif // DATA_STRUCTURE_IMPLEMENTATION_DDList_H
