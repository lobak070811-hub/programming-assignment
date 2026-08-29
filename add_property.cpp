#include "header.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Property{
	
	string propertyID;
	string roomType;
	string propertyName;
	string location;
	double price;
	double area;
	double distance;
	string publisherID;
	string publisherName;
	string publisherPhone;
	string publisherRole;
	
};

string defaultPropertyID();
void inputProperty();
void displayCurrentInputProperty(const Property &p);

void addProperty(){//mian function
	
	inputProperty();
	
}

string defaultPropertyID(){
	
    Property p;
	
    ifstream file("Property.txt");

    int maxID = 0;
    string line;

    while(getline(file, line))//when open file and read line by line
    {
        if (line.empty())//skip the emtpy line if read an empty line
        {
            continue;
        }

        stringstream ss(line);

        string propertyID;
		getline(ss, propertyID, ',');//read until first ','

        if (propertyID.length() > 1)
        {
            int number;
			
			string numberPart = propertyID.substr(1);//'P001'will read from the second int '0'
			stringstream convert(numberPart);//string to int
			convert >> number; 

            if (number > maxID)//get the biggest ID in txt file
            {
                maxID = number;
            }
        }
    }

    file.close();

    maxID++;

    string numberString;
    stringstream convertID;
    convertID << maxID;
    numberString = convertID.str();
    string newID;

    if (maxID < 10)
    {
        newID = "P00" + numberString;
    }
    else if (maxID < 100)
    {
        newID = "P0" + numberString;
    }
    else
    {
        newID = "P" + numberString;
    }
    return newID;
}

void inputProperty(){
	
	Property p;
 
	p.propertyID = defaultPropertyID();
		
    cout << "\n=============================\n";
    cout << "        ADD PROPERTY\n";
    cout << "=============================\n";
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
    p.publisherID = currentID;
    p.publisherName = currentName;
    p.publisherPhone = currentPhone;
    p.publisherRole = currentRole;
	
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
    
    displayCurrentInputProperty(p);
}

void displayCurrentInputProperty(const Property &p){
	
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
