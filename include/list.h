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
		~Node(){
		};
	};

	Node* first = nullptr;
	size_t size;


	class iterator {

		Node* ptr;

	public:

		iterator() {};

		iterator(Node* data) {
			ptr = data;
		};

		iterator& operator++() {
			ptr = ptr->next;
			return *this;
		};

		iterator operator++(int) {
			iterator copy(this->ptr);
			ptr = ptr->next;
			return copy;
		};

		friend bool operator!=(const iterator& it1, const iterator& it2) {
			if (it1.ptr != it2.ptr)
				return true;
			else
				return false;
		};

		Node* operator*() {
			return ptr;
		};
	};

public:

	list() {
		first = new Node();
		size = 1;
	};

	explicit list(size_t count, std::initializer_list<T> init) {
		first = new Node();
		size = count;
		auto iter_init_list = init.begin();
		if (init.begin() != init.end()) {
			first->elem = *(init.begin());
			iter_init_list++;
		}
		Node* tmp = first;
		for (int i = 1; i < count; i++) {
			tmp->next = new Node();
			tmp = tmp->next;
			if (iter_init_list != init.end()) {
				tmp->elem = *(iter_init_list);
				iter_init_list++;
			}
			else {
				tmp->elem = NULL;
			}
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

	size_t get_size() {
		return size;
	};

	Node* operator[](size_t pos){
		return *(this->in_pos(pos));
	};

	void clear(){
		Node* tmp = first;
		while (tmp) {
			Node* tmp2 = tmp->next;
			delete tmp;
			tmp = tmp2;
		}
	};

	void push_back(T val) {
		Node* tmp = (*this)[size - 1];
		tmp->next = new Node(val);
		size++;
	};

	void merge(list& a) {
		Node* ptr1 = this->first;
		Node* ptr2 = a.first;
		Node* tmp = new Node();
		Node* ptr3 = tmp;
		while (ptr1 || ptr2) {
			if (!ptr1) {
				ptr3->next = ptr2;
				ptr3 = ptr2;
				ptr2 = ptr2->next;
			}
			else if (!ptr2) {
				ptr3->next = ptr1;
				ptr3 = ptr1;
				ptr1 = ptr1->next;
			}
			else {
				if (ptr1->elem < ptr2->elem) {
					ptr3->next = ptr1;
					ptr3 = ptr1;
					ptr1 = ptr1->next;
				}
				else {
					ptr3->next = ptr2;
					ptr3 = ptr2;
					ptr2 = ptr2->next;
				}
			}
		}
		this->size += a.size;
		this->first = tmp->next;
		delete tmp;
		a.first = nullptr;
	};

	//void merge_with_iter(list& a) {
	//	Node* tmp = new Node();
	//	Node* ptr = tmp;
	//	Node* copy;
	//	if (this->size >= a.size) {
	//		for (iterator it1 = this->begin(), it2 = a.begin(); it1 != this->end(); it1++) {
	//			if (it2 != a.end()) {
	//				if ((*it1)->elem < (*it2)->elem) {
	//					copy = (*it1);
	//					ptr->next = copy;
	//					ptr = copy;
	//				}
	//				else {
	//					copy = (*it2);
	//					ptr->next = copy;
	//					ptr = copy;
	//					it2++;
	//				}
	//			}
	//			else {
	//				copy = (*it1);
	//				ptr->next = copy;
	//				ptr = copy;
	//			}
	//		}
	//	}
	//	else {
	//
	//	}
	//	this->size += a.size;
	//	while (ptr) {
	//		std::cout << ptr->elem << std::endl;
	//		ptr = ptr->next;
	//	}
	//	//this->first = ptr->next;
	//	//delete tmp;
	//	a.first = nullptr;
	//}

	void merge(list&& a) {};

	void sort() {};

	void insert_after(Node* prev, T val) {
		Node* tmp = prev->next;
		prev->next = new Node(val);
		prev->next->next = tmp;
		size++;
	};

	void erase_after(Node* prev) {
		Node* tmp = prev->next;
		prev->next = tmp->next;
		delete tmp;
		size--;
	};

	iterator begin() {
		return iterator(this->first);
	};

	iterator in_pos(size_t pos) {
		Node* tmp = this->first;
		while (pos > 0) {
			tmp = tmp->next;
			pos--;
		}
		return iterator(tmp);
	};


	iterator end() {
		return iterator(nullptr);
	};
};


