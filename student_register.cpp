#include "header.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

struct Student
{
    string id;
    string name;
    string phone;
    string email;
    string password;
};

int defaultStudentID();
void inputStudent(Student &stu);
void saveStudent(Student s);
void arraystudentlist();
void displayStudent();

void studentRegister()//main function
{
    struct Student s;

    inputStudent(s);

    saveStudent(s);
    
    arraystudentlist();

    displayStudent();
}

int defaultStudentID()
{
    ifstream file("Student.txt");

    string line;
    int count = 0;

    while(getline(file, line))
    {
        count++;
    }

    file.close();

    return count + 1;
}

void inputStudent(Student &stu)
{
    Student s;//Student

    cout << "Name       : ";
    cin.ignore(); 
    getline(cin, stu.name);

    cout << "Phone      : ";
    getline(cin, stu.phone);

    cout << "Email      : ";
    getline(cin, stu.email);

    cout << "Password   : ";
    getline(cin, stu.password);

}

void saveStudent(Student s)
{
    ofstream file("Student.txt", ios::app);
    
    int id = defaultStudentID();

    if(file.is_open())
    {
        file << "S" << setw(3) << setfill('0') << id << ","
             << s.name << ","
             << s.phone << ","
             << s.email << "@gmail.com" << ","
             << s.password << endl;

        file.close();

        cout << "\nStudent Registered Successfully.\n";
    }
    else
    {
        cout << "Cannot open file.\n";
    }
}

Student studentList[50];
int studentCount = 0;

void arraystudentlist()
{
	ifstream file("Student.txt");
	
	if(!file)
	{
		cout << "Cannot open student.txt" << endl;
		return;
	}

	string line;

	while(getline(file, line))
	{
    	stringstream ss(line);

    	getline(ss, studentList[studentCount].id, ',');
    	getline(ss, studentList[studentCount].name, ',');
    	getline(ss, studentList[studentCount].phone, ',');
    	getline(ss, studentList[studentCount].email, ',');
    	getline(ss, studentList[studentCount].password);

    	studentCount++;
	}

	file.close();
}

void displayStudent()
{
	ifstream file("Student.txt");

    string line;

    cout << "\n===== Student List =====\n";
    
    cout << left
    	 << setw(8)  << "ID"
    	 << setw(20) << "Name"
    	 << setw(15) << "Phone"
    	 << setw(35) << "Email"
    	 << endl;
    	 
	for(int i = 0; i < studentCount; i++)
	{
		cout << left
			 << setw(8)  << studentList[i].id
			 << setw(20) << studentList[i].name
			 << setw(15) << studentList[i].phone
			 << setw(35) << studentList[i].email
			 << endl;
	}
}
