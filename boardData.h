//
// Created by kcorea on 12/3/24.
//

#ifndef BOARDDATA_H
#define BOARDDATA_H
#include <string>
#include <vector>


struct boardData {
   static int columnSize;
   static int rowSize;
   static int boardMaxTerms;
   static int maxWordLength;
   static std::vector<std::string> randomWordList;
   static std::vector<std::vector<std::string>> boardCoordinates;
   //2D array of vector. And yes it's confusing and hurts my brain.
   //to future me looking over this, this is basically a vector of vectors.
   static void shuffleList(std::vector<std::string> list);
   static void boardInitialize();
};



#endif //BOARDDATA_H
