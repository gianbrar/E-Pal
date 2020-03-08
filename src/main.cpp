#include <iostream>
#include <unistd.h>
#include <bits/stdc++.h> 
#include <fstream>
#include <string>
#include "user.h"
#define ESAY cout << name << ": " <<
#define CSAY cout << "CONSOLE: " <<
using namespace std;
user u;

int main() {
  system("[ ! -d ../data ] && mkdir ../data");
  bool debugMode = true;
  if (debugMode == true) {
    string deleteAll;
    CSAY "(Debug mode detected as active. Delete all?)" << endl;
    getline(cin, deleteAll);
    if (deleteAll == "Y" || deleteAll == "y") {
      CSAY "(Deleting all)" << endl;
      system("./debug.bash");
    }
    else {
      CSAY "(Not deleting; remaining in debug)" << endl;
    }
  }
	string name = "EPAL";
  bool nameWithoutUser = false;
  u.name = "";
	ofstream oName;
	ifstream iName("../data/name.txt");
	ifstream iUser("../data/userData.txt");
	ofstream oUser;
	getline(iName, name);
	for (int i = 0; i < 2; i++) {
		switch (i) {
			case 0:
				getline(iUser, u.name);
				break;
      case 1:
        getline(iUser, u.gender);
        break;
		}
	}
	if (name == "EPAL" || name == "") {
		name = "EPAL";
    oName.open("../data/name.txt");
		ESAY "Hey there, new friend!" << endl;
		sleep(1);
		ESAY "I'm having some trouble remembering my name. What was it, again?" << endl;
		sleep(1);
		CSAY "(Please enter name)" << endl;
		getline(cin, name);
		oName << name;
		oName.close();
		ESAY "Ohhh, so my name is " << name << ". Can't believe I forgot it! :p" << endl;
	}
	else {
    nameWithoutUser = true;
		switch (rand() % 5 + 1) {
				case 1:
					ESAY "Hi there; I'm your E-pal! ";
					break;
				case 2:
					ESAY "Hey, " << u.name << "!" ;
					break;
				case 3:
					ESAY "Hi, " << u.name << ". ";
					break;
				case 4:
					ESAY "Over here! It's me, your E-pal! Welcome back! ";
					break;
				case 5:
					ESAY "Here we are, again! ";
					break;
			}
	}

  if (u.name == "") {
    if (nameWithoutUser == true) {
      cout << endl;
    }
    ESAY "I'd like to know more about you.\nWhat's your name?" << endl;
    getline(cin, u.name);
    ESAY "Well, nice to meet you, " << u.name << "!" << endl;
    sleep(1);
    u.gender = "";
    while (u.gender != "m" && u.gender != "f" && u.gender != "g" && u.gender != "n" && u.gender != "p") {
      ESAY "Now then, I'd like to know what you refer to yourself as. What is your gender or what pronouns do you align with?\nM: Male\nF: Female\nG: Gender Fluid\nN: Non-Binary" << endl;
      getline(cin, u.gender);
      transform(u.gender.begin(), u.gender.end(), u.gender.begin(), ::tolower);
      if (u.gender != "m" && u.gender != "f" && u.gender != "g" && u.gender != "n" && u.gender != "p") {
        CSAY "(Please enter a valid gender. Contact thehiddenmonkey on GitHub if you belive you have not been properly represented.)" << endl;
      }
    }
    oUser.open("../data/userData.txt");
    oUser << u.name << endl << u.gender;
    oUser.close();
    sleep(1);
    if (u.gender == "p") {
      ESAY "Too uncomfortable? Sorry I made you feel that way!\nAnyways, ";
    }
    ESAY "I think I know enough about you now! ";
  }

	switch (rand() % 3 + 1) {
				case 1:
					cout << "So what now?" << endl;
					break;
				case 2:
					cout << "What do you wanna talk about?" << endl;
					break;
				case 3:
					cout << "How are you feeling?" << endl;
					break;
	}
	string response;
  string responseType;
  int responseTypeArea;
  string botResponseType;
  while (true) {
    cout << "";
    getline(cin, response);
    size_t responseP = response.find(".");
    if (responseP != string::npos) {
      response.erase(responseP, 1);
    }
    transform(response.begin(), response.end(), response.begin(), ::tolower);
    if (response.length() == 0) {
      ESAY "...\nSilent treatment, huh?" << endl;
    }
    string botResponse;
    string back[3][5] = { {"happy", "That's wonderful!|NU", "Me too :)|NU", "What a great emotion!|NU", "Happiness is such a great thing!|NU"}, {"test", "Are you testing me?|NU", "I didn't study for this!|NU", "I'll be the one testing you today, ma'am and/or sir!|MS", "Reminds me of the days in which I took my exams.|NU"}, {"hello there", "General Kenobi!|NU", "Come here, my little friend.|NU", "Hi there!|NU", "*R2D2 NOISES*|NU"} };
    int negState = response.find("not");
    for (int i = 0; i < 3; i++) {
      if (response.find(back[i][0]) != string::npos) {
        botResponse = back[i][rand() % 4 + 1];
        if (response.substr(response.length() - 4, response.length() - 3) == "?") {
          cout << "responseType is question" << endl;
          responseType = "question";
        }
        if (botResponse.substr(botResponse.length() - 4, botResponse.length() - 3) == "?") {
          cout << "botResponseType is question" << endl;
          botResponseType = "question";
        }
        cout << "substr is " << botResponse.substr(botResponse.length() - 3) << endl;
        if (botResponse.substr(botResponse.length() - 3) == "|MS") {
          int ms = botResponse.find("ma'am");
          cout << "u.gender is " << u.gender << endl;
          if (u.gender == "f" || u.gender == "F") {
            botResponse.erase(ms + 5, 12);
          }
          else if (u.gender == "m" || u.gender == "M") {
            botResponse.erase(ms, 13);
          }
        }
        botResponse.erase(botResponse.length() - 3, botResponse.length() - 1);
        ESAY botResponse << endl;
        break;
      }
    }
  }
	return 0;
}
