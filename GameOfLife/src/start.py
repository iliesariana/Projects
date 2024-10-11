from src.UI import UI
from src.board import Board
from src.game import Game
from src.repo import Repo

repo=Repo()
game=Game(repo)
ui=UI(game)
ui.start()
