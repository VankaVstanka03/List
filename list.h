#pragma once
#include "iterator.h"
#include <initializer_list>

template <class T>
class list {
	struct Node {
		T elem;
		Node* next;
		Node() {
			next = nullptr;
		};
		Node(T val) {
			elem = val;
			next = nullptr;
		};
	};
	Node* first = nullptr;
public:
	list() {

	};

	explicit list(size_t count) {
		first = new Node();
		Node* tmp = first;
		for (int i = 1; i < count; i++) {
			tmp->next = new Node();
			tmp = tmp->next;
		}
	};

	list(const list& l) {
		Node* lptr = l.first;
		if (!lptr)
			return;
		first = new Node(lptr->elem);
		lptr = lptr->next;
		Node* tmp = first;
		while (lptr) {
			tmp->next = new Node(lptr->elem);
			lptr = lptr->next;
			tmp = tmp->next;
		}
	};

	//list(const std::initializer_list& il) {
	//
	//
	//};

	~list() {
		Node* tmp = first;
		while (tmp) {
			Node* tmp2 = tmp->next;
			delete tmp;
			tmp = tmp2;
		}
	};

	list& operator=(const list& l) {

	};

	list& operator=(const list&& l) {

	};

	size_t size() {
		Node* tmp = first;
		size_t nums = 0;
		while (tmp) {
			Node* tmp2 = tmp->next;
			tmp = tmp2;
			nums++;
		}
		return nums;
	};

};