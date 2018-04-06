/*********************************************************************
** Program Name: Sock Search Game (CS162 Final Project)
** Author: Becky Chao
** Date: 3/18/18
** Description: This is the header file for the Space class, which is 
an abstract class with pure virtual functions intended to be 
overwritten by derived classes (including the Bedroom, Bathroom, 
Closet, Kitchen, Lounge, and Washing Room classes). Together with 
those classes, the game will offer the user options to search the 
room for valuable items, walk to the next room, and check player 
status.
*********************************************************************/

#include "Player.hpp"

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

#ifndef FINAL_SPACE_HPP
#define FINAL_SPACE_HPP

class Space
{
protected:
    Space* north;
    Space* east;
    Space* south;
    Space* west;
    Space* currentRoom;
public:
    Space();
    // these 3 pure virtual functions makes the Space class abstract and not instantiable
    // functions are intended to be overwritten by derived non-abstract classes e.g. Bedroom and Bathroom
    virtual void spaceMenu(Player&, Space* house[][3]) = 0;
    virtual void moveRoom(Player&, Space* house[][3]) = 0;
    virtual void exploreRoom(Player&, Space* house[][3]) = 0;
    void printMap();
    int validInput(int);
    void checkInventory(Player&);
    void searchRoom(Player&, int);
    void setCurrentRoom(Space*);
    Space* getCurrentRoom();
};
#endif
