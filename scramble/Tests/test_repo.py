from unittest import TestCase

from domain.domain import Sentence
from game_play.gameplay import GamePlay
from repo.repo import FileRepo


class TestRepo(TestCase):
    def setUp(self):
        self.__repo=FileRepo('file.txt')

    def test_add(self):
        x=len(self.__repo._entities)
        self.assertEqual(x,3)
        sentence=self.__repo._entities[0]
        self.__repo.compute_score(sentence)
        self.assertEqual(sentence.Score,10)

class TestService(TestCase):
    def setUp(self):
        self.__repo = FileRepo('file.txt')
        self.__service=GamePlay(self.__repo)

    def test_swap(self):
        sentence = self.__repo._entities[0]
        prop=Sentence(sentence)
        prop.Display='Ana arm eere'
        self.assertRaises(Exception,self.__service.undo,sentence)
        self.__service.swap(prop,1,2,2,0)

        self.assertEqual(prop.Display,'Ana are mere')
        self.__service.undo(prop)

        self.assertEqual(prop.Display, 'Ana arm eere')


