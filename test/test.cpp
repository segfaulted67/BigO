#include <Tree/BST.hpp>
#include <Tree/AVL.hpp>
#include <Tree/RBT.hpp>
#include <Stack/Stack.hpp>
#include <Queue/Queue.hpp>

#include <string>

int main()
{
	BigO::AVL<std::string> tree;

	tree.insert("Jan");
	tree.insert("Feb");
	tree.insert("Mar");
	tree.insert("April");
	tree.insert("May");
	tree.insert("June");
	tree.insert("July");
	tree.insert("Aug");
	tree.insert("Sep");
	tree.insert("Oct");
	tree.insert("Nov");
	tree.insert("Dec");

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

	std::cout << "Search(Feb): " << tree.search("Feb") << std::endl;
	std::cout << "Balance Factor: " << tree.balanceFactor() << std::endl;
	std::cout << "Is Balance: " << tree.isBalance() << std::endl;
	std::cout << "Is Full: " << tree.isFull() << std::endl;

    return 0;
}
