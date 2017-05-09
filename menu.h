#ifndef MENU_H
#define MENU_H
#include "Database.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>

class Menu
{
    public:
        void displayMenu(Database database);
        void printAirport(node<int, Airport>* toPrint);
        void printAllAirports(Database toPrint);
        void exportDatabase(Database toExport);
        Menu();
        ~Menu();
    private:
};

#endif // MENU_H
