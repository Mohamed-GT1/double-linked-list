#include<iostream>
#include"DblLinkedList.h"

using namespace std;

int main() {
	DblLinkedList<int> linkedList;

	/*linkedList.InsertAtEnd(1);
	linkedList.InsertAtEnd(2);
	linkedList.InsertAtEnd(3);*/

	linkedList.InsertAtBeginning(1);
	linkedList.InsertAtBeginning(2);
	linkedList.InsertAtBeginning(3);

	linkedList.PrintLinkedList();

	DblLinkedList<int>::Node* nodeToFind = linkedList.find(2);

	cout << endl;

	if (nodeToFind != NULL)
		cout << "found the node";
	else
		cout << "node not found ";


	linkedList.DeleteNode(nodeToFind);

	cout << endl;
	linkedList.PrintLinkedList();

	linkedList.InsertAfter(linkedList.find(3), 2);

	cout << endl;
	linkedList.PrintLinkedList();

	linkedList.DeleteFirstNode();
	cout << endl;
	linkedList.PrintLinkedList();

	linkedList.DeleteLastNode();
	cout << endl;
	linkedList.PrintLinkedList();

	
	return 0;
}