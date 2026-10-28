namespace BigO {
	template <typename T>
	Queue<T>::Queue(std::size_t capacity)
	{
		_capacity = capacity;
		block = create(capacity);
	}

	template <typename T>
	Queue<T>::~Queue()
	{
		_size = 0;
		_capacity = 0;
		_head = 0;
		_tail = 0;
		delete[] block;
	}

	template <typename T>
	T Queue<T>::operator[](std::size_t index)
	{
		if (index > _size)
			throw std::runtime_error("Error: Out of bounds");

		return block[_head + index];
	}

	template <typename T>
	bool Queue<T>::push(T data)
	{
		if (!block) {
			block = create(256);
			_capacity = 256;
			_tail = 1;
			block[_size] = data;
			_size++;
			return true;
		}

		if (_size == _capacity) {
			std::size_t newCapacity = _capacity * 2;
			resize(block, _capacity, newCapacity);
			_capacity = newCapacity;
		}

		block[_tail] = data;
		_tail = (_tail + 1) % _capacity;
		_size++;

		return true;
	}

	template <typename T>
	T Queue<T>::pop()
	{
		if (_size == 0)
			throw std::runtime_error("Error: Queue is empty");

		T headValue = block[_head];
		_head = (_head + 1) % _capacity;
		_size--;
		return headValue;
	}

	template <typename T>
	bool Queue<T>::isEmpty()
	{
		return _size == 0;
	}

	template <typename T>
	std::size_t Queue<T>::size()
	{
		return _size;
	}

	template <typename T>
	std::size_t Queue<T>::capacity()
	{
		return _capacity;
	}

	template <typename T>
	std::size_t Queue<T>::head()
	{
		return _head;
	}

	template <typename T>
	std::size_t Queue<T>::tail()
	{
		return _tail;
	}

	template <typename T>
	T Queue<T>::peek()
	{
		return block[_head];
	}

	template <typename T>
	T *Queue<T>::create(std::size_t capacity)
	{
		return new T[capacity];
	}

	template <typename T>
	void Queue<T>::resize(T *&block, std::size_t oldCapacity, std::size_t capacity)
	{
		T *newBlock = new T[capacity];
		std::copy(block, block + oldCapacity, newBlock);
		delete[] block;

		block = newBlock;
	}

	template <typename T>
	void Queue<T>::print()
	{
		std::cout << "[";
		for (std::size_t i = _head; i < _tail; ++i) {
			if (i == _tail - 1)
				std::cout << block[i];
			else
				std::cout << block[i] << " ";
		}

		std::cout << "]" << std::endl;
	}
}
