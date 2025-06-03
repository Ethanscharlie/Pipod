//
// Created by ethanscharlie on 6/3/25.
//

#include "../../src/model/MediaManager.hpp"

#include <gtest/gtest.h>

TEST(MediaManagerTest, PlayAudioFile) {
    Model::MediaManager mediaManager;
    mediaManager.loadFile("../tests/res/audiotest.mp3");
    mediaManager.play();

}