/*********************************************************************
** Program Name: Sock Search Game (CS162 Final Project)
** Author: Becky Chao
** Date: 3/18/18
** Description: This file defines the Space class, which is an abstract
class with pure virtual functions intended to be overwritten by derived
classes (including the Bedroom, Bathroom, Closet, Kitchen, Lounge, and
Washing Room classes). Together with those classes, the game will 
offer the user options to search the room for valuable items, walk to 
the next room, and check player status.
*********************************************************************/

#include "Space.hpp"

Space::Space()
{
    north = nullptr;
    east = nullptr;
    south = nullptr;
    west = nullptr;
}

// print map of house for user reference
// this function can be used by derived classes
void Space::printMap()
{
    cout << "                          HOUSE MAP                             " << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "|                   |                     |                    |" << endl;
    cout << "|     Bedroom               Closet        |    Washing Room    |" << endl;
    cout << "|     (start)             (needs key)     | (needs flashlight) |" << endl;
    cout << "|                   |                     |                    |" << endl;
    cout << "|------      -------------------------------------      -------|" << endl;
    cout << "|                   |                     |                    |" << endl;
    cout << "|     Bathroom              Lounge               Kitchen       |" << endl;
    cout << "|                                                              |" << endl;
    cout << "|                   |                     |                    |" << endl;
    cout << "----------------------------------------------------------------" << endl << endl;
}

// collect and validate input
int Space::validInput(int limit)
{
    // n will be the number returned
    int n = 0;

    // s will be the user input (might be an int, might not be)
    string s;

    // check if input is an int
    bool num;

    // keep looping as long as n is over the limit, under 1, unable to be collected by cin, or not an int
    while (n > limit || n < 1 || !cin || !num) {

        // by default, set num to true
        num = true;

        // now collect user input
        getline(cin, s);

        // change string to int
        n = atoi(s.c_str());

        // check that all characters in the string are digits
        // if not, set num to false and later loop again
        for(int i = 0; i < s.length(); i++)
        {
            if(!isdigit(s[i]))
            {
                num = false;
            }
        }

        // error message before looping again to collect int
        if(n > limit || n < 1 || !cin || !num)
        {
            cout << "Please input a number between 1 and " << limit << "." << endl;
        }
    }

    return n;
}

void Space::checkInventory(Player& p)
{
    p.printItems();
}

void Space::searchRoom(Player& p, int n)
{
    // if no items are found, print message saying so
    if(p.getKeyLoc() != n && p.getFlashlightLoc() != n && p.getSock1Loc() != n && p.getSock2Loc() != n)
    {
        cout << "You found nothing but junk. Ugh, you're a mess." << endl << endl;
    }

    // if key is found, print message and add key to inventory
    if(p.getKeyLoc() == n)
    {
        cout << "You found the key!" << endl;
        p.addItem("key");
    }

    // if flashlight is found, print message and add flashlight to inventory
    if(p.getFlashlightLoc() == n)
    {
        cout << "You found the flashlight!" << endl;
        p.addItem("flashlight");
    }

    // if sock #1 is found, print message and add sock #1 to inventory
    if(p.getSock1Loc() == n)
    {
        cout << "You found sock #1!" << endl;
        p.addItem("sock #1");
    }

    // if sock #2 is found, print message and add sock #2 to inventory
    if(p.getSock2Loc() == n)
    {
        cout << "You found sock #2!" << endl;
        p.addItem("sock #2");
    }
}

// this function will be used with the directional pointers
void Space::setCurrentRoom(Space* room)
{
    currentRoom = room;
}

Space* Space::getCurrentRoom()
{
    return currentRoom;
}