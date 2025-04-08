#include "maze.h"

Maze::~Maze(){
	for(int i = 0; i < rows; i++){
                        delete[] layout[i];
                }
                delete[] layout;
}

void Maze::print(){
        for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                        cout << layout[i][j].space;
                }
                cout << endl;
        }
}

cell** readMazeFromFile(string maze_name, int& numRows, int& numCols){
        ifstream maze_file(maze_name);

        if(!maze_file.is_open()){ //Checks if file is valid
                cout << "Error: could not open input file" << endl;
                return NULL;
        }

        string line;
        
        // First line of .csv file is rows,cols
        getline(maze_file, line, ',');
        numRows = stoi(line);
        getline(maze_file, line);
        numCols = stoi(line);

        // Allocate the 2D array
        cell** maze = new cell*[numRows];
        for(int i = 0; i < numRows; i++){
                maze[i] = new cell[numCols];
        }
        
        // Initialize the 2D array
        int row = 0;
        int col = 0;
	while(getline(maze_file, line)){
                stringstream ss(line);
                string value;
                col = 0;
                while(getline(ss, value, ',')){
                        cell tempCell;
                        tempCell.space = value[0];
                        tempCell.x = row;
                        tempCell.y = col;
                        maze[row][col] = tempCell;
                        col++;
                }
                row++;
        }

        maze_file.close();
        return maze;
}