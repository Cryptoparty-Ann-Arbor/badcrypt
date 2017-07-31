#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <strings.h>
#include <vector>
#include <algorithm>
#include "picosha2.h"

using namespace std;

void hideSTD()
{
	termios tty;

	tcgetattr(STDIN_FILENO, &tty);

	/* we want to disable echo */
	tty.c_lflag &= ~ECHO;

	tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

void showSTD()
{
   termios tty;

	tcgetattr(STDIN_FILENO, &tty);

	/* we want to reenable echo */
	tty.c_lflag |= ECHO;

	tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}


int main()
{
	
string username;
string happy;	
vector<string> no = {"N" , "No" , "no" , "NO" ,"nO"};
vector<string> yes = {"y" , "Yes" , "yes" , "yEs" , "YES" , "YEs" , "yeS"};


retry:
cout << "Register a new user" << endl << "username: ";

cin >> username;

if(username.empty()){
cout << endl; goto retry;
} else {
}

cout << "Are you happy with " << username << "?" << endl;
cout << "Y/N" << endl; cin >> happy; 

if(std::find(no.begin(), no.end(), happy) != no.end()) {
goto retry;
} else {
	if(std::find(yes.begin(), yes.end(), happy) != yes.end()) {
	} else {
cout << endl; goto retry;
	}
}

if(happy.empty()){
cout << endl; goto retry;
} else {
}

hideSTD();
string password;
string passhash;
string passwordreconfirm;

redopassword:
cout << "Enter password: ";
cin >> password;

cout << endl << "You are registered as " << username << endl;
cout << "Reconfirm password: ";
cin >> passwordreconfirm;

if ((passwordreconfirm).compare(password))
{cout << endl << "password failed, redo" << endl; goto redopassword;}



showSTD();


}



