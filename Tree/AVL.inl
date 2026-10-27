namespace BigO {
	template <typename T>
	bool AVL<T>::insert(T data)
	{
		return insert(this->root, data);
	}

	template <typename T>
	bool AVL<T>::search(T data) const
	{
		return search(this->root, data);
	}

	template <typename T>
	bool AVL<T>::remove(T data)
	{
		return remove(this->root, data);
	}

	template <typename T>
	const Node<T, AVLTree> *AVL<T>::findMin() const
	{
		return min(this->root);
	}

	template <typename T>
	const Node<T, AVLTree> *AVL<T>::findMax() const
	{
		return max(this->root);
	}

	template <typename T>
	Node<T, AVLTree> *AVL<T>::leftRotate(Node<T, AVLTree> *&node)
	{
		auto newNode = node->right;
		node->right = newNode->left;
		newNode->left = node;
		node->metadata.height = this->height(node);
		newNode->metadata.height = this->height(newNode);

		return newNode;
	}

	template <typename T>
	Node<T, AVLTree> *AVL<T>::rightRotate(Node<T, AVLTree> *&node)
	{
		auto newNode = node->left;
		node->left = newNode->right;
		newNode->right = node;
		node->metadata.height = height(node);
		newNode->metadata.height = height(newNode);

		return newNode;
	}

	template <typename T>
	bool AVL<T>::insert(Node<T, AVLTree> *&node, T data)
	{
		// TODO: Impl insert
		return false;
	}

	template <typename T>
	bool AVL<T>::search(Node<T, AVLTree> *node, T data) const
	{
		if (!node)
			return false;

		if (node->data == data)
			return true;

		if (data < node->data)
			return search(node->left, data);
		else if (data > node->data)
			return search(node->right, data);

		return false;
	}

	template <typename T>
	bool AVL<T>::remove(Node<T, AVLTree> *&node, T data)
	{
		// TODO: Impl remove
		return false;
	}

	template <typename T>
	Node<T, AVLTree> *AVL<T>::min(Node<T, AVLTree> *&node)
	{
		if (!node)
			return nullptr;

		auto current = node;
		while (current->left) {
			current = current->left;
		}
		return current;
	}

	template <typename T>
	Node<T, AVLTree> *AVL<T>::max(Node<T, AVLTree> *&node)
	{
		if (!node)
			return nullptr;

		auto current = node;
		while (current->right) {
			current = current->right;
		}
		return current;
	}
}
