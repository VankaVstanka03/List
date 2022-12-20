#include <gtest.h>
#include "list.h"

TEST(list, can_create_list) {
	ASSERT_NO_THROW(list<int> a(1, { 1 }));
}

TEST(list, cant_create_list_with_non_valid_size) {
	ASSERT_ANY_THROW(list<int> a(-90, { 1 }));
}

TEST(list, can_use_copy_constructor) {
	list<double> a(6, { 2.1, 2.2, 2.3, 2.4, 2.5, 2.6 });
	list<double> b(a);
}