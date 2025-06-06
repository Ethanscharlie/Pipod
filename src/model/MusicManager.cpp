//
// Created by ethanscharlie on 6/5/25.
//

#include "MusicManager.hpp"

#include <filesystem>

namespace Model {
    void MusicManager::addFileIfNotFolder(std::filesystem::path path) {
        if (is_directory(path)) {
            return;
        }

        collectedFiles.push_back(path);
    }

    void MusicManager::collectFiles(std::filesystem::path folder) {
        for (const auto& entry : std::filesystem::recursive_directory_iterator(folder)) {
            addFileIfNotFolder(entry);
        }
    }

    std::vector<std::filesystem::path> MusicManager::getCollectedFileList() {
        return collectedFiles;
    }

    void MusicManager::collectFilesFromArtist(const std::filesystem::path& path,
        const std::string &artistName) {
        const std::filesystem::path artistPath = path / artistName;
        collectFiles(artistPath);
    }

} // Model