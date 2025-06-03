//
// Created by ethanscharlie on 6/3/25.
//

#include "MediaManager.hpp"

namespace Model {
    MediaManager::MediaManager() {
        vlcInstance = {0, nullptr};
    }

    void MediaManager::loadFile(const std::filesystem::path &file) {
        currentMedia = {vlcInstance, file.string(), VLC::Media::FromPath};
        mediaPlayer.setMedia(currentMedia);
    }

    void MediaManager::play() {
        mediaPlayer.play();
    }
} // Model