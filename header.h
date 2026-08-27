#ifndef MY_HEADER
#define MY_HEADER

#include <iostream>

extern string currentID;
extern string currentName;
extern string currentPhone;
extern string currentRole;

void mainMenu();

void registerMenu();
void studentRegister();
void ownerRegister();
void agentRegister();

void loginMenu();

void ownerPropertyMenu();
void agentPropertyMenu();
void addProperty();
void editProperty();

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#endif //end code
