#pragma once

#include "Btree.hpp"

namespace BigO {
	template <typename T>
	class BST : public BinaryTree<T, DefaultTree> {
	public:
		BST() = default;

		bool insert(T data);
		bool search(T data) const;
		Node<T> *remove(T data);

		const Node<T> *findMin();
		const Node<T> *findMax();
	private:
		bool insert(Node<T> *&node, T data);
		bool search(Node<T> *node, T data) const;
		Node<T> *remove(Node<T> *&node, T data);
		Node<T> *min(Node<T> *&node);
		Node<T> *max(Node<T> *&node);
	};
}

#include "BST.inl"
