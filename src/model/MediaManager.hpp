//
// Created by ethanscharlie on 6/3/25.
//

#ifndef MEDIAMANAGER_HPP
#define MEDIAMANAGER_HPP

#include <filesystem>
#include "vlc.hpp"

namespace Model {

class MediaManager {
    VLC::Instance vlcInstance;
    VLC::MediaPlayer mediaPlayer;
    VLC::Media currentMedia;

    std::filesystem::path currentMediaPath;

public:
    MediaManager();
    void loadFile(const std::filesystem::path &file);
    void play();
    void pause();
    void stop();
    bool isPlaying();

    std::string getCurrentlyPlaying();
};

} // Model

#endif //MEDIAMANAGER_HPP
