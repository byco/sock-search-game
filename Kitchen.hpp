/*********************************************************************
** Program Name: Sock Search Game (CS162 Final Project)
** Author: Becky Chao
** Date: 3/18/18
** Description: This is the header file for the Kitchen class and creates
a simulation of a Kitchen (derived from the Space class), with options
to search the room for valuable items, walk to the next room, and check
player status.
*********************************************************************/

#include "Space.hpp"

#ifndef FINAL_Kitchen_HPP
#define FINAL_Kitchen_HPP

class Kitchen : public Space {
public:
    Kitchen();
    virtual void spaceMenu(Player&, Space* house[][3]);
    virtual void moveRoom(Player&, Space* house[][3]);
    virtual void exploreRoom(Player&, Space* house[][3]);
};


#endif
