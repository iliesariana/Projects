import texttable


class Board:
    def __init__(self):
        self.__board=[]
        self.create_board()
    @property
    def board(self):
        return self.__board
    def create_board(self):
        for i in range(8):
            arr=[]
            for j in range(8):
                arr.append(0)
            self.__board.append(arr)

    def __str__(self):
        table=texttable.Texttable()
        for i in range(8):
            row=[]
            for j in range(8):
                if self.__board[i][j]==0:
                    row.append(' ')
                else:
                    row.append('X')
            table.add_row(row)
        return table.draw()



