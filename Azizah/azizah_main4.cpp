// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT9L 
// Names: AZIZAH GITA CAHYANI | BALQIS AFIQAH BINTI AHMAD FAHMI | UZMA FAQIHAH BINTI AZHAN 
// IDs: 1221302491 | 1211103066 | 1211104623 
// Emails: 1221302491@student.mmu.edu.my | 1211103066@student.mmu.edu.my | 1211104623@student.mmu.edu.my
// Phones: 011-2304 4990 | 011-6937 2428 | 011-6272 5225
// ********************************************************* 

// g++ pf\*.cpp testing2.cpp -DDEMO

#include "pf/helper.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <SDL2/SDL.h>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

class GameBoard
{
private:
    vector<vector<char>> board; // convention to put trailing underscore
    vector<vector<char>> trail; // to store the trail
    int row_, colm_ ;     // to indicate private data

public:
    void init(int rows, int colms);
    void display();
    void displaysettings(int rows, int col, int zombie);
    void charattributes(int z);
    void setObject(int col, int row, char alien);
    char commands(int rows, int colms, int zombies);
    void resetAlien(int& alienRow, int& alienCol);
};

//uzma&azizah
void GameBoard::setObject(int col, int row, char alien)
{
    //check the posisition is not a trail
    if (board[colm_ - row][col - 1] != '.')
    {
        trail[colm_ - row][col - 1] = board[colm_ - row][col - 1];
    }

    board[colm_ - row][col - 1] = alien;
}

//azizah
void GameBoard::resetAlien(int& alienRow, int& alienCol)
{
    //random position on the board game
    int newRow, newCol;
    do
    {
        newRow = rand() % row_ + 1;
        newCol = rand() % colm_ + 1;
    } 
    while (board[colm_ -newRow][newCol - 1] == '.');

    // reset alien position 
    board[colm_ - alienRow][alienCol - 1] = trail[colm_ - alienRow][alienCol - 1];
    trail[colm_ - alienRow][alienCol - 1] = '.';
    alienRow = newRow;
    alienCol = newCol;
    board[colm_ - alienRow][alienCol - 1] = 'A';
    trail[colm_ - alienRow][alienCol - 1] = 'A';
}

//azizah
void displaysettings(int row, int column, int zombie)
{

    cout << "Number of columns : " << row << endl;
    cout << "Number of rows : " << column << endl;
    cout << "Number of Zombie(s) : " << zombie << endl;
}

//uzma
void charattributes(int z) 
{
    int life[] = {50, 100, 100, 150, 150, 200, 250, 300};

    int zombattack[] = {5, 10, 10, 15, 20, 25, 30};

    int range[] = {1, 2, 3, 4, 5};

    int alienlife = 100;
    int alienattack = 0;

    cout << " Alien    : Life " << alienlife << ", Attack " << alienattack << endl;
    for (int w = 0; w < z; ++w)
    {
        int objlife = rand() % 8;
        int objzomatt = rand() % 7;
        int objrange = rand() % 5;
        cout << " Zombie " << w + 1 << " : Life " << life[objlife] << ", Attack " << zombattack[objzomatt] << ", Range " << range[objrange] << endl;
    }
}

//azizah
void displayboard(int row_, int colm_)
{
    GameBoard gameboard;
    gameboard.init(row_, colm_);
    gameboard.display();
}

//uzma & azizah
void gamesettings(int rows, int col, int zombie)
{
    char letter;
    cout << "Default Game Settings" << endl;
    cout << "---------------------" << endl;
    cout << "Number of columns -> " << rows << endl;
    cout << "Number of rows -> " << col << endl;
    cout << "Number of zombies -> " << zombie << endl;
    cout << endl;
    cout << "Do you want to change the game settings? (y/n) -> ";
    cin >> letter;
    letter = tolower(letter);
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
        {
            cout << endl;
            cout << endl;
            cout << "New Game Settings" << endl;
            cout << "---------------------" << endl;
            displaysettings(rows, col, zombie);
            pf::Pause();
            pf::ClearScreen();
            displayboard(rows, col);
            charattributes(zombie);
        }
    }
    else if (letter == 'n')
    {
        cout << "you are not changing the default game settings." << endl;
        cout << endl;
        cout << endl;
        pf::Pause();
        pf::ClearScreen();
        displayboard(rows, col);
        charattributes(zombie);
    }
    else
    {
        cout << "Please enter either letter 'y' or 'n' only. " << endl;
        gamesettings(rows, col, zombie);
    }
}

//uzma
char GameBoard::commands(int rows, int colms, int zombies)
{
    GameBoard gameboard;
    
    string commandup = "up";
    string commanddown = "down";
    string commandright = "right";
    string commandleft = "left";
    string commandhelp = "help";
    string commandsave = "save";
    string commandload = "load";
    string commandquit = "quit";
    string usercommand;
    cout << endl;
    cout << "enter command : ";
    cin >> usercommand ;

    if (commandup == usercommand)
    {
        pf::ClearScreen();
        gameboard.display();
        commands(rows, colms, zombies);
    }
    else if (commanddown == usercommand)
    {
        pf::ClearScreen();
        gameboard.display();
        commands(rows, colms, zombies);
    }
    else if (commandright == usercommand)
    {
        pf::ClearScreen();
        gameboard.display();
        commands(rows, colms, zombies);
    }
    else if (commandleft == usercommand)
    {
        pf::ClearScreen();
        gameboard.display();
        commands(rows, colms, zombies);
    }
    else if (commandhelp == usercommand)
    {
        cout << endl;
        cout << "EVERYTHING MUST BE WRITTEN IN LOWER-CASE LETTERS" << endl;
        cout << "to move up => up" << endl;
        cout << "to move down => down" << endl;
        cout << "to move to the right => right" << endl;
        cout << "to move to the left => left" << endl;
        cout << "to switch direction of arrows => arrow" << endl;
        cout << "to save the current game => save" << endl;
        cout << "to load a game => load" << endl;
        cout << "to quit the current game => quit" << endl;
        commands(rows, colms, zombies);
    }
    else if (commandsave == usercommand) //NOT YET DONE
    {
        string filename;
        cout << "Enter a file name to save this game: " ;
        cin >> filename;
        ofstream FileName(filename);
        commands(rows, colms, zombies);
    }
    else if (commandload == usercommand) //NOT YET DONE
    {
        string textinfile;
        cout << "Enter the file name that u want to load: " ;
        string filename;
        cin >> filename;
        ifstream ReadFile(filename);
        while (getline (ReadFile, textinfile))
        {
            cout << textinfile;
        }
        commands(rows, colms, zombies);
    }
    else
    {
        char letter ;
        cout << "Are you sure you want to quit this game? (y/n): ";
        cin >> letter;
        letter = tolower(letter);
        if (letter == 'y')
        {
            cout << "Goodbye !!" << endl;
            return true;
        }
        else if (letter == 'n')
        {
            commands(rows, colms, zombies);
        }
        else
        {
            cout << "Please enter either letter 'y' or 'n' only. " << endl;
            commands(rows, colms, zombies);
        }
    }
    return 0;
}

//azizah & uzma
void GameBoard::init(int rows, int colms)
{
    row_ = rows;
    colm_ = colms;
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', 'v', '^', '<', '>', 'h', 'p', 'r', 'E'};
    char alien [] = {'A'};
    int NoOfobjects = 14;
    board.resize(colm_); // for create row
    for (int i = 0; i < colm_; ++i)
    {
        board[i].resize(row_); // resize each row
    }
    for (int i = 0; i < colms; ++i) // put random characters into vectors array
    {
        for (int j = 0; j < row_; ++j)
        {
            int objNo = rand() % NoOfobjects;
            board[i][j] = objects[objNo];
        }
    }
    board[(colm_ - 1)/2][(row_ - 1)/2] = alien[0]; //to put alien in the middle of gameboard
}

//azizah
void GameBoard::display() 
{
    cout << "  .: Alien vs Zombie :." << endl;
    cout << endl;

    for (int i = 0; i < colm_; ++i) // for each row
    {
        cout << "  "; // display upper border of the row
        for (int j = 0; j < row_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        cout << setw(2) << (colm_ - i); // display row number

        for (int j = 0; j < row_; ++j) // display cell content and border of each column
        {
                cout << "|" << board[i][j];  
        }
        cout << "|" << endl;
    }

    cout << "  ";
    for (int j = 0; j < row_; ++j)// display lower border of the last row
    {
        cout << "+-";
    }
    cout << "+" << endl;

    cout << "  ";
    for (int j = 0; j < row_; ++j)// display column number
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


//uzma || NOT YET DONE
/*void boardobjects()
{
    // if object = 'h'
    int alienlife = 100 ;
        if (alienlife <=100)
        {
            cout << "Alien finds a health pack." << endl << "Alien's life is increased by 20." << endl;
            int newlife;
            newlife = alienlife + 20;
            while (newlife > 100)
            {
                newlife= newlife-5;
            }
            cout << newlife;
        }

    // if object = 'p'

    // if object = 'r'
        for (int m = 0; m < 1; ++m)
        {
            char object[] = {'h', 'p', 'E', ' '};
            int randnum = rand() % 4;
            object[randnum];
            boardobjects();
        }
    
    // E-> attack all zombies

    // if object = ' '
    cout << "Alien found a space." << endl;
}*/

//movw the alien

struct alien 
{
  int x;
  int y;
};

std::vector<alien> components;

void handleInput()
{
     cout << "Enter a command to change alien position";
     char oper;
     switch (oper)
     {
        case 'up':
      // Move the components up
      for (alien& component : components) {
        component.y--;
        }
      break;
    case 'left':
      // Move the components left
      for (alien& component : components) {
        component.x--;
      }
      break;
    case 'down':
      // Move the components down
      for (alien& component : components) {
        component.y++;
      }
      break;
    case 'right':
      // Move the components right
      for (alien& component : components) {
        component.x++;
      }
      break;
     }
}

void render()
 {
  for (const alien& component : components) {
    std::cout << "Component at (" << component.x << ", " << component.y << ")\n";
  }
}

// change arrow direction in gameboard
void main() 
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Arrow Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Surface* arrow_surface = SDL_LoadBMP("arrow.bmp");
    SDL_Texture* arrow_texture = SDL_CreateTextureFromSurface(renderer, arrow_surface);
    SDL_FreeSurface(arrow_surface);

    SDL_Rect arrow_rect = {100, 100, 50, 25};
    int arrow_rotation = 0;

    bool quit = false;
    cout << "Switch direction of arrows" << endl;
    cout << "a key = left" << endl;
    cout << "d key = right" << endl;
    cout << "w key = up" << endl;
    cout << "s key = down" << endl;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_LEFT 'a':
                            arrow_rotation = 180;
                            break;
                        case SDLK_RIGHT 'd':
                            arrow_rotation = 0;
                            break;
                        case SDLK_UP 'w':
                            arrow_rotation = 270;
                            break;
                        case SDLK_DOWN 's':
                            arrow_rotation = 90;
                            break;
                    }
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_RenderCopyEx(renderer, arrow_texture, NULL, &arrow_rect, arrow_rotation, NULL, SDL_FLIP_NONE);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(arrow_texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//to move the zombie
void movezombie() // NOT YET DONE
{
    char entah;
    char moves[] = {'^','v','<','>'};
    int randnum2 = rand() % 4;
    entah = moves[randnum2];
    switch (entah) {
        case '^' :
            //move zombie up (col+1)
            break;
        case 'v' :
            //move zombie down (col-1)
            break;
        case '>' :
            //move zombie to the right (row-1)
            break;
        case '<' :
            //move zombie to the left (row+1)
            break;
    }
}

int main()
{
    GameBoard gameboard;
    pf::ClearScreen();
    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl;
    pf::Pause();
    pf::ClearScreen();
    srand(time(NULL));
    int rows = 15;
    int col = 5;
    int zombie = 1;
    gamesettings(rows, col, zombie);
    gameboard.commands(rows, col, zombie);
    components.push_back({0, 0});
    while (true)
    {
    handleInput();
    render();
    }
    return 0;
    /*cout << "Enter a file name for this new game: ";
    string filename;
    cin >> filename;
    ofstream FileName();
    FileName << gamesettings(rows, col, zombie) << commands() ;*/
    //movezombie();
}