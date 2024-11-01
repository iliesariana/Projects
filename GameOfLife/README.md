##Game of Life

This project is an implementation of Conway's Game of Life, a zero-player cellular automaton game in which cells on a grid live, die, or reproduce based on certain rules. This project allows users to place patterns on a board, evolve the board through generations, and save/load board configurations to/from files.

## Features
- **Grid Creation**: Initializes an 8x8 grid where cells can be either alive or dead.
- **Pattern Placement**: Users can place specific patterns at specified coordinates on the board.
- **Generation Advancement**: Evolves the board state by applying Game of Life rules for a specified number of generations.
- **File Management**: Users can save the current board state to a file or load a board state from a file.
- **Interactive CLI**: A command-line interface (CLI) allows for interactive control of the game.

## Rules of the Game
1. **Underpopulation**: A living cell with fewer than two live neighbors dies.
2. **Overpopulation**: A living cell with more than three live neighbors dies.
3. **Survival**: A living cell with two or three live neighbors survives.
4. **Reproduction**: A dead cell with exactly three live neighbors becomes a live cell.

