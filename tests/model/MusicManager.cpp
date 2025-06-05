//
// Created by ethanscharlie on 6/5/25.
//

#include "../../src/model/MusicManager.hpp"

#include <filesystem>
#include <gtest/gtest.h>

TEST(MusicManagerTest, LoadFiles) {
    std::filesystem::path file = "../tests/res/MusicTests";
    if (!std::filesystem::exists(file)) {
        FAIL() << "Folder does not exist";
    }

    std::vector<std::filesystem::path> expectedFiles = {
        "../res/MusicTests/AnotherArtist/Christmas-lights_fma-182248_001_00-00-00.mp3",
        "../res/MusicTests/AnotherArtist/Christmas-lights_fma-182248_002_00-00-42.mp3",
        "../res/MusicTests/AnotherArtist/City_fma-174834_001_00-01-41.mp3",
        "../res/MusicTests/AnotherArtist/Clavier-1_fma-182140_001_00-00-17.mp3",
        "../res/MusicTests/SomeArtist/Father-Green_fma-175116_001_00-00-00.mp3",
        "../res/MusicTests/SomeArtist/Fleurs-qui-se-dandinent-dans-les-petits-animaux_fma-164995_001_00-00-06.mp3",
        "../res/MusicTests/SomeArtist/Fleurs-qui-se-dandinent-dans-les-petits-animaux_fma-164995_002_00-00-21.mp3",
        "../res/MusicTests/SomeArtist/Fleurs-qui-se-dandinent-dans-les-petits-animaux_fma-164995_003_00-02-00.mp3",
    };

    Model::MusicManager musicManager;
    musicManager.collectFiles(file);

    std::vector<std::filesystem::path> collectedFiles = musicManager.getCollectedFileList();

    if (collectedFiles.size() != expectedFiles.size()) {
        FAIL() << "Files do not match, wrong list size";
    }

    for (int i = 0; i < collectedFiles.size(); i++) {
        if (!collectedFiles[i].compare(expectedFiles[i])) {
            FAIL() << "Files do not match, wrong file name";
        }
    }
}
