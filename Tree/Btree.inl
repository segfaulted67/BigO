namespace BigO {
	template <typename T, typename Metadata>
	BinaryTree<T, Metadata>::BinaryTree(const T &data)
	{
		root = create(data);
	}

	template <typename T, typename Metadata>
	BinaryTree<T, Metadata>::~BinaryTree()
	{
		destroy(root);
	}

	template <typename T, typename Metadata>
	Node<T, Metadata> *BinaryTree<T, Metadata>::create(T data)
	{
		return new Node<T, Metadata>(data);
	}

	template <typename T, typename Metadata>
	void BinaryTree<T, Metadata>::destroy(Node<T, Metadata> *node)
	{
		if (!node)
			return;

		destroy(node->left);
		destroy(node->right);
		delete node;
	}

	template <typename T, typename Metadata>
	void BinaryTree<T, Metadata>::printInorder()
	{
		inorder(root);
		std::cout << std::endl;
	}

	template <typename T, typename Metadata>
	void BinaryTree<T, Metadata>::printPreorder()
	{
		preorder(root);
		std::cout << std::endl;
	}

	template <typename T, typename Metadata>
	void BinaryTree<T, Metadata>::printPostorder()
	{
		postorder(root);
		std::cout << std::endl;
	}

	template <typename T, typename Metadata>
	void BinaryTree<T, Metadata>::print(Traversal traversal)
	{
		if (traversal == Traversal::INORDER)
			printInorder();
		else if (traversal == Traversal::PREORDER)
			printPreorder();
		else if (traversal == Traversal::POSTORDER)
			printPostorder();
	}

	template <typename T, typename Metadata>
	void BinaryTree<T, Metadata>::inorder(Node<T, Metadata> *node)
	{
		if (!node)
			return;

		inorder(node->left);
		std::cout << node->data << " ";
		inorder(node->right);
	}

	template <typename T, typename Metadata>
	void BinaryTree<T, Metadata>::preorder(Node<T, Metadata> *node)
	{
		if (!node)
			return;

		std::cout << node->data << " ";
		preorder(node->left);
		preorder(node->right);
	}

	template <typename T, typename Metadata>
	void BinaryTree<T, Metadata>::postorder(Node<T, Metadata> *node)
	{
		if (!node)
			return;

		postorder(node->left);
		postorder(node->right);
		std::cout << node->data << " ";
	}

	template <typename T, typename Metadata>
	bool BinaryTree<T, Metadata>::operator==(const BinaryTree<T, Metadata>& rhs) const
	{
		return equals(root, rhs.root);
	}

	template <typename T, typename Metadata>
	bool BinaryTree<T, Metadata>::operator!=(const BinaryTree<T, Metadata>& rhs) const
	{
		return !equals(root, rhs.root);
	}

	template <typename T, typename Metadata>
	bool BinaryTree<T, Metadata>::isEmpty() const
	{
		return root == nullptr;
	}

	template <typename T, typename Metadata>
	bool BinaryTree<T, Metadata>::isFull() const
	{
		return isFull(root);
	}

	template <typename T, typename Metadata>
	bool BinaryTree<T, Metadata>::isFull(Node<T, Metadata> *node) const
	{
		if (!node)
			return true;

		if (!node->left && !node->right)
			return true;

		if (node->left && node->right)
			return isFull(node->left) && isFull(node->right);

		return false;
	}

	template <typename T, typename Metadata>
	bool BinaryTree<T, Metadata>::isComplete() const
	{
		return isComplete(root);
	}

	template <typename T, typename Metadata>
	bool BinaryTree<T, Metadata>::isComplete(Node<T, Metadata> *node) const
	{
		if (!node)
			return true;
		// TODO: Impl isComplete();
		return false;
	}

	template <typename T, typename Metadata>
	bool BinaryTree<T, Metadata>::equals(Node<T, Metadata> *node1, Node<T, Metadata> *node2) const
	{
		if (!node1 && !node2)
			return true;
		if (!node1 || !node2)
			return false;

		if (node1->data != node2->data)
			return false;

		return equals(node1->left, node2->left) &&
			   equals(node1->right, node2->right);
	}

	template <typename T, typename Metadata>
	std::size_t BinaryTree<T, Metadata>::size() const
	{
		return size(root);
	}

	template <typename T, typename Metadata>
	std::size_t BinaryTree<T, Metadata>::size(Node<T, Metadata> *node) const
	{
		if (!node)
			return 0;

		return 1 + size(node->left) + size(node->right);
	}

	template <typename T, typename Metadata>
	std::size_t BinaryTree<T, Metadata>::height() const
	{
		return height(root);
	}

	template <typename T, typename Metadata>
	std::size_t BinaryTree<T, Metadata>::height(Node<T, Metadata> *node) const
	{
		if (!node)
			return 0;
		return 1 + std::max(height(node->left), height(node->right));
	}

	template <typename T, typename Metadata>
	std::size_t BinaryTree<T, Metadata>::countLeaf() const
	{
		return countLeaf(root);
	}

	template <typename T, typename Metadata>
	std::size_t BinaryTree<T, Metadata>::countLeaf(Node<T, Metadata> *node) const
	{
		if (!node)
			return 0;
		if (node->isLeaf())
			return 1;
		return countLeaf(node->left) + countLeaf(node->right);
	}

	template <typename T, typename Metadata>
	std::size_t BinaryTree<T, Metadata>::countInternalNode() const
	{
		return countInternalNode(root);
	}

	template <typename T, typename Metadata>
	std::size_t BinaryTree<T, Metadata>::countInternalNode(Node<T, Metadata> *node) const
	{
		if (!node)
			return 0;

		std::size_t count = (node->isInternalNode()) ? 1 : 0;
		return count + countInternalNode(node->left) + countInternalNode(node->right);
	}

	template <typename T, typename Metadata>
	std::size_t BinaryTree<T, Metadata>::countNode() const
	{
		return countNode(root);
	}

	template <typename T, typename Metadata>
	std::size_t BinaryTree<T, Metadata>::countNode(Node<T, Metadata> *node) const
	{
		if (!node)
			return 0;

		return 1 + countNode(node->left) + countNode(node->right);
	}

	template <typename T, typename Metadata>
	int BinaryTree<T, Metadata>::balanceFactor() const
	{
		return balanceFactor(root);
	}

	template <typename T, typename Metadata>
	int BinaryTree<T, Metadata>::balanceFactor(Node<T, Metadata> *node) const
	{
		if (!node)
			return 0;

		int left = static_cast<int>(height(node->left));
		int right = static_cast<int>(height(node->right));

		return left - right;
	}

	template <typename T, typename Metadata>
	void BinaryTree<T, Metadata>::clear()
	{
		destroy(root);
		root = nullptr;
	}

	template <typename T, typename Metadata>
	void BinaryTree<T, Metadata>::Example()
	{
		destroy(root);

		root = create(T(10));
		root->left = create(T(5));
		root->right = create(T(20));

		root->left->left = create(T(4));
		root->left->right = create(T(7));
	}
}
