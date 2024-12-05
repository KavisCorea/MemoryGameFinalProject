//
// Created by kcorea on 12/3/24.
//

#include "display.h"

#include <iostream>

#include "tuiLogic.h"
using namespace std;

display::display(vector<vector<string>>& wordList){currentWordList = wordList;}

//column size is how many columns there are
//column length is the length of empty space in between
//box length is the total length counting the edges
//yes I need better variable names
//fun fact, this used to be the logic of just the game, but then I realized it could work for anything interactable.
void display::renderButton(){
    rowSize = currentWordList.size();
    columnSize = currentWordList[0].size();

    checkMax(currentWordList);
    columnLength = maxStringLength + 2;
    boxWidth = maxStringLength + 4;

    timesPrintedX = 0;
    timesPrintedY = 0;

    for (int y = 0; y < rowSize; y++) {
        //top row
        cornerLoop(topLeftCorner, topRightCorner);
        cout << endl;
        //top middle row

        middleLoop();
        cout << endl;
        /**/
        //middle row with string logic;
        for (int x = 0; x < columnSize; x++) {
            ;
            printAndTrack(verticalLine);
            //I got stuck here for so long because I used i (x used be i) instead of s. Kill me
            for (int s = 0; s < marginLogic(false, y, x); s++) {printAndTrack(space);}
            printAndTrack(currentWordList[y][x]);
            for (int s = 0; s < marginLogic(true, y, x); s++) {printAndTrack(space);}
            ;
            printAndTrack(verticalLine);
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

void display::cornerLoop(std::string leftCorner, std::string rightCorner) {
    for (int i = 0; i < columnSize; i++) {
        printAndTrack(leftCorner);
        for (int s = 0; s < columnLength; s++) {
             printAndTrack(horizontalLine);
        }
        printAndTrack(rightCorner);
    }
}

void display::middleLoop() {
    for (int i = 0 ; i < columnSize; i++) {
        printAndTrack(verticalLine);
        //accounts for the max string length plus two for centering the longest string
        for (int v = 0; v < columnLength; v++) {
            printAndTrack(space);
        }
        printAndTrack(verticalLine);
    }
}

int display::marginLogic(bool rightMargin, int y, int x) {
    //debugging log, I mixed up putting x, y instead of y, x causing an out of bounds error. Debugging is a pain.
    string& word = currentWordList[y][x]; //man, & references are awesome, they simplify things so much.
    int totalPadding = columnLength - word.size(); //total padding on both size needed to center the word

    //divide the padding for the left side into two. Int automatically truncates any remainders. So it provides effectively
    //a cieling for the left padding.
    int leftPadding = totalPadding/2;

    //right adding will be basically just whatever is left over.
    int rightPadding = totalPadding - leftPadding;

    //explanation for future self: if total columnLength = 7, and word.Size() = 4:
    //totalPadding = 7 - 4 = 3
    //leftMargin = 3/2 = 1
    //rightMargin = 3 - 1 = 2
    //3 was the total padding, and it was odd. So by dividing it by 2 it would technically be 1.5, but it collapses into
    //1. Then I subtract the total padding amount, by the left margin, since I've already got that covered so rightMargin
    //needs to be whatever is left of the total padding.

    return rightMargin ? rightPadding : leftPadding; //if rightMargin is true, give rightPadding else give leftPadding.
    }

void display::checkMax(vector<vector<string>>& wordList) {
    for (int y = 0; y < rowSize; y++) {
        for (int x = 0; x < columnSize; x++) {
            if (wordList[y][x].size() > maxStringLength) {maxStringLength = wordList[y][x].size();}
        }
    }
}

void display::reset() {
    rowSize = 0;
    columnSize = 0;
    maxStringLength = 0;
    currentWordList.clear();
}

//it may not look like it. But this was hours, upon hours, of debugging and suffering.
void display::colorTracker(){
    if (timesPrintedX == boxWidth){xCoordinate++; timesPrintedX = 0;}
    if (xCoordinate >= columnSize){xCoordinate = 0; timesPrintedY++;}
    if (timesPrintedY == boxHeight){yCoordinate++; timesPrintedY = 0;}
    if (tuiLogic::buttonSelected[yCoordinate][xCoordinate]) {cout << "\033[31m";}
    else {cout << "\033[0m";}
}

//this too, I initially had colorTracker() everywhere I printed something. Realized I wasn't going to catch everything
//so instead each time I used cout to print something, I ran it through here instead.
void display::printAndTrack(string& str) {
    colorTracker();
    cout << str;

    bool bigData = false;
    for (int i = 0; i < 6; i++) {
        if (str == compareContainer[i]) {timesPrintedX++; bigData = true; break;}
    }
    if (bigData == false){timesPrintedX += str.size();}
    }
