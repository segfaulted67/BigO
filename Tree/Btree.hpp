#pragma once

#include <iostream>
#include <algorithm>

namespace BigO {
	template <typename T>
	struct Node {
		T data;
		Node<T> *left = nullptr;
		Node<T> *right = nullptr;

		Node() = default;
		explicit Node(const T &value) : data(value) { }

		bool isLeaf();
		bool isInternalNode();
	};

	template <typename T>
	class BinaryTree {
	public:
		BinaryTree() = default;
		BinaryTree(T data);
		~BinaryTree();

		// TODO: Impl copying constructor
		BinaryTree(const BinaryTree&) = delete;
		BinaryTree& operator=(const BinaryTree&) = delete;

		void printInorder();
		void printPreorder();
		void printPostorder();

		bool isEmpty();
		bool isFull();
		bool isComplete();

		std::size_t size();
		std::size_t height();
		std::size_t countLeaf();
		std::size_t countInternalNode();

		void clear();
		void Example();
	private:
		Node<T> *create(T data);
		void destroy(Node<T> *node);
		void inorder(Node<T> *node);
		void preorder(Node<T> *node);
		void postorder(Node<T> *node);
		bool isFull(Node<T> *node);
		bool isComplete(Node<T> *node);
		std::size_t size(Node<T> *node);
		std::size_t height(Node<T> *node);
		std::size_t countLeaf(Node<T> *node);
		std::size_t countInternalNode(Node<T> *node);
	private:
		Node<T> *root = nullptr;
	};
}

#include "Btree.inl"
