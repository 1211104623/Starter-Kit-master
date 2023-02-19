#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

int gamesettings()
{
    int rows = 15;
    int col = 5;
    int zombie = 1;
    char letter;
    cout << "Default Game Settings" << endl;
    cout << "---------------------" << endl;
    displaysettings(rows, col, zombie);
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
        {
            true;
        }
        else
        {
            cout << "Please enter ODD NUMBER for number of columns -> ";
            cin >> rows;
        }
        cout << "Enter number of rows : ";
        cin >> col;
        if (col % 2 != 0)
        {
            true;
        }
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
    }
}

//to display characters attributes
void charattributes(int z) 
{
    int life[] = {50, 100, 100, 150, 150, 200, 250, 300};
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
        int objlife = rand() % numoflife; //will randomly generate zombie's attributes
        int objzomatt = rand() % numofzombatt;
        int objrange = rand() % numofrange;
        cout << "Zombie " << w + 1 << " : Life " << life[objlife] << ", Attack " << zombattack[objzomatt] << ", Range " << range[objrange] << endl;
    }
}

//commands from user
char commands()
{
    string commandhelp = "help";
    string commandsave = "save";
    string commandload = "load";
    string commandquit = "quit";
    string usercommand;
    cout << endl;
    cout << endl;
    cout << "enter command : ";
    cin >> usercommand ;
    if (commandhelp == usercommand)
    {
        cout << endl;
        cout << endl;
        cout << "EVERYTHING MUST BE WRITTEN IN LOWER-CASE LETTERS" << endl;
        cout << "to move up => up"  << endl;
        cout << "to move down => down"  << endl;
        cout << "to move to the right => right"  << endl;
        cout << "to move to the left => left"  << endl;
        cout << "to switch direction of arrows => arrow"  << endl;
        cout << "to save the current game => save"  << endl;
        cout << "to load a game => load"  << endl;
        cout << "to quit the current game => quit"  << endl;
    }
    else if (commandsave == usercommand) //NOT YET DONE
    {
        string filename;
        cout << "Enter a file name to save this game: " ;
        cin >> filename;
        ofstream FileName(filename);
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
    }
    else if (commandquit == usercommand)
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
            commands();
        }
        else
        {
            cout << "Please enter either letter 'y' or 'n' only. " << endl;
            commands();
        }
    }
    else
    {
        cout << "Please enter either help or save";
        commands();
    }
    return true;
}