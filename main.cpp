#include "Menu.hpp"

int main() {
    Space* house[2][3];
    Menu m;
    Player p;

    m.intro();
    m.startGame(p, house);
    m.deleteRooms(house);

    return 0;
}