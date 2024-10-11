import pickle

from src.repository.Repository import BookRepo


class BookBinaryFile(BookRepo):
    def __init__(self,file_name="book.bin"):
        super().__init__()
        self._file_name=file_name
        self._load_from_file()

    def _load_from_file(self):
        try:
            fin = open(self._file_name, 'rb')
            obj = pickle.load(fin)
        except EOFError:
            return
        for new_book in obj:
            super().save_book(new_book)
        fin.close()

    def save_to_file(self):
        fout=open(self._file_name,"wb")
        pickle.dump(self.find_all_books(),fout)
        fout.close()


    def save_book(self, new_book):
        """
        Saves a book to the file and repository
        """
        super().save_book(new_book)
        self.save_to_file()

    def delete_book_book_id(self, book_id):
        """
        Deletes a book by ID from the file and repository
        """
        super().delete_book_book_id(book_id)
        self.save_to_file()

    def update_book(self, book):
        """
        Updates a book in the file and repository
        """
        super().update_book(book)
        self.save_to_file()

    def find_all_books(self):
        """
        Returns all books from the repository
        """
        return super().find_all_books()

    def delete_all_books(self):
        """
        Deletes all books from the file and repository
        """
        super().delete_all_books()
        self.save_to_file()
