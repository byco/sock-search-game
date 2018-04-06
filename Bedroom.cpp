/*********************************************************************
** Program Name: Sock Search Game (CS162 Final Project)
** Author: Becky Chao
** Date: 3/18/18
** Description: This file defines the Bedroom class and creates
a simulation of a Bedroom (derived from the Space class), with options
to search the room for valuable items, walk to the next room, and check
player status.
*********************************************************************/

#include "Bedroom.hpp"

Bedroom::Bedroom()
{
    south = nullptr;
    east = nullptr;
    north = nullptr;
    west = nullptr;
}

void Bedroom::spaceMenu(Player& p, Space* house[][3])
{
    // if the player is still under 101 steps and doesn't have both socks, continue game
    // if the player wins with a last search (5 steps), that's ok
    if(p.getSteps() < 96 && !p.sockCheck()) {

        cout << "CURRENT STEP COUNT: " << p.getSteps() << endl;
        cout << "You are in the Bedroom. Options:" << endl;
        cout << "1. Explore room" << endl;
        cout << "2. Walk to next room" << endl;
        cout << "3. Print house map" << endl;
        cout << "4. Check inventory" << endl;

        // collect and validate user input
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

void Bedroom::exploreRoom(Player& p, Space* house[][3])
{
    // if the player is still under 101 steps and doesn't have both socks, continue game
    if(p.getSteps() < 96 && !p.sockCheck()) {
        cout << "CURRENT STEP COUNT: " << p.getSteps() << endl;
        cout << "You are exploring the Bedroom. Options: " << endl;
        cout << "1. Search under bed" << endl;
        cout << "2. Search drawer" << endl;
        cout << "3. Search floor" << endl;
        cout << "4. Walk to another room" << endl;
        cout << "5. Return to room menu" << endl;

        int n = validInput(5);

        if (n == 1) {
            cout << "You walk 5 steps over to search underneath the bed." << endl << endl;
            p.addSteps(5);
            // note that bed is #1 in locations list (see design document) 
            searchRoom(p, 1);
            exploreRoom(p, house);
        }

        if (n == 2) {
            cout << "You walk 5 steps over to search in the drawer." << endl << endl;
            p.addSteps(5);
            // note that bedroom drawer is #2 in locations list (see design document)
            searchRoom(p, 2);
            exploreRoom(p, house);
        }

        if (n == 3) {
            cout << "You walk 5 steps over to search the bedroom floor." << endl << endl;
            p.addSteps(5);
            // note that bedroom floor is #3 in locations list (see design document)
            searchRoom(p, 3);
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

void Bedroom::moveRoom(Player& p, Space* house[][3])
{
    // set pointers to adjoining rooms
    south = house[1][0];
    east = house[0][1];
    north = nullptr;
    west = nullptr;

    cout << "Here are the rooms next to the bedroom. Where would you like to go next?" << endl;
    cout << "1. Closet (east, requires key)" << endl;
    cout << "2. Bathroom (south)" << endl;

    int c = validInput(2);

    // the closet requires a key
    // if the user has key, then walk (add 10 steps), reset current room to Closet using East pointer, and go to Closet menu
    if(c == 1)
    {
        if (p.searchItem("key")) {
            cout << "You walk 10 steps to the next room." << endl << endl;
            p.addSteps(10);
            setCurrentRoom(east);
            currentRoom->spaceMenu(p, house);
        }

        // if user doesn't currrently have key, then do nothing and return the menu
        else
        {
            cout << "You don't have the key for the closet." << endl << endl;
            spaceMenu(p, house);
        }
    }

    // if the user chooses to go south (ie. to the bathroom)
    // reset currentRoom pointer using South pointer and go to Bathroom menu
    if(c == 2)
    {
        cout << "You walk 10 steps to the next room." << endl << endl;
        p.addSteps(10);
        setCurrentRoom(south);
        currentRoom->spaceMenu(p, house);
    }
}