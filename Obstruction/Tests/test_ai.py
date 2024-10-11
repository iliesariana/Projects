
import unittest
from domain.domain import Board
from service.ai import Game

class TestObstructionGame(unittest.TestCase):

    def test_initialization(self):
        board = Board(3, 3)
        #ai = AIController(board)
        ai=Game(board)
        ai.create_board()
        self.assertEqual(len(ai.get_board().available_move()), 9)  # All squares should be available initially

    def test_move(self):
        board = Board(3, 3)
        #ai = AIController(board)
        ai = Game(board)
        ai.create_board()
        ai.make_move_ai(True, 0, 0)  # Simulate AI making a move
        self.assertNotEqual(len(ai.get_board().available_move()), 9)  # Number of available moves should decrease
        self.assertRaises(Exception,ai.make_move_player,0,0)

    def test_end_game(self):
        board = Board(2, 2)
        #ai = AIController(board)
        ai = Game(board)
        ai.create_board()
        ai.make_move_player(0, 0)
        #ai.make_move_ai(True, 1, 1)
        self.assertFalse(ai.game_over())  # Game should be over as no moves are left
        self.assertEqual(len(board.available_move()),0)

    def test_board_state_after_moves(self):
        board = Board(3, 3)
        #ai = AIController(board)
        ai = Game(board)
        ai.create_board()
        ai.make_move_player(1, 1)
        self.assertEqual(len(ai.get_board().available_move()), 0)

    def test_ai_first_move_middle(self):
        board = Board(3, 3)
        ai = Game(board)
        ai.create_board()

        # Make the AI's first move
        ai.make_move_ai(True, 0, 0)

        # Check if the AI's first move is in the middle
        middle_point = board.row // 2, board.column // 2
        self.assertEqual(ai.get_board().board[middle_point[0]][middle_point[1]], 2)

    def test_exceptions(self):
        board = Board(3, 3)
        #ai = AIController(board)
        ai = Game(board)
        ai.create_board()
        self.assertRaises(Exception,ai.make_move_player,1,'a')
        self.assertRaises(Exception,ai.make_move_player,4,4)
        self.assertRaises(Exception,ai.make_move_player,-1,4)

if __name__ == '__main__':
    unittest.main()
