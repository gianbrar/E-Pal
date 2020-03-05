#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#define ESAY cout << name << ": " <<
#define CSAY cout << "CONSOLE: " <<
using namespace std;

int main() {
	string name = "EPAL";
	string uname;
	ofstream oName;
	ifstream iName("name.txt");
	ifstream iUser("userData.txt");
	ofstream oUser;
	name = getline(iName, name);
	for (int i = 1; i < 2; i++) {
		switch (i) {
			case 1:
				getline(iUser, uname);
				break;
		}
	}
	oName.open("name.txt");
	int motd = rand() % 5 + 1;
	int prompt = rand() % 3 + 1;
	if (name == "") {
		ESAY "Hey there, new friend!" << endl;
		ESAY "I'm having some trouble remembering my name. What was it, again?" << endl;
		CSAY "(Please enter name)" << endl;
		getline(cin, name);
		oName << name;
		ESAY "Ohhh, so my name is " << name << ". Can't believe I forgot it! :p" << endl;
	}
	else {
		switch (motd) {
				case 1:
					ESAY "Hi there; I'm your E-pal! ";
					break;
				case 2:
					ESAY "Hey, " << uname << "!" ;
					break;
				case 3:
					ESAY "Hi, " << uname << ". ";
					break;
				case 4:
					ESAY "Over here! It's me, your E-pal! Welcome back! ";
					break;
				case 5:
					ESAY "Here we are, again! ";
					break;
			}
		switch (prompt) {
			case 1:
				ESAY "So what now?" << endl;
				break;
			case 2:
				ESAY "What do you wanna talk about?" << endl;
				break;
			case 3:
				ESAY "How are you feeling?" << endl;
				break;
		}
	}
	return 0;
}
