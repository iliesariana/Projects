from copy import deepcopy
from unittest import TestCase

from src.game import Game, PatternError
from src.repo import Repo


class Test(TestCase):
    def setUp(self):
        self.__repo=Repo()
        self.__game=Game(self.__repo)

    def test_load_from_file(self):
        self.assertEqual(len(self.__repo.get_all()),5)
        patterns=self.__repo.get_all()
        self.assertIsNotNone(patterns['block'])
        self.assertIsNotNone(patterns['tub'])
        self.assertIsNotNone(patterns['beacon'])
        self.assertIsNotNone(patterns['spaceship'])
    def test_place_pattern(self):
        self.__game.place_pattern(0,0,'block')
        self.assertEqual(self.__game.board.board[0][0],1)
        self.assertEqual(self.__game.board.board[0][1],1)
        self.assertEqual(self.__game.board.board[1][0],1)
        self.assertEqual(self.__game.board.board[1][1],1)

    def test_exception_place_pattern(self):
        self.assertRaises(PatternError,self.__game.place_pattern,0,0,'aaa')
        self.__game.place_pattern(0,0,'block')
        self.assertRaises(PatternError,self.__game.place_pattern,0,0,'block')
        self.assertRaises(PatternError,self.__game.place_pattern,0,0,'tub')
        self.assertRaises(PatternError,self.__game.place_pattern,7,7,'beacon')

    def test_tick(self):
        self.__game.place_pattern(0,0,'blinker')
        old_board=deepcopy(self.__game.board)
        self.__game.tick(1)
        self.assertEqual(self.__game.board.board[0][1],1)
        self.assertEqual(self.__game.board.board[1][0],0)
        self.assertEqual(self.__game.board.board[1][1],1)
        self.__game.tick(1)
        self.assertEqual(self.__game.board.board,old_board.board)

    def test_tick_beacon(self):
        self.__game.place_pattern(0,0,'beacon')
        self.assertEqual(self.__game.board.board[0][0],1)
        self.assertEqual(self.__game.board.board[1][1],1)
        self.__game.tick(1)
        self.assertEqual(self.__game.board.board[1][1],0)

    def count_living_cells(self):
        self.__game.place_pattern(0,0,'block')

        self.assertEqual(self.__game.count_cells(0,0,self.__game.board),3)
        self.assertEqual(self.__game.count_cells(0,1,self.__game.board),3)
        self.assertEqual(self.__game.count_cells(2,2,self.__game.board),0)

    def count_living_cell2(self):
        self.__game.place_pattern(0,0,'beacon')
        self.assertEqual(self.__game.count_cells(0,0,self.__game.board),3)
        self.assertEqual(self.__game.count_cells(1,3,self.__game.board),4)
        self.assertEqual(self.__game.count_cells(0,3,self.__game.board),2)

    def test_tick_spaceship(self):
        self.__game.place_pattern(0,0,'spaceship')
        self.__game.tick(4)
        self.assertEqual(self.__game.board.board[0][1],0)
        self.assertEqual(self.__game.board.board[1],[0,0,1,0,0,0,0,0])
        self.assertEqual(self.__game.board.board[2],[0,0,0,1,0,0,0,0])
        self.assertEqual(self.__game.board.board[3],[0,1,1,1,0,0,0,0])



