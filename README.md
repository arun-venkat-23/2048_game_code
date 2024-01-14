# 2048 Code Explanation:

This is a simple console-based implementation of the popular 2048 game in C++. The game is played on a 5x5 grid, and the objective is to reach the tile with the value of 2048. <br>

## Game play

- Use the arrow keys (8 for Up, 4 for Left, 6 for Right, and 2 for Down) to move the tiles in the respective direction.
- Press 0 to end the game at any time.
- The game randomly generates a new tile (either 2 or 4) after each move.
- Tiles with the same value can be combined by merging them in the direction of the move.

## Code Explanantion

#### Header Files
```
#include<iostream>
#include<stdlib.h>
#include<process.h>
#include<stdio.h>
#include<time.h>
#include<fstream>
```
These are the standard C++ header files used for input/output, random number generation, file handling, and other necessary functionalities.

#### Global Declarations
```
int arr[5][5]; 
int stop[5][5];
int t, y, flag = 0, move, score = 0;
char ans;
```
Global variables are declared, including the game board (arr), a stop array (stop) to prevent merging the same tiles multiple times, and variables for various purposes.

#### Class Definition: Point
```
class Point
{
    public:
        int points;
        char name[20];
        
        void input() {...}
        void display() {...}
} data;
```
A class Point is defined to store player information, including their name and score. It has methods (input and display) for inputting player data and displaying it.

#### Function: scorekeeper()

This function handles end-of-game tasks such as saving player scores, displaying high scores, and asking the player if they want to play again.

#### Class Definition: MoveGen
'''
class MoveGen {...} mover;
'''
A class MoveGen is defined to handle movements in the game (up, down, left, right). It contains methods (up, down, left, right) to perform these movements on the game board. Please check the codes added in the code.

#### Function: Board()
```
void Board() {...}
```
This function displays the current state of the game board, including the tiles and the score.

#### main() Function
```
int main() {...}
```
The main function initializes the game board, generates the initial tiles, and enters a loop where the player makes moves until the game ends. It utilizes the functionalities provided by the classes and functions mentioned above.

#### Game Logic

The game logic involves random generation of new tiles, handling player moves, merging tiles with the same value, updating the score, and checking for the end of the game.

#### User Input and Output

The game relies on user input from the arrow keys (8 for Up, 4 for Left, 6 for Right, and 2 for Down) to make moves. The console is used to display the game board and interact with the player.

#### File Handling

The code includes file handling operations to read and write player scores to a file (score.DAt).

#### Score Calculation

<p> The score variable is initialized to 0 at the beginning of the game. When two tiles with the same value are merged, their values are added, and the result becomes the new value of the merged tile.
    
> For example, if two tiles with the value 2 are merged, the resulting tile will have a value of 4.

The score is incremented by the value of the merged tile. <br>

The score keeps accumulating as the player continues to merge tiles during the game. When the player decides to end the game (ans is 'y'), the final score is displayed. The player is prompted to enter their name, and the input method of the Point class is used to associate the player's name with their score. The player's name and score are then written to a file (score.DAt) for record-keeping. </p>

#### Viewing High Scores

After recording the current player's score, the code gives the option to view high scores. If the player chooses to view high scores (condition is 'Y'), the program reads from the file and displays the names and scores of players who achieved high scores.

#### Random Number Generation

The rand() function is used for random number generation, and the srand(time(0)) initializes the random seed based on the current time.

#### Miscellaneous

    The game includes colorful console output using system("COLOR ...").
    The code uses goto for input validation, directing the program to label again when an invalid input is detected.

#### Sample Output:

![image](https://github.com/arun-venkat-23/2048_game_code/assets/137104589/ace8701f-0d0e-4f62-8b26-a89c177da66f)

<br>

![image](https://github.com/arun-venkat-23/2048_game_code/assets/137104589/e85e34f8-ebec-4c01-90d5-330a6f17a536)

<br>

![image](https://github.com/arun-venkat-23/2048_game_code/assets/137104589/8cbbd0ec-6229-4e5d-9032-1dd3fc15ecdd)

<br>

![image](https://github.com/arun-venkat-23/2048_game_code/assets/137104589/41dbeb94-9673-48a3-a71a-dd6a43c20daa)

<br>

![image](https://github.com/arun-venkat-23/2048_game_code/assets/137104589/4cf551e9-040f-49af-ae83-ea3f7953c0fe)
