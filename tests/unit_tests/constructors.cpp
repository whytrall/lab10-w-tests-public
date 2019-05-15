//
// Created by trall on 2019-04-21.
//
#include <vector>
#include "gtest/gtest.h"
#include "bst.h"

class BSTConstructorsTestParams : public ::testing::TestWithParam<std::vector<int>> {
};

TEST_P(BSTConstructorsTestParams, CopyConstructor) {
    BST<int> bst_original;
    if (GetParam().size() != 0) {
        bst_original.assign(GetParam().begin(), GetParam().end());
        ASSERT_EQ(bst_original.size(), GetParam().size());
    }

    BST<int> bst_copy = bst_original;

    ASSERT_EQ(bst_copy.size(), bst_original.size());

    for (auto &i : bst_original) {
        ASSERT_TRUE(std::find(bst_copy.begin(), bst_copy.end(), i) != bst_copy.end());
    }
}

TEST_P(BSTConstructorsTestParams, AssignmentConstructor) {
    BST<int> bst_original;
    if (GetParam().size() != 0) {
        bst_original.assign(GetParam().begin(), GetParam().end());
        ASSERT_EQ(bst_original.size(), GetParam().size());
    }

    BST<int> bst_copy;
    bst_copy = bst_original;

    ASSERT_EQ(bst_copy.size(), bst_original.size());

    for (auto &i : bst_original) {
        ASSERT_TRUE(std::find(bst_copy.begin(), bst_copy.end(), i) != bst_copy.end());
    }
}

TEST_P(BSTConstructorsTestParams, AssignmentConstructorForNonEmptyBST) {
    BST<int> bst_original;
    if (GetParam().size() != 0) {
        bst_original.assign(GetParam().begin(), GetParam().end());
        ASSERT_EQ(bst_original.size(), GetParam().size());
    }

    BST<int> bst_copy;
    std::vector<int> numbers_for_copy = {1,2,3,4};
    bst_copy.assign(numbers_for_copy.begin(), numbers_for_copy.end());
    bst_copy = bst_original;

    ASSERT_EQ(bst_copy.size(), bst_original.size());

    for (auto &i : bst_original) {
        ASSERT_TRUE(std::find(bst_copy.begin(), bst_copy.end(), i) != bst_copy.end());
    }
}

INSTANTIATE_TEST_SUITE_P(BSTConstructorsTest, BSTConstructorsTestParams, ::testing::Values(
        std::vector<int>({1, 10}), // normal test
        std::vector<int>({}) // empty
    ));