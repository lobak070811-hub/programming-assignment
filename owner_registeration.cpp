#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Owner
{
	int id;
	string name;
	string phone;
	string email;
	string password;
};

Owner inputOwner()
{
    Owner o;

    cout << "Owner ID   : ";
    cin >> o.id;
    cin.ignore();

    cout << "Name       : ";
    getline(cin, o.name);

    cout << "Phone      : ";
    getline(cin, o.phone);

    cout << "Email      : ";
    getline(cin, o.email);

    cout << "Password   : ";
    getline(cin, o.password);

    return o;
}

void saveOwner(Owner o)
{
    ofstream file("owner.txt", ios::app);

    if(file.is_open())
    {
        file << o.id << ", "
             << o.name << ", "
             << o.phone << ", "
             << o.email << ", "
             << o.password << endl;

        file.close();

        cout << "\nOwner Registered Successfully.\n";
    }
    else
    {
        cout << "Cannot open file.\n";
    }
}

void displayOwner()
{
    ifstream file("owner.txt");

    string line;

    cout << "\n====== Owner List ======\n";

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

int main()
{
	Owner o;

    o = inputOwner();

    saveOwner(o);

    displayOwner();

    return 0;
}
