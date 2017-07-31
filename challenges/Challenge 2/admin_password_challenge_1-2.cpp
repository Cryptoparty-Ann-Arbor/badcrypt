//this code is written under an alter-ego...Craig. Craig makes poor security choices for
//his login applet, can you root Craig and show him why?
//Craig makes use of a modified "smoke_hash" he found on the cryptoparty github
//clever...he was explicitly told not to do this..devious..
//
//update:
//Craig is on to the haxxors and has improved his hashing algorithm, he monitors 
//the a2 cryptoparty github so it's all very meta.

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
	int pt_sum_mod = pt_sum; // extra precautions...stealthy
    //pre-generated random data 10 entries, of 10 length
    std::vector<std::string> random_data = {"7061958243", "4567210938", "3671082459", "2498367501", "2831095764", "2640719503", "5643729810", "6047315892", "6987314502", "5438097216"};
    
    int index_i = dng(pt_sum, 0, 9); //determining index 1

    for (int i=0; i < 10; i++) // Craig doesnt see the need for more than 10
    {
	//int temp = random_data[pt[i%pt.length()] % random_data.size()];    
        //double temp = std::stod(random_data[((i*pt[i % pt.length()]) % random_data.size())]);
        pt_sum_mod = pt_sum_mod - pt[i]; // skittles	
        delicious.push_back(random_data[index_i][dng(pt[i % pt.length()],0,9)]); // hello
        index_i = dng(pt_sum_mod, 0, 9); // to avoid repetition yes..yes...
    }

    return delicious;
}
//code for fancy hiding of commandline stuff
void hideSTD()
{
	termios tty;

	tcgetattr(STDIN_FILENO, &tty);

	/* we want to disable echo */
	tty.c_lflag &= ~ECHO;

	tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}
//code for fancy showing of commandline stuff
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
    std::cout << craigs_hash_is_bomb(password) << " does not equal " << admin_password;
    std::cout << std::endl;
    std::cout << "Nice try sucka get real";
    std::cout << std::endl;}

}
