//
// Created by trall on 2019-04-21.
//

#include "gtest/gtest.h"
#include "bst.h"
#include <vector>

TEST(BSTEmptySizeTest, EmptyAndSizeOnInit) {
    BST<int> bst;

    ASSERT_TRUE(bst.empty());
    ASSERT_EQ(bst.size(), static_cast<size_t>(0));
}

TEST(BSTEmptySizeTest, NotEmptyAndSizeAfterInsertionAndDeletion) {
    BST<int> bst;
    ASSERT_TRUE(bst.empty());

    bst.insert(10);
    bst.remove(10);
    bst.insert(10);

    ASSERT_FALSE(bst.empty());
    ASSERT_EQ(bst.size(), static_cast<size_t>(1));
}
