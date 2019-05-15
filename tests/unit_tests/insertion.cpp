//
// Created by trall on 2019-04-21.
//

#include "gtest/gtest.h"
#include "bst.h"

TEST(BSTInsertionTest, Insertion) {
    BST<int> bst;

    std::vector<int> content = {17,8,3,9,7,15,23,18,16};

    bst.assign(content.begin(), content.end());
    ASSERT_EQ(bst.size(), content.size());

    std::sort(content.begin(), content.end());

    auto iterator = bst.begin();
    for (int i = 0; i < content.size(); ++i) {
        ASSERT_EQ(*(iterator++), content[i]);
    }
}

TEST(BSTInsertionTest, UniqueInsertion) {
    BST<int> bst;

    bst.insert(10);
    bst.insert(10);

    ASSERT_FALSE(bst.empty());
    ASSERT_EQ(bst.size(), static_cast<size_t>(1));
}