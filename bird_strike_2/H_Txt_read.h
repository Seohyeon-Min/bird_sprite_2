/* GAM100

Seokhwa Hong

All content © 2023 DigiPen (USA) Corporation, all rights reserved. */

#include <iostream>
#include <vector>
#include "H_GameState.h"
#ifndef TXT_READ_H
#define TXT_READ_H

const std::string scorefile = "scores.txt";
const std::string challengefile = "challenge.txt";


struct ScoreEntry {
    std::string playerName;
    int score;

    ScoreEntry(const std::string& name, int s);
};

struct ChallengeEntry {
    std::string challengeName;
    bool completed;

    ChallengeEntry(const std::string& challenge, bool b);
};



void saveScores(const std::vector<ScoreEntry>& scores, const std::string& filename);

void saveChallenge(const std::vector<ChallengeEntry>& completed_, const std::string& filename);

std::vector<ScoreEntry> loadScores(const std::string& filename);

std::vector<ChallengeEntry> loadChallenge(const std::string& filename);

void updateChallenge(std::vector<ChallengeEntry>& completed_, const std::string& challengeName);


#endif