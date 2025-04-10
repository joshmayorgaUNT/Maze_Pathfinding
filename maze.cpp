#include "maze.h"

// Maze Constructor: Initializes rows, cols, and by reading the configuration from a .csv file
// - Allocates and initializes a 2D array of cells based on the file content
// Parameters:
// - string maze_name: The name of the .csv file
Maze::Maze(string maze_name){
        ifstream maze_file(maze_name);

        if(!maze_file.is_open()){ //Checks if file is valid
                cout << "Error: could not open maze file" << endl;
                rows = 0;
                cols = 0;
                layout = NULL;
		return;
        }

        string line;

        // First line of .csv file is rows,cols
        getline(maze_file, line, ',');
        rows = stoi(line);
        getline(maze_file, line);
        cols = stoi(line);

        // Allocate the 2D array
        layout = new cell*[rows];
        for(int i = 0; i < rows; i++){
                layout[i] = new cell[cols];
        }
  
        // Initialize the 2D array
        int curr_row = 0;
        int curr_col = 0;
        while(getline(maze_file, line)){
                stringstream ss(line);
                string value;
                curr_col = 0;
                while(getline(ss, value, ',')){
			cell tempCell;
                        tempCell.space = value[0];
                        tempCell.x = curr_row;
                        tempCell.y = curr_col;
			tempCell.isWall = value[0] == '0' ? true : false;
			// Initialize adjacent cell pointers
			if(curr_row != 0){		// if cell is not on the top row
				tempCell.above = &layout[curr_row-1][curr_col];
			}
			if(curr_row != rows-1){		//if cell is not on the bottom row
				tempCell.below = &layout[curr_row+1][curr_col];
			}
			if(curr_col != 0){		//if cell is not on the leftmost col
				tempCell.left = &layout[curr_row][curr_col-1];
			}
			if(curr_col != cols-1){		//if cell is not on the rightmost col
				tempCell.right = &layout[curr_row][curr_col+1];
			}
                        layout[curr_row][curr_col] = tempCell;
                        curr_col++;
                }
                curr_row++;
        }

        maze_file.close();
}

// Maze Destructor: Deallocates the dynamically allocated memory for the maze layout
Maze::~Maze(){
        for(int i = 0; i < rows; i++){
                        delete[] layout[i];
                }
                delete[] layout;
}

// Maze print: prints the maze
void Maze::print(){
        for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                        cout << layout[i][j].space;
                }
                cout << endl;
        }
}

// readMazeFromFile: Reads a maze configuration from a .csv file and initializes the maze layout
// - If the maze was already allocated, it deallocates the previous array
// Parameters:
// - string maze_name: The name of the .csv file
bool Maze::readMazeFromFile(string maze_name){
        ifstream maze_file(maze_name);

        if(!maze_file.is_open()){ //Checks if file is valid
			return false;
	}

        string line;

        // First line of .csv file is rows,cols
        getline(maze_file, line, ',');
        rows = stoi(line);
        getline(maze_file, line);
        cols = stoi(line);

        // If maze was already allocated, deallocate prev array
        if(layout != NULL){
                for(int i = 0; i < rows; i++){
                        delete[] layout[i];
                }
                delete[] layout;
        }

        // Allocate the 2D array
        layout = new cell*[rows];
        for(int i = 0; i < rows; i++){
                layout[i] = new cell[cols];
        }
  
        // Initialize the 2D array
        int curr_row = 0;
        int curr_col = 0;
        while(getline(maze_file, line)){
                stringstream ss(line);
                string value;
                curr_col = 0;
                while(getline(ss, value, ',')){
                        cell tempCell;
                        tempCell.space = value[0];
			tempCell.x = curr_row;
                        tempCell.y = curr_col;			
			tempCell.isWall = value[0] == '0' ? true : false;
			// Initialize adjacent cell pointers
			if(curr_row != 0){		// if cell is not on the top row
				tempCell.above = &layout[curr_row-1][curr_col];
			}
			if(curr_row != rows-1){		//if cell is not on the bottom row
				tempCell.below = &layout[curr_row+1][curr_col];
			}
			if(curr_col != 0){		//if cell is not on the leftmost col
				tempCell.left = &layout[curr_row][curr_col-1];
			}
			if(curr_col != cols-1){		//if cell is not on the rightmost col
				tempCell.right = &layout[curr_row][curr_col+1];
			}
                        layout[curr_row][curr_col] = tempCell;
                        curr_col++;
                }
                curr_row++;
        }

        maze_file.close();
        return true;
}
