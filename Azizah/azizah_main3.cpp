#include "pf/helper.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

// g++ pf\*.cpp azizah_main2.cpp -DDEMO

class GameBoard
{
private:
    vector<vector<char>> map; // convention to put trailing underscore
    int row_, column_;        // to indicate private data

public:
    GameBoard(int row = 13, int column = 5);
    void init(int rows, int column);
    void display() const;
    void displaysettings(int row, int column, int zombie);
    void charattributes(int z);
   // int getRow() const;
   // int getColumn() const;
};
//int GameBoard::getRow() const
//{
//    return row_; // row  is local variable
//}
//int GameBoard::getColumn() const
//{
//    return column_;
//} 

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
    map.resize(column_); // to create row
    for (int i = 0; i < column_; ++i)
    {
        map[i].resize(row_); // rezsize each row
    }
    for (int i = 0; i < column; ++i) // put random characters into vectors array
    {
        for (int j = 0; j < row_; ++j)
        {
            int objNo = rand() % NoOfobjects;
            map[i][j] = objects[objNo];
        }
        // set the center of the board to 'A'
        map[(column_ + 1) / 3][(row_ - 1) / 2] = 'A';
    }
}

void GameBoard::display() const
{
    cout << "  .: Alien vs Zombie :." << endl;
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
                cout << "|" << map[i][j];
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
void test1_1()
{
    GameBoard map;
    map.display();
}

void charattributes(int z)
{
    int life[] = {50, 100, 100 , 150, 150, 200, 250, 300};
    int numoflife = 8;

    int zombattack[] = {5, 10, 10, 15, 20, 25, 30};
    int numofzombatt = 7;

    int range[] = {1, 2, 3, 4, 5};
    int numofrange = 5;

    int alienlife = 100;
    int alienattack = 0;

    cout << "Alien    : Life " << alienlife << ", Attack " << alienattack << endl;
    for (int w = 0; w < z; ++w) 
    {
        int objlife = rand() % numoflife;
        int objzomatt = rand () % numofzombatt;
        int objrange = rand () % numofrange;
        cout << "Zombie " << w + 1 << " :  Life " << life[objlife] << ", Attack " << zombattack[objzomatt] << ", Range " << range[objrange] << endl;
    }
}
void displaysettings(int row, int column, int zombie)
{
    cout << "Number of columns : " << row << endl;
    cout << "Number of rows : " << column << endl;
    cout << "Number of Zombie(s) : " << zombie << endl;
}

int gamesettings()
{
    int row = 13;
    int column = 5;
    int zombie = 1;
    char letter;
    cout << "Default Game Settings" << endl;
    cout << "---------------------" << endl;
    displaysettings(row, column, zombie);
    cout << endl;
    cout << "Do you want to change the game settings? (y/n) -> " ;
    cin >> letter;
    if (letter == 'y')
    {
        cout << endl;
        cout << "Please enter new value for number of rows, columns and zombie(s)" << endl;
        cout << "Enter number of columns : ";
        cin >> row;
        if (row % 2 != 0)
        {
            true;
        }
        else
        {
            cout << "Please enter ODD NUMBER for number of columns -> ";
            cin >> row;
        }
        cout << "Enter number of rows : ";
        cin >> column;
        if (column % 2 != 0)
        {
            true;
        }
        else
        {
            cout << "Please enter ODD NUMBER for number of rows -> ";
            cin >> column;
        }
        cout << "Enter number of zombie : ";
        cin >> zombie;
        if (zombie > 10)
        {
            cout << "Please enter value NOT MORE THAN 10 for number of zombies -> ";
            cin >> zombie;
        }
        else 
            cout << endl;
            cout << endl;
            cout << "New Game Settings" << endl;
            cout << "----------------- " << endl;
            displaysettings(row, column, zombie);
            pf::Pause();
            pf::ClearScreen();
            test1_1();
            charattributes (zombie);
        {
            true;
        }
    }
    else if (letter == 'n' )
    {
        cout << "you are not changing the default game settings." << endl;
        cout << endl;
        cout << endl;
        pf::Pause();
        pf::ClearScreen();
        test1_1();
        charattributes(zombie);
    }
    else 
    {
        cout << "Please enter either letter 'y' or 'n' only. ";
    }
    return true;
}
int main()
{
    pf::ClearScreen();
    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl;
    pf::Pause();
    pf::ClearScreen();
    test1_1();
    srand(time(NULL));
    gamesettings();
}