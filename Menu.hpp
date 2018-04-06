/*********************************************************************
** Program Name: Sock Search Game (CS162 Final Project)
** Author: Becky Chao
** Date: 3/18/18
** Description: This is the header file for the Menu class, which includes 
functions necessary to introduce user to game goals, randomize locations
of items that the user needs to collect, create and delete Space
objects, and print game over messages (if the user wins or loses).
*********************************************************************/

#include "Bedroom.hpp"
#include "Bathroom.hpp"
#include "Closet.hpp"
#include "Kitchen.hpp"
#include "Lounge.hpp"
#include "WashingRoom.hpp"

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

#ifndef FINAL_MENU_HPP
#define FINAL_MENU_HPP

class Menu {
public:
    void intro();
    int random8(int);
    int random12(int);
    void startGame(Player&, Space* house[][3]);
    void createRooms(Space* house[][3]);
    void deleteRooms(Space* house[][3]);
};


#endif
