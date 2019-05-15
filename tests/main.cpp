//
// Created by trall on 2019-04-21.
//

#include <iostream>
#include <gtest/gtest.h>

// BST tree example
// 17 8 3 9 7 15 23 18 16
//
//          17
//        /    \
//       /      \
//      8       23
//     / \      /
//    3   9    18
//       / \
//      7  15
//           \
//           16
//


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}