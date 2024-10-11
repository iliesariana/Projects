import texttable

from domain.Point  import Point


class Board:
    def __init__(self, row=0, column=0):
        self.__row = row
        self.__column = column
        self.__board = []

    @property
    def row(self):
        """Returns the number of rows"""
        return self.__row

    @property
    def column(self):
        """Returns the number of columns"""
        return self.__column

    @row.setter
    def row(self, row):
        """Setting the row"""
        self.__row = row

    @column.setter
    def column(self, column):
        """Setting the column"""
        self.__column = column

    def available_move(self):
        """Function that returns the available moves"""
        move = []
        for x in range(self.row):
            for y in range(self.column):
                if self.__board[x][y] == 0:
                    move.append(Point(x, y))
        return move

    def board_move(self, point):
        """Function that borders all the existing neighbours of a point, if they exist and they are not bordered
        already"""
        x = point.get_x
        y = point.get_y
        x=int(x)
        y=int(y)
        if x - 1 >= 0 and y - 1 >= 0 and self.__board[x - 1][y - 1] == 0:
            self.__board[x - 1][y - 1] = -1
        if x - 1 >= 0 and self.__board[x - 1][y] == 0:
            self.__board[x - 1][y] = -1
        if x - 1 >= 0 and y + 1 < self.__column and self.__board[x - 1][y + 1] == 0:
            self.__board[x - 1][y + 1] = -1
        if y - 1 >= 0 and self.__board[x][y - 1] == 0:
            self.__board[x][y - 1] = -1
        if y + 1 < self.__column and self.__board[x][y + 1] == 0:
            self.__board[x][y + 1] = -1
        if x + 1 < self.__row and y + 1 < self.__column and self.__board[x + 1][y + 1] == 0:
            self.__board[x + 1][y + 1] = -1
        if x + 1 < self.__row and self.__board[x + 1][y] == 0:
            self.__board[x + 1][y] = -1
        if x + 1 < self.__row and y - 1 >= 0 and self.__board[x + 1][y - 1] == 0:
            self.__board[x + 1][y - 1] = -1

    def __len__(self):
        """Overriding the len function"""
        return len(self.__board)

    def __str__(self):
        """
        Ovewrites the str function
        :return: str representing the board
        """
        table=texttable.Texttable()
        headers=[' ']
        for x in range(self.column):
            headers.append(str(x))
        table.header(headers)
        for i in range(self.row):
            row=[str(i)]
            for j in range(self.column):
                if self.board[i][j]==1:
                    row.append(' 0 ')
                elif self.board[i][j]==2:
                    row.append(' X ')
                elif self.board[i][j]==-1:
                    row.append('|||')
                else:
                    row.append('   ')
            table.add_row(row)
        return table.draw()


    @property
    def board(self):
        """Function that returns the board"""
        return self.__board
    @board.setter
    def board(self,i,j,val):
        self.__board[i][j]=val

    def create_board(self):
        """
        This function creates the board with the corresponding dimension.
        The board will be a list of lists, each list will represent a row, and each element of these lists will
        represent a column.
        The board will have self.__row lists and each list will have self.__column elements.
        """
        for x in range(self.__row):
            array = []
            for y in range(self.__column):
                array.append(0)
            self.__board.append(array)

    def destroy_board(self):
        """Function that sets the board to the "default" size"""
        self.__board = []
        self.__row = 0
        self.__column = 0


class ValidatePoint:
    @staticmethod
    def valid_point(x, y, board):
        """Function that validates the coordinates of a point given"""
        try:
            x = int(x)
            y = int(y)
        except ValueError:
            raise Exception("Please give integers!")
        if y < 0 or x < 0 or y >= board.column or x >= board.row:
            raise Exception("Point out of border!")
        if board.board[x][y] == -1 or board.board[x][y] == 1 or board.board[x][y] == 2:
            raise Exception("Square already taken!")