#pragma once
#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int number;
	Node* next;
	string name;

	Node(int number, string _name) {
		this->number = number;
		next = nullptr;
		name = _name;
	}
};
class TelephoneGuide {
private:
	Node* head;
	Node* tail;
	int count;
public:
	TelephoneGuide() {
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	bool isEmpty() {
		if (head == nullptr) {
			return true;
		}
		return false;
	}
	int getCount() {
		return count;
	}
	void printAll() {
		if (head == nullptr) {
			return;
		}
		Node* temp = head;
		int i = 1;
		cout << i << ". " << temp->name << "---" << temp->number << endl;
		while (temp->next != nullptr) {
			temp = temp->next;
			cout << i << ". " << temp->name << "---" << temp->number << endl;

			i++;
		}
	}
	void addFirst(int number, string name) {
		Node* node = new Node(number, name);
		if (head == nullptr) {
			head = node;
			tail = node;
		}
		else {
			node->next = head;
			head = node;
		}
		count++;
	}
	void addLast(int number, string name) {
		Node* node = new Node(number, name);
		if (head == nullptr) {
			head = node;
			tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}
		count++;
	}
	void deleteFirst() {
		if (count == 0) {
			return;
		}
		Node* temp = head;
		if (count == 1) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = head->next;
		}
		count--;
		delete temp;
	}
	void deleteLast() {
		if (count == 0) {
			return;
		}
		Node* temp = head;
		Node* temp2 = head;
		while (temp2->next != nullptr) {
			temp = temp2;
			temp2 = temp2->next;
		}
		temp->next = nullptr;
		tail = temp;
		delete temp2;
		count--;
		if (count == 0) {
			tail = nullptr;
			head = nullptr;
		}
	}
	Node* getNode(int index) {
		if (index >= count || index < 0) {
			return nullptr;
		}
		Node* temp = head;
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		return temp;
	}
	bool insertNode(int index, int number, string name) {
		if (index > count || index < 0) {
			return false;
		}
		if (index == 0) {
			addFirst(number, name);
			return true;
		}
		else if (index == count) {
			addLast(number, name);
			return true;
		}
		Node* temp = getNode(index - 1);
		Node* node = new Node(number, name);
		node->next = temp->next;
		temp->next = node;
		count++;
		return true;


	}
	bool deleteNode(int index) {
		if (index >= count || index < 0) {
			return false;
		}
		if (index == 0) {
			deleteFirst();
			return true;
		}
		else if (index == count - 1) {
			deleteLast();
			return true;
		}
		Node* temp = getNode(index - 1);
		Node* temp2 = getNode(index);
		temp->next = temp2->next;
		delete temp2;
		count--;
		return true;
	}
}; 
