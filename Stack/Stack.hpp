#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>

namespace BigO {
	template <typename T>
	class Stack {
	public:
		Stack() = default;
		explicit Stack(std::size_t capacity);
		~Stack();

		T operator[](std::size_t index);

		bool push(T data);
		T pop();
		bool isEmpty() const;

		void print();
	private:
		T *create(std::size_t capacity);
		void resize(T *&block, std::size_t oldCapacity, std::size_t capacity);
	private:
		T *block = nullptr;
		std::size_t _size = 0;
		std::size_t _capacity = 0;
	};
}

#include "Stack.inl"
