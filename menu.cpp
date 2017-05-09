#include "menu.h"

Menu::Menu()
{
    //ctor
}
void Menu::displayMenu(Database newDatabase)
{
    int option;
    std::cout<<"Welcome to airport database"<<std::endl;
    while (true)
    {
        std::cout<<"MAIN MENU"<<std::endl;
        std::cout<<"---------"<<std::endl;
        std::cout<<"1. Add airport"<<std::endl;
        std::cout<<"2. Delete airport"<<std::endl;
        std::cout<<"3. Edit airport"<<std::endl;
        std::cout<<"4. Display airport"<<std::endl;
        std::cout<<"5. Display all airports"<<std::endl;
        std::cout<<"6. Export database to a file"<<std::endl;
        std::cout<<"7. Exit"<<std::endl;
        std::cout<<"What do you want to do? Enter correct number"<<std::endl;
        std::cin>>option;
        if (std::cin.fail())
        {
            std::cout<<"Bad input"<<std::endl;
            system("cls");
            return;
        }
        switch(option)
        {
            case 1:
            {
                system("cls");
                int k;
                std::cout<<"Type the key: ";
                std::cin>>k;
                std::string x;
                std::cout<<"Type the name of the airport: ";
                std::cin>>x;
                std::cin.ignore(100,'\n');
                std::string y;
                std::cout<<"Type the country of the airport: ";
                std::cin>>y;
                std::cin.ignore(100,'\n');
                int a;
                std::cout<<"Type the number of terminals: ";
                std::cin>>a;
                int b;
                std::cout<<"Type the number of runways: ";
                std::cin>>b;
                newDatabase.addAirport(k, x, y, a, b);
            }
            break;

            case 2:
            {

            }
            break;

            case 3:
            {

            }
            break;

            case 4:
            {
                system("cls");
                int k;
                std::cout<<"Type the key: ";
                std::cin>>k;
                printAirport(newDatabase.findAirportN(k));
            }

            case 5:
            {

            }
            break;

            case 6:
            {

            }
            break;

            case 7:
            {
                system("cls");
                std::cout<<"Goodbye";
                exit(0);
            }

            default:
            std::cout<<"There is no such an option"<<std::endl;
            getchar();
        }

        std::cout<<"For next activity click press enter";
        getchar();
        system("cls");
    }
}

void Menu::printAirport(node<int, Airport>* toPrint)
{
    std::cout<<toPrint->key<<" "<<toPrint->item.getName()<<" "<<toPrint->item.getCountry()<<" "<<
    toPrint->item.getTerNum()<<" "<<toPrint->item.getRunNum()<<std::endl;
}
void Menu::printAllAirports(Database toPrint)
{

}
void Menu::exportDatabase(Database toExport)
{

}
Menu::~Menu()
{
    //dtor
}
