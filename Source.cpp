#include<iostream>
#include"DblLinkedList.h"

using namespace std;

int main() {
	DblLinkedList<int> linkedList;

	linkedList.InsertAtEnd(10);
	linkedList.InsertAtEnd(20);
	linkedList.InsertAtEnd(70);
	linkedList.InsertAtEnd(99);
	linkedList.InsertAtEnd(50);
	
	linkedList.PrintLinkedList();

	
	linkedList.InsertAfter(2, 90000);
	
	cout << endl;
	linkedList.PrintLinkedList();
	return 0;
}