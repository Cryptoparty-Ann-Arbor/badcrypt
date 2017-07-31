//this code is written under an alter-ego...Craig. Craig makes poor security choices for
//his login applet, can you root Craig and show him why?
//Craig makes use of a modified "smoke_hash" he found on the cryptoparty github
//clever...he was explicitly told not to do this..devious..


#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

//#include "picosha2.h" //nah not going to use sha256 because its so well known its terrible - Craig 2017

//I'm using a number generator...
int dng(int seed, int min, int max)
{
 
    std::mt19937 mt(seed);
    std::uniform_int_distribution<int> dist(min, max);

    return dist(mt);


}

std::string craigs_hash_is_bomb(std::string &password) // passing password to pt for hash function hell yeah
{

    std::string pt = password; //plaintext
    std::vector<int> pt_int; //integer values of characters
    std::string delicious;
    int pt_sum = 0;

    for (int i=0; i < pt.length(); i++)
    {
        pt_int.push_back(pt[i]); //filling vector
        pt_sum = pt_sum + pt_int[i]; //sum of character values

    }

    //pre-generated random data 10 entries, of 10 length
    std::vector<std::string> random_data = {"3846870223", "3962687902", "7470852223", "7514179786", "2202953802", "7504486334", "1795029264", "7766294303", "6736111978", "9393656247"};
    
    int index_i = dng(pt_sum, 0, 9); //determining index 1

    for (int i=0; i < 10; i++) // Craig doesnt see the need for more than 10
    {
        
        delicious.push_back(random_data[index_i][dng(pt[i % pt.length()],0,9)]); 
        index_i = ((index_i + 1) % 10); // to avoid repetition
    }

    return delicious;
}

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

std::string username;
std::string password;

std::string admin_password = "3006394608"; //doesn't matter if they have this hash, what could they possibly do with it hahahah - Craig 2017

std::cout << "username: ";
std::cin >> username;
std::cout << "password: ";

hideSTD();
std::cin >> password;
showSTD();
if (craigs_hash_is_bomb(password) == admin_password && username == "admin")
{
std::cout << std::endl;
std::cout << "ACCESS GRANTED; Welcome Back Craig, ";
std::cout << std::endl;
std::cout << "Unhackable King";
std::cout << std::endl;
}


else {
    std::cout << std::endl;
    std::cout << "Nice try sucka get real";
    std::cout << std::endl;}

}