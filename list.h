#pragma once
#include "iterator.h"
#include <initializer_list>
#include <list>

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

	class list_iterator {
		Node<T>* ptr;
	public:
		list_iterator() {};

		list_iterator(Node<T>* data) {
			ptr = data;
		};

		list_iterator& operator++() {
			ptr = ptr->next;
			return *this;
		};

		list_iterator operator++(int) {
			list_iterator copy(this->ptr);
			ptr = ptr->next;
			return copy;
		};

		friend bool operator!=(const list_iterator& it1, const list_iterator& it2) {
			if (it1->ptr != it2->ptr)
				return true;
			else
				return false;
		};
	};

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

	void clear() {};

	void merge(list& a) {};

	void merge(list&& a) {};

	void sort() {};

	void insert_after(Node* prev, T val) {};

	void erase_after(Node* prev) {};
};

template <class T>
class Stack {
	std::list<T> data;
public:
	
	Stack() {};

	Stack(T val) {
		data.push_back(val);
	};

	void push(T val) {
		data.push_back(val);
	};

	void pop() {
		if (data.empty())
			throw std::exception("Empty stack");
		data.pop_back();
	};

	T top() {
		return data.back();
	};

	bool empty() {
		return data.empty();
	};

	size_t sz() { return data.size(); };
};

template <class T>
class Queue {
	std::list<T> data;
public:
	Queue() {};

	Queue(T val) {
		data.push_back(val);
	};

	void push(T val) {
		data.push_back(val);
	};

	void pop() {
		if (data.empty())
			throw std::exception("Empty queue");
		data.pop_front();
	};

	T front() {
		return data.front();
	};

	size_t sz() {
		return data.size();
	};

	bool empty() {
		return data.empty();
	};
};