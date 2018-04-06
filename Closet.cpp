/*********************************************************************
** Program Name: Sock Search Game (CS162 Final Project)
** Author: Becky Chao
** Date: 3/18/18
** Description: This file defines the Closet class and creates
a simulation of a Closet (derived from the Space class), with options
to search the room for valuable items, walk to the next room, and check
player status.
*********************************************************************/

#include "Closet.hpp"

Closet::Closet()
{
    south = nullptr;
    east = nullptr;
    north = nullptr;
    west = nullptr;
}

void Closet::spaceMenu(Player& p, Space* house[][3])
{
    // if the player is under 101 steps and doesn't have both socks, continue game
    if(p.getSteps() < 96 && !p.sockCheck()) {
        cout << "CURRENT STEP COUNT: " << p.getSteps() << endl;
        cout << "You are in the Closet. Options:" << endl;
        cout << "1. Explore room" << endl;
        cout << "2. Walk to next room" << endl;
        cout << "3. Print house map" << endl;
        cout << "4. Check inventory" << endl;

        // collect and validate user choice
        int n = validInput(4);

        if (n == 1) {
            exploreRoom(p, house);
        }

        if (n == 2) {
            moveRoom(p, house);
        }

        if (n == 3) {
            printMap();
            spaceMenu(p, house);
        }

        if (n == 4) {
            checkInventory(p);
            spaceMenu(p, house);
        }
    }
}

void Closet::exploreRoom(Player& p, Space* house[][3])
{
    // if the player is under 101 steps and doesn't have both socks, continue game
    if(p.getSteps() < 96 && !p.sockCheck()) {
        cout << "CURRENT STEP COUNT: " << p.getSteps() << endl;
        cout << "You are exploring the Closet. Options: " << endl;
        cout << "1. Search the closet" << endl;
        cout << "2. Walk to another room" << endl;
        cout << "3. Return to room menu" << endl;

        int n = validInput(3);

        if (n == 1) {
            cout << "You walk 5 steps over to search the closet." << endl << endl;
            p.addSteps(5);
            // note that closet is #9 on locations list (see design document)
            searchRoom(p, 9);
            exploreRoom(p, house);
        }

        if (n == 2) {
            moveRoom(p, house);
        }

        if (n == 3) {
            spaceMenu(p, house);
        }
    }
}

void Closet::moveRoom(Player& p, Space* house[][3])
{
    // reset pointers to adjoining rooms
    west = house[0][0];
    north = nullptr;
    south = nullptr;
    east = nullptr;

    cout << "Here are the rooms next to the Closet. Where would you like to go next?" << endl;
    cout << "1. Bedroom (west)" << endl;

    int c = validInput(1);

    // go to bedroom - set currentRoom pointer using west pointer and go to Bedroom menu
    if(c == 1)
    {
        cout << "You walk 10 steps to the next room." << endl << endl;
        p.addSteps(10);
        setCurrentRoom(west);
        currentRoom->spaceMenu(p, house);
    }
}