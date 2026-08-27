#include "header.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addProperty(){//main function
	
    Property p;

	string defaultPropertyID(){
	
    ifstream file("Property.txt");

    int maxID = 0;
    string line;

    while (getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }

        stringstream ss(line);

        string propertyID;

        getline(ss, propertyID, ',');

        if (propertyID.length() > 1)
        {
            int number = stoi(propertyID.substr(1));

            if (number > maxID)
            {
                maxID = number;
            }
        }
    }

    file.close();

    maxID++;

    string newID;

    if (maxID < 10)
    {
        newID = "P00" + to_string(maxID);
    }
    else if (maxID < 100)
    {
        newID = "P0" + to_string(maxID);
    }
    else
    {
        newID = "P" + to_string(maxID);
    }

    return newID;
	}
	
	p.propertyID = defaultPropertyID();
		
    cout << "\n=============================\n";
    cout << "        ADD PROPERTY\n";
    cout << "=============================\n";

    cout << "Property ID  : ";
    cin >> p.propertyID;

    cout << "Room Type\n";
    cout << "1. Master\n";
    cout << "2. Middle\n";
    cout << "3. Small\n";

    int roomChoice;
    cout << "Enter choice: ";
    cin >> roomChoice;

    switch (roomChoice)
    {
        case 1:
            p.roomType = "Master";
            break;

        case 2:
            p.roomType = "Middle";
            break;

        case 3:
            p.roomType = "Small";
            break;

        default:
            cout << "Invalid room type.\n";
            return;
    }

    cin.ignore();

    cout << "Property Name : ";
    getline(cin, p.propertyName);

    cout << "Location      : ";
    getline(cin, p.location);

    cout << "Price (RM)    : ";
    cin >> p.price;

    cout << "Area (sqft)   : ";
    cin >> p.area;

    cout << "Distance from school (km): ";
    cin >> p.distance;

    // Publisher information
    p.publisherID = publisherID;
    p.publisherName = publisherName;
    p.publisherPhone = publisherPhone;
    p.publisherRole = publisherRole;
	
    ofstream file("Property.txt", ios::app);// Save to Property.txt

    if (!file)
    {
        cout << "Cannot open Property.txt\n";
        return;
    }

    file << p.propertyID << ","
         << p.roomType << ","
         << p.propertyName << ","
         << p.location << ","
         << p.price << ","
         << p.area << ","
         << p.distance << ","
         << p.publisherID << ","
         << p.publisherName << ","
         << p.publisherPhone << ","
         << p.publisherRole
         << endl;

    file.close();
	
	//show added property
    cout << "\n====================================\n";
    cout << "       PROPERTY ADDED SUCCESSFULLY\n";
    cout << "====================================\n";

    cout << "Property ID     : " << p.propertyID << endl;
    cout << "Room Type       : " << p.roomType << endl;
    cout << "Property Name   : " << p.propertyName << endl;
    cout << "Location        : " << p.location << endl;
    cout << "Price           : RM" << p.price << endl;
    cout << "Area            : " << p.area << " sqft" << endl;
    cout << "Distance        : " << p.distance << " km" << endl;
    cout << "Published By    : " << p.publisherName << endl;
    cout << "Role            : " << p.publisherRole << endl;
    cout << "Phone           : " << p.publisherPhone << endl;

    cout << "====================================\n";
}
