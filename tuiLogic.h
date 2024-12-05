//
// Created by kcorea on 12/4/24.
//

#ifndef TUILOGIC_H
#define TUILOGIC_H
#include <string>
#include <vector>


class tuiLogic {
public:
    void mainMenu();
    void modeSelect();
    void difficultySelect();
    void themeSelect();
    static void generateButtons(std::vector<std::vector<std::string>>& buttons);
    static std::vector<std::vector<bool>> buttonSelected;
    private:
    void selectionLogic();
    static int columnSize;
    static int rowSize;
};



#endif //TUILOGIC_H
