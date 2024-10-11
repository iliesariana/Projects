class GameOver(Exception):
    pass


class Controller:
    def __init__(self,repo):
        self.__repo=repo
        self.__sentence=self.__repo.get_random_sentence()
        self.__display=self.modif_sentence(self.__sentence)
        self.__hangman='_______'
        self.letters=[]
    @property
    def display(self):
        return self.__display
    @property
    def hangman(self):
        return self.__hangman
    @hangman.setter
    def hangman(self,val):
        self.__hangman=val
    @display.setter
    def display(self,val):
        self.__display=val
    @property
    def sentence(self):
        return self.__sentence
    @sentence.setter
    def sentence(self,val):
        self.__sentence=val
    def modif_sentence(self,sentence):
        words=sentence.split()
        new_words=[]
        for word in words:
            first=word[0]
            last=word[-1]
            new_word=''
            for i in range(len(word)):
                if word[i]==last or word[i]==first:
                    new_word+=word[i]
                else:
                    new_word+='_'
            new_words.append(new_word)
        new_sentence=' '.join(new_words)
        return new_sentence

    def modif_hangman(self):
        word='HANGMAN'
        new_word=""
        ok=0
        for i in range(7):
            if ok==0:
                if self.hangman[i]=='_':
                    new_word+=word[i]
                    ok=1
                else:
                    new_word+=self.hangman[i]
            else:
                new_word+=self.hangman[i]
        self.hangman=new_word

    def check_win(self):
        if '_' not in self.display:
            return True
        return False
    def add_sentence(self,s):
        self.__repo.add_sentence(s)
        self.modif_hangman()

    def add_letter(self,letter):
        if letter in self.letters:
            self.modif_hangman()

            return
        self.letters.append(letter)
        words=self.__sentence.split()
        words_split=self.display.split()
        new_words=[]
        ok=0
        for i,word in enumerate(words):
            new_word=''
            for j,c in enumerate(word):
                if c==letter and words_split[i][j]=='_':
                    ok=1
                    new_word+=c
                else:
                    new_word+=words_split[i][j]
            new_words.append(new_word)
        new_display=" ".join(new_words)
        self.display=new_display
        if ok==0:
            self.modif_hangman()

    def game_over(self):
        pass




