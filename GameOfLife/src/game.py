from copy import deepcopy

from src.board import Board


class PatternError(Exception):
    pass


class Game:
    def __init__(self,repo):
        self.__repo=repo
        self.__board=Board()
    @property
    def board(self):
        return self.__board

    @board.setter
    def board(self,value):
        self.__board=value
    def count_cells(self,x,y,board):
        """
        Function that count the living cells around a given cell
        :param x: The x coordinate of the x cell
        :param y: The y coordinate of the y cell
        :param board: The board on with the counting is done
        :return: The number of living cells
        """
        cnt=0
        for i in [-1,0,1]:
            for j in [-1,0,1]:
                nx=x+i
                ny=y+j
                if 0<=nx<=7 and 0<=ny<=7 and board.board[nx][ny]==1 and (i,j)!=(0,0):
                    cnt+=1
        return cnt

    def save_to_file(self,file_name):
        self.__repo.save_to_file(file_name,self.board)
    def load_from_file(self,file_name):
        return self.__repo.load_from_file(file_name)


    def tick(self,n):
        """
        Function that creates new generations. It checks for every live and dead cell how many live neighbours
        it has and if the conditions are obeyed it transforms the grid
        :param n: The number of states to be advanced with

        """
        for _ in range(n):
            new_board=deepcopy(self.board)
            for i in range(8):
                for j in range(8):
                    if new_board.board[i][j]==1:
                        if self.count_cells(i,j,new_board)<2:

                            self.board.board[i][j]=0
                        if self.count_cells(i,j,new_board)>3:
                            self.board.board[i][j]=0
                    elif new_board.board[i][j]==0:
                        if self.count_cells(i,j,new_board)==3:
                            self.board.board[i][j]=1
    def continue_game(self,board):
        self.board=board

    def place_pattern(self,x,y,pattern):
        """
        Function that places a certain pattern at coordinates x,y
        if the pattern overlaps another one or it gets outside of bounds it raises a value error
        :param x: the x coordinate
        :param y: the y coordinate
        :param pattern: the pattern that has to be placed
        :return: PatternError in case of wrong pattern or coordinates
        """
        if pattern not in self.__repo.get_all().keys():
            raise PatternError("The pattern does not exist")
        coord=self.__repo.get_all()[pattern]
        for pair in coord:
            i,j=pair
            nx=i+x
            ny=j+y
            if not 0<=nx<=7 :
                raise PatternError("Pattern would be outside the board")
            if not 0<=ny<=7:
                raise PatternError("pattern would be outside the board")
            if self.board.board[nx][ny]!=0:
                raise PatternError("Can not overlap other patterns")

        for pair in coord:
            i,j=pair
            nx = i + x
            ny = j + y
            self.__board.board[nx][ny]=1





