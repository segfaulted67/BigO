namespace BigO {
	template <typename T, typename Metadata>
	bool Node<T, Metadata>::isLeaf() const
	{
		return !left && !right;
	}

	template <typename T, typename Metadata>
	bool Node<T, Metadata>::isInternalNode() const
	{
		return left || right;
	}

	template <typename T, typename Metadata>
	bool Node<T, Metadata>::haveTwoChild() const
	{
		return left && right;
	}
}