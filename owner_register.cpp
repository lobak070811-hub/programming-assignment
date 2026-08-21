#include "header.h" 

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

struct Owner
{
    string id;
    string name;
    string phone;
    string email;
    string password;
};

int defaultOwnerID();
void inputOwner(Owner &ow);
void saveOwner(Owner o);
void array_ownerlist();
void displayOwner();

void ownerRegister()//main function
{
    struct Owner o;

    inputOwner(o);

    saveOwner(o);
    
    array_ownerlist();

    displayOwner();

    return 0;
}

int defaultOwnerID()
{
    ifstream file("Owner.txt");

    string line;
    int count = 0;

    while(getline(file, line))
    {
        count++;
    }

    file.close();

    return count + 1;
}

void inputOwner(Owner &ow)
{
    Owner o;//Owner

    cout << "Name       : ";
    getline(cin, ow.name);

    cout << "Phone      : ";
    getline(cin, ow.phone);

    cout << "Email      : ";
    getline(cin, ow.email);

    cout << "Password   : ";
    getline(cin, ow.password);

}

void saveOwner(Owner o)
{
    ofstream file("Owner.txt", ios::app);
    
    int id = defaultOwnerID();

    if(file.is_open())
    {
        file << "O" << setw(3) << setfill('0') << id << ","
             << o.name << ","
             << o.phone << ","
             << o.email << "@gmail.com" << ","
             << o.password << endl;

        file.close();

        cout << "\nOwner Registered Successfully.\n";
    }
    else
    {
        cout << "Cannot open file.\n";
    }
}

Owner ownerList[50];
int ownerCount = 0;

void array_ownerlist()
{
	ifstream file("Owner.txt");
	
	if(!file)
	{
		cout << "Cannot open owner.txt" << endl;
		return;
	}

	string line;

	while(getline(file, line))
	{
    	stringstream ss(line);

    	getline(ss, ownerList[ownerCount].id, ',');
    	getline(ss, ownerList[ownerCount].name, ',');
    	getline(ss, ownerList[ownerCount].phone, ',');
    	getline(ss, ownerList[ownerCount].email, ',');
    	getline(ss, ownerList[ownerCount].password);

    	ownerCount++;
	}

	file.close();
}

void displayOwner()
{
	ifstream file("Owner.txt");

    string line;

    cout << "\n===== Owner List =====\n";
    
    cout << left
    	 << setw(8)  << "ID"
    	 << setw(20) << "Name"
    	 << setw(15) << "Phone"
    	 << setw(35) << "Email"
    	 << endl;
    	 
	for(int i = 0; i < ownerCount; i++)
	{
		cout << left
			 << setw(8)  << ownerList[i].id
			 << setw(20) << ownerList[i].name
			 << setw(15) << ownerList[i].phone
			 << setw(35) << ownerList[i].email
			 << endl;
	}
}
