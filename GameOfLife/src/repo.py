import pickle


class RepoError(Exception):
    pass


class Repo:
    def __init__(self):
        self.__patterns={}
        self.load_patterns()

    def get_all(self):
        """
        Function that returns the list of all the patterns loaded from file
        :return:The dictionary representing the patterns
        """
        return self.__patterns
    def load_patterns(self):
        """
        Function that loads patterns from file. It reads line by line the name
        of the pattern and the pattern itself,savin in the dictionary the coordinates where
        a pattern places a living cell

        """
        with open('patterns.txt','r') as f:
            lines=f.readlines()
        for line in lines:
            line=line.strip()
            if line=="":
                continue
            if ':' in line:
                name=line[:-1]
                self.__patterns[name]=[]
                row=0
            else:
                for i,ch in enumerate(line):
                    if ch=='X':
                        self.__patterns[name].append((row,i))
                row+=1

    def save_to_file(self,file_name,board):
        with open(file_name,'wb') as f:
            pickle.dump(board,f)

    def load_from_file(self,file_name):
        try:
            with open(file_name,'rb') as f:
                board=pickle.load(f)
            return board
        except FileNotFoundError:
            raise RepoError("Not such file")


