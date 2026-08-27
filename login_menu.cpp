#include "header.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//temporary storage to save log in details, destroyed after finish editing
string currentID;
string currentName;
string currentPhone;
string currentRole;

bool checkLogin(string filename, string inputID, string inputPassword)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        return false;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string id;
        string name;
        string phone;
        string email;
        string password;

        // Read each field from the .txt file
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, password);

        // Check ID and Password
        if (id == inputID && password == inputPassword)
        {
            file.close();
            return true;
        }
    }

    file.close();

    return false;
}

void login(){//main function 

    string inputID;
    string inputPassword;

    cout << "\n=============================\n";
    cout << "           LOG IN\n";
    cout << "=============================\n";

    cout << "ID       : ";
    cin >> inputID;

    cout << "Password : ";
    cin >> inputPassword;

    // Check Student
    if (checkLogin("Student.txt", inputID, inputPassword))
    {
        cout << "\nLogin Successful!\n";
        cout << "Welcome, Student " << inputID << "!\n";

        // Later:
        // studentMenu();

        return;
    }

    // Check Owner
	if (checkLogin("Owner.txt", inputID, inputPassword))
	{
    	currentID = inputID;

    	getUserInfo(
        	"Owner.txt",
        	inputID,
        	currentName,
        	currentPhone
    	);

    	currentRole = "Owner";

    	cout << "\nLogin Successful!\n";
    	cout << "Welcome, " << currentName << "!\n";

    	ownerPropertyMenu();

    	return;
	}

    // Check Agent
    if (checkLogin("Agent.txt", inputID, inputPassword))
    {
    	currentID = inputID;

    	getUserInfo(
        	"Agent.txt",
        	inputID,
        	currentName,
        	currentPhone
    	);

    	currentRole = "Agent";
    	
        cout << "\nLogin Successful!\n";
        cout << "Welcome, " << currentName << "!\n";

        agentPropertyMenu();

        return;
    }
    // If no matching ID + Password
    cout << "\nLogin Failed!\n";
    cout << "Incorrect ID or Password.\n";
}
