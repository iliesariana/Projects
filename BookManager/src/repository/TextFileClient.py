from src.domain.Entities import Client
from src.repository.Repository import ClientRepo

class ClientTextFileRepository(ClientRepo):
    def __init__(self,file_name="clients.txt"):
        super().__init__()
        self._file_name=file_name
        self._load_from_file()

    def _load_from_file(self):
        try:
            with open(self._file_name,'r') as fin:
                lines=fin.readlines()
                for line in lines:
                    parts=line.strip().split(',')
                    client=Client(parts[0],parts[1])
                    super().save_client(client)
        except IOError:
            pass

    def save_to_file(self):
        with open(self._file_name,'w') as fout:
            for client in super().find_all_clients():
                client_data = f"{client.id},{client.name}\n"
                fout.write(client_data)

    def save_client(self, new_client:Client):
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






