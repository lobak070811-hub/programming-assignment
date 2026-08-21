//agent registeration
#include "header.h" 

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

struct Agent
{
    string id;
    string name;
    string phone;
    string email;
    string password;
};

int defaultAgentID();
void inputAgent(Agent &ag);
void saveAgent(Agent a);
void array_agentlist();
void displayAgent();

void agentRegister()//main function
{
    struct Agent a;

    inputAgent(a);

    saveAgent(a);
    
    array_agentlist();

    displayAgent();

    return 0;
}

int defaultAgentID()
{
    ifstream file("Agent.txt");

    string line;
    int count = 0;

    while(getline(file, line))
    {
        count++;
    }

    file.close();

    return count + 1;
}

void inputAgent(Agent &ag)
{
    Agent a;//Owner

    cout << "Name       : ";
    getline(cin, ag.name);

    cout << "Phone      : ";
    getline(cin, ag.phone);

    cout << "Email      : ";
    getline(cin, ag.email);

    cout << "Password   : ";
    getline(cin, ag.password);

}

void saveAgent(Agent a)
{
    ofstream file("Agent.txt", ios::app);
    
    int id = defaultAgentID();

    if(file.is_open())
    {
        file << "A" << setw(3) << setfill('0') << id << ","
             << o.name << ","
             << o.phone << ","
             << o.email << "@gmail.com" << ","
             << o.password << endl;

        file.close();

        cout << "\nAgent Registered Successfully.\n";
    }
    else
    {
        cout << "Cannot open file.\n";
    }
}

Agent agentList[50];
int agentCount = 0;

void array_agentlist()
{
	ifstream file("Agent.txt");
	
	if(!file)
	{
		cout << "Cannot open agent.txt" << endl;
		return;
	}

	string line;

	while(getline(file, line))
	{
    	stringstream ss(line);

    	getline(ss, agentList[agentCount].id, ',');
    	getline(ss, agentList[agentCount].name, ',');
    	getline(ss, agentList[agentCount].phone, ',');
    	getline(ss, agentList[agentCount].email, ',');
    	getline(ss, agentList[agentCount].password);

    	agentCount++;
	}

	file.close();
}

void displayAgent()
{
	ifstream file("Agent.txt");

    string line;

    cout << "\n===== Agent List =====\n";
    
    cout << left
    	 << setw(8)  << "ID"
    	 << setw(20) << "Name"
    	 << setw(15) << "Phone"
    	 << setw(35) << "Email"
    	 << endl;
    	 
	for(int i = 0; i < agentCount; i++)
	{
		cout << left
			 << setw(8)  << agentList[i].id
			 << setw(20) << agentList[i].name
			 << setw(15) << agentList[i].phone
			 << setw(35) << agentList[i].email
			 << endl;
	}
}
