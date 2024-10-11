from domain.domain import Sentence


class RepoException:
    pass


class UI:
    def __init__(self,game):
        self.game=game
        self.validator=Validator()
    def swap(self,sentence,word1,letter1,word2,letter2):
        self.game.swap(sentence,word1,letter1,word2,letter2)
        print(sentence.Display.strip() + " score is: " + str(sentence.Score))

    def scramble_sentence(self,sentence):
        self.game.scramble_sentence(sentence)

    def compute_score(self,sentence):
        self.game.compute_score(sentence)
    def undo(self,sentence):
        self.game.undo(sentence)
    def print_menu(self):
        sentence = self.game.select_random()
        self.game.scramble_sentence(sentence)
        self.compute_score(sentence)
        while True:

            print(sentence.Display)
            option=input(">>>>")
            option = option.lower().strip()
            tokens = option.split(' ')
            if len(tokens)>1:
                try:
                    self.validator.validate_input(option)
                    option=option.lower().strip()
                    word1=int(tokens[1])
                    letter2=int(tokens[3])
                    val_mij = tokens[2].split('-')

                    letter1=int(val_mij[0])
                    word2=int(val_mij[1])
                    self.swap(sentence,word1,letter1,word2,letter2)
                except Exception  as ve:
                    print(ve)
            elif option=='undo':
                try:
                    self.game.undo(sentence)
                    print(sentence.Display)
                except Exception as ve:
                    print(ve)
            elif option=='x':
                break





class Validator:
    @staticmethod
    def validate_input(input):
        input.lower().strip()
        tokens=input.split(' ')
        if tokens[0]!='swap':
            raise Exception('wrong command')
        try:
           int(tokens[1])
           int(tokens[3])
        except Exception:
            raise Exception('integers must be given')
        val_mij=tokens[2].split('-')
        try:
            int(val_mij[0])
            int(val_mij[1])
        except Exception:
            raise Exception("integers must be given")


