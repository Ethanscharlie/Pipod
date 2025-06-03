#include <iostream>
#include <gtest/gtest.h>

#include "model/MediaManager.hpp"

int runTests(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

int main(int argc, char **argv) {
    runTests(argc, argv);

    Model::MediaManager mediaManager;
}
