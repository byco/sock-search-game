/*********************************************************************
** Program Name: Sock Search Game (CS162 Final Project)
** Author: Becky Chao
** Date: 3/18/18
** Description: This is the header file for the Closet class and creates
a simulation of a Closet (derived from the Space class), with options
to search the room for valuable items, walk to the next room, and check
player status.
*********************************************************************/

#include "Space.hpp"

#ifndef FINAL_Closet_HPP
#define FINAL_Closet_HPP

class Closet : public Space {
public:
    Closet();
    virtual void spaceMenu(Player&, Space* house[][3]);
    virtual void moveRoom(Player&, Space* house[][3]);
    virtual void exploreRoom(Player&, Space* house[][3]);
};


#endif
