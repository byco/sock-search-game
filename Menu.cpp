/*********************************************************************
** Program Name: Sock Search Game (CS162 Final Project)
** Author: Becky Chao
** Date: 3/18/18
** Description: This file defines the Menu class, which includes 
functions necessary to introduce user to game goals, randomize locations
of items that the user needs to collect, create and delete Space
objects, and print game over messages (if the user wins or loses).

ASCII sock text art from: http://www.oocities.org/spunk1111/cloth.htm
*********************************************************************/

#include "Menu.hpp"

void Menu::intro()
{
    cout << "                          GAME INTRO                            " << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "You have lost your SOCKS." << endl << endl;
    cout << "Now, before you laugh at the premise of this game, remember that" << endl;
    cout << "you have a job interview in an hour and that you absolutely need" << endl;
    cout << "your lucky socks or else wearing no socks at all with your " << endl;
    cout << "snazzy interview outfit will force you into a negative mental " << endl;
    cout << "tailspin that will result in NO job offer. OH NO!!!! :(" << endl << endl;
    cout << "Your house is messy. Your washing room's light needs to be " << endl;
    cout << "replaced; in the meantime, you need to find the flashlight so " << endl;
    cout << "you can see in there. Your crazy magpie of a housemate has " << endl;
    cout << "finally moved out, but you still need a key to access your " << endl;
    cout << "closet. You don't know where your flashlight or key is." << endl << endl;
    cout << "YOU MUST FIND YOUR SOCKS UNDER 101 STEPS OR ELSE BE FORCED" << endl;
    cout << "TO GO TO YOUR JOB INTERVIEW SOCKLESS. Good luck!" << endl;
    cout << "----------------------------------------------------------------" << endl;
}

// this function returns a random number from 1-8 (used for key and flashlight locations)
int Menu::random8(int n)
{
    srand(n + 41);

    return rand() % 8 + 1;
}

// this function returns a random number from 1-12 (used for sock #1 and sock #2 locations)
int Menu::random12(int n)
{
    srand(n + 89);

    return rand() % 12 + 1;
}

void Menu::startGame(Player& p, Space* house[][3])
{
    p.setKeyLoc(random8(time(NULL)));
    p.setFlashlightLoc(random8(random12(time(NULL) + 5467)));
    p.setSock1Loc(random12(time(NULL)));
    p.setSock2Loc(random12(random8(time(NULL) + 121)));

    // TESTING ONLY
    // NOTE: The key, flashlight, and sock locations will NOT be shown to the user
    // Generate the key and flashlight locations using the random8 function
    // Generate sock locations using the random12 function
    /*cout << "key location: " << p.getKeyLoc() << endl;
    cout << "flashlight location: " << p.getFlashlightLoc() << endl;
    cout << "sock 1 location: " << p.getSock1Loc() << endl;
    cout << "sock 2 location: " << p.getSock2Loc() << endl;
    cout << "steps: " << p.getSteps() << endl << endl;*/

    createRooms(house);
    // start in bedroom - set up currentRoom pointer
    Bedroom b;
    b.setCurrentRoom(house[0][0]);

    // go to bedroom menu
    b.getCurrentRoom()->spaceMenu(p, house);

    // losing message
    // prints if over 100 steps and doesn't have both socks
    if(!p.sockCheck()) {
        cout << "OH NO!!! NO LUCKY SOCKS FOR YOU!" << endl;
        cout << "You're out of steps and forced to leave your house sockless and in a rush..." << endl << endl;
    }

    // winning message - prints if player has both socks
    if(p.sockCheck())
    {
        cout << "You found both socks! Hooray!" << endl;
        cout << "You finished the game in " << p.getSteps() << " steps!" << endl << endl;

        cout << "                         /`-.\n";
        cout << "               /`-.     /   /\n";
        cout << "              /   /    /   /\n";
        cout << "             /   /    /  _/\n";
        cout << "            /  _/    /  / |\n";
        cout << "           /  / |  .'   \\_/\n";
        cout << "         .'   \\_/.'   .-'\n";
        cout << "       .'   .-' /_  .'\n";
        cout << "      /_  .'    \\_\\/\n";
        cout <<"      \\_\\/";
        cout << endl << endl;
    }

    cout << "            GAME OVER" << endl << endl;
}

// create rooms (ie. derived spaces objects) using pointer to array of Spaces
void Menu::createRooms(Space* house[][3])
{
    house[0][0] = new Bedroom();
    house[1][0] = new Bathroom();
    house[0][1] = new Closet();
    house[1][1] = new Lounge();
    house[0][2] = new WashingRoom();
    house[1][2] = new Kitchen();
}

// deallocate memory used to create rooms
void Menu::deleteRooms(Space* house[][3])
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            delete house[i][j];
        }
    }
}