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

	linkedList.Reverse();

	cout << endl;
	linkedList.PrintLinkedList();
	
	return 0;
}