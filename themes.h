#pragma once
#include <string>
#include <vector>

class themes {
public:
    void themeInitialize(int choiceInput);

    //utility for resetting and getting vector
    std::vector<std::string> getThemeList();
    int getMaxLength();
    //for resetting, will need to be reset each time a new game theme is being selected.
    //this means themes can be initialized twice or more times, allowing for the other modes I have made to be possible
    int getThemeListLength();
    void reset();
private:
    int choice;
    int maxLength = 0;

    std::vector<std::string> themeStringList;
    std::string whichFile();
    void checkMax(int stringLength);
};

