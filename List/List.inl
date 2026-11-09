namespace BigO {
	template <typename T>
	List<T>::~List()
	{
		destroy(head);
	}

	template <typename T>
	bool List<T>::insert(T data, std::size_t position)
	{
		bool result = insertAt(head, tail, data, _size, position);
		if (result) _size++;

		return result;
	}

	template <typename T>
	bool List<T>::push_back(T data)
	{
		bool result = insertLast(head, tail, data);
		if (result) _size++;

		return result;
	}

	template <typename T>
	bool List<T>::push_front(T data)
	{
		bool result = insertFirst(head, tail, data);
		if (result) _size++;

		return result;
	}

	template <typename T>
	bool List<T>::search(T data) const
	{
		return search(head, data);
	}

	template <typename T>
	LNode<T> *List<T>::remove(std::size_t position)
	{
		auto result = removeAt(head, tail, _size, position);
		if (result) _size--;

		return result;
	}

	template <typename T>
	LNode<T> *List<T>::pop()
	{
		auto result = removeLast(head, tail);
		if (result)	_size--;

		return result;
	}

	template <typename T>
	LNode<T> *List<T>::pop_front()
	{
		auto result = removeFirst(head, tail);
		if (result)	_size--;

		return result;
	}

	template <typename T>
	std::size_t List<T>::size() const
	{
		return _size;
	}

	template <typename T>
	void List<T>::print() const
	{
		print(head);
	}

	template <typename T>
	LNode<T> *List<T>::create(T data)
	{
		return new LNode<T>(data);
	}

	template <typename T>
	void List<T>::destroy(LNode<T> *nodeHead)
	{
		if (!nodeHead)
			return;

		destroy(nodeHead->next);
		delete nodeHead;
	}

	template <typename T>
	bool List<T>::insertFirst(LNode<T> *&nodeHead, LNode<T> *&nodeTail, T data)
	{
		if (!nodeHead) {
			nodeHead = create(data);
			nodeTail = nodeHead;
		} else {
			auto newNode = create(data);
			newNode->next = nodeHead;
			nodeHead = newNode;
		}
		return true;
	}

	template <typename T>
	bool List<T>::insertLast(LNode<T> *&nodeHead, LNode<T> *&nodeTail, T data)
	{
		if (!nodeHead) {
			nodeHead = create(data);
			nodeTail = nodeHead;
		} else if (nodeTail && !nodeTail->next) {
			nodeTail->next = create(data);
			nodeTail = nodeTail->next;
		}

		return true;
	}

	template <typename T>
	bool List<T>::insertAt(LNode<T> *&nodeHead, LNode<T> *&nodeTail, T data, std::size_t size, std::size_t position)
	{
		if (position > size)
			return false;

		if (position == 0)
			return insertFirst(nodeHead, nodeTail, data);
		else if (position == size)
			return insertLast(nodeHead, nodeTail, data);
		else if (position == 1) {
			auto newNode = create(data);

			newNode->next = nodeHead->next;
			nodeHead->next = newNode;
			return true;
		}

		return insertAt(nodeHead->next, nodeTail, data, size, position - 1);
	}

	template <typename T>
	bool List<T>::search(LNode<T> *nodeHead, T data) const
	{
		auto current = nodeHead;

		while (current) {
			if (current->data == data)
				return true;
			current = current->next;
		}
		return false;
	}

	template <typename T>
	LNode<T> *List<T>::removeFirst(LNode<T> *&nodeHead, LNode<T> *&nodeTail)
	{
		if (!nodeHead)
			return nullptr;

		if (!nodeHead->next) {
			auto temp = nodeHead;
			nodeHead = nullptr;
			nodeTail = nodeHead;
			delete temp;
			return nodeHead;
		} else {
			auto temp = nodeHead;
			auto newHead = nodeHead->next;
			nodeHead = newHead;
			delete temp;
			return nodeHead;
		}
	}

	template <typename T>
	LNode<T> *List<T>::removeLast(LNode<T> *&nodeHead, LNode<T> *&nodeTail)
	{
		if (!nodeHead)
			return nullptr;

		if (nodeHead->next == nodeTail) {
			auto temp = nodeTail;
			auto newTail = nodeHead;
			nodeHead->next = nullptr;
			nodeTail = newTail;
			delete temp;
			return nodeTail;
		}

		return removeLast(nodeHead->next, nodeTail);
	}

	template <typename T>
	LNode<T> *List<T>::removeAt(LNode<T> *&nodeHead, LNode<T> *&nodeTail, std::size_t size, std::size_t position)
	{
		if (position > size)
			return nullptr;

		if (!nodeHead)
			return nullptr;

		if (position == 0)
			return removeFirst(nodeHead, nodeTail);
		else if (position == 1) {
			auto temp = nodeHead->next;
			auto newNode = temp->next;
			nodeHead->next = newNode;
			delete temp;
			return nodeHead;
		}
		return removeAt(nodeHead->next, nodeTail, size, position - 1);
	}

	template <typename T>
	const LNode<T> *List<T>::peek() const
	{
		return tail;
	}

	template <typename T>
	void List<T>::print(LNode<T> *nodeHead) const
	{
		if (!nodeHead)
			return;

		auto current = nodeHead;
		while (current) {
			std::string arrow = current->next ? " -> " : "\n";
			std::cout << current->data << arrow;
			current = current->next;
		}
	}
}
