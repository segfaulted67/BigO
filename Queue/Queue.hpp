#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>

namespace BigO {
	template <typename T>
	class Queue {
	public:
		Queue() = default;
		explicit Queue(std::size_t capacity);
		~Queue();

		T operator[](std::size_t index);

		bool push(T data);
		T pop();

		bool isEmpty();

		std::size_t size();
		std::size_t capacity();
		T head();
		T tail();

		T peek();

		void print();
	private:
		T *create(std::size_t capacity);
		void resize(T *&block, std::size_t oldCapacity, std::size_t capacity);
	private:
		T *block = nullptr;
		std::size_t _size = 0;
		std::size_t _capacity = 0;
		std::size_t _head = 0;
		std::size_t _tail = 0;
	};
}

#include "Queue.inl"
