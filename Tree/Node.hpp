#pragma once

namespace BigO {
	struct DefaultTree { };

	template <typename T, typename Metadata = DefaultTree>
	struct Node {
		T data;
		Node<T, Metadata> *left = nullptr;
		Node<T, Metadata> *right = nullptr;
		Metadata metadata{ };

		Node() = default;
		explicit Node(const T &value) : data(value) { }

		bool isLeaf() const;
		bool isInternalNode() const;
		bool haveTwoChild() const;
	};

	struct AVLTree {
		std::size_t height;

		AVLTree() : height(1) { }
	};

	template <typename T>
	struct RBTree {
		bool red;
		Node<T, RBTree> *parent = nullptr;

		RBTree() : red(true) { }
	};
}

#include "Node.inl"
