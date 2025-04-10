#include "maze.h"
#include <queue>
#include <vector>

/* Breadth First Search: BFS pathfinding algorithm to navigate through the maze
  ------------------------
   - Algorithm:
   1. Add starting cell to queue
   2. Mark starting cell as visited
   3. While the queue is not empty: (Note: when the queue is empty, paths have been exhausted)
	4. Set the current cell to the front of the queue
	5. Get the adjacent cells of the current cell
	6. Pop the queue
   	7. Check if the current cell is the finishing cell
	   -If true, pathfinding is complete
	8. If false go through adjacent cells
	9. If the adjacent_cells are not visited
		10. mark the adjacent cell as visited
		11. add the unvisited adjacent cell to the queue
    12. Repeat until queue is empty or current cell is the finishing cell

   Parameters:
    - double& runtime: pass-by-reference runtime to keep track of runtime (UNFINISHED)

   Returns:
    - int distance: shortest distance from start to finish (UNFINISHED)
*/

// Returns a vector of adjacent cells
vector<cell*> get_adjacent_cells(cell* input_cell);

int Maze::breadthfirstsearch(double& runtime){
	int distance;
	queue<cell*> bfs_queue;

	cell* startingCell = &layout[0][1];
	cell* finishingCell = &layout[rows-1][cols-2];

	// 1. push starting cell to queue
	bfs_queue.push(startingCell);

	// 2. mark starting cell as visited
	startingCell->space = '*';

	int num_iterations = 0;
	cell* curr_cell;
	vector<cell*> adjacent_cells;

	// 3. while queue is not empty
	while(!bfs_queue.empty() && num_iterations < 400){
		// 4. set curr_cell to front of the queue
		curr_cell = bfs_queue.front();
		// 5. get cells adjacent to curr_cell
		adjacent_cells = get_adjacent_cells(curr_cell);
		// 6. pop curr_cell from queue
		bfs_queue.pop();
		// 7. check if curr_cell is finishing cell
		if(curr_cell == finishingCell){
			return num_iterations;
		}

		// 8. if not, add adjacent cells to queue:
		//     go through every adjacent cell
		for(cell*  adjacent_cell : adjacent_cells){
			// 9. if the adjacent_cell is not visited
			if(adjacent_cell->space != '*'){
				// 10. mark the adjacent cell as visited
				adjacent_cell->space = '*';
				// 11. add the adjacent cell to the bfs_queue
				bfs_queue.push(adjacent_cell);
			}
		}
		//12. clear adjacent_cells and repeat
		adjacent_cells.clear();
		num_iterations++;
	}

	return num_iterations;
}

vector<cell*> get_adjacent_cells(cell* input_cell){
	vector<cell*> adjacent_cells;
	if(input_cell->above != NULL && !input_cell->above->isWall){
		adjacent_cells.push_back(input_cell->above);
	}
        if(input_cell->right != NULL && !input_cell->right->isWall){
                adjacent_cells.push_back(input_cell->right);
        }
        if(input_cell->below != NULL && !input_cell->below->isWall){
                adjacent_cells.push_back(input_cell->below);
        }
        if(input_cell->left != NULL && !input_cell->left->isWall){
                adjacent_cells.push_back(input_cell->left);
        }
	return adjacent_cells;
}
