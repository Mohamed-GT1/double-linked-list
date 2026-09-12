#include<iostream>
#include"DblLinkedList.h"

using namespace std;

int main() {
	DblLinkedList<int> linkedList;

	if (linkedList.IsEmpty())
		cout << "yes the list is empty \n";
	else
		cout << "no the list is not empty\n";

	linkedList.InsertAtEnd(1);
	linkedList.InsertAtEnd(2);
	linkedList.InsertAtEnd(3);
	linkedList.InsertAtEnd(4);
	
	linkedList.PrintLinkedList();

	cout << "\n the size of the list " << linkedList.Size();

	cout << endl;
	if (linkedList.IsEmpty())
		cout << "yes the list is empty \n";
	else
		cout << "no the list is not empty\n";
	
	return 0;
}