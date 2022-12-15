#include <iostream>
#include "vector.h"
#include "iterator.h"
#include "list.h"
#include <forward_list>

int main() {
	list<double> a(6, {2.1, 2.2, 2.3, 2.4, 2.5, 2.6});
	list<double> b(4, {1.1, 1.2, 1.3, 1.4});
	//a.erase_after(*(a.in_pos(0)));
	std::cout << a[0]->elem << std::endl;
	std::cout << a[1]->elem << std::endl;
	std::cout << a[2]->elem << std::endl;
	std::cout << a[3]->elem << std::endl;
	std::cout << a[4]->elem << std::endl;
	//std::cout << a[5]->elem << std::endl;
	std::cout << a.get_size() << std::endl;
	//std::cout << a[5]->elem << std::endl;
	std::cout << a.get_size() << std::endl;
	a.merge(b);
	//std::cout << a[0]->elem << std::endl;
	//std::cout << a[1]->elem << std::endl;
	//std::cout << a[2]->elem << std::endl;
	//std::cout << a[3]->elem << std::endl;
	//std::cout << a[4]->elem << std::endl;
	//std::cout << a[5]->elem << std::endl;
	//std::cout << a[6]->elem << std::endl;
	//std::cout << a[7]->elem << std::endl;
	//std::cout << a[8]->elem << std::endl;
	//std::cout << a[9]->elem << std::endl;
	return 0;
}