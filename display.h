#pragma once
#include <string>

#include "boardData.h"
#include "themes.h"

class display
{
public:
    //used mostly so this can take care of using the correct methods within that class
    display(std::vector<std::vector<std::string>>& wordList);
    void renderButton();
private:
    std::string bottomLeftCorner = "╚"; //
    std::string topLeftCorner = "╔"; //

    std::string topRightCorner = "╗"; //
    std::string bottomRightCorner = "╝"; //

    std::string horizontalLine = "═"; //
    std::string verticalLine = "║"; //

    int columnSize = 0;
    int rowSize = 0;
    int maxStringLength = 0;
    int columnLength = 0;
    int boxHeight = 5;
    int boxWidth = 0;

    int yCoordinate = 0;
    int xCoordinate = 0;

    int timesPrintedX = 0;
    int timesPrintedY = 0;

    std::string space = " ";

    std::vector<std::vector<std::string>> currentWordList;

    void cornerLoop(std::string leftCorner, std::string rightCorner);
    void middleLoop();
    void checkMax(std::vector<std::vector<std::string>>& wordList);
    int marginLogic(bool rightMargin, int x, int y);
    void colorTracker();
    void printAndTrack(std::string& str);
    void reset();

    std::string compareContainer[6] = {horizontalLine, verticalLine, topLeftCorner, topRightCorner, bottomLeftCorner, bottomRightCorner};
};
