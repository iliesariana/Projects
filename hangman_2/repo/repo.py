import random

class Repo:
    def __init__(self):
        self.__data=[]
        self.load_from_file()
        self.validator=Validator()

    @property
    def data(self):
        return self.__data
    def load_from_file(self):
        with open("date.txt",'r') as f:
            lines=f.readlines()
        for line in lines:
            line=line.strip()
            if line=="":
                continue
            self.__data.append(line)

    def save_to_file(self):
        with open("date.txt",'w') as f:
            for el in self.__data:
                f.write(f"{el}\n")

    def get_random_sentence(self):
        sentence=random.choice(self.__data)
        return sentence
    def add_sentence(self,s):
        self.validator.validate_sentence(s)
        self.__data.append(s)

class Validator:
    def validate_sentence(self,sentence):
        sentence=sentence.strip()
        words=sentence.split(' ')
        if len(words)<1:
            raise Exception("Min 1 word")
        for w in words:
            if len(w)<3:
                raise Exception("Min 3 letters")



