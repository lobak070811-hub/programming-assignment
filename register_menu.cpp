#include "header.h"

#include <iostream>

using namespace std;

void registerMenu()
{
    int choice;

    while (true)
    {
        cout << "\n=============================\n";
        cout << "          REGISTER\n";
        cout << "=============================\n";
        cout << "1. Register as Student\n";
        cout << "2. Register as Owner\n";
        cout << "3. Register as Agent\n";
        cout << "4. Back to Main Menu\n";
        cout << "=============================\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                studentRegister();
                break;

            case 2:
                ownerRegister();
                break;

            case 3:
                agentRegister();
                break;

            case 4:
                return;

            default:
                cout << "\nInvalid choice.\n";
        }
    }
}
