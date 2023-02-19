#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int ROWS = 5;
const int COLS = 5;
char board[ROWS][COLS];

void init_board()
{
    memset(board, '.', sizeof(board));
}

void print_board()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

struct zombie
{
    int x;
    int y;
};

std::vector<zombie> components;

void handleInput()
{
    char input = getchar();
    switch (input)
    {
    case 'w':
        // Move the components up
        for (zombie &component : components)
        {
            component.y--;
        }
        break;
    case 'a':
        // Move the components left
        for (zombie &component : components)
        {
            component.x--;
        }
        break;
    case 's':
        // Move the components down
        for (zombie &component : components)
        {
            component.y++;
        }
        break;
    case 'd':
        // Move the components right
        for (zombie &component : components)
        {
            component.x++;
        }
        break;
    }
}

void render()
{
    for (const zombie &component : components)
    {
        std::cout << "Component at (" << component.x << ", " << component.y << ")\n";
    }
}

int main()
{
    init_board();
    print_board();
    components.push_back({0, 0});
    while (true)
    {
        handleInput();
        render();
    }
    return 0;
}