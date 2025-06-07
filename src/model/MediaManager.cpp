//
// Created by ethanscharlie on 6/3/25.
//

#include "MediaManager.hpp"

#include <iostream>

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
        currentMediaPath = file;
    }

    void MediaManager::play() {
        if (!mediaPlayer.isValid()) {
            std::cout << "Cannot play, no file loaded\n";
            return;
        }

        mediaPlayer.play();
    }

    void MediaManager::pause() {
        if (mediaPlayer.isPlaying()) {
            mediaPlayer.pause();
        }
    }

    void MediaManager::stop() {
        if (!mediaPlayer.isValid()) {
            std::cout << "Cannot stop, no file loaded\n";
            return;
        }

        mediaPlayer.stop();
    }

    bool MediaManager::isPlaying() {
        return mediaPlayer.isPlaying();
    }

    std::string MediaManager::getCurrentlyPlaying() {
        return currentMediaPath.string();
    }
} // Model