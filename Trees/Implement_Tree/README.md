# Implement MultiSet using (Binary Search Tree) :

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