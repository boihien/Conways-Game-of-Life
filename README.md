# Conway's Game of Life
My project is a zero-player game that takes in an initial random state and generates a population. It follows the rules of Conway's Game of life, which is a cellulalr automation program that simulates the life cycles of cells in a boundary. Once the user starts the program, no further input is necessary and the program will continue to run until the population ceases to exist. The sleep function provides a scrolling effect when the population increases. 

## Rules 
```
1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
2. Any live cell with two or three live neighbours lives on to the next generation.
3. Any live cell with more than three live neighbours dies, as if by overpopulation.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
```
## Demonstration
![Alt Text](https://imgur.com/a/pa38X0l)


## Known Bugs
The program does not end once the population is destroyed. 
