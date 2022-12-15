#include <gtest.h>
#include "list.h"

TEST(list, smth) {
	list<int> a(4, {1 , 2, 3, 4});
	list<int> b(a);
	for (int i = 0; i < 4; i++) {
		std::cout << "a" << i << " = " << a[i]->elem << "  " << "b" << i << " = " << b[i]->elem << std::endl;
	}
}