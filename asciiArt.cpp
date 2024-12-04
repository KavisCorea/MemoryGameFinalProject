//
// Created by kcorea on 12/3/24.
//

#include "asciiArt.h"

#include <iostream>

#include "boardData.h"
using namespace std;
void asciiArt::grid(){
    for (int y = 0; y < boardData::rowSize-1; y++) {
        //top row
        cornerLoop(topLeftCorner, topRightCorner);
        cout << endl;

        //top middle row

        middleLoop();
        cout << endl;
        /**/
        //middle row with string logic;
        for (int x = 0; x < boardData::columnSize-1; x++) {
            cout << verticalLine;
            //I got stuck here for so long because I used i instead of s. Kill me
            for (int s = 0; s < marginLogic(false, x, y); s++) {cout << " ";}
            cout << boardData::boardCoordinates[x][y];
            for (int s = 0; s < marginLogic(true, x, y); s++ ) {cout << " ";}
            cout << verticalLine;
        }
        cout << endl;
        //bottom middle row
        middleLoop();
        cout << endl;
        //bottom row
        cornerLoop(bottomLeftCorner, bottomRightCorner);
        cout << endl;
    }
}

void asciiArt::cornerLoop(std::string leftCorner, std::string rightCorner) {
    for (int i = 0; i < boardData::columnSize; i++) {
        cout << leftCorner;
        for (int s = 0; s < columnLength; s++) {
            cout << horizontalLine;
        }
        cout << rightCorner;
    }
}

void asciiArt::middleLoop() {
    for (int i = 0 ; i < boardData::columnSize; i++) {
        cout << verticalLine;
        //accounts for the max string length plus two for centering the longest string
        for (int v = 0; v < columnLength; v++) {
            cout << " ";
        }
        cout << verticalLine;
    }
}

int asciiArt::marginLogic(bool rightMargin, int x, int y) {
    string& word = boardData::boardCoordinates[x][y]; //man, & references are awesome, they simplify things so much.
    int marginSize = (columnLength - word.size()) / 2;
    if (rightMargin && word.size() % 2 != 0) {marginSize++;};
    //checking if the word queued up is an odd number. If so, add one more space when it's the right margin
    return marginSize;
    }

    //takes the current string length, subtracts it by the max string length + 2, divides it by two. That's how many
    //spaces it needs to be centered as best as it can.
    //Example: Max word length is let's say 4. So the emptySpace is going to be 6
    //Then for a string that is only 2 long: 6 - 2 = 4, divide by 2 equals 2. It needs two spaces each side to be complete.
    //If it's uneven, lets say 3 long: 6 - 3 = 3, divide by 2 equals 1 with a remainder of 1
    //so one each side except the right will have the spacer added of 1.