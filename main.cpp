#include <iostream>
#include <iomanip>
#include <string.h>
#include "test.h"
#include "menu.h"

int main()
{
    /*Database myDatabase;
    Menu newMenu;
    newMenu.displayMenu(myDatabase);*/
    //Database newDatabase;
    //Airport a1("Balice", "Polska", 1, 5);
    //newDatabase.addAirport(5, a1, newDatabase.getRoot());
    myMap<int, Airport> newMap;
    Airport a1("Balice", "Polska", 100, 5);
    newMap.addNode(6, a1, newMap.getRoot());
    std::cout<<"FUCK YOU"<<std::endl;
    return 0;
}
