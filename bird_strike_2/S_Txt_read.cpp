/* GAM100

Seokhwa Hong

All content © 2023 DigiPen (USA) Corporation, all rights reserved. */

#include <iostream>
#include <fstream>
#include <vector>
#include "H_Txt_read.h"
#include <algorithm> 



ScoreEntry::ScoreEntry(const std::string& name, int s) : playerName(name), score(s) {}
ChallengeEntry::ChallengeEntry(const std::string& challenge, bool b) : challengeName(challenge), completed(b) {}


//Don't touch this fountion! That will make some error...
void saveScores(const std::vector<ScoreEntry>& scores, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const ScoreEntry& entry : scores) {
            file << entry.playerName << " " << entry.score << std::endl;
        }
        file.close();

    }
    else {
        std::cerr << "ERROR: " << filename << std::endl;
    }
}


//Don't touch this fountion! That will make some error...
void saveChallenge(const std::vector<ChallengeEntry>& completed, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const ChallengeEntry& entry : completed) {
            file << entry.challengeName << " " << entry.completed << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "ERROR:  " << filename << std::endl;
    }
}

std::vector<ScoreEntry> loadScores(const std::string& filename) {
    std::vector<ScoreEntry> scores;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string name;
        int score;
        while (file >> name >> score) {
            scores.emplace_back(name, score);
        }
        file.close();
    }
    else {
        std::cerr << "ERROR:  " << filename << std::endl;
    }
    return scores;
}



std::vector<ChallengeEntry> loadChallenge(const std::string& filename) {
    std::vector<ChallengeEntry> completed_;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string challenge;
        bool completed;
        while (file >> challenge >> completed) {
            completed_.emplace_back(challenge, completed);
        }
        file.close();
    }
    else {
        std::cerr << "ERROR:  " << filename << std::endl;
    }
    return completed_;
}


//if you want to use this fountion -> updateChallenge(completed_,type challenge name);
void updateChallenge(std::vector<ChallengeEntry>& completed_, const std::string& challengeName) {
    for (ChallengeEntry& entry : completed_) {
        if (entry.challengeName == challengeName) {
            entry.completed = 1;
            break;
        }
    }
}
