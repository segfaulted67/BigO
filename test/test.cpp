#include <Tree/BST.hpp>
#include <Tree/AVL.hpp>
#include <Stack/Stack.hpp>
#include <Queue/Queue.hpp>
#include <List/List.hpp>

#include <string>
#include <random>
#include <cassert>

struct Calander {
	enum Month {
		JANUARY = 0,
		FEBRUARY,
		MARCH,
		APRIL,
		MAY,
		JUNE,
		JULY,
		AUGUST,
		SEPTEMBER,
		OCTOBER,
		NOVEMBER,
		DECEMBER,
	};

	std::string month;
	int value;

	Calander(const std::string &_month, int _value) : month(_month), value(_value) { }
	Calander(int _value) : value(_value)
	{
		switch (_value) {
		case JANUARY:
			month = "January";
			break;
		case FEBRUARY:
			month = "February";
			break;
		case MARCH:
			month = "March";
			break;
		case APRIL:
			month = "April";
			break;
		case MAY:
			month = "May";
			break;
		case JUNE:
			month = "June";
			break;
		case JULY:
			month = "July";
			break;
		case AUGUST:
			month = "August";
			break;
		case SEPTEMBER:
			month = "September";
			break;
		case OCTOBER:
			month = "October";
			break;
		case NOVEMBER:
			month = "November";
			break;
		case DECEMBER:
			month = "December";
			break;
		default:
			break;
		}
	}

	bool operator==(Calander &other)
	{
		return value == other.value;
	}

	bool operator>(Calander &other)
	{
		return value > other.value;
	}

	bool operator<(Calander &other)
	{
		return value < other.value;
	}

	bool operator>=(Calander &other)
	{
		return value >= other.value;
	}

	bool operator<=(Calander &other)
	{
		return value <= other.value;
	}

    friend std::ostream& operator<<(std::ostream& os, const Calander& calander) {
        os << calander.month;
        return os;
    }
};

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, 10000);

	// BigO::AVL<int> *tree = new BigO::AVL<int>{};
	//
	//    for (int i = 0; i < 500; i++) {
	//        tree->insert(distrib(gen));
	//    }
	//
	//    for (int i = 0; i < 100; i++) {
	//        tree->remove(distrib(gen));
	//    }
	//
	// std::cout << "Inorder: ";
	// tree->printInorder();
	// std::cout << "Preorder: ";
	// tree->printPreorder();
	// std::cout << "Postorder: ";
	// tree->printPostorder();
	// std::cout << "Levelorder: ";
	// tree->printLevelorder();
	//
	// std::cout << "Size: " << tree->size() << std::endl;
	// std::cout << "Height: " << tree->height() << std::endl;
	// std::cout << "Leaf: " << tree->countLeaf() << std::endl;
	// std::cout << "InternalNode: " << tree->countInternalNode() << std::endl;
	// std::cout << "Total Nodes: " << tree->countNode() << std::endl;
	// std::cout << "Min element: " << tree->findMin()->data << std::endl;
	// std::cout << "Max element: " << tree->findMax()->data << std::endl;
	//
	// std::cout << "Search(20): " << tree->search(20) << std::endl;
	// std::cout << "Balance Factor: " << tree->balanceFactor() << std::endl;
	// std::cout << "Is Balance: " << tree->isBalance() << std::endl;
	// std::cout << "Is Full: " << tree->isFull() << std::endl;
	// std::cout << "Is Complete: " << tree->isComplete() << std::endl;
	//
	// tree->print();
	//    delete tree;
	//
	BigO::List<int> list;
    for (int i = 0; i < 20; i++) {
        list.push_back(distrib(gen) % 12);
	}

	std::cout << "Size: " << list.size() << std::endl;
	std::cout << "Peek: " << list.peek()->data << std::endl;
	list.print();
    list.pop();
    list.pop();
    list.print();
    return 0;
}
