//
// Created by trall on 2019-04-21.
//

#include "gtest/gtest.h"
#include "bst.h"
#include <algorithm>

// Begin, end

TEST(BSTInteratorsTest, IteratorBegin) {
    BST<int> bst;
    std::vector<int> content = {17,8,3,9,7,15,23,18,16};
    bst.assign(content.begin(), content.end());
    std::sort(content.begin(), content.end());

    ASSERT_EQ(*(bst.begin()), *(content.begin()));
}

TEST(BSTInteratorsTest, IteratorEnd) {
    BST<int> bst;
    std::vector<int> content = {17,8,3,9,7,15,23,18,16};
    bst.assign(content.begin(), content.end());
    std::sort(content.begin(), content.end());

    ASSERT_EQ(*(--bst.end()), *(--content.end()));
}

TEST(BSTInteratorsTest, EmptyBSTIterators) {
    BST<int> bst;

    if (bst.begin() != bst.end()) FAIL();
}

// Increments

TEST(BSTInteratorsTest, IteratorIncrementPre) {
    BST<int> bst;
    std::vector<int> content = {17,8,3,9,7,15,23,18,16};
    bst.assign(content.begin(), content.end());
    std::sort(content.begin(), content.end());

    auto iterator = bst.begin();
    auto content_iter = content.begin();
    ASSERT_EQ(*(iterator), *(content_iter));
    ASSERT_EQ(*(++iterator), *(++content_iter));
    ASSERT_EQ(*(++iterator), *(++content_iter));
}

TEST(BSTInteratorsTest, IteratorIncrementPost) {
    BST<int> bst;
    std::vector<int> content = {17,8,3,9,7,15,23,18,16};
    bst.assign(content.begin(), content.end());
    std::sort(content.begin(), content.end());

    auto iterator = bst.begin();
    auto content_iter = content.begin();
    ASSERT_EQ(*(iterator++), *(content_iter++));
    ASSERT_EQ(*(iterator++), *(content_iter++));
    ASSERT_EQ(*(iterator), *(content_iter));
}

// Decrements

TEST(BSTInteratorsTest, IteratorDecrementPre) {
    BST<int> bst;
    std::vector<int> content = {17,8,3,9,7,15,23,18,16};
    bst.assign(content.begin(), content.end());
    std::sort(content.begin(), content.end());

    auto iterator = bst.end();
    auto content_iter = content.end();
    ASSERT_EQ(*(--iterator), *(--content_iter));
    ASSERT_EQ(*(--iterator), *(--content_iter));
    ASSERT_EQ(*(--iterator), *(--content_iter));
}

TEST(BSTInteratorsTest, IteratorDecrementPost) {
    BST<int> bst;
    std::vector<int> content = {17,8,3,9,7,15,23,18,16};
    bst.assign(content.begin(), content.end());
    std::sort(content.begin(), content.end());

    auto iterator = bst.end();
    auto content_iter = content.end();
    iterator--;
    content_iter--;
    ASSERT_EQ(*(iterator--), *(content_iter--));
    ASSERT_EQ(*(iterator--), *(content_iter--));
    ASSERT_EQ(*(iterator), *(content_iter));
}

// Loops
#if __cplusplus >= 201103L
TEST(BSTInteratorsTest, RangeBasedLoop) {
    BST<int> bst;
    std::vector<int> content = {17,8,3,9,7,15,23,18,16};
    bst.assign(content.begin(), content.end());
    std::sort(content.begin(), content.end());

    auto content_iter = content.begin();
    for (auto &obj : bst) {
        ASSERT_EQ(obj, *(content_iter++));
    }
}
#endif

// Const iterator

TEST(BSTInteratorsTest, ConstIterator) {
    BST<int> bst;

    bst.insert(4);
    bst.insert(5);

    ASSERT_EQ(bst.size(), static_cast<size_t>(2));

    BST<int>::const_iterator iterator1 = bst.begin();
    BST<int>::const_iterator iterator2 = --(bst.end());

    ASSERT_EQ(*(iterator1), 4);
    ASSERT_EQ(*(iterator2), 5);
}

// Algorithm

TEST(BSTAlgorithm, FindAlgorithm) {
    BST<int> bst;
    std::vector<int> content = {17,8,3,9,7,15,23,18,16};
    bst.assign(content.begin(), content.end());
    std::sort(content.begin(), content.end());

    auto value_to_find = *(--content.end());

    ASSERT_EQ(*(std::find(bst.begin(), bst.end(), value_to_find)), value_to_find);
}