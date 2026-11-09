#pragma once

#include "Binarytree.hpp"

namespace BigO {
	template <typename T>
	class BST : public BinaryTree<T, DefaultTree> {
	public:
		BST() = default;

		bool insert(T data);
		bool search(T data) const;
		Node<T, DefaultTree> *remove(T data);

		const Node<T, DefaultTree> *findMin();
		const Node<T, DefaultTree> *findMax();
	private:
		bool insert(Node<T, DefaultTree> *&node, T data);
		bool search(Node<T, DefaultTree> *node, T data) const;
		Node<T, DefaultTree> *remove(Node<T, DefaultTree> *&node, T data);
		Node<T, DefaultTree> *min(Node<T, DefaultTree> *&node);
		Node<T, DefaultTree> *max(Node<T, DefaultTree> *&node);
	};
}

#include "BST.inl"
