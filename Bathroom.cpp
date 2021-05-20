

#include "Bathroom.hpp"

Bathroom::Bathroom()
{
    south = nullptr;
    east = nullptr;
    north = nullptr;
    west = nullptr;
}

void Bathroom::spaceMenu(Player& p, Space* house[][3])
{
    // if the player is still under 101 steps and doesn't have both socks, continue game
    // if the player wins with a last search (5 steps), that's ok
    if(p.getSteps() < 96 && !p.sockCheck()) {
        cout << "CURRENT STEP COUNT: " << p.getSteps() << endl;
        cout << "You are in the Bathroom. Options:" << endl;
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

void Bathroom::exploreRoom(Player& p, Space* house[][3])
{
    // if the player is still under 101 steps and doesn't have both socks, continue game
    if(p.getSteps() < 96 && !p.sockCheck()) {
        cout << "CURRENT STEP COUNT: " << p.getSteps() << endl;
        cout << "You are exploring the Bathroom. Options: " << endl;
        cout << "1. Search in clothes hamper" << endl;
        cout << "2. Walk to another room" << endl;
        cout << "3. Return to room menu" << endl;

        // collect and validate user choice
        int n = validInput(3);

        if (n == 1) {
            cout << "You walk 5 steps over to search the clothes hamper." << endl << endl;
            p.addSteps(5);
            // note: bathroom clothes hamper is #8 on locations list (see design document)
            // searchRoom function will search if any of the items have been randomly placed at #8
            searchRoom(p, 8);
            // return to exploreRoom menu
            exploreRoom(p, house);
        }

        if (n == 2) {
            moveRoom(p, house);
        }

        if (n == 3) {
            // return to first room menu
            spaceMenu(p, house);
        }
    }
}

void Bathroom::moveRoom(Player& p, Space* house[][3])
{
    // setting pointers to adjoining rooms
    north = house[0][0];
    east = house[1][1];
    west = nullptr;
    south = nullptr;

    cout << "Here are the rooms next to the Bathroom. Where would you like to go next?" << endl;
    cout << "1. Bedroom (north)" << endl;
    cout << "2. Lounge (east)" << endl;

    // collecting and validating user input
    int c = validInput(2);

    // if user chooses 1, then reset currentRoom pointer to north (ie. the bedroom)
    if(c == 1)
    {
        p.addSteps(10);
        cout << "You walk 10 steps to the next room." << endl << endl;
        setCurrentRoom(north);
        currentRoom->spaceMenu(p, house);
    }

    // if user chooses 2, then reset currentRoom pointer to east (ie. lounge)
    if(c == 2)
    {
        p.addSteps(10);
        cout << "You walk 10 steps to the next room." << endl << endl;
        setCurrentRoom(east);
        currentRoom->spaceMenu(p, house);
    }
}
