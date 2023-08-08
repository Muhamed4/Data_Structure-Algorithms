# Implement MultiSet using (Binary Search Tree) :


## Main Class :

* ```c++
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

---

* [ ] Insert
    > Insert a new value into the tree.
    * <details>
        <summary> Implementation </summary>

        ```c++
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
        
    </details>

* [ ] Count(_value)
    > Count the number of nodes that have this value.

* [ ] Clear
    > Clear all nodes of the tree.

* [ ] Print
    > Print the tree in these ways:

    > Inorder Traversal.

    > Preorder Traversal.

    > PostOrder Traversal.

    > Level Order Traversal.

* [ ] Find(_value)
    > return true if (_value) exist in the tree otherwise return false.

* [ ] Get_Height()
    > return the height of the tree.

* [ ] Get_Min()
    > return the minimum value in the tree.

* [ ] Get_Max()
    > return the maximum value in the tree.

* [ ] IsBinarySearchTree()
    > return true if the tree is a binary search tree otherwise return false.