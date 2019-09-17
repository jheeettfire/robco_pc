//Declare the login sequence here
#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <string>
#include <float.h>
#include <stdio.h>
#include "clear_screen.h" //Use this to clear the screen for next output
#include "screen_headers.h" //Use this to print the RobCo headers
#include "init_header.h" //Import the device name from here
#include "root_access.h" //Use this to check the username and password
using namespace std;

int login_main(){
	//Login parameters
	char usr_un[100];
	char passwd[100];
	int usr_match = 0;
	int pwd_match = 0;

login_enter_un:
	ClearScreen();
	robco_header();
	cout << " ============================================================== \n\n";

	cout << " Login " << term_name << endl;
	cout << " USR: ";
	cin >> usr_un;

	usr_match = usr(usr_un);

	if (usr_match != 0) {
		//ClearScreen();
		//robco_header();
		//cout << " ============================================================== \n\n";
		//cout << " Login " << term_name << endl;
		cout << " PWD: ";
		cin >> passwd;

		pwd_match = pwd(usr_un);

		if (pwd_match != 0) {
			//ClearScreen();
			//robco_header();
			//cout << " ============================================================== \n\n";
			//cout << " Login " << term_name << endl;
			cout << "\n PWD: ";
			cin >> passwd;
		}

		Sleep(4000); //Comment out for functionality
		return 1;
		
	}
	else {
		ClearScreen();
		robco_header();
		cout << " ============================================================== \n\n";
		cout << " Login " << term_name << endl;
		cout << " USR: ";
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << " > User not recognized...";
		Sleep(4000); //Comment out for functionality
		goto login_enter_un;
	}
}
