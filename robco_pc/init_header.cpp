//This is the cpp file for the init_header file in the RobCo PC program
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <string>	
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
using namespace std;

int get_sys_ram() {
	MEMORYSTATUSEX statex;

	statex.dwLength = sizeof(statex); // I misunderstand that

	GlobalMemoryStatusEx(&statex);
	float sys_ram = (float)statex.ullTotalPhys / (1024 * 1024 * 1024);

	return (float)sys_ram; //Return sys ram value
}

//These are the variables for the initialization
static char pip_boy_ver[100] = "v7.3.4";
static char ver_PC[100] = "v4.5";
static char ver_year[100] = "08/10/2075";
static char loader[100] = "v1.1";
static char exec_ver[100] = "41.10";
static int sys_ram = get_sys_ram(); //Get the system RAM for the current device
static char holotape_stat[100] = " NO HOLOTAPE FOUND";
static char rom_stat[100] = " Load ROM: Deitrix";
static char term_name[100] = "RMIT_10.09_Terminal";

void init_robco() {
	char init1[1000] = " *************** PIP - OS(R) V7.1.0.8 ***************\n\n COPYRIGHT 2075 ROBCO(R)\n LOADER V1.1\n EXEC VERSION 41.10\n 64K RAM SYSTEM\n 38911 BYTES FREE\n NO HOLOTAPE FOUND\n LOAD ROM(1): DEITRIX 303\n";
	for (int i = 0; i != strlen(init1); i++) {
		cout << init1[i];
		Sleep(10);
	}
}

/*
void init_pipboy() { //Use this to initialize the RobCo PC
cout << " *************** PIP - OS(R) " << pip_boy_ver << " ***************\n\n";
cout << " Copyright " << ver_year << " " << ver_PC << endl;
cout << " Loader " << loader << endl;
cout << " Exec Ver " << exec_ver << endl;
cout << " " << sys_ram << " GB System RAM" << endl;
cout << holotape_stat << endl;
cout << rom_stat << endl;
}*/