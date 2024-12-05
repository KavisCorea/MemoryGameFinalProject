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
    checkMax();
    cout << "Max string size: " << maxWordLength << endl;
    boardInitialize();
}

//debugging log: I got stuck here for an hour, only to realize the bug was that I never called boardInitialize() in the first place
void boardData::boardInitialize(){
    random_device seed;
    mt19937 generator(seed());
    uniform_int_distribution<int> randomGen(0, randomWordList.size() - 1);
    vector<bool> notDuplicate(randomWordList.size(), true); //bool array to keep track if it's a duplicate

    int resetFlag = 0;
    int randomNumber;
    int count;
    for (int y = 0; y < rowSize; y++) {
        for (int x = 0; x < columnSize; x++) {
            if (resetFlag == boardMaxTerms) {
                fill (begin(notDuplicate), end(notDuplicate), true);
                resetFlag = 0;
            }
            //due to the size being half that of the board, once it reaches beyond the max term, it resets to do it all over it again
            //since there is always a matching term on the board

            int infiniteTracker;
            while(true) {
                randomNumber = randomGen(generator);
                infiniteTracker++;
                if (notDuplicate[randomNumber]) {break;}
                if (infiniteTracker > 1000) {throw runtime_error ("Infinite loop in board initiation");}
                //I learned about throwing errors due to this one giving me a lot of trouble, and needing it for debugging.
            }
            boardCoordinates[y][x] = randomWordList[randomNumber];
            cout << "Populate time: " << ++count << endl;
            notDuplicate[randomNumber] = false;
            resetFlag++;
        }
    }
}

void boardData::checkMax() {
    for (int t  = 0; t < boardData::boardMaxTerms; t++) {
        if (maxWordLength < randomWordList[t].size()){maxWordLength = randomWordList[t].size();}
    }
}