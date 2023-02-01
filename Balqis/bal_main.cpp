#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

int main()
{
    ofstream createcharacter("characters.txt");
    if (createcharacter.is_open())
    {
        cout << "ALIEN ZOMBIE!" << endl;
    }
    else
    {
        cout << "ALIEN ZOMBIE!" << endl;
    }
    int loop = 1;
    int userid = 1;
    string username;
    string usermanual;
    while (loop != 0)
    {
        cout << "Welcome! Please press 0 to get started!" << endl;
        cin >> username;
        cout << "***USER MANUAL***" << endl;
        cout << "0 = Start game" << endl;
        cout << "1 = Exit game" << endl;
        cout << "2 = Save game" << endl;
        cout << "Up arrow key = Up" << endl;
        cout << "Down arrow key = Down" << endl;
        cout << "Right arrow key = Right" << endl;
        cout << "Left arrow key = Left" << endl;
        cin >> usermanual;
        createcharacter << userid << " " << username << " " << usermanual << endl;
        userid++;
        cout << "Please enter 1 if you want to begin the game" << endl;
        cin >> loop;
    }
    createcharacter.close();
    return 0;
}

//not yet compile into the main.cpp , will be done in part2.