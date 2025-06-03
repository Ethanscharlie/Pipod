#include <iostream>
#include <gtest/gtest.h>

#include "model/MediaManager.hpp"

TEST(MediaManagerTest, testPlayWithoutLoadedFile) {
    Model::MediaManager mediaManager;
    mediaManager.play();
}

TEST(MediaManagerTest, testStopWithoutLoadedFile) {
    Model::MediaManager mediaManager;
    mediaManager.stop();
}

TEST(MediaManagerTest, PlayAudioFile) {
    std::filesystem::path file = "../tests/res/audiotest.mp3";
    if (!std::filesystem::exists(file)) {
        FAIL() << "File does not exist";
    }

    Model::MediaManager mediaManager;
    mediaManager.loadFile(file);
    mediaManager.play();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    EXPECT_TRUE(mediaManager.isPlaying());
    mediaManager.stop();
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
