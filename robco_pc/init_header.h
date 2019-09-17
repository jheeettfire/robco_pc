//This is the initializer header 
#ifndef INIT_HEADER_INCLUDED
#define INIT_HEADER_INCLUDED
//#define _WIN32_WINNT  0x0501 // I misunderstand that

int get_sys_ram();
void init_robco();

//These are the variables for the initialization

static char pip_boy_ver[100];
static char ver_PC[100];
static char ver_year[100];
static char loader[100];
static char exec_ver[100];
static int sys_ram = get_sys_ram(); //Get the system RAM for the current device
static char holotape_stat[100];
static char rom_stat[100];
static char term_name[100];

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

#endif INIT_HEADER_INCLUDED

