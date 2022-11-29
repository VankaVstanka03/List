#include <iostream>
#include "vector.h"
#include "iterator.h"
#include "list.h"

int main() {
	//laba3::vector<int> a;
	//a.push_back(1);
	//a.push_back(2);
	//a.push_back(3);
	//a.push_back(4);
	//a.push_back(5);
	//a.push_back(6);
	//
	//for (iterator<int> i(a.begin()); i != a.end();i++){
	//	std::cout << *i << std::endl;
	//}
	//std::cout << "\n";
	//iterator<int> i(a.begin());
	//std::cout << *(i + 2) << std::endl;
	//list<int> a(6);
	//list<int> b(1);
	//std::cout << a.size() << std::endl;
	//std::cout << b.size() << std::endl;
	Stack<int> a;
	a.push(1);
	a.push(2);
	std::cout << a.sz() << std::endl;
	std::cout << a.top() << std::endl;
	a.empty();
	a.pop();
	a.pop();
	a.empty();

	Queue<int> a1;
	a1.push(1);
	a1.push(2);
	std::cout << a1.sz() << std::endl;
	std::cout << a1.front() << std::endl;
	a1.empty();
	a1.pop();
	a1.pop();
	a1.empty();

	return 0;
}