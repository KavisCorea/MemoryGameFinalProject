//
// Created by kcorea on 12/2/24.
//

#include "themes.h"
#include <fstream>
#include <iostream>
using namespace std;
void themes::themeInitialize(int choiceInput) {
    choice = choiceInput;
    ifstream<string> file;
    file = "resources/" + whichFile();
    file.open(file);
    for (int index = 0; index < 50; index++) {
        getline(file, themeStringList.push_back);

        //checking for max string length logic
        string check;
        getline(file, check);
        checkMax(check.size());
    }
    //reads files and inputs them into themeStringList, inputs them at the last index, mainly for flexibility and
    //to account for multi-theme mode and beyond 10x10 grid
}

string themes::getThemeWord(int index){return themeStringList[index];}
int themes::getMaxLength() {return maxLength;}
void themes::reset() {themeStringList.clear(); maxLength = 0;}

string themes::whichFile() {
    string fileName;
    switch (choice) {
        case 1:
            fileName = "gameCharacters.txt";
        break;
        case 2:
            fileName = "bunnySpecies.txt";
        break;
        case 3:
            fileName = "computerParts.txt";
        break;
        default:
            cout << "Something went wrong..." << endl;
    }
    return fileName;
}

void themes::checkMax(int stringLength){if (stringLength > maxLength) {maxLength = stringLength;}}