# Game of Life

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

## Architecture

The project uses a **layered architecture** with the following components:

1. **Repository Layer **: Manages data storage and retrieval, specifically handling the saving and loading of game board states to and from text files. This layer abstracts the file operations, making it easy to change data sources if needed.

2. **Game Logic Layer **: Contains the core logic of the Game of Life, including:
   - Counting neighbors for each cell
   - Applying Game of Life rules (underpopulation, overpopulation, reproduction, and survival)
   - Allowing patterns to be placed on the board at specified locations

3. **Table/Board Layer**: Represents the game board itself, storing cell states in a grid and providing a structured way to initialize and display the board.

4. **User Interface Layer **: A command-line interface that interacts with the user, enabling commands like placing patterns, advancing generations, and saving/loading the game state.
