# Obstruction Game

This is a Python implementation of the **Obstruction Game** following a layered architecture. It includes both a **command-line interface (CLI)** and a **graphical user interface (GUI)**. The game logic is organized into distinct layers to maintain a clean separation of concerns.


## Game Rules

**Obstruction** is a two-player game where the objective is to be the last player able to make a move. It is played on a rectangular grid. Players take turns placing their markers (1 for the player, 2 for the AI). Once a marker is placed, the surrounding cells (including diagonally adjacent ones) are blocked and cannot be used for future moves. The game ends when no more moves are available, and the player unable to move loses the game.

### Key Rules:
1. Players alternate making moves.
2. When a marker is placed, the adjacent 8 cells are blocked.
3. The player who can make the last valid move wins.
4. The AI can either:
   - Use a mirroring strategy on odd-sized boards.
   - Play randomly if no specific strategy is available.

## Architecture

The game follows a **layered architecture** for a clean structure:

1. **Domain Layer**: Handles the core logic, including the board structure, point validation, and available moves.
2. **Repository Layer**: Manages board state, storing, and retrieving the current state.
3. **Controller Layer (Game Logic)**: Coordinates player and AI moves, checks game-over conditions, and manages board updates.
4. **UI Layer**: Two user interface options:
   - **CLI**: Command-line interface for playing via the terminal.
   - **GUI**: Graphical interface using a Python library like Tkinter or Pygame.

## Features

- Play against a basic AI.
- Two interfaces: CLI and GUI.
- AI uses either a mirroring strategy (on odd boards) or random move generation.
- Save and load game board state.
-
