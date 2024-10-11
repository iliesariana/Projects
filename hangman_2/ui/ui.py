from services.Controller import GameOver


class UI:
    def __init__(self,controller):
        self.__controller=controller

    def start(self):
        sentence=input("enter a sentence:")

        try:
            self.__controller.add_sentence(sentence)

        except Exception as ve:
            print(ve)
        while True:
            print(self.__controller.display)
            print(self.__controller.hangman)
            if self.__controller.check_win():
                print("You won")
                break

            letter=input("letter")
            try:
                self.__controller.add_letter(letter)
                if self.__controller.hangman=='HANGMAN':
                    print(self.__controller.hangman)
                    print("GAME OVER")
                    break
            except GameOver as ve:
                print(ve)


