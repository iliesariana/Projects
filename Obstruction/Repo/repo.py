class BoardRepository:
    def __init__(self,board):
        self.__board = board

    def save_board_state(self, board):
        """
        function that saves the current state of the board
        :param board: the board

        """
        self.__board = board

    def get_current_board(self):
        """
        Function that gets the current state of the board
        :return: the state of the board
        """
        return self.__board
    @property
    def board(self):
        """
        Property -board
        :return: the board
        """
        return self.__board
    def board_move(self, point):
        """Function that borders all the existing neighbours of a point, if they exist and they are not bordered
        already"""
        x = point.get_x
        y = point.get_y
        x=int(x)
        y=int(y)
        if x - 1 >= 0 and y - 1 >= 0 and self.__board[x - 1][y - 1] == 0:
            self.get_current_board()[x - 1][y - 1] = -1
        if x - 1 >= 0 and self.__board[x - 1][y] == 0:
            self.__board[x - 1][y] = -1
        if x - 1 >= 0 and y + 1 < self.board.__column and self.__board[x - 1][y + 1] == 0:
            self.__board[x - 1][y + 1] = -1
        if y - 1 >= 0 and self.__board[x][y - 1] == 0:
            self.__board[x][y - 1] = -1
        if y + 1 < self.board.__column and self.__board[x][y + 1] == 0:
            self.__board[x][y + 1] = -1
        if x + 1 < self.board.__row and y + 1 < self.board.__column and self.__board[x + 1][y + 1] == 0:
            self.__board[x + 1][y + 1] = -1
        if x + 1 < self.board.__row and self.__board[x + 1][y] == 0:
            self.__board[x + 1][y] = -1
        if x + 1 < self.board.__row and y - 1 >= 0 and self.__board[x + 1][y - 1] == 0:
            self.__board[x + 1][y - 1] = -1