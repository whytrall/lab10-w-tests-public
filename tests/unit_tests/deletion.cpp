//
// Created by trall on 2019-04-21.
//

#include "gtest/gtest.h"
#include "bst.h"
#include <vector>

class BSTDeletionTestParams : public ::testing::TestWithParam<int> {
};

TEST(BSTDeletionTest, DeleteSingleRoot) {
    BST<int> bst;

    bst.insert(5);

    ASSERT_EQ(bst.size(), static_cast<size_t>(1));

    bst.remove(5);

    ASSERT_EQ(bst.size(), static_cast<size_t>(0));

    if (bst.begin() != bst.end()) FAIL();
}

TEST_P(BSTDeletionTestParams, VariousDeletion) {
    BST<int> bst;

    std::vector<int> content = {17,8,3,9,7,15,23,18,16};

    bst.assign(content.begin(), content.end());
    ASSERT_EQ(bst.size(), content.size());

    int deleted = GetParam();

    bst.remove(deleted);

    std::sort(content.begin(), content.end());

    auto iterator = bst.begin();
    for (int &i : content) {
        if (i == deleted) continue;
        ASSERT_EQ(*(iterator++), i);
    }

    ASSERT_EQ(bst.size(), content.size()-1);
}

TEST(BSTDeletionTest, DeleteLinearTree) {
    BST<int> bst;
    ASSERT_TRUE(bst.empty());

    for (int i = 1; i < 4; ++i) {
        bst.insert(i);
    }

    for (int i = 1; i < 3; ++i) {
        bst.remove(i);
        ASSERT_EQ(*(bst.begin()), i+1);
    }

    ASSERT_EQ(bst.size(), 1);
}

INSTANTIATE_TEST_SUITE_P(BSTDeletionTest, BSTDeletionTestParams, ::testing::Values(
        17, // Root
        8, // Subroot
        18, // List
        23, // ElementWithoutRightSubtree
        15, // ElementWithoutLeftSubtree
        4 // NonExistingElement
    ));