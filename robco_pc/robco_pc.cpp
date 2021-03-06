// robco_pc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <string>
#include <float.h>
#include <stdio.h>
#include "clear_screen.h"
#include "screen_headers.h"
#include "init_header.h"
#include "body_header.h"
#include "root_access.h"
#include "login_seq.h"

char mail_err[100] = " Restricted access. Please contact you administrator..."; //Error if not root access to mail
char pass_err[100] = " Password not recognized..."; //Error to send when password is not recognized
char menu_err[100] = " Invalid option. Try again..."; //Error for when the menu letter is wrong
char exit_stat[100] = " Terminating console..."; //Status to print when exiting

enum choices {
	a, //Admin
	e, //Staff
	s, //Students
	m, //Mail
	x,  //Exit 
	q	//Root access
};

using namespace std;

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 575, 400, TRUE); // 800 width, 100 height

	char in_cnsl; //Store the input here
	char in_pass[100];

	//Start PipBoy OS here
	//Print initialization screen
	system("COLOR A");
	init_robco();

	Sleep(4000); //Wait for 4 seconds before going to main menu

boot_sequence:
	while (1) {
		//1.Prompt for a login first. It could be either root access (RobCo Technicians) or user access (staff, students, etc.)
		int LOGIN_SUCCESS = login_main();

		switch (LOGIN_SUCCESS) {
		case 0: //Login success as root
			break;
		case 1: //Login success as a normal user
			break;
		}
		ClearScreen();
		robco_header(); //Call this everytime to maintain the RobCo header on the console
		welcome_header(); //This is the header for the school of Engineering header
		body_main(); //Print the body main to show menu
		cout << " \n";
		cout << " > "; //17 - This is the input line 
		cin >> in_cnsl;

		//Check for the user option
		switch (in_cnsl) {
		case 'a':
			break;
		case 'e':
			break;
		case 's':
			break;
		case 'm':
			ClearScreen();
			system("COLOR A");
			robco_header(); //Call this everytime to maintain the RobCo header on the console
			welcome_header(); //This is the header for the school of Engineering header
			body_main();

			//Print the error message for "Restricted Access"
			for (int i = 0; i != strlen(mail_err); i++) {
				cout << mail_err[i];
				Sleep(10);
			}

			cout << endl;
			cout << " < "; //17 - This is the input line 
			Sleep(2000);

			//Clear the input buffer
			in_cnsl = '\0';
			break;
		case 'x':
			ClearScreen();
			robco_header(); //Call this everytime to maintain the RobCo header on the console
			welcome_header(); //This is the header for the school of Engineering header
			body_main(); //Print the body main to show menu

			//Print status for the menu selected
			for (int i = 0; i < strlen(exit_stat); i++) {
				cout << exit_stat[i];
				Sleep(10);
			}

			cout << endl;
			cout << " < "; //17 - This is the input line 
			Sleep(5000);
			return 0; //Close terminal
		}
	}
	return 0; //Exit the whole program
}

