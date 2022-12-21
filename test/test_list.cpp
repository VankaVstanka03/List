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
	ASSERT_NO_THROW(list<double> b(a));
	list<double> b(a);
	for (int i = 0; i < a.get_size(); i++) {
		EXPECT_EQ(a[i], b[i]);
	}
}

TEST(list, can_use_move_constructor) {
	list<double> a(6, { 2.1, 2.2, 2.3, 2.4, 2.5, 2.6 });
	list<double> b(std::move(a));
	list<double> prov(6, { 2.1, 2.2, 2.3, 2.4, 2.5, 2.6 });
	EXPECT_EQ(0, a.get_size());
	EXPECT_EQ(6, b.get_size());
	for (int i = 0; i < b.get_size(); i++) {
		EXPECT_EQ(prov[i], b[i]);
	}
}

TEST(list, can_use_operator_eq) {
	list<double> a(6, { 2.1, 2.2, 2.3, 2.4, 2.5, 2.6 });
	list<double> b = a;
	list<double> prov(6, { 2.1, 2.2, 2.3, 2.4, 2.5, 2.6 });
	EXPECT_EQ(6, a.get_size());
	EXPECT_EQ(6, b.get_size());
	for (int i = 0; i < b.get_size(); i++) {
		EXPECT_EQ(prov[i], b[i]);
		EXPECT_EQ(prov[i], a[i]);
	}
}

TEST(list, can_use_move_operator_eq) {
	list<double> a(6, { 2.1, 2.2, 2.3, 2.4, 2.5, 2.6 });
	list<double> b = std::move(a);
	list<double> prov(6, { 2.1, 2.2, 2.3, 2.4, 2.5, 2.6 });
	EXPECT_EQ(0, a.get_size());
	EXPECT_EQ(6, b.get_size());
	for (int i = 0; i < b.get_size(); i++) {
		EXPECT_EQ(prov[i], b[i]);
	}
}

TEST(list, can_clear_list) {
	list<double> a(6, { 2.1, 2.2, 2.3, 2.4, 2.5, 2.6 });
	a.clear();
	EXPECT_EQ(0, a.get_size());
}

TEST(list, can_iterate_on_the_list) {
	list<double> a(6, { 2.1, 2.2, 2.3, 2.4, 2.5, 2.6 });
	list<double> prov(6, { 2.1, 2.2, 2.3, 2.4, 2.5, 2.6 });
	for (auto it1 = a.begin(), it2 = prov.begin(); it1 != a.end(); it1++, it2++) {
		EXPECT_EQ((*it2),(*it1));
	}
}

class Fixture : public ::testing::Test {
public:
	list<double> l;
	list<double> j;
	Fixture() : l(10, { 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0 }), j(10, { 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0 }) {}
};

TEST_F(Fixture, can_push_back) {
	l.push_back(2.1);
	EXPECT_EQ(11, l.get_size());
	EXPECT_EQ(2.1, (*l.pre_end()));
}

TEST_F(Fixture, can_insert_after) {
	l.insert_after(l.pre_end(), 2.1);
	EXPECT_EQ(11, l.get_size());
	EXPECT_EQ(2.1, l[10]);
}

TEST_F(Fixture, can_erase_after) {
	EXPECT_EQ(l.end(), l.erase_after(l.in_pos(8)));
	EXPECT_EQ(9, l.get_size());
}

TEST_F(Fixture, can_merge_lists) {
	list<double> proverka(20, { 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0 });
	l.merge(j);
	EXPECT_EQ(0, j.get_size());
	EXPECT_EQ(20, l.get_size());
	for (int i = 0; i < l.get_size(); i++) {
		EXPECT_EQ(proverka[i], l[i]);
	}
}