from domain.domain import Board
from service.ai import Game
from ui.gui import GameGUI
game = Game(Board())

from ui.console import Console

"""
ui = Console(game)
ui.start()
"""
ui=GameGUI(game)




