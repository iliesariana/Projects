from domain import *
import random

from domain.domain import Sentence
class FileRepo:
    def __init__(self,file_name):
        self._entities=[]
        self._filename=file_name
        #self._readEntity=readEntity
        self.__load_from_file()


    def __load_from_file(self):
        self._entities=[]
        with open(self._filename,'r') as f:
            lines=f.readlines()
            for line in lines:
                if line != "":
                    entity = line.strip()
                    self._entities.append(Sentence(entity))

    def get_all(self):
        return self._entities

    def select_random(self):
        list = self.get_all()
        entity= random.choice(list)
        return entity
    def compute_score(self,sentence):
        tokens=sentence.Sentence.split(' ')
        score=0
        for token in tokens:
            score=score+len(token)
        sentence.Score=score

    def undo(self,sentence):
        if len(sentence.History)==0:
            raise Exception("can not undo")
        sentence.Display=sentence.History[-1]
        sentence.History.pop()

    def scramble_sentence(self,Sentence):
        prop=Sentence.Sentence
        ch=[]
        new_words=[]

        words=Sentence.Sentence.split()
        for word in words:
            for i,c in enumerate(word):
                if i!=0 and i!=len(word)-1:
                    ch.append(c)
        for word in words:
            new_word=''
            for i in range(0,len(word)):
                if i==0 or i==len(word)-1:
                    new_word+=word[i]
                else:
                    new_ch=random.choice(ch)
                    new_word+=new_ch
            new_words.append(new_word)

        Sentence.Display=' '.join(new_words)






