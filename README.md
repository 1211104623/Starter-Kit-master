# Alien vs. Zombie

A C++ game named Alien vs Zombie that is similar to Alien Path. The game requires the players to eliminate the zombies on the game board by cleverly navigating the aliens on a path to destroy the invading robots. Please read the user manual before starting the game.

A signature screenshot of our program. Check out [the screenshot](/images/Screenshot_20230219_050739.png).

Please provide the YouTube link to your [Video Demo](https://youtu.be/Yt95riXgGWA).

## Compilation Instructions

g++ pf\*.cpp main.cpp -DDEMO

## User Manual

When entering values in the program, make sure that everything is lowercase letters.
At the beginning, user will have the option to change the game settings by entering 'y' for yes or 'n' for no.
Then, it will proceed to display the gameboard according to the user's input if user opt for 'y'.
The gameboard will consists of :
- ^ / v / < / > => arrows (up, down, left, right)
- h => health (adds 20 life to alien)
- p => pod (inflicts 10 damage to nearby zombie)
- r => rock (hides a game object:- arrows/health/pod/spaces)
-   => space
Next, user will be asked to enter commands to start moving the alien. (lower case only)
The commands are :
- up ; to move up
- down ; to move down
- right ; move right
- left ; move left
- arrow ; to change the direction of an arrow
- help ; show commands can be used in game
- save ; to save the game
- load ; to load a game
- quit ; to quit a game
After Alien had their move, the zombie will move accordingly.
After all zombies had their move, it will be the Alien's turn to move again.
The game will ends when Alien or all Zombies are defeated.
Players can choose to play again or quit.

## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors

- Azizah Gita Cahyani
- Balqis Afiqah binti Ahmad Fahmi
- Uzma Faqihah binti Azhan


