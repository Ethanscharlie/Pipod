//
// Created by ethanscharlie on 6/3/25.
//

#include "MediaManager.hpp"

namespace Model {
    MediaManager::MediaManager() {
        vlcInstance = {0, nullptr};
    }

    void MediaManager::loadFile(const std::filesystem::path &file) {
        if (!std::filesystem::exists(file)) {
            throw std::logic_error("MeidaManager Load file: File does not exist");

        }

        currentMedia = {vlcInstance, file.string(), VLC::Media::FromPath};
        mediaPlayer = currentMedia;
    }

    void MediaManager::play() {
        mediaPlayer.play();
    }

    void MediaManager::stop() {
        mediaPlayer.stop();
    }

    bool MediaManager::isPlaying() {
        return mediaPlayer.isPlaying();
    }
} // Model