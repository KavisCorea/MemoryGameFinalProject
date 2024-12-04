#include <iostream>

#include "asciiArt.h"
#include "themes.h"
int main() {

    themes test;
    test.themeInitialize(1);
    boardData::shuffleList(test.getThemeList());

    asciiArt gridTest;
    gridTest.grid();
}
