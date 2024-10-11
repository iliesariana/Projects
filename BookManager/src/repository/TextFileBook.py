from src.repository.Repository import BookRepo
from src.domain.Entities import Book

from src.repository.Repository import BookRepo
from src.domain.Entities import Book

class BookTextFileRepository(BookRepo):
    """
    Data saved in 'book.txt' and inherits all the methods and functions from BookRepo
    """
    def __init__(self, file_name="book.txt"):
        """
        Inherits the necessary methods and additionally requires a file
        to which we load from
        """
        super().__init__()
        self._file_name = file_name
        self._load_from_file()

    def _load_from_file(self):
        """
        Opens the text file, reads lines, and splits them to create new Book objects
        def __init__(self, id, book_id, cl_id, rent_date, returned_date):
        """
        try:
            with open(self._file_name, 'r') as fin:
                lines = fin.readlines()
                for line in lines:
                    parts = line.strip().split(",")
                    new_book = Book(parts[0], parts[1], parts[2],parts[3])
                    super().save_book(new_book)
        except IOError:
            pass

    def save_to_file(self):
        """
        Writes the data back into the file
        """
        with open(self._file_name, "w") as fout:
            for book in super().find_all_books():
                book_data = f"{book.book_id},{book.title},{book.author},{book.is_available}\n"
                fout.write(book_data)

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
