#pragma once

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>

#include "Node.hpp"
#include "../Queue/Queue.hpp"

namespace BigO {
	enum class Traversal {
		INORDER,
		PREORDER,
		POSTORDER,
		LEVELORDER,
	};

	template <typename T, typename Metadata>
	class BinaryTree {
	public:
		BinaryTree() = default;
		explicit BinaryTree(const T &data);
		virtual ~BinaryTree();

		BinaryTree(const BinaryTree& rhs);
		BinaryTree& operator=(const BinaryTree& rhs);

		void printInorder();
		void printPreorder();
		void printPostorder();
		void printLevelorder();
		void print(Traversal traversal = Traversal::INORDER);

		bool operator==(const BinaryTree<T, Metadata>& rhs) const;
		bool operator!=(const BinaryTree<T, Metadata>& rhs) const;
		bool isEmpty() const;
		bool isFull() const;
		bool isComplete() const;
		bool isBalance() const;

		std::size_t size() const;
		std::size_t height() const;
		std::size_t countLeaf() const;
		std::size_t countInternalNode() const;
		std::size_t countNode() const;
		int balanceFactor() const;

		void clear();
		void Example();
	private:
		Node<T, Metadata> *create(T data);
		void destroy(Node<T, Metadata> *node);
		void inorder(Node<T, Metadata> *node);
		void preorder(Node<T, Metadata> *node);
		void postorder(Node<T, Metadata> *node);
		void levelorder(Node<T, Metadata> *node);
		bool isFull(Node<T, Metadata> *node) const;
		bool isComplete(Node<T, Metadata> *node) const;
		bool isBalance(Node<T, Metadata> *node) const;
		bool equals(Node<T, Metadata> *node1, Node<T, Metadata> *node2) const;
		Node<T, Metadata> *copy(Node<T, Metadata> *node);
		std::size_t size(Node<T, Metadata> *node) const;
		std::size_t countLeaf(Node<T, Metadata> *node) const;
		std::size_t countInternalNode(Node<T, Metadata> *node) const;
		std::size_t countNode(Node<T, Metadata> *node) const;
	protected:
		std::size_t height(Node<T, Metadata> *node) const;
		int balanceFactor(Node<T, Metadata> *node) const;
	protected:
		Node<T, Metadata> *root = nullptr;
	};
}

#include "Btree.inl"
