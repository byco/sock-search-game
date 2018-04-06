/*********************************************************************
** Program Name: Sock Search Game (CS162 Final Project)
** Author: Becky Chao
** Date: 3/18/18
** Description: This is the header file for the Lounge class and creates
a simulation of a Lounge (derived from the Space class), with options
to search the room for valuable items, walk to the next room, and check
player status.
*********************************************************************/

#include "Space.hpp"

#ifndef FINAL_LOUNGE_HPP
#define FINAL_LOUNGE_HPP

class Lounge : public Space {
public:
    Lounge();
    virtual void spaceMenu(Player&, Space* house[][3]);
    virtual void moveRoom(Player&, Space* house[][3]);
    virtual void exploreRoom(Player&, Space* house[][3]);
};


#endif
