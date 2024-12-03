//
// Created by kcorea on 12/2/24.
//

#ifndef GAME_H
#define GAME_H



class Game
{
    public:
    void start();

private:
    memoryGrid gridLogic; //Effectively the game logic, keeping track what's shown, giving info for the display logic, so on.
    display tuiLogic; //Logic for displaying the information on screen, updating screen to feel reactive and such. In charge of interactivity as well
    themes themesLogic; //Logic for themes: including selection, reading, and providing data for other classes
    asciiArt displayArt; //Effectively a table of reference to be able to easily print ASCII art and customize
};



#endif //GAME_H
