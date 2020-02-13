#include "OpenClose.h"
#include <stdlib.h>
#include <iostream>
#include <string>

bool OpenClose::validInput(std::string stringInput, bool isPlayerPredictor)
{
    // Check if the length of input is valid or not
    bool validLength;
    if (isPlayerPredictor)
    {
        validLength = stringInput.length() == 3;
    }
    else
    {
        validLength = stringInput.length() == 2;
    }

    // Check if the first 2 character are valid or not
    bool validFirst2Char =
        ((stringInput[0] == 'o' || stringInput[0] == 'O') ||
         (stringInput[0] == 'c' || stringInput[0] == 'C')) &&
        ((stringInput[1] == 'o' || stringInput[1] == 'O') ||
         (stringInput[1] == 'c' || stringInput[1] == 'C'));

    // Check if the third character is between 0 and 4 or not
    bool validNumber =
        (stringInput[2] >= '0' && stringInput[2] <= '4');

    if ((validLength && validNumber && validFirst2Char) ||
        (validLength && validFirst2Char && !isPlayerPredictor))
        return true;
    else if ((!validLength && !validFirst2Char && !validNumber) ||
             (validLength && !validFirst2Char && !validNumber) ||
             (isPlayerPredictor && !validLength && validFirst2Char && !validNumber))
    {
        std::cout << "Bad input: correct input should be of the form CC3,"
                     "where the first two letters indicate [O]pen or [C]losed state for each hand,"
                     "followed by the prediction (0-4)."
                  << std::endl;
        return false;
    }
    else if (!(validNumber && isPlayerPredictor) && validLength && validFirst2Char)
    {
        std::cout << "Bad input: prediction should be in the range of 0-4." << std::endl;
        return false;
    }
    else if ((!validLength && validFirst2Char && validNumber) && !isPlayerPredictor)
    {
        std::cout << "Bad input: no prediction expected, you are not the predictor." << std::endl;
        return false;
    }
    return false;
}

bool OpenClose::play(std::string stringInput, bool isPlayerPredictor, bool randomAI, std::string aiHand_nonRandom, 
    std::string endMessage)
{
    // randomAI, aiHand_nonRandom and endMessage are for debugging.
    // normally, we would set them to true, "", "" respectively.

    int prediction;
    std::string aiHand;
    if (randomAI)
    {
        for (int i = 0; i < 2; i++)
        {
            if (rand() % 2 == 1)
                aiHand.push_back('O');
            else
                aiHand.push_back('C');
        }
    }
    else
        aiHand = aiHand_nonRandom;

    if (isPlayerPredictor) // Set the prediction as user's input
    {
        prediction = stringInput[2] - '0';
        std::cout << "AI: " << aiHand << std::endl;
    }
    else // Random prediction by AI
    {
        if (randomAI)
        {
            prediction = rand() % 4 + 1;
            std::cout << "AI: " << aiHand << prediction << std::endl;
        }
        else   {
            prediction = aiHand[2] - '0';
            std::cout << "AI: " << aiHand << std::endl;
        }
    }

    int count_open = 0;
    for (int i = 0; i < 2; i++)
    {
        if (aiHand[i] == 'O')
            count_open++;
        if (stringInput[i] == 'o' || stringInput[i] == 'O')
            count_open++;
    }

    if (count_open == prediction)
    {
        if (isPlayerPredictor)
        {
            std::cout << "You WIN!!" << std::endl;
        }
        else
        {
            std::cout << "You LOSE!!" << std::endl;
        }
        std::cout << "Do you want to play again?" << std::endl;
        std::string tryAgain;
        
        if(!randomAI)
            tryAgain = endMessage;
        else
            std::getline(std::cin, tryAgain);

        if (tryAgain[0] == 'n' || tryAgain[0] == 'N')
            return true;
    }
    else
    {
        std::cout << "No winner." << std::endl;
    }

    return false;
}