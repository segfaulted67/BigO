// -------------------------------------------------------------------------------------------------------------
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
//
/// @file AVL.hpp
/// @brief AVL Trees: A self balancing varient of Binary Search Trees(BST)
// -------------------------------------------------------------------------------------------------------------
#pragma once

#include "Binarytree.hpp"

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
