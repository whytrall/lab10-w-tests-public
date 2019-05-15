//
// Created by trall on 2019-04-21.
//

#include "gtest/gtest.h"
#include "bst.h"

class BSTFindTestParams : public ::testing::TestWithParam<int> {
};

TEST_P(BSTFindTestParams, Find) {
    BST<int> bst;

    std::vector<int> content = {17,8,3,9,7,15,23,18,16};

    bst.assign(content.begin(), content.end());
    ASSERT_EQ(bst.size(), content.size());

    std::sort(content.begin(), content.end());

    auto finder = bst.find(GetParam());
    if (std::find(content.begin(), content.end(), GetParam()) != content.end()) {
        ASSERT_EQ(*(finder), GetParam());
        if (finder == bst.end()) FAIL();
    }
    else {
        if (finder != bst.end()) FAIL();
    }
}

INSTANTIATE_TEST_SUITE_P(BSTConstructorsTest, BSTFindTestParams, ::testing::Values(
        9, // ExsistingElement
        1337 // NonExistsingElement
    ));