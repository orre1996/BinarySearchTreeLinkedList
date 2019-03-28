#include <iostream>
#include <string>
#include <stdexcept>
#include "LinkedList.h"
#include "BinarySearchTree.h"
#include "UnitTest.h"
using namespace std;

int main(int argc, char* argv[]) {
	try {
		BinarySearchTree<int> tree;
		cout << "-----------xXBinary Search TreeXx--------------" << endl;
		tree.insert(4);
		tree.insert(1);
		tree.insert(2);
		tree.insert(3);
		tree.insert(5);
		tree.insert(6);
		tree.insert(7);
		std::cout << "-----------xXTraversal In OrderXx----------" << endl;
		tree.traversal_in_order();
		cout << "" << endl;

		LinkedList<int> list;
		cout << "--------------xXLinked ListXx-----------------" << endl;
		list.push_back(2);
		list.push_front(10);
		list.push_back(21);
		list.print();
		list.size();
		list.pop_back();
		list.size();
		list.print();
		list.size();
		cout << "" << endl;
		cout << "---------------xXUnit Testing Linked ListXx--------------" << endl;
		cout << "" << endl;
		cout << "Is front where it's supposed to be?" << endl;
		UnitTest::TestEqual(list.front(), 19, "list.front() ");
		UnitTest::TestEqual(list.front(), 10, "list.front() ");
		cout << "" << endl;
		cout << "Is back where it's supposed to be?" << endl;
		UnitTest::TestEqual(list.back(),21, "list.back() ");
		UnitTest::TestEqual(2, list.back(), "list.back()  ");
		cout << "" << endl;
		cout << "---------------xXUnit Testing Binary Search TreeXx--------------" << endl;
		cout << "" << endl;
		cout << "Is the root what it's supposed to be?" << endl;
		UnitTest::TestEqual(tree.Root(),2, "tree.Root() ");
		UnitTest::TestEqual(4, tree.Root(), "tree.Root() ");
		cout << "" << endl;
		cout << "Which is the highest number in the tree?" << endl;
		UnitTest::TestEqual(tree.Highest(),19, "tree.Highest() ");
		UnitTest::TestEqual(7, tree.Highest(), "tree.Highest() ");
		cout << "" << endl;
		cout << "Which is the lowest number in the tree?" << endl;
		UnitTest::TestEqual(tree.Lowest(),6, "tree.Lowest()");
		UnitTest::TestEqual(1, tree.Lowest(), "tree.Lowest()");	
	}
	catch (const runtime_error& e) {
		cout << e.what() << endl;
	}
	catch (...) {
		cout << "You are so wrong!" << endl;
	}
	return 0;
}
