#pragma once
#include <string>

#include "boardData.h"
#include "themes.h"

class asciiArt
{
public:
    //used mostly so this can take care of using the correct methods within that class
    void grid();
private:
    std::string bottomLeftCorner = "╚"; //
    std::string topLeftCorner = "╔"; //

    std::string topRightCorner = "╗"; //
    std::string bottomRightCorner = "╝"; //

    std::string horizontalLine = "═"; //
    std::string verticalLine = "║"; //

    int index = 0;
    int columnLength = boardData::maxWordLength + 2;

    void cornerLoop(std::string leftCorner, std::string rightCorner);
    void middleLoop();
    int marginLogic(bool rightMargin, int x, int y);

};
