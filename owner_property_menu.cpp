#include "header.h"

#include <iostream>

using namespace std;

void ownerPropertyMenu()
{
    int choice;

    while (true)
    {
        cout << "\n====================================\n";
        cout << "              OWNER MENU\n";
        cout << "====================================\n";

        cout << "Welcome, " << currentName << "!\n";
        cout << "ID    : " << currentID << endl;
        cout << "Phone : " << currentPhone << endl;

        cout << "\n------------------------------------\n";
        cout << "1. Upload Property\n";
        cout << "2. Edit Property\n";
        cout << "3. Delete Property\n";
        cout << "4. View My Properties\n";
        cout << "5. Log out\n";
        cout << "------------------------------------\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addProperty();
                break;

            case 2:
                editProperty();
                break;

            case 3:
                deleteProperty();
                break;

            case 4:
                viewMyProperty();
                break;

            case 5:
                cout << "\nLogging out...\n";

                //destroy the temporary storage 
                currentID = "";
                currentName = "";
                currentPhone = "";
                currentRole = "";

                return;

            default:
                cout << "\nInvalid choice.\n";
        }
    }
}
