
#include <iostream>
#include <string>
#include <conio.h>
#include "header.h"


int main()
{
    Employee* emplo = new Employee[amountofemplo];
    const int SIZE = 100;
    char path[SIZE];
    cout << "Type the path to the file: " << endl;
    cin >> path;
    while (1)
    {
        showMenu(path, emplo);
    }
}
