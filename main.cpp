#include <iostream>
#include <vector>
#include <string>

using namespace std;
using Strings = vector<string>;

vector<string> map = Strings{
    "####################",
    "####################",
    "####################",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    "
};

struct Coords {
    int x; // min: 0, max: 19
    int y; // min: 0, max: 9
} playerPos, lastPos, currentPos;

bool firstRound = true;

void displayMap()
{
    for (const auto& value: map) {
        cout << value << endl;
    }
}

void updateMap(Coords player, Coords ball)
{
    if (lastPos.x == ball.x && ball.y == ball.y && !firstRound) {
        return;
    }

    map[lastPos.y][lastPos.x] = ' ';
    map[ball.y][ball.x] = '*';
    map[playerPos.y][playerPos.x] = '-';
}

void initGame()
{
    lastPos.x = currentPos.x = 10;
    lastPos.y = currentPos.y = 8;

    playerPos.x = 10;
    playerPos.y = 9;
}

int main(void)
{
    initGame();
    updateMap(playerPos, currentPos);
    displayMap();

    firstRound = false;

    return 0;
}
