from src.game import PatternError
from src.repo import RepoError


class CoordinateException(Exception):
    pass


class SaveException(Exception):
    pass


class CommandException(Exception):
    pass


class UI:
    def __init__(self,game):
        self.__game=game

    def print_menu(self):
        print("You can add a pattern,save to file,load to file.Type 'exit' to exit the program")
    def start(self):
        while True:
            print(self.__game.board)
            self.print_menu()
            option=input(">>>").strip().lower()
            tokens=option.split()
            if tokens[0]=='place':
                try:
                    if len(tokens)!=3:
                        raise CommandException('Wrong command,try again')
                    if ',' not in tokens[2]:
                        raise CommandException('Wrong command')
                    coord=tokens[2].split(',')
                    try:
                        x=int(coord[0])
                        y=int(coord[1])
                    except ValueError :
                        raise CoordinateException('Coordinates must be integers')
                    if x<0 or x>8 or y<0 or y>8:
                        raise CoordinateException('Coordinates out of bounds')

                    pattern=tokens[1]
                    try:
                        self.__game.place_pattern(x,y,pattern)
                    except PatternError as ve:
                        print(ve)
                except CoordinateException as c:
                    print(c)
                except CommandException as c1:
                    print(c1)

            elif tokens[0]=='tick':
                if len(tokens)==1:
                    self.__game.tick(1)
                else:
                    try:
                        n=int(tokens[1])
                        self.__game.tick(n)
                    except ValueError:
                        print("n must be an integer")
            elif tokens[0]=='save':
                try:
                    if len(tokens)!=2:
                        raise SaveException('Wrong command')
                    filename=tokens[1]
                    self.__game.save_to_file(filename)
                except SaveException as ve:
                    print(ve)
            elif tokens[0]=='load':
                try:
                    if len(tokens)!=2:
                        raise SaveException('Wrong command')

                    file_name=tokens[1]
                    try:
                        new_board=self.__game.load_from_file(file_name)
                        self.__game.continue_game(new_board)
                    except RepoError as ve:
                        print(ve)
                except SaveException as c2:
                    print(c2)
            elif tokens[0]=='exit':
                break
            else:
                print("Invalid command.Please try again")