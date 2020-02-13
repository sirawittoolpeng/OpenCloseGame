#ifndef PROJECT_OPEN_CLOSE_H
#define PROJECT_OPEN_CLOSE_H
#include <string>
#include <stdlib.h>

class OpenClose {
public:
    static bool validInput(std::string stringInput, bool isPlayerPredictor);

    static bool play(std::string stringInput, bool isPlayerPredictor, bool randomAI, std::string aiHand_nonRandom,
    std::string endMessage);
};

#endif //PROJECT_OPEN_CLOSE_H


