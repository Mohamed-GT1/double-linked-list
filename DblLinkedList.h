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

		
		return _size;
	}

	bool IsEmpty() {
		return _size == 0;
	}

	void Clear() {
		
		while (_size > 0) {
			DeleteFirstNode();
		}

	}

	void Reverse() {
		
		
		Node* current = head;
		Node* temppointer = NULL;

		while (current != NULL) {
			temppointer = current->prev;
			current->prev = current->next;
			current->next = temppointer;

			current = current->prev;
		}
		if (temppointer != NULL)
			head = temppointer->prev;

		
	}


	Node* GetNodeByIndex(int index) {
		int currentIndex = 0;
		Node* current = head;

		if (index < 0 || index > _size - 1)
			return NULL;

		while (current != NULL) {
			if (currentIndex == index)
				return current;
			current = current->next;
			currentIndex++;
		}
		
		return NULL;

	}

};

