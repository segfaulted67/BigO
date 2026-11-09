#pragma once

namespace BigO {
	template <typename T>
	struct LNode {
		T data;
		LNode<T> *next = nullptr;

		LNode() = default;
		explicit LNode(const T &_data) : data(_data), next(nullptr) { }
	};

	template <typename T>
	class List {
	public:
		List() = default;
		~List();

		bool insert(T data, std::size_t position);
		bool push_back(T data);
		bool push_front(T data);
		bool search(T data) const;
		LNode<T> *remove(std::size_t position);
		LNode<T> *pop();
		LNode<T> *pop_front();

		std::size_t size() const;
		const LNode<T> *peek() const;

		void print() const;
	private:
		LNode<T> *create(T data);
		void destroy(LNode<T> *nodeHead);
		bool insertFirst(LNode<T> *&nodeHead, LNode<T> *&nodeTail, T data);
		bool insertLast(LNode<T> *&nodeHead, LNode<T> *&nodeTail, T data);
		bool insertAt(LNode<T> *&nodeHead, LNode<T> *&nodeTail, T data, std::size_t size, std::size_t position);
		bool search(LNode<T> *nodeHead, T data) const;
		LNode<T> *removeFirst(LNode<T> *&nodeHead, LNode<T> *&nodeTail);
		LNode<T> *removeLast(LNode<T> *&nodeHead, LNode<T> *&nodeTail);
		LNode<T> *removeAt(LNode<T> *&nodeHead, LNode<T> *&nodeTail, std::size_t size, std::size_t position);
		void print(LNode<T> *nodeHead) const;
	private:
		LNode<T> *head = nullptr;
		LNode<T> *tail = nullptr;
		std::size_t _size = 0;
	};
}

#include "List.inl"
