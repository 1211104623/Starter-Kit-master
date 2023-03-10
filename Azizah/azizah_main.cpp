#include "pf/helper.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

//g++ pf\*.cpp azizah_main.cpp -DDEMO

class GameBoard
{
private:
    vector<vector<char>> board; // convention to put trailing underscore
    int row_, colm_, zomb_;     // to indicate private data

public:
    GameBoard(int rows = 199, int colms = 199);
    void init(int rows, int colms);
    void display(int row_, int colm_);
    void displaysettings(int rows,int col,int zombie);
    void charattributes(int z);
};

GameBoard::GameBoard(int rows, int colms)
{
    init(rows, colms);
}

void displaysettings(int row, int column, int zombie)
{

    cout << "Number of columns : " << row << endl;
    cout << "Number of rows : " << column << endl;
    cout << "Number of Zombie(s) : " << zombie << endl;
}

void charattributes(int z) //int r, int c, int z
{
    int life[] = {50, 100, 100, 150, 150, 200, 250, 300};
    int numoflife = 8;

    int zombattack[] = {5, 10, 10, 15, 20, 25, 30};
    int numofzombatt = 7;

    int range[] = {1, 2, 3, 4, 5};
    int numofrange = 5;

    cout << "Alien    : Life 100 , Attack " << endl;
    for (int w = 0 ; w < z ; ++w)
    {
        int objlife = rand() % numoflife;
        int objzomatt = rand() % numofzombatt;
        int objrange = rand() % numofrange;
        cout << "Zombie " << w + 1 << " : Life " << life[objlife] << ", Attack " << zombattack[objzomatt] << ", Range " << range[objrange] << endl;
    }
}

void test1_1(int row_, int colm_)
{
    GameBoard board;
    board.display(row_, colm_);
}

int gamesettings()
{
    int rows = 15;
    int col = 5;
    int zombie = 1;
    char letter;
    cout << "Default Game Settings" << endl;
    cout << "---------------------" << endl;
    displaysettings(rows, col, zombie); //done by uzma and azizah
        cout << endl;
        cout << "Do you want to change the game settings? (y/n) -> ";
        cin >> letter;
    if (letter == 'y')
    {
        cout << endl;
        cout << "Please enter new value for number of rows, columns and zombie(s)" << endl;
        cout << "Enter number of columns : ";
        cin >> rows;
        if (rows % 2 != 0)
        {true;}
        else
        {
            cout << "Please enter ODD NUMBER for number of columns -> ";
            cin >> rows;
        }
        cout << "Enter number of rows : ";
        cin >> col;
        if (col % 2 != 0)
        {true;}
        else
        {
            cout << "Please enter ODD NUMBER for number of rows -> ";
            cin >> col;
        }
        cout << "Enter number of zombie : ";
        cin >> zombie;
        if (zombie > 10)
        {
            cout << "Please enter values NOT MORE THAN 10 for number of zombies -> ";
            cin >> zombie;
        }
        else
        cout << endl;
        cout << endl;
        cout << "New Game Settings" << endl;
        cout << "---------------------" << endl;
        displaysettings(rows, col, zombie);
        pf::Pause();
        cout << endl;
        test1_1(rows, col);
        charattributes(zombie);
        {true;}
    }
    else if (letter == 'n')
    {
        cout << "you are not changing the default game settings." << endl;
        pf::Pause();
        cout << endl;
        test1_1(rows, col);
        charattributes(zombie);
    }
    else{cout << "Please enter either letter 'y' or 'n' only. ";}
    return true;
}

void GameBoard::init(int rows, int colms)
{
    row_ = rows;
    colm_ = colms;
    char objects[] = {' ', ' ', ' ', ' ', ' ', 'v', '^', '<', '>', 'h', 'p', 'r', 'E'};
    int NoOfobjects = 13; 
    board.resize(colm_); // for create row
    for (int i = 0; i < colm_; ++i)
    {
        board[i].resize(row_); // resize each row
    }
    for (int i = 0; i < colms; ++i)// put random characters into vectors array
    {
        for (int j = 0; j < row_; ++j)
        {
            int objNo = rand() % NoOfobjects;
            board[i][j] = objects[objNo];
        }
    }
}

void GameBoard::display(int row_, int colm_) 
{
    cout << ".: Alien vs Zombie :." << endl;
    cout << endl;

    for (int i = 0; i < colm_; ++i)// for each row
    {
        cout << "  ";// display upper border of the row
        for (int j = 0; j < row_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        // display row number
        cout << setw(2) << (colm_ - i);

        // display cell content and border of each column
        for (int j = 0; j < row_; ++j)
        {
            int medrow_ = (row_ + 1)/2;
            int medcolms_ = (colm_ + 1)/2;
            if (board[medrow_][medcolms_] == board[i][j])
            {
                cout << "|" << "A";
            }
            else 
            {
                cout << "|" << board[i][j];
            }
        }
        cout << "|" << endl;
    }

    // display lower border of the last row
    cout << "  ";
    for (int j = 0; j < row_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;

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
    pf::ClearScreen();
    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl;
    pf::Pause();
    srand(time(NULL));
    gamesettings();
}