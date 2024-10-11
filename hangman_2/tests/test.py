from unittest import TestCase

from repo.repo import Repo
from services.Controller import Controller


class Test(TestCase):
    def setUp(self):
        self.__repo=Repo()
        self.__controller=Controller(self.__repo)

    def test_repo(self):
        self.assertEqual(len(self.__repo.data),2)
        sentence='El e'
        self.assertRaises(Exception,self.__repo.add_sentence,sentence)
        sentence1 = 'El'
        self.assertRaises(Exception, self.__repo.add_sentence, sentence1)
        s1='Dream without fear'
        s2=self.__controller.modif_sentence(s1)
        self.assertEqual(s2[0],'D')
        self.assertEqual(s2[4],'m')
    def test_service(self):
        self.__controller.sentence='Ana merge acolo'
        self.__controller.display=self.__controller.modif_sentence(self.__controller.sentence)
        self.__controller.add_letter('n')
        self.assertEqual(self.__controller.display,'Ana me__e a_o_o')
        self.__controller.add_letter('x')
        self.assertEqual(self.__controller.hangman,'H______')

    def test_check_win(self):
        self.__controller.sentence = 'Ana merge acolo'
        self.__controller.display = self.__controller.modif_sentence(self.__controller.sentence)
        self.__controller.add_letter('n')
        self.__controller.add_letter('r')
        self.__controller.add_letter('g')
        self.__controller.add_letter('c')
        self.__controller.add_letter('o')
        self.assertEqual(self.__controller.check_win(),False)
        self.__controller.add_letter('l')
        self.assertEqual(self.__controller.check_win(), True)







