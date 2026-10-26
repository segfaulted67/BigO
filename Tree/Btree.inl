namespace BigO {
	template <typename T>
	bool Node<T>::isLeaf()
	{
		return !left && !right;
	}

	template <typename T>
	bool Node<T>::isInternalNode()
	{
		return left || right;
	}

	template <typename T>
	BinaryTree<T>::BinaryTree(T data)
	{
		root = create(data);
	}

	template <typename T>
	BinaryTree<T>::~BinaryTree()
	{
		destroy(root);
	}

	template <typename T>
	Node<T> *BinaryTree<T>::create(T data)
	{
		return new Node<T>(data);
	}

	template <typename T>
	void BinaryTree<T>::destroy(Node<T> *node)
	{
		if (!node)
			return;

		destroy(node->left);
		destroy(node->right);
		delete node;
	}

	template <typename T>
	void BinaryTree<T>::printInorder()
	{
		inorder(root);
		std::cout << std::endl;
	}

	template <typename T>
	void BinaryTree<T>::printPreorder()
	{
		preorder(root);
		std::cout << std::endl;
	}

	template <typename T>
	void BinaryTree<T>::printPostorder()
	{
		postorder(root);
		std::cout << std::endl;
	}

	template <typename T>
	void BinaryTree<T>::inorder(Node<T> *node)
	{
		if (!node)
			return;

		inorder(node->left);
		std::cout << node->data << " ";
		inorder(node->right);
	}

	template <typename T>
	void BinaryTree<T>::preorder(Node<T> *node)
	{
		if (!node)
			return;

		std::cout << node->data << " ";
		preorder(node->left);
		preorder(node->right);
	}

	template <typename T>
	void BinaryTree<T>::postorder(Node<T> *node)
	{
		if (!node)
			return;

		postorder(node->left);
		postorder(node->right);
		std::cout << node->data << " ";
	}

	template <typename T>
	bool BinaryTree<T>::isEmpty()
	{
		return root == nullptr;
	}

	template <typename T>
	bool BinaryTree<T>::isFull()
	{
		return isFull(root);
	}

	template <typename T>
	bool BinaryTree<T>::isFull(Node<T> *node)
	{
		if (!node)
			return true;

		if (!node->left && !node->right)
			return true;

		if (node->left && node->right)
			return isFull(node->left) && isFull(node->right);

		return false;
	}

	template <typename T>
	bool BinaryTree<T>::isComplete()
	{
		return isComplete(root);
	}

	template <typename T>
	bool BinaryTree<T>::isComplete(Node<T> *node)
	{
		if (!node)
			return true;
		// TODO: Impl isComplete();
		return false;
	}

	template <typename T>
	std::size_t BinaryTree<T>::size()
	{
		return size(root);
	}

	template <typename T>
	std::size_t BinaryTree<T>::size(Node<T> *node)
	{
		if (!node)
			return 0;
		return 1 + size(node->left) + size(node->right);
	}

	template <typename T>
	std::size_t BinaryTree<T>::height()
	{
		return height(root);
	}

	template <typename T>
	std::size_t BinaryTree<T>::height(Node<T> *node)
	{
		if (!node)
			return 0;
		return 1 + std::max(height(node->left), height(node->right));
	}

	template <typename T>
	std::size_t BinaryTree<T>::countLeaf()
	{
		return countLeaf(root);
	}

	template <typename T>
	std::size_t BinaryTree<T>::countLeaf(Node<T> *node)
	{
		if (!node)
			return 0;
		if (node->isLeaf())
			return 1;
		return countLeaf(node->left) + countLeaf(node->right);
	}

	template <typename T>
	std::size_t BinaryTree<T>::countInternalNode()
	{
		return countInternalNode(root);
	}

	template <typename T>
	std::size_t BinaryTree<T>::countInternalNode(Node<T> *node)
	{
		if (!node)
			return 0;

		std::size_t count = (node->isInternalNode()) ? 1 : 0;
		return count + countInternalNode(node->left) + countInternalNode(node->right);
	}

	template <typename T>
	void BinaryTree<T>::clear()
	{
		destroy(root);
		root = nullptr;
	}

	template <typename T>
	void BinaryTree<T>::Example()
	{
		destroy(root);

		root = create(T(10));
		root->left = create(T(5));
		root->right = create(T(20));

		root->left->left = create(T(10));
	}
}
