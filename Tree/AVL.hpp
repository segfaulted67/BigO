#pragma once

#include "Btree.hpp"

namespace BigO {
	template <typename T>
	class AVL : public BinaryTree<T, AVLTree> {
	public:
		AVL() = default;

		bool insert(T data);
		bool search(T data) const;
		bool remove(T data);

		const Node<T, AVLTree> *findMin() const;
		const Node<T, AVLTree> *findMax() const;
	private:
		Node<T, AVLTree> *leftRotate(Node<T, AVLTree> *&node);
		Node<T, AVLTree> *rightRotate(Node<T, AVLTree> *&node);
		bool insert(Node<T, AVLTree> *&node, T data);
		bool search(Node<T, AVLTree> *node, T data) const;
		bool remove(Node<T, AVLTree> *&node, T data);
		Node<T, AVLTree> *min(Node<T, AVLTree> *&node);
		Node<T, AVLTree> *max(Node<T, AVLTree> *&node);
	};
}

#include "AVL.inl"
