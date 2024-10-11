from src.repository.Repository import BookRepo, ClientRepo, RentRepo
from src.repository.TextFileClient import ClientTextFileRepository
from src.repository.TextFileRent import RentTextFileRepository
from src.services.BookService import BookService
from src.services.ClientService import ClientService
from src.services.RentalService import RentalService
from src.tests.ServiceTest import init_tests
from src.ui.menu import Menu
from jproperties import Properties
from src.repository.TextFileBook import BookTextFileRepository
from jproperties import Properties
from src.repository.BinaryFileBook import BookBinaryFile
from src.repository.BinaryFileClient import ClientBinaryFile
from src.repository.BinaryFileRent import RentBinaryFile
import atexit
def use_properties():
    
    configs = Properties()
    with open('settings.properties', 'rb') as config_file:
        configs.load(config_file)

    repo_command = configs.get("repository").data
    book = configs.get("book").data
    client = configs.get("client").data
    rental= configs.get("rental").data
    print(repo_command, book[1:-1], client[1:-1],rental[1:-1])
    b=book[1:-1]
    c=client[1:-1]
    r=rental[1:-1]
    repo1 = ''
    repo2 = ''
    repo3 = ''
    print("The repository in use is: ", repo_command)
    if repo_command == "inmemory":
        repo1 = BookRepo()
        repo2 = ClientRepo()
        repo3 = RentRepo()

    elif repo_command == "textfiles":
        repo1 = BookTextFileRepository(b)
        repo2 = ClientTextFileRepository(c)
        repo3= RentTextFileRepository(r)

    elif repo_command == "binaryfiles":
        repo1 = BookBinaryFile(b)
        repo2 = ClientBinaryFile(c)
        repo3= RentBinaryFile(r)

    return repo1,repo2,repo3,repo_command

if __name__ == '__main__':

    b_rep,c_rep,rent_rep,repo_command=use_properties()
    """

    def save_final_state():
        b_rep.save_to_file()  # Save books to file
        c_rep.save_to_file()  # Save clients to file
        rent_rep.save_to_file()  # Save rentals to file
    b_rep, c_rep, rent_rep=BookTextFileRepository(),ClientTextFileRepository(),RentTextFileRepository()
    """
    b_service, c_service = BookService(b_rep), ClientService(c_rep, rent_rep, b_rep)

    r_service = RentalService(rent_rep, b_rep, c_rep)

    ui = Menu(b_service, c_service, r_service)

    init_tests(b_service, c_service)

    ui.run_console()

    """
    from src.repository.Repository import BookRepo, ClientRepo, RentRepo
    from src.services.BookService import BookService
    from src.services.ClientService import ClientService
    from src.services.RentalService import RentalService
    from src.tests.ServiceTest import init_tests
    from src.ui.menu import Menu
    #from src.services.UndoRedo import UndoService
    if __name__ == '__main__':
        b_rep=BookRepo()
        c_rep, rent_rep =ClientRepo(), RentRepo()
        #undo_service = UndoService()
        b_service, c_service = BookService(b_rep), ClientService(c_rep, rent_rep, b_rep)

        r_service = RentalService(rent_rep, b_rep, c_rep)

        ui = Menu(b_service, c_service, r_service,undo_service)

        init_tests(b_service, c_service)

        ui.run_console()

    """













    if repo_command=="textfiles" or repo_command=="binaryfiles":
        def save_final_state():
            b_rep.save_to_file()  # Save books to file
            c_rep.save_to_file()  # Save clients to file
            rent_rep.save_to_file()  # Save rentals to file
        atexit.register(save_final_state)
"""
from src.repository.Repository import BookRepo, ClientRepo, RentRepo
from src.services.BookService import BookService
from src.services.ClientService import ClientService
from src.services.RentalService import RentalService
from src.tests.ServiceTest import init_tests
from src.ui.menu import Menu
#from src.services.UndoRedo import UndoService
if __name__ == '__main__':
    b_rep=BookRepo()
    c_rep, rent_rep =ClientRepo(), RentRepo()
    #undo_service = UndoService()
    b_service, c_service = BookService(b_rep), ClientService(c_rep, rent_rep, b_rep)

    r_service = RentalService(rent_rep, b_rep, c_rep)

    ui = Menu(b_service, c_service, r_service,undo_service)

    init_tests(b_service, c_service)

    ui.run_console()
    
"""
