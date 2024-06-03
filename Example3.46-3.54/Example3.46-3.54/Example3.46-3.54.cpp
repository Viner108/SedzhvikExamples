#include "Header.h"
#include <iostream>
#include <vector>

typedef int Item;

struct Node {
	Item data;
	Node* next;

	Node(Item data):data(data),next(nullptr){}
	Node(Node node) :data(node->data), next(node->next) {}

};

void deleteNode(Node* first,Node* deleteItem) {
	for (Node* i = first; i !=nullptr; i=i->next)
	{
		if (i->data == deleteItem->data) {
			first = i->next;
			delete first;
		}
		if (i->next->data == deleteItem->data) {
			i->next = i->next->next;
		}
	}
}

void printList(Node* head) {
	Node* current = head;
	while (current) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

Node* createList(std::vector<int> vector) {
	int i;
	Node* head = new Node(vector[0]);
	Node* j = head;
	for (i = 1; i < vector.size(); i++)
	{
		j->next = new Node(vector[i]);
		j = j->next;
	}
	return head;
}
/*
Написать программу, которая удаляет все узлы связного списка (вызывает операцию delete с указателем).
*/
void example3_46() {
	std::vector<int> v{ 4,6,8,3,9,1,5 };
	Node* head = createList(v);
	printList(head);
	for (Node* i = head; i != nullptr; i = i->next) {
		deleteNode(head, i);
	}
}