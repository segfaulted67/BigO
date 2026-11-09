// MIT License
//
// Copyright (c) 2026 segfaulted67
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

/** @file Binarytree.hpp */
/** @brief A general binary tree class containing all general operations required by all types of binary trees */

#pragma once

/** Includes */
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>

#include "Node.hpp"
#include "../Queue/Queue.hpp"

/** Class      BinaryTree
 *  @brief    General structure for binary trees, templated binary tree
 *  @details  see https://en.wikipedia.org/wiki/Binary_tree for details of
 *            what binary trees are and how they work \n\n
 *
 *            A binary tree is a tree data structure in which each node has
 *            at most two children, referred to as the left child and the right child.
 *            The implementation shares many features that are shared between many varients
 *            of binary trees such as AVL trees, Binary search trees, Red-Black trees, etc.
 *            This Binary tree is implemented with the intention that other varients of binary trees
 *            will inherit this class as it provides the general structure and functionality common to binary trees,
 *            such as Construtor, Destructor, all types of traversals, isEmpty, isFull, countLeaf, etc
 *            to make it easy to implement BST, AVL or any sort of binary tree without reimplementing these
 *            functions which will occur in every binary tree varients.
 */
namespace BigO {
	enum class Traversal {
		INORDER,
		PREORDER,
		POSTORDER,
		LEVELORDER,
		DEFAULT,
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
		void print(Traversal traversal = Traversal::DEFAULT);
		void render();

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
		void render(Node<T, Metadata> *node, const std::string &prefix, bool isLast, bool isRoot);
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
} // Namespace BigO

#include "Binarytree.inl"
