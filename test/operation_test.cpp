#include "gtest/gtest.h"
#include "OpenClose.h"

TEST(input_validation_test, test1) // For the scenario of player putting wrong format 
    // and we want to inform them the correct one.
{
    //arrange
    bool isPlayerPredictor = true;
    std::string stringInput = "chicken";

    std::string expectConsoleOutput = 
    "Bad input: correct input should be of the form CC3,"
                     "where the first two letters indicate [O]pen or [C]losed state for each hand,"
                     "followed by the prediction (0-4).\n";

    testing::internal::CaptureStdout();
    //assert
    EXPECT_EQ (OpenClose::validInput (stringInput, isPlayerPredictor),  false);

    // To primarily check that if the input from user is valid for further progress or not

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ (output,  expectConsoleOutput);

    // To check that if the console shows the message we expected or not

    //References

    /* For example, if the user enters “chicken” on their turn, you could display a message such as:

    Bad input: correct input should be of the form CC3, 
    where the first two letters indicate [O]pen or [C]losed state for each hand,
    followed by the prediction (0-4).


    */
}

TEST(input_validation_test, test2) // For the scenario of player putting the correct format 
    // but predicted impossible open hand number
{
    //arrange
    bool isPlayerPredictor = true;
    std::string stringInput = "CC8";

    std::string expectConsoleOutput = 
    "Bad input: prediction should be in the range of 0-4.\n" ;

    testing::internal::CaptureStdout();
    //assert
    EXPECT_EQ (OpenClose::validInput (stringInput, isPlayerPredictor),  false);

    // To primarily check that if the input from user is valid for further progress or not

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ (output,  expectConsoleOutput);

    // To check that if the console shows the message we expected or not

    //References

    /* If the user enters “CC8” the error could be:

        Bad input: prediction should be in the range of 0-4.

    */
}

TEST(input_validation_test, test3) // For the scenario of player putting the correct format 
    // but the player wasn't the predictor
{
    //arrange
    bool isPlayerPredictor = false;
    std::string stringInput = "CO2";
 

    std::string expectConsoleOutput = 
    "Bad input: no prediction expected, you are not the predictor.\n" ;

    testing::internal::CaptureStdout();
    //assert
    EXPECT_EQ (OpenClose::validInput (stringInput, isPlayerPredictor),  false);

    // To primarily check that if the input from user is valid for further progress or not

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ (output,  expectConsoleOutput);

    // To check that if the console shows the message we expected or not

    //References

    /* 
    Or, if they are not the predictor:

        Bad input: no prediction expected, you are not the predictor.
    */
}

TEST(game_logic_test, test1) // For the scenario of : player is the predictor  
    // and the player guess correctly
    // player didn't want to play again
{
    //arrange

    bool isPlayerPredictor = true;
    bool randomAI = false;
    std::string aiHand = "CO";
    std::string stringInput = "CO2";
    std::string endMessage = "N";

    std::string expectConsoleOutput = 
    "AI: CO\n"
    "You WIN!!\n"
    "Do you want to play again?\n" ;

    testing::internal::CaptureStdout();
    //assert
    EXPECT_EQ (OpenClose::play(stringInput, isPlayerPredictor, randomAI, aiHand, endMessage),  true);


    // To primarily check that if the input from user is valid for further progress or not

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ (output,  expectConsoleOutput);

    // To check that if the console shows the message we expected or not

    //References

    /* 
    Or, if they are not the predictor:

        Bad input: no prediction expected, you are not the predictor.
    */
}

TEST(game_logic_test, test2) // For the scenario of : player is the predictor  
    // and the player guess the wrong prediction
{
    //arrange

    bool isPlayerPredictor = true;
    bool randomAI = false;
    std::string aiHand = "OO";
    std::string stringInput = "OO2";
    std::string endMessage = "N";

    std::string expectConsoleOutput = 
    "AI: OO\n"
    "No winner.\n" ;

    testing::internal::CaptureStdout();
    //assert
    EXPECT_EQ (OpenClose::play(stringInput, isPlayerPredictor, randomAI, aiHand, endMessage),  false);


    // To primarily check that if the input from user is valid for further progress or not

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ (output,  expectConsoleOutput);

    // To check that if the console shows the message we expected or not
}

TEST(game_logic_test, test3) // For the scenario of : AI is the predictor  
    // and the AI guess correctly
    // player didn't want to play again
{
    //arrange

    bool isPlayerPredictor = false;
    bool randomAI = false;
    std::string aiHand = "OO4";
    std::string stringInput = "OO";
    std::string endMessage = "N";

    std::string expectConsoleOutput = 
    "AI: OO4\n"
    "You LOSE!!\n"
    "Do you want to play again?\n" ;

    testing::internal::CaptureStdout();
    //assert
    EXPECT_EQ (OpenClose::play(stringInput, isPlayerPredictor, randomAI, aiHand, endMessage),  true);


    // To primarily check that if the input from user is valid for further progress or not

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ (output,  expectConsoleOutput);

    // To check that if the console shows the message we expected or not
}

TEST(game_logic_test, test4) // For the scenario of : AI is the predictor  
    // and the AI guess the wrong prediction
{
    //arrange

    bool isPlayerPredictor = false;
    bool randomAI = false;
    std::string aiHand = "OO2";
    std::string stringInput = "OO";
    std::string endMessage = "N";

    std::string expectConsoleOutput = 
    "AI: OO2\n"
    "No winner.\n";

    testing::internal::CaptureStdout();
    //assert
    EXPECT_EQ (OpenClose::play(stringInput, isPlayerPredictor, randomAI, aiHand, endMessage),  false);


    // To primarily check that if the input from user is valid for further progress or not

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ (output,  expectConsoleOutput);

    // To check that if the console shows the message we expected or not
}

TEST(game_logic_test, test5) // For the scenario of : player is the predictor  
    // and the player guess correctly
    // player wanted to play again
{
    //arrange

    bool isPlayerPredictor = true;
    bool randomAI = false;
    std::string aiHand = "CO";
    std::string stringInput = "CO2";
    std::string endMessage = "Y";

    std::string expectConsoleOutput = 
    "AI: CO\n"
    "You WIN!!\n"
    "Do you want to play again?\n" ;

    testing::internal::CaptureStdout();
    //assert
    EXPECT_EQ (OpenClose::play(stringInput, isPlayerPredictor, randomAI, aiHand, endMessage),  false);


    // To primarily check that if the input from user is valid for further progress or not

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ (output,  expectConsoleOutput);

    // To check that if the console shows the message we expected or not

    //References

    /* 
    Or, if they are not the predictor:

        Bad input: no prediction expected, you are not the predictor.
    */
}

TEST(game_logic_test, test6) // For the scenario of : player is the predictor  
    // and the player guess the wrong prediction
{
    //arrange

    bool isPlayerPredictor = true;
    bool randomAI = false;
    std::string aiHand = "OO";
    std::string stringInput = "OO2";
    std::string endMessage = "Y";

    std::string expectConsoleOutput = 
    "AI: OO\n"
    "No winner.\n" ;

    testing::internal::CaptureStdout();
    //assert
    EXPECT_EQ (OpenClose::play(stringInput, isPlayerPredictor, randomAI, aiHand, endMessage),  false);


    // To primarily check that if the input from user is valid for further progress or not

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ (output,  expectConsoleOutput);

    // To check that if the console shows the message we expected or not
}

TEST(game_logic_test, test7) // For the scenario of : AI is the predictor  
    // and the AI guess correctly
    // player wanted to play again
{
    //arrange

    bool isPlayerPredictor = false;
    bool randomAI = false;
    std::string aiHand = "OO4";
    std::string stringInput = "OO";
    std::string endMessage = "Y";

    std::string expectConsoleOutput = 
    "AI: OO4\n"
    "You LOSE!!\n"
    "Do you want to play again?\n" ;

    testing::internal::CaptureStdout();
    //assert
    EXPECT_EQ (OpenClose::play(stringInput, isPlayerPredictor, randomAI, aiHand, endMessage),  false);


    // To primarily check that if the input from user is valid for further progress or not

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ (output,  expectConsoleOutput);

    // To check that if the console shows the message we expected or not
}

TEST(game_logic_test, test8) // For the scenario of : AI is the predictor  
    // and the AI guess the wrong prediction
{
    //arrange

    bool isPlayerPredictor = false;
    bool randomAI = false;
    std::string aiHand = "OO2";
    std::string stringInput = "OO";
    std::string endMessage = "Y";

    std::string expectConsoleOutput = 
    "AI: OO2\n"
    "No winner.\n";

    testing::internal::CaptureStdout();
    //assert
    EXPECT_EQ (OpenClose::play(stringInput, isPlayerPredictor, randomAI, aiHand, endMessage),  false);


    // To primarily check that if the input from user is valid for further progress or not

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ (output,  expectConsoleOutput);

    // To check that if the console shows the message we expected or not
}