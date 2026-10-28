#include <Tree/BST.hpp>
#include <Tree/AVL.hpp>
#include <Queue/Queue.hpp>

int main()
{
	BigO::AVL<int> tree;

	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	tree.insert(50);
	tree.insert(60);
	tree.insert(25);
	tree.insert(27);
	tree.insert(23);
	tree.insert(70);
	tree.remove(20);
	tree.insert(80);
	tree.insert(0);
	tree.insert(-10);
	tree.insert(-2);

	std::cout << "Inorder: ";
	tree.printInorder();
	std::cout << "Preorder: ";
	tree.printPreorder();
	std::cout << "Postorder: ";
	tree.printPostorder();
	std::cout << "Levelorder: ";
	tree.printLevelorder();

	std::cout << "Size: " << tree.size() << std::endl;
	std::cout << "Height: " << tree.height() << std::endl;
	std::cout << "Leaf: " << tree.countLeaf() << std::endl;
	std::cout << "InternalNode: " << tree.countInternalNode() << std::endl;
	std::cout << "Total Nodes: " << tree.countNode() << std::endl;
	std::cout << "Min element: " << tree.findMin()->data << std::endl;
	std::cout << "Max element: " << tree.findMax()->data << std::endl;

	std::cout << "Search(-2): " << tree.search(-2) << std::endl;
	std::cout << "Balance Factor: " << tree.balanceFactor() << std::endl;
	std::cout << "Is Balance: " << tree.isBalance() << std::endl;
    return 0;
}
