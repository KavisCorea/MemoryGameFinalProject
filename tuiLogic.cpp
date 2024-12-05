//
// Created by kcorea on 12/4/24.
//

#include "tuiLogic.h"

#include "display.h"
using namespace std;

void tuiLogic::mainMenu() {
    system("clear");
    vector menuButtons = {1, vector<string>{2, {"Start", "Quit"}}};
    generateButtons(menuButtons);
    selectionLogic(menuButtons);
}

void tuiLogic::generateButtons(std::vector<std::vector<std::string>> &words) {
    rowSize = words.size();
    columnSize = words[0].size();
    buttonSelected.clear();
    buttonSelected.resize(rowSize);
    for (int y = 0; y < rowSize; y++) {
        for (int x = 0; x < columnSize; x++) {
            buttonSelected[y].resize(columnSize, false);
        }
    }
    buttonSelected[0][0] = true; //default
}

bool tuiLogic::selectionLogic(vector<vector<string>> &buttonLabels) {
    generateButtons(buttonLabels);
    display buttons(buttonLabels);

    string input;
    bool inputGiven = false;
    while (inputGiven == false) {
        buttons.renderButton();
        cin >>
    }

}
vector<vector<bool>> tuiLogic::buttonSelected(rowSize, std::vector(columnSize, false));
int tuiLogic::rowSize = 0;
int tuiLogic::columnSize = 0;

