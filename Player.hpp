/*********************************************************************
** Program Name: Sock Search Game (CS162 Final Project)
** Author: Becky Chao
** Date: 3/18/18
** Description: This is the header file for the Player class, which 
keeps track of player status (i.e. the number of socks collected, 
items in the vector inventory, steps walked by the player) and the 
location of valuable items the player needs to collect.
*********************************************************************/

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

#ifndef FINAL_PLAYER_HPP
#define FINAL_PLAYER_HPP

class Player {
public:
    Player();
    int validInput(int);

    void addItem(string);
    void printItems();
    void removeItem();
    bool searchItem(string);

    void setKeyLoc(int);
    void setFlashlightLoc(int);
    void setSock1Loc(int);
    void setSock2Loc(int);
    
    int getKeyLoc();
    int getFlashlightLoc();
    int getSock1Loc();
    int getSock2Loc();

    bool sockCheck();

    void addSteps(int);
    int getSteps();
private:
    vector<string> inventory;
    int keyLoc;
    int flashlightLoc;
    int sock1Loc;
    int sock2Loc;
    int steps;
};


#endif
