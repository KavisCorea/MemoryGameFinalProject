//
// Created by kcorea on 12/2/24.
//

#include "themes.h"
#include <fstream>
#include <iostream>

#include "boardData.h"
using namespace std;
void themes::themeInitialize(int choiceInput){
    choice = choiceInput;

    ifstream file;
    string filePath = "resources/" + whichFile();
    file.open(filePath);

    for (string container; getline(file, container); checkMax(container.size())) {
        themeStringList.push_back(container);
    }
    //reads files and inputs them into themeStringList, inputs them at the last index, mainly for flexibility and
    //to account for multi-theme mode and beyond 10x10 grid
    //also this for loop makes a temporary string variable to store the line, and check the string size,
    //since I will want to adjust the size of the boxes I make depending on the size. It uses the checkMax method here,
    //and stores it
    file.close();
    if (boardData::maxWordLength < maxLength){boardData::maxWordLength = maxLength;}
}

vector<string> themes::getThemeList(){return themeStringList;}
int themes::getMaxLength() {return maxLength;}
void themes::reset() {themeStringList.clear(); maxLength = 0;}
int themes::getThemeListLength() {return themeStringList.size();}


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