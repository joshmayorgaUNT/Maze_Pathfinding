#ifndef MAZE_H
#define MAZE_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Cell: Represents a single cell in the maze with x and y coordinates and a space character.
struct cell{
	int x;          // x-coord of the cell (x = 0 is the left-most cell)
	int y;          // y-coord of the cell (y = 0 is the upper most cell)
	char space;     // cell can either be a wall '0' or empty ' '
	bool isWall;	// isWall bool to help with pathfinding

	cell* above = NULL;	// Pointers to adjacent cells to assist with pathfinding
	cell* below = NULL;
	cell* left = NULL;
	cell* right = NULL;
};

 // Maze: Represents the maze with rows, columns, and a dynamic 2D array of cells
class Maze{
public:
	int rows;		// Number of rows in the maze
	int cols;		// Number of columns in the maze
	cell** layout;		// Pointer to a dynamically allocated 2D array of cells

	Maze() : rows(0), cols(0), layout(NULL) {};	// Default constructor 
	Maze(string file_name);				// Constructor that initializes the maze from a file
	~Maze();					// Destructor to clean up dynamically allocated memory
	
	bool readMazeFromFile(string file_name);	// Reads maze configuration from a file
	int a_star(double& runtime);			// Implements the A* algorithm for pathfinding
	int dijkstra(double& runtime);			// Implements Dijkstra's algorithm for pathfinding
	int breadthfirstsearch(double &runtime);	// Implements breadth first search for pathfinding

	void print();					// Prints the maze layout
};

#endif
