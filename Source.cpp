#include<iostream>
#include"DblLinkedList.h"

using namespace std;

int main() {
	DblLinkedList<int> linkedList;

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

	linkedList.Clear();
	cout << endl;
	cout << "size : "<<linkedList.Size();
	
	return 0;
}