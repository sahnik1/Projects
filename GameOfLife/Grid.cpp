#include <iostream>
#include <fstream>
#include "Grid.h"

using namespace std;

int grid[17][17] = {0};

Grid::Grid(string filename){

    this->gridMAX = 16;

    ifstream input(filename.c_str());

    int x, y;
    char comma;

    //Initializes Array with All 0 Values
    for(size_t i = 0; i < gridMAX; i++){
        for(size_t j = 0; j < gridMAX; j++){
            grid[i][j] = 0;
        }
    }

    //Reads File line by line with a comma as a delimiter
    while (!input.eof()){
        input >> x >> comma >> y;
        grid[y][x] = 1;
    }
    
    //Garbage Collection
    input.close();
}

void Grid::outGrid(string filename){
    ofstream file;
    file.open(filename.c_str(), ios::out);

    //Writes Valid Match Coordinates to File
    for(size_t i = 1; i < gridMAX; i++)
    {
        for(size_t j = 1; j < gridMAX; j++)
        {
            if (grid[i][j] == 1) {
                file << j << "," << i << endl;
            }
        }
        
    }
    file.close();
}

void Grid::displayGrid(){

    //Displays Different Symbols for Alive Cells and empty spaces
    for(size_t i = 1; i < gridMAX; i++){

        for(size_t j = 1; j < gridMAX; j++){
            
            if (grid[i][j] == 1) {
                cout << " 0 ";
            }
            else
            {
                cout << " - ";
            }
            
        }
        cout << endl; // New Line Char at End of Each Outputted Row
    }
}

void Grid::gameState(){

    int gridtemp[17][17];
    copyGrid(gridtemp); 

    int neighbours = 0;
    for(size_t i = 1; i < gridMAX; i++){

        for(size_t j = 1; j < gridMAX; j++){
            // Computes Total Number of Neighbours Including Diagonal Ones
            neighbours = gridtemp[i+1][j] + gridtemp[i+1][j+1] + gridtemp[i][j+1] +
                            gridtemp[i-1][j] + gridtemp[i-1][j-1] + gridtemp[i][j-1] +
                            gridtemp[i-1][j+1] + gridtemp[i+1][j-1];

            if (neighbours == 3 && grid[i][j] == 0) {
                grid[i][j] = 1; // A Cell is Born!!!
            }
            else if ((neighbours == 3 || neighbours == 2) && grid[i][j] == 1){
                grid[i][j] = 1; // If in This range, Cell Stays Alive
            }
            else if (neighbours <= 1) {
                grid[i][j] = 0; // Cell Dies :(
            }
            else if (neighbours >= 4) {
                grid[i][j] = 0; // Cell Dies :(
            }
        }
    }
}

void Grid::copyGrid(int gridtemp[17][17]){
    //Loops Through each Row then Column to Copy Array
    for(size_t i = 0; i < gridMAX; i++){
        for(size_t j = 0; j < gridMAX; j++){
            gridtemp[i][j] = grid[i][j];
        }
    }
}

bool Grid::aliveCell(){
    // Loops Through to Check if Any Value in Array Equal to 1
    for(size_t i = 1; i < gridMAX; i++){
        for(size_t j = 1; j < gridMAX; j++){
            if (grid[i][j] == 1){
                return true;
            }
        }
    }
    return false;
}
