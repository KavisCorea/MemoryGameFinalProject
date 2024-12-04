//
// Created by kcorea on 12/3/24.
//

#include "boardData.h"

#include <iostream>
#include <random>

using namespace std;

int boardData::columnSize = 5;
int boardData::rowSize = 4;
int boardData::maxWordLength = 0;
int boardData::boardMaxTerms = (columnSize * rowSize)/2;

vector<string> boardData::randomWordList = {""};
vector<vector<string>> boardData::boardCoordinates (rowSize, vector<string> (columnSize, "")); //this hurts my brain

void boardData::shuffleList(vector<string> list) {
    random_device seed; //generates seed
    mt19937 generator(seed()); //this is a modern random number generator (mersenne twister rng)
    uniform_int_distribution<int> randomGen(0, list.size() - 1); //distributes the likelihood of getting any one of these numbers in this range
    int randomNumber;
    vector<string> shuffleContainer = list; //making copy of original list
    while (shuffleContainer.size() != boardData::boardMaxTerms) {
        randomNumber = randomGen(generator);
        shuffleContainer.erase(shuffleContainer.begin() + randomNumber);
        //the erase thing for vectors are weird but basically, I can't erase it directly, I have to use an iterator. That's
        //shuffleContainer.begin(), which points to the first element.
        //shuffleContainer[0] is the element, which is a bit different.

        //since I removed an element at random, I need to resize what the random number generator can choose, lest it goes out of bounds.
        randomGen = uniform_int_distribution<int>(0, shuffleContainer.size() - 1);
    }
    boardData::randomWordList = shuffleContainer;
    //I used a container instead of the vector directly cause it made my head hurt trying to understand it when used directly
}

void boardData::boardInitialize(){
    random_device seed;
    mt19937 generator(seed());
    uniform_int_distribution<int> randomGen(0, randomWordList.size() - 1);
    vector<bool> notDuplicate(randomWordList.size(), true); //bool array to keep track if it's a duplicate
    int resetFlag = 0;
    int randomNumber;
    for (int y = 0; y < rowSize; y++) {
        for (int x = 0; x < columnSize; x++) {
            if (resetFlag > boardMaxTerms) {
                fill (begin(notDuplicate), end(notDuplicate), true);
                resetFlag = 0;
            }
            //due to the size being half that of the board, once it reaches beyond the max term, it resets to do it all over it again
            //since there is always a matching term on the board
            while(true) {
                randomNumber = randomGen(generator);
                if (notDuplicate[randomNumber]) {break;}
            }
            boardCoordinates[y][x] = randomWordList[randomNumber];
            notDuplicate[randomNumber] = false;
            resetFlag++;
        }
    }
}
