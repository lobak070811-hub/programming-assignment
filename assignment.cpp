#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cstdlib>

using namespace std;

// ==================== 1. ?????? ==================== //
struct User {
    string username;
    string password;
    string role;     // Student / Owner / Agent
    string contact;
    string name;     // ????????
};

struct Property {
    int id;
    string ownerUsername;
    string type;           // Condo / Apartment / Room
    double price;          // RM
    double sqft;           // sqft
    double distance;       // km
    int shortlistedCount;
    string title;          // ????????
};

// ??????
vector<User> users;
vector<Property> properties;
User currentUser;
bool isLoggedIn = false;

// ??????
string readLine() {
    string str;
    getline(cin, str);
    return str;
}

int readInt() {
    string str = readLine();
    stringstream ss(str);
    int val = 0;
    ss >> val;
    return val;
}

double readDouble() {
    string str = readLine();
    stringstream ss(str);
    double val = 0.0;
    ss >> val;
    return val;
}

// ????
void loadData();
void saveData();
void userRegister();
bool userLogin();
void module1_ListingAndSearching();
void module2_EnquiryReviewAppointment();
void module3_Analytics();

// ==================== 2. ?? I/O ?? (?????) ==================== //
void loadData() {
    users.clear();
    properties.clear();

    string label; // ?????????????(? "Username:"?"Password:" ?)

    // 1. ?? Users
    ifstream ufile("users.txt");
    if (ufile.is_open()) {
        User u;
        // ????????????
        while (ufile >> label >> u.username 
                     >> label >> u.password 
                     >> label >> u.role 
                     >> label >> u.contact 
                     >> label) { // ??? label ?? "Name:"
            ufile.ignore();     // ?? "Name:" ??????
            getline(ufile, u.name); // ??????????? Name
            users.push_back(u);
        }
        ufile.close();
    }

    // 2. ?? Properties
    ifstream pfile("properties.txt");
    if (pfile.is_open()) {
        Property p;
        while (pfile >> label >> p.id 
                     >> label >> p.ownerUsername 
                     >> label >> p.type 
                     >> label >> p.price 
                     >> label >> p.sqft 
                     >> label >> p.distance 
                     >> label >> p.shortlistedCount 
                     >> label) { // ??? label ?? "Title:"
            pfile.ignore();     // ?? "Title:" ??????
            getline(pfile, p.title); // ??????????? Title
            properties.push_back(p);
        }
        pfile.close();
    }
}

void saveData() {
    // 1. ?? Users(??????)
    ofstream ufile("users.txt");
    for (size_t i = 0; i < users.size(); i++) {
        ufile << "Username: " << users[i].username << " "
              << "Password: " << users[i].password << " "
              << "Role: " << users[i].role << " "
              << "Contact: " << users[i].contact << " "
              << "Name: " << users[i].name << "\n";
    }
    ufile.close();

    // 2. ?? Properties(??????)
    ofstream pfile("properties.txt");
    for (size_t i = 0; i < properties.size(); i++) {
        pfile << "ID: " << properties[i].id << " "
              << "Owner: " << properties[i].ownerUsername << " "
              << "Type: " << properties[i].type << " "
              << "Price: " << properties[i].price << " "
              << "Sqft: " << properties[i].sqft << " "
              << "Distance: " << properties[i].distance << " "
              << "Shortlisted: " << properties[i].shortlistedCount << " "
              << "Title: " << properties[i].title << "\n";
    }
    pfile.close();
}

// ==================== 3. ?????? ==================== //

// ?? 1:???????
void module1_ListingAndSearching() {
    cout << "\n=== Module 1: Listing & Searching ===" << endl;
    cout << "1. View All Listings" << endl;
    cout << "2. Search Property by Max Price" << endl;
    if (currentUser.role == "Owner" || currentUser.role == "Agent") {
        cout << "3. Add New Listing" << endl;
    } else {
        cout << "3. Shortlist a Property" << endl;
    }
    cout << "Enter choice: ";
    int choice = readInt();

    if (choice == 1) {
        cout << "\n" << left << setw(5) << "ID" << setw(30) << "Title" << setw(12) << "Type" 
             << setw(10) << "Price" << setw(10) << "Sqft" << setw(10) << "Distance" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        for (size_t i = 0; i < properties.size(); i++) {
            cout << left << setw(5) << properties[i].id
                 << setw(30) << properties[i].title
                 << setw(12) << properties[i].type
                 << setw(10) << properties[i].price
                 << setw(10) << properties[i].sqft
                 << properties[i].distance << " km" << endl;
        }
    } 
    else if (choice == 2) {
        cout << "Enter maximum budget (RM): ";
        double maxPrice = readDouble();

        cout << "\n--- Matching Properties ---" << endl;
        cout << left << setw(5) << "ID" << setw(30) << "Title" << setw(10) << "Price" << setw(10) << "Distance" << endl;
        for (size_t i = 0; i < properties.size(); i++) {
            if (properties[i].price <= maxPrice) {
                cout << left << setw(5) << properties[i].id
                     << setw(30) << properties[i].title
                     << setw(10) << properties[i].price
                     << properties[i].distance << " km" << endl;
            }
        }
    }
    else if (choice == 3 && (currentUser.role == "Owner" || currentUser.role == "Agent")) {
        Property p;
        p.id = properties.size() + 1;
        p.ownerUsername = currentUser.username;

        cout << "Enter Property Title (Spaces allowed, e.g. Flora Green Block A): ";
        p.title = readLine();

        cout << "Enter Type (e.g. Condo / Apartment / Room): ";
        p.type = readLine();

        cout << "Enter Monthly Rental Price (RM): ";
        p.price = readDouble();

        cout << "Enter Size (sqft): ";
        p.sqft = readDouble();

        cout << "Enter Distance to UTAR (km): ";
        p.distance = readDouble();

        p.shortlistedCount = 0;
        properties.push_back(p);
        saveData(); // ?????????
        cout << "\nProperty '" << p.title << "' added successfully!" << endl;
    }
    else if (choice == 3 && currentUser.role == "Student") {
        cout << "Enter Property ID to shortlist: ";
        int propId = readInt();

        bool found = false;
        for (size_t i = 0; i < properties.size(); i++) {
            if (properties[i].id == propId) {
                properties[i].shortlistedCount++;
                saveData();
                cout << "Successfully added '" << properties[i].title << "' to your shortlist!" << endl;
                found = true;
                break;
            }
        }
        if (!found) cout << "Property ID not found!" << endl;
    }
}

// ?? 2:???????
void module2_EnquiryReviewAppointment() {
    cout << "\n=== Module 2: Enquiry, Review & Appointment ===" << endl;
    cout << "1. Send Enquiry to Owner" << endl;
    cout << "2. Schedule Viewing Appointment" << endl;
    cout << "Choice: ";
    int c = readInt();

    if (c == 1) {
        cout << "Enter Property ID to enquire: ";
        int propId = readInt();

        cout << "Enter your message: ";
        string msg = readLine();
        cout << "Enquiry sent successfully!" << endl;
    } else if (c == 2) {
        cout << "Enter Property ID to view: ";
        int propId = readInt();

        cout << "Enter preferred date (e.g. 2026-08-15): ";
        string date = readLine();
        cout << "Appointment request submitted for " << date << "!" << endl;
    }
}

// ?? 3:???????
void module3_Analytics() {
    cout << "\n=== Module 3: Accommodation Analytics ===" << endl;
    if (properties.empty()) {
        cout << "No property data available." << endl;
        return;
    }

    double totalPricePerSqft = 0;
    int countWithin1km = 0;

    for (size_t i = 0; i < properties.size(); i++) {
        if (properties[i].sqft > 0) {
            totalPricePerSqft += (properties[i].price / properties[i].sqft);
        }
        if (properties[i].distance <= 1.0) {
            countWithin1km++;
        }
    }

    double avgPsf = totalPricePerSqft / properties.size();

    cout << "------------------------------------------" << endl;
    cout << "Total Accommodation Listings: " << properties.size() << endl;
    cout << "Average Price per Sqft (PSF): RM " << fixed << setprecision(2) << avgPsf << endl;
    cout << "Properties within 1.0 km to UTAR: " << countWithin1km << endl;

    if (currentUser.role == "Owner" || currentUser.role == "Agent") {
        cout << "\n--- Owner Insights ---" << endl;
        for (size_t i = 0; i < properties.size(); i++) {
            if (properties[i].ownerUsername == currentUser.username) {
                cout << "Property ID " << properties[i].id << " (" << properties[i].title << "): "
                     << properties[i].shortlistedCount << " student(s) shortlisted this." << endl;
            }
        }
    }
    cout << "------------------------------------------" << endl;
}

// ????
void userRegister() {
    User u;
    cout << "\n--- User Registration ---" << endl;
    cout << "Enter Username: "; 
    u.username = readLine();

    cout << "Enter Password: "; 
    u.password = readLine();

    cout << "Enter Role (Student / Owner / Agent): "; 
    u.role = readLine();

    cout << "Enter Contact Number: "; 
    u.contact = readLine();

    cout << "Enter Full Name (Spaces allowed, e.g. Choo Yang): "; 
    u.name = readLine();

    users.push_back(u);
    saveData(); // ?????????
    cout << "\nRegistration successful! Welcome, " << u.name << ". You can now login." << endl;
}

// ????
bool userLogin() {
    cout << "\n--- User Login ---" << endl;
    cout << "Username: "; 
    string un = readLine();

    cout << "Password: "; 
    string pw = readLine();

    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].username == un && users[i].password == pw) {
            currentUser = users[i];
            cout << "\nLogin successful! Welcome, " << currentUser.name << " [" << currentUser.role << "]!" << endl;
            return true;
        }
    }
    cout << "Invalid Username or Password!" << endl;
    return false;
}

// ==================== 4. ????? ==================== //
int main() {
    loadData();

    while (true) {
        cout << "\n==============================================" << endl;
        cout << " UTAR SG Long Accommodation Management System " << endl;
        cout << "==============================================" << endl;

        if (!isLoggedIn) {
            cout << "1. Register\n2. Login\n3. Exit\nChoice: ";
            int option = readInt();

            if (option == 1) userRegister();
            else if (option == 2) isLoggedIn = userLogin();
            else if (option == 3) {
                cout << "Thank you for using the system. Goodbye!" << endl;
                break;
            }
        } else {
            cout << "Logged in as: " << currentUser.name << " [" << currentUser.role << "]" << endl;
            cout << "1. Accommodation Listing & Search (Module 1)\n";
            cout << "2. Enquiry & Appointment (Module 2)\n";
            cout << "3. Analytics Report (Module 3)\n";
            cout << "4. Logout\nChoice: ";
            int option = readInt();

            if (option == 1) module1_ListingAndSearching();
            else if (option == 2) module2_EnquiryReviewAppointment();
            else if (option == 3) module3_Analytics();
            else if (option == 4) { 
                isLoggedIn = false; 
                cout << "Logged out successfully.\n"; 
            }
        }
    }
    return 0;
}
