#include <stdlib.h>
#include <iostream>
#include <string>
#include "OpenClose.h"

int main(int argc, char *argv[])
{

    bool game_end_status = false;
    bool isPlayerPredictor = true;
    std::string stringInput;

    std::cout << "Welcome to the game!" << std::endl;

    while (!game_end_status)
    {

        if (isPlayerPredictor)
        {
            std::cout << "You are the predictor, what is your input?" << std::endl;
        }
        else
        {
            std::cout << "AI is the predictor, what is your input?" << std::endl;
        }

        std::getline(std::cin, stringInput); // get the input from keyboard

        if (OpenClose::validInput(stringInput, isPlayerPredictor))
        {
            game_end_status = OpenClose::play(stringInput, isPlayerPredictor, true, "", "");
            if (!game_end_status) // In case that there's no winner, switch the predictor.
                isPlayerPredictor = !isPlayerPredictor;
        }
    }

    std::cout << "Ok, bye!" << std::endl;
    return 0;
}
