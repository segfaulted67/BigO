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
	Node<T, AVLTree> *AVL<T>::remove(T data)
	{
		return remove(this->root, data);
	}

	template <typename T>
	const Node<T, AVLTree> *AVL<T>::findMin()
	{
		return min(this->root);
	}

	template <typename T>
	const Node<T, AVLTree> *AVL<T>::findMax()
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
		node->metadata.height = this->height(node);
		newNode->metadata.height = this->height(newNode);

		return newNode;
	}

	template <typename T>
	void AVL<T>::balanceTree(Node<T, AVLTree> *&node, T data, int balanceFactor)
	{
		if (balanceFactor > 1 && data < node->left->data) {
			node = rightRotate(node);
		} else if (balanceFactor > 1 && data > node->left->data) {
			node->left = leftRotate(node->left);
			node = rightRotate(node);
		} else if (balanceFactor < -1 && data < node->right->data) {
			node->right = rightRotate(node->right);
			node = leftRotate(node);
		} else if (balanceFactor < -1 && data > node->right->data) {
			node = leftRotate(node);
		}
	}

	template <typename T>
	bool AVL<T>::insert(Node<T, AVLTree> *&node, T data)
	{
		if (!node) {
			node = new Node<T, AVLTree>(data);
			return true;
		}

		bool inserted = false;
		if (data < node->data)
			inserted = insert(node->left, data);
		else if (data > node->data)
			inserted = insert(node->right, data);
		else
			return false;

		if (!inserted)
			return false;

		node->metadata.height = this->height(node);
		int balance = this->balanceFactor(node);
		balanceTree(node, data, balance);

		// if (balance > 1 && data < node->left->data) {
		// 	node = rightRotate(node);
		// } else if (balance > 1 && data > node->left->data) {
		// 	node->left = leftRotate(node->left);
		// 	node = rightRotate(node);
		// } else if (balance < -1 && data < node->right->data) {
		// 	node->right = rightRotate(node->right);
		// 	node = leftRotate(node);
		// } else if (balance < -1 && data > node->right->data) {
		// 	node = leftRotate(node);
		// }
		return true;
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
	Node<T, AVLTree> *AVL<T>::remove(Node<T, AVLTree> *&node, T data)
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

		if (!node)
			return nullptr;

		node->metadata.height = this->height(node);
		int balance = this->balanceFactor(node);

		if (balance > 1) {
			if (this->balanceFactor(node->left) > 0)
				node = rightRotate(node);
			else {
				node->left = leftRotate(node->left);
				node =  rightRotate(node);
			}
		} else if (balance < -1) {
			if (this->balanceFactor(node->right) < 0)
				node = leftRotate(node);
			else {
				node->right = rightRotate(node->right);
				node = leftRotate(node);
			}
		}

		return node;
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
