#include <iostream>
#include <fstream>
#include "Play.h"

Play::Play()
{   cout << "8eeee8                                     8     8  8eeee 8eeee\n" << "8    e eeeee eeeeeee eeee    eeeee eeee    8     8  8     8\n" << "8e     8   8 8  8  8 8       8  88 8       8e    8e 8eeee 8eeee\n" << "88  ee 8eee8 8e 8  8 8eee    8   8 8eee    88    88 88    88\n" << "88   8 88  8 88 8  8 88      8   8 88      88    88 88    88\n" << "88eee8 88  8 88 8  8 88ee    8eee8 88      88eee 88 88    88eee\n\n";
    string userin; // String for Capturing User Input
    cout << "Enter Name of State File: " << endl;
    cin >> userin;
    Grid gameConfig(userin); // Grid Defined Using User Inputted File Name
    cout << "\n---------------Initial Configuration--------------" << endl;
    while(gameConfig.aliveCell() ){   
        gameConfig.displayGrid(); // Displays Grid After Each Iteration
        cout << "Enter Y to Output to File, N to Continue, E to Exit: " << endl;
        cin >> userin;
        if (userin == "Y" || userin == "y") {
            cout << "Enter Desired Filename: " << endl;
            cin >> userin;
            gameConfig.outGrid(userin); // Outputs to File with Name of User Inputted String
        }
        else if (userin == "N" || userin == "n") {
            gameConfig.gameState(); // Updates the State of the Game
        }
        else if (userin == "E" || userin == "e") {
            break; // Ends a Game if E/e Entered
        }
        cout << endl;
    }
    gameConfig.displayGrid(); // Displays Grid After Loop Ended After All Cells Dead
}

int main(){
    Play(); // Calls the View Module Play()
    return 0;
}