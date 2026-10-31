namespace BigO {
	template <typename T>
	Stack<T>::Stack(std::size_t capacity) : _capacity(capacity)
	{
		block = create(capacity);
	}

	template <typename T>
	Stack<T>::~Stack()
	{
		delete[] block;
	}

	template <typename T>
	T Stack<T>::operator[](std::size_t index)
	{
		if (index >= _size)
			throw std::runtime_error("Error: Out of bounds");

		return block[index];
	}

	template <typename T>
	bool Stack<T>::push(T data)
	{
		if (!block) {
			block = create(256);
			_capacity = 256;
			block[_size] = data;
			_size++;
			return true;
		}

		if (_size == _capacity) {
			std::size_t newCapacity = _capacity * 2;
			resize(block, _capacity, newCapacity);
			_capacity = newCapacity;
		}

		block[_size++] = data;

		return true;
	}

	template <typename T>
	T Stack<T>::pop()
	{
		if (_size == 0)
			throw std::runtime_error("Error: Stack is empty");

		T poppedData = block[_size -  1];
		_size--;
		return poppedData;
	}

	template <typename T>
	bool Stack<T>::isEmpty() const
	{
		return _size == 0;
	}

	template <typename T>
	void Stack<T>::print()
	{
		std::cout << "[";
		for (std::size_t i = 0; i < _size; ++i) {
			if (i == _size - 1)
				std::cout << block[i];
			else
				std::cout << block[i] << " ";
		}

		std::cout << "]" << std::endl;
	}

	template <typename T>
	T *Stack<T>::create(std::size_t capacity)
	{
		return new T[capacity];
	}

	template <typename T>
	void Stack<T>::resize(T *&block, std::size_t oldCapacity, std::size_t capacity)
	{
		T *newBlock = new T[capacity];
		std::copy(block, block + oldCapacity, newBlock);
		delete[] block;

		block = newBlock;
	}
}
