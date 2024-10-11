import pickle

from src.domain.Entities import Client
from src.repository.Repository import ClientRepo


class ClientBinaryFile(ClientRepo):
    def __init__(self,file_name="clients.bin"):
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
            super().save_client(new_book)
        fin.close()

    def save_to_file(self):
        fout=open(self._file_name,"wb")
        pickle.dump(self.find_all_clients(),fout)
        fout.close()

    def save_client(self, new_client: Client):
        super().save_client(new_client)
        self.save_to_file()

    def delete_client_id(self, id):
        super().delete_client_id(id)
        self.save_to_file()

    def update_client(self, client):
        super().update_client(client)
        self.save_to_file()

    def find_all_clients(self):
        return super().find_all_clients()

    def delete_all_clients(self):
        super().delete_all_clients()
        self.save_to_file()