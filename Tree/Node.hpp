#pragma once

namespace BigO {
	struct DefaultTree { };

	struct AVLTree {
		std::size_t height;

		AVLTree() : height(1) { }
	};

	struct RBTree {
		bool red;

		RBTree() : red(true) { }
	};

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
}

#include "Node.inl"
