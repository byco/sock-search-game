/*********************************************************************
** Program Name: Sock Search Game (CS162 Final Project)
** Author: Becky Chao
** Date: 3/18/18
** Description: This file defines the Kitchen class and creates
a simulation of a Kitchen (derived from the Space class), with options
to search the room for valuable items, walk to the next room, and check
player status.
*********************************************************************/

#include "Kitchen.hpp"

Kitchen::Kitchen()
{
    south = nullptr;
    east = nullptr;
    north = nullptr;
    west = nullptr;
}

void Kitchen::spaceMenu(Player& p, Space* house[][3])
{
    // if the user is still under 101 steps and doesn't have both socks, continue game
    if(p.getSteps() < 96 && !p.sockCheck()) {
        cout << "CURRENT STEP COUNT: " << p.getSteps() << endl;
        cout << "You are in the Kitchen. Options:" << endl;
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

void Kitchen::exploreRoom(Player& p, Space* house[][3])
{
    // if the user is under 101 steps and doesn't have both socks, continue game
    if(p.getSteps() < 96 && !p.sockCheck()) {
        cout << "CURRENT STEP COUNT: " << p.getSteps() << endl;
        cout << "You are exploring the Kitchen. Options: " << endl;
        cout << "1. Search the floor" << endl;
        cout << "2. Walk to another room" << endl;
        cout << "3. Return to room menu" << endl;

        int n = validInput(3);

        if (n == 1) {
            cout << "You walk 5 steps over to search the kitchen floor." << endl << endl;
            p.addSteps(5);
            // note that kitchen floor is #7 on list of locations (see design document)
            searchRoom(p, 7);
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

void Kitchen::moveRoom(Player& p, Space* house[][3])
{
    // reset pointers to adjoining rooms
    north = house[0][2];
    west = house[1][1];
    east = nullptr;
    south = nullptr;

    cout << "Here are the rooms next to the Kitchen. Where would you like to go next?" << endl;
    cout << "1. Lounge (west)" << endl;
    cout << "2. Washing Room (north, requires flashlight)" << endl;

    int c = validInput(2);

    if(c == 1)
    {
        // if the user wants to go west to the lounge, reset currentRoom using west pointer
        // then go to lounge menu
        cout << "You walk 10 steps to the next room." << endl << endl;
        p.addSteps(10);
        setCurrentRoom(west);
        currentRoom->spaceMenu(p, house);
    }

    if(c == 2)
    {
        // washing room entry requires the flashlight
        // check if user has flashlight in inventory first
        // if so, reset currentRoom pointer using north and go to washing room menu
        if (p.searchItem("flashlight")) {
            cout << "You walk 10 steps to the next room." << endl << endl;
            p.addSteps(10);
            setCurrentRoom(north);
            currentRoom->spaceMenu(p, house);
        }

        else
        {
            // message if user doesn't have flashlight
            // can't enter washing room
            cout << "You don't have the flashlight for the washing room." << endl;
            spaceMenu(p, house);
        }
    }
}