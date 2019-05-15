//
// Created by trall on 2019-04-21.
//

#include <vector>
#include "gtest/gtest.h"
#include "bst.h"

TEST(BSTAssignTest, AssignFromVector) {
    BST<int> bst;

    std::vector<int> values = {1,2,5,4,3};

    bst.assign(values.begin(), values.end());
    ASSERT_EQ(bst.size(), values.size());

    for (auto &i : values) {
        ASSERT_TRUE(std::find(bst.begin(), bst.end(), i) != bst.end());
    }
}

TEST(BSTAssignTest, AssignToNonEmptyBSTFromVector) {
    BST<int> bst;
    std::vector<int> initial = {6,7,9,10,8};
    bst.assign(initial.begin(), initial.end());

    std::vector<int> values = {1,2,5,4,3};

    bst.assign(values.begin(), values.end());
    ASSERT_EQ(bst.size(), values.size());

    for (auto &i : values) {
        ASSERT_TRUE(std::find(bst.begin(), bst.end(), i) != bst.end());
    }
    
    for (auto &i : initial) {
        ASSERT_FALSE(std::find(bst.begin(), bst.end(), i) != bst.end());
    }
}