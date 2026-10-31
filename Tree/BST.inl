namespace BigO {
	template <typename T>
	bool BST<T>::insert(T data)
	{
		return insert(this->root, data);
	}

	template <typename T>
	bool BST<T>::search(T data) const
	{
		return search(this->root, data);
	}

	template <typename T>
	Node<T> *BST<T>::remove(T data)
	{
		return remove(this->root, data);
	}

	template <typename T>
	const Node<T> *BST<T>::findMin()
	{
		return min(this->root);
	}

	template <typename T>
	const Node<T> *BST<T>::findMax()
	{
		return max(this->root);
	}

	template <typename T>
	bool BST<T>::insert(Node<T> *&node, T data)
	{
		if (!node) {
			node = new Node<T>(data);
			return true;
		}

		if (data < node->data)
			return insert(node->left, data);
		else if (data > node->data)
			return insert(node->right, data);

		return false;
	}

	template <typename T>
	bool BST<T>::search(Node<T> *node, T data) const
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
	Node<T> *BST<T>::remove(Node<T> *&node, T data)
	{
		if (!node)
			return nullptr;

		if (data < node->data)
			node->left = remove(node->left, data);
		else if (data > node->data)
			node->right = remove(node->right, data);
		else {
			if (node->left && node->right) {
				auto temp = min(node->right);
				node->data = temp->data;
				node->right = remove(node->right, node->data);
			} else {
				auto temp = node;
				if (!node->left)
					node = node->right;
				else if (!node->right)
					node = node->left;
				delete temp;
			}
		}
		return node;
	}

	template <typename T>
	Node<T> *BST<T>::min(Node<T> *&node)
	{
		if (!node)
			return nullptr;

		auto current = node;
		while (current->left)
			current = current->left;
		return current;
	}

	template <typename T>
	Node<T> *BST<T>::max(Node<T> *&node)
	{
		if (!node)
			return nullptr;

		auto current = node;
		while (current->right)
			current = current->right;
		return current;
	}
}
