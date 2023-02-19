#include "pf/helper.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

class GameBoard
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int row_, column_;         // to indicate private data

public:
    GameBoard(int row, int column);
    void init(int rows, int column);
    void display(int row_, int column_);
};

GameBoard::GameBoard(int row, int column)
{
    init(row, column);
}

void GameBoard::init(int row, int column)
{
    row_ = row;
    column_ = column;
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', 'v', '^', '<', '>', 'h', 'p', 'r', 'E'};
    int NoOfobjects = 14;
    map_.resize(column_); // for create row
    for (int i = 0; i < column_; ++i)
    {
        map_[i].resize(row_); // rezise each row
    }
    for (int i = 0; i < column; ++i) // put random characters into vectors array
    {
        for (int j = 0; j < row_; ++j)
        {
            int objNo = rand() % NoOfobjects;
            map_[i][j] = objects[objNo];
        }
        // set the center of the board to 'A'
        map_[(column_ + 1) / 2][(row_ + 1) / 2] = 'A';
    }
}

void GameBoard::display(int row_, int column_)
{
    cout << "   .: Alien vs Zombie :." << endl;
    cout << endl;

    for (int i = 0; i < column_; ++i) // for each row
    {
        cout << "  "; // display upper border of the row
        for (int j = 0; j < row_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        // display row number
        cout << setw(2) << (column_ - i);

        // display cell content and border of each column
        for (int j = 0; j < row_; ++j)
        {
            {
                cout << "|" << map_[i][j];
            }
        }
        cout << "|" << endl;
    }
    // display column number
    cout << "  ";
    for (int j = 0; j < row_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < row_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl;
    cout << endl;
}

int main()
{
    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl;
    pf::Pause();
    pf::ClearScreen();
}
