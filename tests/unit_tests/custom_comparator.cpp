//
// Created by trall on 2019-04-24.
//

#include "gtest/gtest.h"
#include "bst.h"
#include <vector>

TEST(BSTCustomComparatorTest, CustomComparator) {
    class CustomInt {
        int x;
    public:
        CustomInt() {}
        CustomInt(int x): x(x) {}
        int get() const {
            return x;
        }
    };

    class CustomIntComparator {
    public:
        bool operator()(const CustomInt& a, const CustomInt& b) {
            return a.get() > b.get();
        }
    };

    BST<CustomInt, CustomIntComparator> bst;

    std::vector<CustomInt> values = {CustomInt(10), CustomInt(15)};

    bst.assign(values.begin(), values.end());

    ASSERT_EQ(bst.size(), values.size());

    for (auto &i : values) {
        ASSERT_TRUE(std::find_if(bst.begin(), bst.end(), [i](CustomInt j){ return i.get() == j.get(); }) != bst.end());
    }
}

