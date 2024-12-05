#include <iostream>
#include "boardData.h"
#include "display.h"
#include "themes.h"
#include "tuiLogic.h"

int main() {
    themes test;
    test.themeInitialize(1);
    boardData::shuffleList(test.getThemeList());


    display gridTest(boardData::boardCoordinates);
    tuiLogic::generateButtons(boardData::boardCoordinates);

    std::cout << std::endl;
}
