import random
from copy import deepcopy

from Repo.repo import BoardRepository
from domain.domain import ValidatePoint,Board
from domain.Point import Point
from random import randint


class Game:
    def __init__(self, board):
        self.__board = board
        self.__valid = ValidatePoint()
        self.__startodd = False  # Variable which tells us if AI is the first to make a move on an odd board
        self.__board_repository=BoardRepository(board)
    def get_board(self):
        """Returns the board"""
        return self.__board_repository.get_current_board()

    def set_row(self, row):
        """Sets the row of the board"""
        self.__board.row=row

    def set_column(self, column):
        """Sets the column of the board"""
        self.__board.column=column

    def create_board(self):
        """Creates the board and sets the __startodd variable to its default value"""
        self.__board.create_board()
        self.__startodd = False

    def destroy_board(self):
        """Function that destroys the board"""
        self.__board.destroy_board()

    def make_move_player(self, x, y):
        """Function that validates the move the player wants to make.
        Raises exception if the move is invalid or if the square is taken.
        Otherwise it records the move.
        params:x,y-coordinates of the move
        """
        self.__valid.valid_point(x, y, self.__board)
        point = Point(x, y)
        self.__board.board[int(point.get_x)][int(point.get_y)] = 1
        self.__board.board_move(point)

        self.__board_repository.save_board_state(self.__board)

    def _check_odd(self, x, y):
        """Function that returns true if the board has an odd size and false otherwise
        params:x,y dimension of the board
        """
        return x % 2 and y % 2

    def _get_mirror(self, x, y):
        """Function that returns a Point that represents the mirrored move of the player
        (strategy used by AI when it is the one to make the first move on an odd board)"""
        row = self.__board.row
        col = self.__board.column

        if self.__board.board[row - x - 1][col - y - 1] == 0:
            return Point(row - x - 1, col - y - 1)

        if self.__board.board[x][col - y - 1] == 0:
            return Point(x, col - y - 1)

        if self.__board.board[row - x - 1][y] == 0:
            return Point(row - x - 1, y)

    def _decide_move(self, computer, row, column, moves):
        """Function that decides how will the AI make its next move based on some criteria
        row-the row
        column-the column
        moves-availabe moves

        """
        if self.check_for_winning_move():
            return 1
        # If the AI starts we check if the board has odd coordinates
        if computer is True and len(moves) == row * column:
            if self._check_odd(row, column):
                return 1

        # If the board is odd and AI started we continue with 1
        if self.__startodd is True and len(moves) != row * column:
            return 1

        # If the above criteria wasn't met, the AI will just make its move randomly
        return 2

    def _first_odd(self, row, column, moves, x, y):
        """Function that follows the next strategy:
        If the board is odd and AI makes the first move, then the first move will be in the center of the board.
        In order to win, next the AI will only mirror the player's moves.
        params:
        row=the row
        column=the column
        moves=available moves
        x,y coordinates of the moves
        """

        # If it is the first move, AI takes the central square
        if len(moves) == row * column:
            row_x = row // 2
            column_y = column // 2
            self.__board.board[int(row_x)][int(column_y)] = 2
            move = Point(row_x, column_y)
            self.__board.board_move(move)

            self.__startodd = True
            return move

        # If the board is odd and AI started, it will mirror the player's move in order to win
        if len(moves) != row * column:
            move = self._get_mirror(int(x), int(y))
            self.__board.board[int(move.get_x)][int(move.get_y)] = 2
            self.__board.board_move(move)

            return move

    def _random_move(self, moves):
        """Function that makes AI move randomly
        params: moves-available moves

        """
        move = randint(0, len(moves) - 1)
        self.__board.board[moves[move].get_x][moves[move].get_y] = 2
        self.__board.board_move(moves[move])
        return moves[move]

    def make_move_ai(self, computer, x, y):
        """
        Function that makes the computer move
        :param computer: the computer
        :param x: x coordinate
        :param y:y coordinate

        """
        moves = self.__board.available_move()
        row = self.__board.row
        column = self.__board.column
        next_move = self._decide_move(computer, row, column, moves)
        if self.check_for_winning_move():
            move=random.choice(self.check_for_winning_move())
            self.__board.board[int(move.get_x)][int(move.get_y)]=2
            self.__board.board_move(move)
            return
        if next_move == 1:
            return self._first_odd(row, column, moves, x, y)
        elif next_move == 2:
            # If the above criteria wasn't met, the AI will just make its move randomly
            return self._random_move(moves)
        self.__board_repository.save_board_state(self.__board)

    """
    def make_move_ai(self, computer, x, y):
        
        moves = self.__board.available_move()
        row = self.__board.row
        column = self.__board.column

        # Use Minimax to find the best move
        best_move = None
        best_score = -float('inf')
        for move in moves:
            mx, my = move.get_x, move.get_y
            mx=int(mx)
            my=int(my)
            self.__board.board[mx][my] = 2  # AI makes a move
            score = self._minimax(3, False)  # Adjust depth as needed
            self.__board.board[mx][my] = 0  # Undo the move

            if score > best_score:
                best_score = score
                best_move = move

        # Apply the best move found
        if best_move:
            mx, my = best_move.get_x, best_move.get_y
            mx=int(mx)
            my=int(my)
            self.__board.board[mx][my] = 2
            self.__board.board_move(best_move)
            return best_move

        # Fallback to a random move if no move is found (should not happen)
        return self._random_move(self.__board.available_move())
    """
    def game_over(self):
        """Function that returns True if there are still available moves to be made and False otherwise"""
        if self.__board.available_move():
            return True
        return False

    def check_for_winning_move(self):
        """
        Function that checks for winning move
        :return: a list of winning moves
        """
        moves=self.__board.available_move()
        temp_board=deepcopy(self.__board.board)
        winning_moves=[]
        for move in moves:
            x,y=move.get_x,move.get_y
            temp_board[x][y]=2
            if self.game_over() is False:
                winning_moves.append(move)
            temp_board[x][y]=0
        return winning_moves


    def _evaluate(self):
        # Simple evaluation: count the number of available moves
        available_moves = len(self.__board.available_move())
        return -available_moves  # Negative score because fewer moves are better for AI
    """
    def _minimax(self, depth, is_max):
        if depth == 0 or self.game_over():
            return self._evaluate()

        if is_max:
            best_score = -float('inf')
            for move in self.__board.available_move():
                x, y = move.get_x(), move.get_y()
                self.__board.board[x][y] = 2  # AI makes a move
                score = self._minimax(depth - 1, False)
                self.__board.board[x][y] = 0  # Undo the move
                best_score = max(best_score, score)
            return best_score
        else:
            best_score = float('inf')
            for move in self.__board.available_move():
                x, y = move.get_x(), move.get_y()
                self.__board.board[x][y] = 1  # Player makes a move
                score = self._minimax(depth - 1, True)
                self.__board.board[x][y] = 0  # Undo the move
                best_score = min(best_score, score)
            return best_score
    """


