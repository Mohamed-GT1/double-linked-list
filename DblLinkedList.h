#pragma once
#include<iostream>
using namespace std;

template <class t>
class DblLinkedList
{

public:
	class Node {
	public:
		t data;
		Node* next;
		Node* prev;

		static void PrintNodeDetails(Node* head)
		{

			if (head->prev != NULL)
				cout << head->prev->data;
			else
				cout << "NULL";

			cout << " <--> " << head->data << " <--> ";

			if (head->next != NULL)
				cout << head->next->data << "\n";
			else
				cout << "NULL";

		}
	};

private:
	Node *head = NULL;
	int _size;
	
public:
	
	void PrintLinkedList() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void InsertAtBeginning(t value) {
		
		Node* node = new Node;
		node->data = value;
		node->next = head;
		node->prev = NULL;

		if (head != NULL) {
			head->prev = node;
		}
		head = node;
		_size++;
	}

	
	
	void PrintListDetails()
	{
		Node* temp = head;
		cout << "\n\n";
		while (temp != NULL) {
			PrintNodeDetails(temp);
			temp = temp->next;
		}
	}

	 Node* find(t value) {

		Node* temp = head;

		while (temp != NULL) {
			if (temp->data == value) {
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}

	void InsertAfter(Node* prevNode, t value) {

		Node* newnode = new Node;
		newnode->data = value;
		newnode->prev = prevNode;
		newnode->next = prevNode->next;

		if (prevNode->next != NULL) {
			prevNode->next->prev = newnode;
		}
		prevNode->next = newnode;

		_size++;
	}

	void InsertAtEnd( t value) {
		Node* newnode = new Node;
		newnode->data = value;
		newnode->next = NULL;

		if (head == NULL) {
			newnode->prev = NULL;
			head = newnode;
			_size++;
			return;
		}

		Node* current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newnode;
		newnode->prev = current;
		_size++;
	}

	void DeleteNode(Node*& nodeToDelete) {
		if (nodeToDelete == NULL || head == NULL)
			return;

		if (head == nodeToDelete)
		{
			if (head->next != NULL)
				head->next->prev = NULL;
			head = head->next;
			delete nodeToDelete;
			_size--;
			return;
		}

		if (nodeToDelete->next != NULL)
			nodeToDelete->next->prev = nodeToDelete->prev;

		nodeToDelete->prev->next = nodeToDelete->next;
		delete nodeToDelete;
		_size--;

	}

	void DeleteFirstNode() {
		if (head == NULL)
			return;

		Node* temp = head;
		head = head->next;
		if (head != NULL)
			head->prev = NULL;
		delete temp;
		_size--;
	}

	void DeleteLastNode() {
		if (head == NULL)
			return;

		if (head->next == NULL) {
			delete head;
			head = NULL;
			_size--;
			return;
		}

		Node* current = head;

		while (current->next != NULL) {
			current = current->next;
		}

		current->prev->next = NULL;
		delete current;
		_size--;
	}

	int Size() {

		//works just fine but slower , uses O(n)
		///*const Node* temp = head;
		//int counter = 0;
		//

		//while (temp != NULL) {
		//	counter++;
		//	temp = temp->next;
		//}

		//return counter;*/
		
		return _size;
	}

};

