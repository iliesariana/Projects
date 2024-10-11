from domain import *
from domain.domain import Sentence
from game_play.gameplay import GamePlay
from repo.repo import FileRepo
from ui.ui import UI

repo=FileRepo('fiel.txt')
list=repo.get_all()
game=GamePlay(repo)

ui=UI(game)
ui.print_menu()
# sentence=game.select_random()
# game.scramble_sentence(sentence)
# print(sentence.Sentence)
# print(sentence.Display)
# game.compute_score(sentence)
# ui.swap(sentence,1,1,2,1)
