#include "header.h"

#include <iostream>

using namespace std;

void mainMenu();

int main(){
	
	mainMenu();
	
	return 0;
}

void mainMenu()
{
    int choice;

    while (true)
    {
        cout << "\n=============================\n";
        cout << "   Accommodation System\n";
        cout << "=============================\n";
        cout << "1. Log in\n";
        cout << "2. Register\n";
        cout << "3. Exit\n";
        cout << "=============================\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                loginMenu();
                break;

            case 2:
                registerMenu();
                break;

            case 3:
                cout << "\nThank you for using the system.\n";
                return 0;

            default:
                cout << "\nInvalid choice.\n";
        }
    }
}

