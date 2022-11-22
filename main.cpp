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
	list<int> a(6);
	list<int> b(1);
	std::cout << a.size() << std::endl;
	std::cout << b.size() << std::endl;
	return 0;
}