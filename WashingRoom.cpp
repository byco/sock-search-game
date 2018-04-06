/*********************************************************************
** Program Name: Sock Search Game (CS162 Final Project)
** Author: Becky Chao
** Date: 3/18/18
** Description: This file defines the Washing Room class and creates
a simulation of a Washing Room (derived from the Space class), with options
to search the room for valuable items, walk to the next room, and check
player status.
*********************************************************************/

#include "WashingRoom.hpp"

WashingRoom::WashingRoom()
{
    south = nullptr;
    east = nullptr;
    north = nullptr;
    west = nullptr;
}

void WashingRoom::spaceMenu(Player& p, Space* house[][3])
{
    // if the user is under 101 steps and doesn't have both socks, continue game
    if(p.getSteps() < 101 && !p.sockCheck()) {
        cout << "CURRENT STEP COUNT: " << p.getSteps() << endl;
        cout << "You are in the Washing Room. Options:" << endl;
        cout << "1. Explore room" << endl;
        cout << "2. Walk to next room" << endl;
        cout << "3. Print house map" << endl;
        cout << "4. Check inventory" << endl;

        int n = validInput(4);

        if (n == 1) {
            exploreRoom(p, house);
        }

        if (n == 2) {
            moveRoom(p, house);
        }

        if (n == 3) {
            printMap();
            // return to this menu after printing map
            spaceMenu(p, house);
        }

        if (n == 4) {
            checkInventory(p);
            // return to this menu after print inventory
            spaceMenu(p, house);
        }
    }
}

void WashingRoom::exploreRoom(Player& p, Space* house[][3])
{
    // if the user is under 101 steps and doesn't have both socks, continue game
    if(p.getSteps() < 101 && !p.sockCheck()) {
        cout << "CURRENT STEP COUNT: " << p.getSteps() << endl;
        cout << "You are exploring the Washing Room. Options: " << endl;
        cout << "1. Search washing machine" << endl;
        cout << "2. Search dryer" << endl;
        cout << "3. Search floor" << endl;
        cout << "4. Walk to another room" << endl;
        cout << "5. Return to room menu" << endl;

        int n = validInput(5);

        if (n == 1) {
            cout << "You walk 5 steps over to search the washing machine." << endl << endl;
            p.addSteps(5);
            // note that washing machine is #10 on locations list (see design doc)
            searchRoom(p, 10);
            exploreRoom(p, house);
        }

        if (n == 2) {
            cout << "You walk 5 steps over to search the dryer." << endl << endl;
            p.addSteps(5);
            // note that dryer is #11 on locations list (see design doc)
            searchRoom(p, 11);
            exploreRoom(p, house);
        }

        if (n == 3) {
            cout << "You walk 5 steps over to search the washing room floor." << endl << endl;
            p.addSteps(5);
            // note that washing room floor is #12 on locations list (see design doc)
            searchRoom(p, 12);
            exploreRoom(p, house);
        }

        if (n == 4) {
            moveRoom(p, house);
        }

        if (n == 5) {
            spaceMenu(p, house);
        }
    }
}

void WashingRoom::moveRoom(Player& p, Space* house[][3])
{
    // reset pointers to adjoining rooms
    south = house[1][2];
    north = nullptr;
    west = nullptr;
    east = nullptr;

    cout << "Here are the rooms next to the Washing Room. Where would you like to go next?" << endl;
    cout << "1. Kitchen (south)" << endl;

    int c = validInput(1);

    // if the user chooses 1, then reset currentRoom using south pointer and go to kitchen menu
    if(c == 1)
    {
        cout << "You walk 10 steps to the next room." << endl << endl;
        p.addSteps(10);
        setCurrentRoom(south);
        currentRoom->spaceMenu(p, house);
    }
}