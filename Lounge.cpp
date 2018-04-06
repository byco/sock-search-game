/*********************************************************************
** Program Name: Sock Search Game (CS162 Final Project)
** Author: Becky Chao
** Date: 3/18/18
** Description: This file defines the Lounge class and creates
a simulation of a Lounge (derived from the Space class), with options
to search the room for valuable items, walk to the next room, and check
player status.
*********************************************************************/

#include "Lounge.hpp"

Lounge::Lounge()
{
    south = nullptr;
    east = nullptr;
    north = nullptr;
    west = nullptr;
}

void Lounge::spaceMenu(Player& p, Space* house[][3])
{
    // if user has less than 101 steps and doesn't have both socks, continue game
    if(p.getSteps() < 96 && !p.sockCheck()) {
        cout << "CURRENT STEP COUNT: " << p.getSteps() << endl;
        cout << "You are in the Lounge. Options:" << endl;
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
            spaceMenu(p, house);
        }

        if (n == 4) {
            checkInventory(p);
            spaceMenu(p, house);
        }
    }
}

void Lounge::exploreRoom(Player& p, Space* house[][3])
{
    // if user is under 101 steps and doesn't have both socks, continue game
    if(p.getSteps() < 96 && !p.sockCheck()) {
        cout << "CURRENT STEP COUNT: " << p.getSteps() << endl;
        cout << "You are exploring the Lounge. Options: " << endl;
        cout << "1. Search under sofa" << endl;
        cout << "2. Search shoe shelf" << endl;
        cout << "3. Search floor" << endl;
        cout << "4. Walk to another room" << endl;
        cout << "5. Return to room menu" << endl;

        int n = validInput(5);

        if (n == 1) {
            cout << "You walk 5 steps over to search underneath the sofa." << endl << endl;
            p.addSteps(5);
            // note that lounge sofa is #4 on locations list (see design doc)
            searchRoom(p, 4);
            exploreRoom(p, house);
        }

        if (n == 2) {
            cout << "You walk 5 steps over to search the shoe shelf." << endl << endl;
            p.addSteps(5);
            // note that shoe shelf is #5 on locations list (see design doc)
            searchRoom(p, 5);
            exploreRoom(p, house);
        }

        if (n == 3) {
            cout << "You walk 5 steps over to search the lounge floor." << endl << endl;
            p.addSteps(5);
            // note that lounge floor is #6 on locations list (see design doc)
            searchRoom(p, 6);
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

void Lounge::moveRoom(Player& p, Space* house[][3])
{
    // reset pointers to adjoining rooms
    west = house[1][0];
    east = house[1][2];
    north = nullptr;
    south = nullptr;

    cout << "Here are the rooms next to the Lounge. Where would you like to go next?" << endl;
    cout << "1. Bathroom (west)" << endl;
    cout << "2. Kitchen (east)" << endl;

    int c = validInput(2);

    if(c == 1)
    {
        // add steps, reset currentRoom with west pointer and go to Bathroom menu
        cout << "You walk 10 steps to the next room." << endl << endl;
        p.addSteps(10);
        setCurrentRoom(west);
        currentRoom->spaceMenu(p, house);
    }

    if(c == 2)
    {
        // add steps, reset currentRoom with east pointer and go to kitchen menu
        cout << "You walk 10 steps to the next room." << endl << endl;
        p.addSteps(10);
        setCurrentRoom(east);
        currentRoom->spaceMenu(p, house);
    }
}