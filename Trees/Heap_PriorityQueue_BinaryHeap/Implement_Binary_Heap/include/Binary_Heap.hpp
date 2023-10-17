//
// Created by muhamed on 16/08/23.
//

#ifndef DATA_STRUCTURE_IMPLEMENTATION_BINARY_HEAP_H
#define DATA_STRUCTURE_IMPLEMENTATION_BINARY_HEAP_H

#include <stdexcept>
#include <vector>
#include <algorithm>

namespace DSA
{
	template<typename T, typename comp = std::less<T>>
	class Priority_queue
	{
	private:
		
		int _size;
		std::vector<T> _data;

		
	public:

		Priority_queue();

		inline bool empty() const;

		inline void pop();

		inline void push(const T& element);

		inline int size() const;

		inline void Swap(Priority_queue<T, comp> &_Right);

		inline const T& top() const;


	private:

		inline void bubble_up(const int& index);

		inline void bubble_down(const int& index);

		inline void incrementSize();

		inline void decrementSize();

	protected:

		comp comparator{};

	};

	template<typename T, typename comp>
	Priority_queue<T, comp>::Priority_queue()
	{
		this->_size = 0;
		this->_data = std::vector<T>(this->_size);
	}

	template<typename T, typename comp>
	inline void Priority_queue<T, comp>::incrementSize()
	{
		++this->_size;
	}

	template<typename T, typename comp>
	inline void Priority_queue<T, comp>::decrementSize()
	{
		--this->_size;
	}

	template<typename T, typename comp>
	inline bool Priority_queue<T, comp>::empty() const
	{
		return this->_size == 0;
	}

	template<typename T, typename comp>
	inline void Priority_queue<T, comp>::pop()
	{
		if (this->_size == 0)
			throw std::runtime_error("Priority_queue is empty ...!");

		this->_data[0] = this->_data[_size - 1];

		this->decrementSize();

		this->bubble_down(0);
	}

	template<typename T, typename comp>
	inline void Priority_queue<T, comp>::bubble_down(const int& index)
	{
		int root = index;
		int leftChild = 2 * root + 1;
		int rightChild = 2 * root + 2;

		if (leftChild < this->size()) 
		{

			bool _checkleft = comparator(this->_data[root], this->_data[leftChild]);

			if (_checkleft == true)
				root = leftChild;
		}

		if (rightChild < this->size())
		{

			bool _checkright = comparator(this->_data[root], this->_data[rightChild]);

			if (_checkright == true)
				root = rightChild;
		}

		if (root != index)
		{
			std::swap(this->_data[index], this->_data[root]);

			this->bubble_down(root);
		}

	}

	template<typename T, typename comp>
	inline void Priority_queue<T, comp>::push(const T& element)
	{
		this->_data.push_back(element);
		this->incrementSize();
		this->bubble_up(this->size() - 1);
	}


	// there is an logical error in comparison
	template<typename T, typename comp>
	inline void Priority_queue<T, comp>::bubble_up(const int& index)
	{
		if (index == 0)
			return;

		int par = (index - 1) / 2;
		
		bool _check = comparator(this->_data[par], this->_data[index]);

		if (_check == true)
		{
			std::swap(this->_data[index], this->_data[par]);
			this->bubble_up(par);
		}

		return;
	}

	template<typename T, typename comp>
	inline int Priority_queue<T, comp>::size() const
	{
		return this->_size;
	}

	template<typename T, typename comp>
	inline const T& Priority_queue<T, comp>::top() const
	{
		if (this->_size == 0)
		{
			throw std::runtime_error("Priority_queue is empty ...!");
		}

		return this->_data[0];
	}

}

#endif // DATA_STRUCTURE_IMPLEMENTATION_BINARY_HEAP_H