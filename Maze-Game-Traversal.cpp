#include<iostream>
using namespace std;

const int MAZE_SIZE = 12;

void displayBoard(char **maze, int rows, int cols);
bool mazeSolver(char **maze, int nrows, int ncols, int srow, int scol);

int main() {
    // Allocate memory for the rows
    char **maze = new char *[MAZE_SIZE];
    for (int i = 0; i < MAZE_SIZE; i++) {
        maze[i] = new char[MAZE_SIZE];
    }

    // Initialize the maze with values
    char initial_maze[MAZE_SIZE][MAZE_SIZE] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
        {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
        {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
        {'.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    // Copy the initial maze into the allocated memory
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = initial_maze[i][j];
        }
    }

    // Print the initial maze
    displayBoard(maze, MAZE_SIZE, MAZE_SIZE);

    // Solve the maze starting from row 4, column 11
    bool is_solved = mazeSolver(maze, MAZE_SIZE, MAZE_SIZE, 4, 11);

    // Print the final maze
    displayBoard(maze, MAZE_SIZE, MAZE_SIZE);

    // Deallocate memory when done
    for (int i = 0; i < MAZE_SIZE; i++) {
        delete [] maze[i];
    }
    delete [] maze;

    return 0;
}

void displayBoard(char **maze, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


	bool mazeSolver( char **maze, int nrows, int ncols, int srow, int scol )
{
	
    // Check if the starting position is a wall or outside the maze
    if (maze[srow][scol] == '#' || srow < 0 || srow >= nrows || scol < 0 || scol >= ncols) 
	{
        return false;
    }

    // Check if we have reached the exit
    if ((srow == 0 || srow == nrows - 1 || scol == 0 || scol == ncols - 1) && (ncols != scol))
	{
        maze[srow][scol] = 'X'; // Mark the exit
        return true;
    }

    // Mark the current position as visited
    maze[srow][scol] = 'X';
    
    
	if (mazeSolver(maze, nrows, ncols, srow, scol-1)) 
	{
	 // Left
        return true;
    }
    // Try moving in all possible directions
    if (mazeSolver(maze, nrows, ncols, srow-1, scol))
	{
	 // Up
        return true;
    }
    if (mazeSolver(maze, nrows, ncols, srow+1, scol)) 
	{
	 // Down
        return true;
    }

    if (mazeSolver(maze, nrows, ncols, srow, scol+1)) 
	{ 
	// Right
        return true;
    }
	
    // If no path was found, backtrack and unmark this position
    maze[srow][scol] = '.';
    return false;
 
}

