#pragma once

#include "Btree.hpp"

namespace BigO {
	template <typename T>
	class AVL : public BinaryTree<T, AVLTree> {
	public:
		AVL() = default;

		bool insert(T data);
		bool search(T data) const;
		Node<T, AVLTree> *remove(T data);

		const Node<T, AVLTree> *findMin();
		const Node<T, AVLTree> *findMax();
	private:
		Node<T, AVLTree> *leftRotate(Node<T, AVLTree> *&node);
		Node<T, AVLTree> *rightRotate(Node<T, AVLTree> *&node);
		void balanceTree(Node<T, AVLTree> *&node, T data, int balanceFactor);
		bool insert(Node<T, AVLTree> *&node, T data);
		bool search(Node<T, AVLTree> *node, T data) const;
		Node<T, AVLTree> *remove(Node<T, AVLTree> *&node, T data);
		Node<T, AVLTree> *min(Node<T, AVLTree> *&node);
		Node<T, AVLTree> *max(Node<T, AVLTree> *&node);
	};
}

#include "AVL.inl"
