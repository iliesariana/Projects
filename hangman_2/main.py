
from repo.repo import Repo
from services.Controller import Controller
from ui.ui import UI

repo=Repo()
game=Controller(repo)
ui=UI(game)
ui.start()