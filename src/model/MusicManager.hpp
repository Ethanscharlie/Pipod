//
// Created by ethanscharlie on 6/5/25.
//

#ifndef MUSICMANAGER_HPP
#define MUSICMANAGER_HPP
#include <filesystem>
#include <string>
#include <vector>

namespace Model {

class MusicManager {
    std::vector<std::filesystem::path> collectedFiles;

    void addFileIfNotFolder(std::filesystem::path path);

public:
    void collectFiles(std::filesystem::path folder);
    std::vector<std::filesystem::path> getCollectedFileList();
};

} // Model

#endif //MUSICMANAGER_HPP
