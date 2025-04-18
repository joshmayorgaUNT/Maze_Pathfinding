#include "maze.h"

int main(){
	Maze maze1("Mazes1.csv");
	Maze maze2("Mazes2.csv");
	Maze maze3("Mazes3.csv");
	maze1.print();

	double runtime_dijkstra = 0;
	int distance_dijkstra = maze1.dijkstra(runtime_dijkstra);

	cout << "Dijkstra:" << endl;
	cout << "Shortest distance: " << distance_dijkstra << endl;
	cout << "Runtime: " << runtime_dijkstra << endl;

	double runtime_a_star = 0;
	int distance_a_star = maze1.a_star(runtime_a_star); 
	
	cout << "A* Pathfinding:" << endl; 
        cout << "Shortest distance: " << distance_a_star << endl; 
        cout << "Runtime: " << runtime_a_star << endl; 

	return 0;
}
