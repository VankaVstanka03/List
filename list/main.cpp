#include <iostream>
#include "vector.h"
#include "iterator.h"
#include "list.h"
#include <forward_list>

int main() {
	list<double> a(5, {2.1, 2.2, 2.3, 2.4, 2.5});
	list<double> b = a;

	//list<double> m = circled_list(std::move(a));
	std::cout << (*a.pre_end()) << std::endl;
	a.insert_after(a.pre_end(), 2.6);
	std::cout << (*a.pre_end()) << std::endl;
	std::cout << (*a.erase_after(a.in_pos(3))) << std::endl;;
	std::cout << a[0] << std::endl;
	std::cout << a[1] << std::endl;
	std::cout << a[2] << std::endl;
	std::cout << a[3] << std::endl;
	std::cout << a[4] << std::endl;
	//std::cout << a[5] << std::endl;

	//std::cout << m[0] << std::endl;
	//std::cout << m[1] << std::endl;
	//std::cout << m[2] << std::endl;
	//std::cout << m[3] << std::endl;
	//std::cout << m[4] << std::endl;
	//std::cout << m[5] << std::endl;
	//std::cout << m[6] << std::endl;
	//
	//std::cout << std::endl;
	//std::cout << m.circle_in_the_list() << std::endl;
	//std::cout << b[0] << std::endl;
	//std::cout << b[1] << std::endl;
	//std::cout << b[2] << std::endl;
	//std::cout << b[3] << std::endl;
	//std::cout << b[4] << std::endl;
	//std::cout << b[5] << std::endl;
	//std::cout << b.circle_in_the_list() << std::endl;
	////std::cout << a[5]->elem << std::endl;
	//std::cout << a.get_size() << std::endl;
	////std::cout << a[5]->elem << std::endl;
	//std::cout << a.get_size() << std::endl;
	//a.merge(b);
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