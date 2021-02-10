#include "stdafx.h"
#include <cstdio>	
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include "root_access.h"

using namespace std;

class login {
	char user[100];
	char pass[100];
};

int usr(char data[1000]) {
	//These variables are the main parameters to check
	int size_buff = 2;

	int chksum = 0; //Flags for match checking
	int neg_chksum = 0;
	char root_access[2][100] = { "./root ", "./s3602052 " };
	//strcpy(, 100, usr_input); //Store the data parse to this function

	int match_flag = 0; // 0 if not match, 1 if match
	int j;
	int i;
	for (i = 0; i < size_buff; i++) {
		for (j = 0; j < strlen(&root_access[i][j]); j++) {
			if (root_access[i][j] == data[j]) {
				chksum = 1; //Increase flag for matching letters
			}
			else {
				neg_chksum = 1; //Increase flag for non-matching letters
				match_flag = 0;
				return match_flag;
			}
		}
		//Check if the password actually matches
		if (chksum == strlen(&root_access[i][j])) {
			match_flag = 1; //Signal that the username entered matches the database
			return match_flag;
		}
	}
}

int pwd(char data[1000]) {
	//These variables are the main parameters to check
	int size_buff = 4;

	int chksum = 0; //Flags for match checking
	int neg_chksum = 0;
	char pass_buff[4][100] = { "435263553Qq", "9272523262", "nicole08", "kikimomabaho" };
	//strcpy(, 100, usr_input); //Store the data parse to this function

	int match_flag = 0; // 0 if not match, 1 if match
	int j;
	int i;
	for (i = 0; i < size_buff; i++) {
		for (j = 0; j < strlen(&pass_buff[i][j]); j++) {
			if (pass_buff[i][j] == data[j]) {
				chksum = 1; //Increase flag for matching letters
			}
			else {
				neg_chksum = 1; //Increase flag for non-matching letters
				match_flag = 0;
				return match_flag;
			}
		}
		//Check if the password actually matches
		if (chksum == strlen(&pass_buff[i][j])) {
			match_flag = 1; //Signal that the username entered matches the database
			return match_flag;
		}
	}
}