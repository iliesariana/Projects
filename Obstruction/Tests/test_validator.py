from unittest import TestCase

from domain.domain import ValidatePoint, Board


class TestValidator(TestCase):
    def setUp(self):
        self.validator=ValidatePoint()
        self.board=Board()
        self.board.row=6
        self.board.column=6
        self.board.create_board()
    def test_valid(self):
        self.assertRaises(Exception,self.validator.valid_point,8,8,self.board)
        self.assertRaises(Exception,self.validator.valid_point,0,-1,self.board)
        self.board.board[0][0]=1
        self.assertRaises(Exception,self.validator.valid_point,0,0,self.board)
