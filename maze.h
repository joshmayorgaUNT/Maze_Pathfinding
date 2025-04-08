#ifndef MAZE_H
#define MAZE_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct cell{
	int x;		// x-coord of the cell (x = 0 is the left-most cell)
	int y;		// y-coord of the cell (y = 0 is the upper most cell)
	char space;	// cell can either be a wall '0' or empty ' '
};

// maze class
// rows, cols, and dynamic 2D array are initialized by readMazeFromFile() func
class Maze{
public:
	int rows;
	int cols;
	cell** layout;	// Dynamic 2D array
	
	Maze() : rows(0), cols(0), layout(NULL) {};
	~Maze();
	
	int a_star(double& runtime);	
	int dijkstra(double& runtime); 


	void print();
};

cell** readMazeFromFile(string maze_name, int& numRows, int& numCols);


#endif