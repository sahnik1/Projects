/**
 * \file Grid.h
 * \author Karanjot Singh Sahni, MacID: sahnik
 * \brief Header for grid class for cells.
*/

#ifndef A4_GRID_H
#define A4_GRID_H

using namespace std; 

class Grid {

	int gridMAX;
    int grid[17][17];

	public:
		/**
		 	*  \brief Constructor for a Grid From a Vector
	 		*  \details Constructs a Grid from a Given File
     		*  \param filename String Representation of File Name
	 		*/
        Grid(string filename);

		/**
	 		*  \brief Output of Game to File
	 		*  \details Outputs the Current Game State to a File
     		*  \param filename String Representation of File Name
	 		*/
		void outGrid(string filename);

		/**
	 		*  \brief Helper Function for gameState()
	 		*  \details Copies Grid Values to Given Array
     		*  \param gridtemp[17][17] Array to be Copied to
	 		*/
		void copyGrid(int gridtemp[17][17]);

		/**
	 		*  \brief Checks for if Any Cells are Alive
	 		*  \details Returns True if atleast one Cell is Alive
     		*  \return A Boolean Value if any Cells Alive or Not
	 		*/
		bool aliveCell();

		/**
	 		*  \brief Output of Grid to Screen
	 		*  \details Outputs the Live View of a Grid
	 		*/
		void displayGrid();

		/**
	 		*  \brief Updates State of Game
	 		*  \details Updates Game State Based on Grid
	 		*/
		void gameState();
		
};

#endif
