from src.repository.Repository import RentRepo
import pickle

class RentBinaryFile(RentRepo):
    def __init__(self,file_name="rentals.bin"):
        super().__init__()
        self._file_name=file_name
        self._load_from_file()

    def _load_from_file(self):
        try:
            fin = open(self._file_name, 'rb')
            obj = pickle.load(fin)
        except EOFError:
            return

        for new_rent in obj:
            super().save_rental(new_rent)
        fin.close()

    def save_to_file(self):
        fout = open(self._file_name, "wb")
        pickle.dump(self.find_all_rentals(), fout)
        fout.close()

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
