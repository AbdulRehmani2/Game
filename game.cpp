#include <iostream>
#include <windows.h>

using namespace std;

void printMaze();
void gotoxy(int x, int y);
void clear(int x, int y, char previousChar);
void clearP(int x, int y);
void showGhost(int x, int y);
char getCharAtxy(short int x, short int y);
void lose();

int main() {
    system("cls");
    printMaze();
    int x = 5;
    int y = 3;
    int gx = 5;
    int gy = 15;
    int gx2 = 35;
    int gy2 = 6;
    int score = 0;
    char previousChar = ' ';
    string direction = "right";
    string direction2 = "up";
    char nextLocation;
    gotoxy(x, y);
    cout << "P";
    showGhost(gx, gy);
    showGhost(gx2, gy2);
    while (true) {
        gotoxy(2, 24);
        cout << "Score : " << score;
        if (GetAsyncKeyState(VK_UP)) {
            char nextLocation = getCharAtxy(x, y - 1);
            if (nextLocation == ' ' || nextLocation == '.') {
                if (nextLocation == '.') {
                    score += 1;
                }
                clearP(x, y);
                gotoxy(x, y - 1);
                cout << "P";
                y -= 1;
            }
        } else if (GetAsyncKeyState(VK_DOWN)) {
            char nextLocation = getCharAtxy(x, y + 1);
            if (nextLocation == ' ' || nextLocation == '.') {
                if (nextLocation == '.') {
                    score += 1;
                }
                clearP(x, y);
                gotoxy(x, y + 1);
                cout << "P";
                y += 1;
            }
        } else if (GetAsyncKeyState(VK_LEFT)) {
            char nextLocation = getCharAtxy(x - 1, y);
            if (nextLocation == ' ' || nextLocation == '.') {
                if (nextLocation == '.') {
                    score += 1;
                }
                clearP(x, y);
                gotoxy(x - 1, y);
                cout << "P";
                x -= 1;
            }
        } else if (GetAsyncKeyState(VK_RIGHT)) {
            char nextLocation = getCharAtxy(x + 1, y);
            if (nextLocation == ' ' || nextLocation == '.') {
                if (nextLocation == '.') {
                    score += 1;
                }
                clearP(x, y);
                gotoxy(x + 1, y);
                cout << "P";
                x += 1;
            }
        }
        if (direction == "right") {
            nextLocation = getCharAtxy(gx + 1, gy);
            if (nextLocation != ' ' && nextLocation != '.') {
                direction = "left";
            } else if (nextLocation == ' ' || nextLocation == '.') {
                clear(gx, gy, previousChar);
                gx = gx + 1;
                previousChar = nextLocation;
                showGhost(gx, gy);
            }
            if (nextLocation == 'P') {
                lose();
            }

        } else if (direction == "left") {
            nextLocation = getCharAtxy(gx - 1, gy);
            if (nextLocation != ' ' && nextLocation != '.') {
                direction = "right";
            } else if (nextLocation == ' ' || nextLocation == '.') {
                clear(gx, gy, previousChar);
                gx = gx - 1;
                previousChar = nextLocation;
                showGhost(gx, gy);
            }
            if (nextLocation == 'P') {
                lose();
            }
        }
        if (direction2 == "up") {
            nextLocation = getCharAtxy(gx2, gy2 - 1);
            if (nextLocation != ' ' && nextLocation != '.') {
                direction2 = "down";
            } else if (nextLocation == ' ' || nextLocation == '.') {
                clear(gx2, gy2, previousChar);
                gy2 = gy2 - 1;
                previousChar = nextLocation;
                showGhost(gx2, gy2);
            }
            if (nextLocation == 'P') {
                lose();
            }

        } else if (direction2 == "down") {
            nextLocation = getCharAtxy(gx2, gy2 + 1);
            if (nextLocation != ' ' && nextLocation != '.') {
                direction2 = "up";
            } else if (nextLocation == ' ' || nextLocation == '.') {
                clear(gx2, gy2, previousChar);
                gy2 = gy2 + 1;
                previousChar = nextLocation;
                showGhost(gx2, gy2);
            }
            if (nextLocation == 'P') {
                lose();
            }

        }
        if (score == 375) {
            system("cls");
            cout << "Game Over";
            Sleep(2000);
            exit(0);
        }
        Sleep(100);
    }
}

void printMaze() {
    cout << "######################################################################" << endl;
    cout << "||.. .....................................................  ......  ||" << endl;
    cout << "||.. %%%%%%%%%%%%%%%%        ...     %%%%%%%%%%%%%%  |%|..   %%%%   ||" << endl;
    cout << "||..        |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||" << endl;
    cout << "||..        |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||" << endl;
    cout << "||..        %%%%%%%%% . . |%|...     %%%%%%%%%%%%%%     ..  %%%%.   ||" << endl;
    cout << "||..       |%|        . . |%|...    ............... |%| ..      .   ||" << endl;
    cout << "||..       %%%%%%%%%%%. . |%|...    %%%%%%%%%%%%    |%| ..  %%%%.   ||" << endl;
    cout << "||..               |%|.             |%|......       |%| ..   |%|.   ||" << endl;
    cout << "||..     ......... |%|.             |%|......|%|        ..   |%|.   ||" << endl;
    cout << "||..|%|  |%|%%%|%|.|%|. |%|            ......|%|        ..|%||%|.   ||" << endl;
    cout << "||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|         .|%|.      ||" << endl;
    cout << "||..|%|  |%|   |%|..           ...|%|     %%%%%%        . |%|.      ||" << endl;
    cout << "||..|%|            .           ...|%|               |%| ..|%|.      ||" << endl;
    cout << "||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||" << endl;
    cout << "||...............................................   |%| ..........  ||" << endl;
    cout << "||   ............................................          .......  ||" << endl;
    cout << "||..|%|  |%|   |%|..   %%%%%%%%%%%%%  .......|%|    |%| ..|%|.      ||" << endl;
    cout << "||..|%|  |%|   |%|..          ...|%|      %%%%%%    |%| ..|%|.      ||" << endl;
    cout << "||..|%|            .          ...|%|                |%| ..|%|.      ||" << endl;
    cout << "||..|%|  %%%%%%%%%%%%%%       ...|%|%%%%%%%%%%%     |%| ..|%|%%%%%% ||" << endl;
    cout << "||...............................................   |%| ........... ||" << endl;
    cout << "||  .............................................       ........... ||" << endl;
    cout << "######################################################################" << endl;
}


void gotoxy(int x, int y) {
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void clear(int x, int y, char previousChar) {
    gotoxy(x, y);
    cout << previousChar;
}

void clearP(int x, int y) {
    gotoxy(x, y);
    cout << ' ';
}

void showGhost(int x, int y) {
    gotoxy(x, y);
    cout << "G";
}

char getCharAtxy(short int x, short int y) {
    CHAR_INFO ci;
    COORD xy = { 0, 0 };
    SMALL_RECT rect = { x, y, x ,y };
    COORD coordBuffSize;
    coordBuffSize.X = 1;
    coordBuffSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBuffSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void lose() {
    system("cls");
    cout << "You lose";
    Sleep(2000);
    exit(0);
}