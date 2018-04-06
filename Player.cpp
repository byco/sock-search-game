/*********************************************************************
** Program Name: Sock Search Game (CS162 Final Project)
** Author: Becky Chao
** Date: 3/18/18
** Description: This file defines the Player class, which keeps track
of player status (i.e. the number of socks collected, items in the
vector inventory, steps walked by the player) and the location of 
valuable items the player needs to collect.
*********************************************************************/

#include "Player.hpp"

Player::Player()
{
    // these variables will be reset in startGame function (under menu)
    keyLoc = 0;
    flashlightLoc = 0;
    sock1Loc = 0;
    sock2Loc = 0;
    steps = 0;
}

// add item to inventory vector
void Player::addItem(string s)
{
    // Note that it's possible to have flashlight + key + sock 1 and still need to get sock 2
    // need to drop key or flashlight to WIN

    // Check that inventory size is limited to 3 at a time
    if(inventory.size() < 3)
    {
        inventory.push_back(s);
        cout << "You grab the " << s << " and it has been added to your inventory." << endl << endl;

        // reset the locations of items picked up to 0 (they cannot be picked up again)
        if (s == "key")
        {
            setKeyLoc(0);
        }

        if (s == "flashlight")
        {
            setFlashlightLoc(0);
        }

        if (s == "sock #1")
        {
            setSock1Loc(0);
        }

        if (s == "sock #2")
        {
            setSock2Loc(0);
        }
    }

    // if user has 3 items in inventory already, give them option to remove item
    else
    {
        cout << "You're trying to pick up the " << s << "." << endl;
        cout << "But you can only hold 3 items at a time!" << endl;
        cout << "Would you like to remove an item?" << endl << endl;

        cout << "1. Yes, remove an item" << endl;
        cout << "2. No, ignore item" << endl;

        int c = validInput(2);


        if (c == 1)
        {
            removeItem();
            addItem(s);
        }

        // item will still be there if user wishes to search again (another 5 steps however)
        if (c == 2)
        {
            cout << "You decide not to pick up the " << s << "." << endl;
        }

        cout << endl;
    }
}

void Player::printItems()
{
    if(inventory.empty())
    {
        cout << "You're holding nothing..." << endl << endl;
    }

    else
    {
        // print list of items in inventory
        cout << "Items you're currently holding: " << endl;

        for(int i = 0; i < inventory.size(); i++)
        {
            // note that loop needs to start at 0, but the printed list starts at 1
            cout << i + 1 << ". " << inventory[i] << endl;
        }

        cout << endl;
    }
}

// collect and validate input
int Player::validInput(int limit)
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

void Player::removeItem()
{
    if(inventory.empty())
    {
        cout << "You're holding nothing..." << endl;
    }

    else
    {
        cout << "Choose an item to remove: " << endl;

        for(int i = 0; i < inventory.size(); i++)
        {
            cout << i + 1 << ". " << inventory[i] << endl;
        }

        int del = validInput(inventory.size());

        // note that again, i needs to start at 0, but the printed list starts at 1
        // so delete the item at del - 1
        string d = inventory[del - 1];
        inventory.erase(inventory.begin() + del - 1);
        cout << "You drop the " << d << " from your hands." << endl;
    }
}

// search item in inventory - this will be used to check for key, flashlight, and sock possession
bool Player::searchItem(string s)
{
    bool found = false;

    for(int i = 0; i < inventory.size(); i++)
    {
        if(inventory[i] == s)
        {
            found = true;
        }
    }

    return found;
}

// getter and setter functions for steps, along with key, flashlight, and sock locations
int Player::getKeyLoc()
{
    return keyLoc;
}

int Player::getFlashlightLoc()
{
    return flashlightLoc;
}

int Player::getSock1Loc()
{
    return sock1Loc;
}

int Player::getSock2Loc()
{
    return sock2Loc;
}

int Player::getSteps()
{
    return steps;
}

void Player::setKeyLoc(int i)
{
    keyLoc = i;
}

void Player::setFlashlightLoc(int i)
{
    flashlightLoc = i;
}

void Player::setSock1Loc(int i)
{
    sock1Loc = i;
}

void Player::setSock2Loc(int i)
{
    sock2Loc = i;
}

void Player::addSteps(int i)
{
    steps += i;
}

// check if player has both socks
bool Player::sockCheck()
{
    bool f1 = false;
    bool f2 = false;
    bool f3 = false;

    for(int i = 0; i < inventory.size(); i++)
    {
        if(inventory[i] == "sock #1")
        {
            // if sock #1 is in inventory, set first bool to true
            f1 = true;
        }

        if(inventory[i] == "sock #2")
        {
            // if sock #2 is in inventory, set second bool to true
            f2 = true;
        }
    }

    // both of the first sock bools must be true in order for f3 to be true
    // otherwise, return false
    if (f1 && f2)
    {
        f3 = true;
    }

    return f3;
}