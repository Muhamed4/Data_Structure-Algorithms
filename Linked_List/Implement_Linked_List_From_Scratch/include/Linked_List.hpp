

#ifndef DATA_STRUCTURE_IMPLEMENTATION_List_H
#define DATA_STRUCTURE_IMPLEMENTATION_List_H
#include <iostream>

namespace DSA
{

    class List
    {
        private:
            int data;
            List *Next;
        public:
            List(): data(0), Next(nullptr) {}

            List(int _data): data(_data), Next(nullptr) {}

    };

} // namespace DSA

#endif // DATA_STRUCTURE_IMPLEMENTATION_List_H