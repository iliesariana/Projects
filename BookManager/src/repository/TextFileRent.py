from src.domain.Entities import Rental
from src.repository.Repository import RentRepo


class RentTextFileRepository(RentRepo):

    def __init__(self,file_name="rentals.txt"):
        super().__init__()
        self._file_name = file_name

        self._load_from_file()

    def _load_from_file(self):
        """
        Opens the text file, reads lines, and processes them to create new Rental objects.
        """
        try:
            with open(self._file_name, 'r') as fin:
                lines = fin.readlines()
                """
                  def __init__(self, id, book_id, cl_id, rent_date, returned_date):
                """
                for line in lines:
                    parts = line.strip().split(",")
                    # Assuming Rental class structure and how data is stored in the file
                    new_rental = Rental(parts[0], parts[1], parts[2],parts[3],parts[4])  # Adjust this as needed
                    super().save_rental(new_rental)
        except IOError:
            pass

    def save_to_file(self):
        """
        Writes the data back into the file.
        """
        with open(self._file_name, "w") as fout:
            for rental in super().find_all_rentals():
                rental_data = f"{rental.id},{rental.book_id},{rental.cl_id},{rental.rent_date},{rental.returned_date}\n"
                fout.write(rental_data)

    def save_rental(self, new_rental):
        """
        Saves a rental to the file and repository.
        """
        super().save_rental(new_rental)
        self.save_to_file()

    def delete_rental(self, id):
        super().delete_rental(id)
        self.save_to_file()


    def update_rental(self, id, rental):
        super().update_rental(id,rental)
        self.save_to_file()


    def delete_all_rentals(self):
        super().delete_all_rentals()
        self.save_to_file()


    def find_all_rentals(self):
        return super().find_all_rentals()
