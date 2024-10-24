# Obstruction Game

This is a Python implementation of the **Obstruction Game** with both a **command-line interface (CLI)** and a **graphical user interface (GUI)**. The game architecture follows a layered design, allowing separation between game logic, user interaction, and AI mechanics.

## Table of Contents
- [Game Rules](#game-rules)
- [Architecture](#architecture)
- [Features](#features)
- [Requirements](#requirements)
- [How to Play](#how-to-play)
  - [Command-Line Interface](#command-line-interface)
  - [Graphical User Interface](#graphical-user-interface)
- [Installation](#installation)
- [Usage](#usage)
- [Code Overview](#code-overview)
  - [Domain Layer](#domain-layer)
  - [Repository Layer](#repository-layer)
  - [Controller Layer](#controller-layer)
  - [UI Layer](#ui-layer)
- [Contributing](#contributing)
- [License](#license)

## Game Rules

The **Obstruction Game** is a two-player game where players take turns marking cells on a grid. After each move, all surrounding cells (including diagonally adjacent ones) are blocked. The player who can no longer make a valid move loses.

### Key Rules:
1. Players alternate turns placing their markers (`O` for Player, `X` for AI).
2. When a player places a marker, the adjacent 8 cells are blocked and marked.
3. The first player who cannot make a move loses.
4. The AI can either play randomly or use a mirroring strategy.

## Architecture

The game is designed with a **layered architecture**:

1. **Domain Layer**: Manages core logic such as board representation and move validation (e.g., `Board`, `ValidatePoint`).
2. **Repository Layer**: Handles saving and retrieving the current board state (e.g., `BoardRepository`).
3. **Controller Layer**: Coordinates the interaction between the player, AI, and board, and checks game-over conditions.
4. **UI Layer**: 
   - **CLI (Command-Line Interface)**: A text-based interface that allows players to enter moves via the terminal.
   - **GUI (Graphical User Interface)**: A visual interface using Tkinter, where players can interact with the game by clicking on the grid.

## Features

- Play against a basic AI.
- Two user interfaces: CLI and GUI.
- Selectable grid sizes (e.g., 6x6, 7x8, 7x9, 8x8 grids).
- AI uses either random or mirroring strategies.
- Save and load board states.
- Randomized AI move selection, based on the current board configuration.

## Requirements

- Python 3.x
- Libraries: 
  - `texttable` (for CLI board display)
  - `tkinter` (for GUI)
  - Any other requirements can be installed from the `requirements.txt` file.

## How to Play

### Command-Line Interface

To play via the command line:
1. The player chooses the grid size and who starts the game (player or AI).
2. Players enter their moves by specifying grid coordinates (x, y).
3. The board is updated and displayed after every move, showing which cells are blocked.
4. The game ends when a player can no longer make a valid move.

### Graphical User Interface

In the GUI version:
- Players choose the grid size and can decide whether to start first.
- Players interact with the grid by clicking to place their markers.
- The board updates visually, blocking off surrounding cells after each move.
- The game continues until no more moves can be made.
