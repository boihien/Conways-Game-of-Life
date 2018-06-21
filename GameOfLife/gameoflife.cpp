#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <unistd.h>
using namespace std;

bool isInBounds(int row, int col, int n)
{
    if(row >= n || row <= -1)
    {
        return false;
    }
    if(col >= n || col <= -1)
    {
        return false;
    }
    return true;
}

void nextGeneration(vector<vector<bool> > &grid) {
    vector<vector<bool> > copy = grid;
    for(int row = 0; row < grid.size(); ++row)
    {
        for (int col = 0; col < grid.size(); ++col)
        {
            int numberAlive = 0;
            if (isInBounds(row - 1, col - 1, grid.size()))
            {
                if(copy[row-1][col-1] == true)
                {
                    numberAlive++;
                }
            }
            if(isInBounds(row - 1, col, grid.size()))
            {
                if(copy[row-1][col] == true)
                {
                    numberAlive++;
                }
            }
            if(isInBounds(row - 1, col + 1, grid.size()))
            {
                if(copy[row - 1][col + 1] == true)
                {
                    numberAlive++;
                }
            }
            if(isInBounds(row, col + 1, grid.size()))
            {
                if(copy[row][col + 1] == true)
                {
                    numberAlive++;
                }
            }
            if(isInBounds(row + 1, col + 1, grid.size()))
            {
                if(copy[row + 1][col + 1] == true)
                {
                    numberAlive++;
                }
            }
            if(isInBounds(row + 1, col, grid.size()))
            {
                if(copy[row + 1][col] == true)
                {
                    numberAlive++;
                }
            }
            if(isInBounds(row + 1, col - 1, grid.size()))
            {
                if(copy[row + 1][col - 1] == true)
                {
                    numberAlive++;
                }
            }
            if(isInBounds(row, col - 1, grid.size()))
            {
                if(copy[row][col - 1] == true)
                {
                    numberAlive++;
                }
            }

            bool isAlive = copy[row][col];
           // cout << "Position: " << row << ", " << col << " Alive: " << numberAlive << endl;
            if (isAlive)
            {
                if(numberAlive <= 1)
                {
                    grid[row][col] = false;
                }
                else if(numberAlive >= 4)
                {
                    grid[row][col] = false;
                }
            }
            else 
            {
                if(numberAlive >= 3)
                {
                    grid[row][col] = true;
                }
            }
        }
    }
}

void print(const vector<vector<bool> >& grid)
{
    for(int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid.size(); ++j)
        {
            if(grid[i][j] == true)
            {
                cout << "*";
            }
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<bool> > initializeGrid(int n) {
    vector<vector<bool> > grid(n, vector<bool> (n, false));
    for(int i = 0; i < grid.size(); ++i)
    {
        for(int j = 0; j < grid.size(); ++j)
        {
            int value = 0;
            value = rand()%2;
            if(value == 1)
            {
                grid[i][j] = true;
            }
            else
                grid[i][j] = false;
        }
    }
    return grid;
}

int main()
{
    auto grid = initializeGrid(5);
    while(true){
        print(grid);
        nextGeneration(grid);
        sleep(2);
    }
    return 0;
}