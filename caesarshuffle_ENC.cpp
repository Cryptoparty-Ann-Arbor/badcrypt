//caesarshuffle encryption

#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <algorithm>

//laziness
#define newline std::cout << std::endl;

int main()
{

std::string password;
std::string shift_this;
std::string temp_string;
int temp_int;
std::vector<std::string> default_alphabet = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
std::vector<std::string> user_alphabet = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
std::string encrypted_text;
std::vector<int> password_int;
std::vector<int> shift_int;
int seed;

pass_entry:
user_alphabet = default_alphabet;
std::cout << "enter your password: ";

getline(std::cin, password);

for (int i = 0; i < password.length(); i++)
{
    password_int.push_back(password[i]);
}
//setting initial state of alphabet
for (int i = 0; i < password.length(); i++)
{
    shuffle(std::begin(user_alphabet), std::end(user_alphabet), std::mt19937(password_int[i]));
}

if (user_alphabet == default_alphabet)
{
    std::cout << "invalid password";
    goto pass_entry;
}

retry:
shift_this = "null";
std::cout << "enter string to encrypt (ALL CAPS & spaces): ";

getline(std::cin, shift_this);

for (int i = 0; i < shift_this.length(); i++)
{   

    temp_string = shift_this[i];
    shift_int.push_back(shift_this[i]);

    if (shift_int[i] == 32)
    {continue;}

    if(std::find(default_alphabet.begin(), default_alphabet.end(), temp_string) != default_alphabet.end()) {
	} else {std::cout << "Please use A-Z (CAPS ONLY) and spaces to represent your message" << std::endl; goto retry;}

}

seed = password[0]; 

for (int i = 0; i < password.length(); i++)
{
seed = seed*password[i];
shuffle(std::begin(user_alphabet), std::end(user_alphabet), std::mt19937(seed));

}

seed = 0;

for (int i = 0; i < shift_this.length(); i++)
{

seed = shift_int[i];

temp_string = shift_this[i];
temp_int = std::distance(default_alphabet.begin(), (std::find(default_alphabet.begin(), default_alphabet.end(), temp_string)));

if (shift_int[i] == 32)
{continue;}

encrypted_text.append(user_alphabet[temp_int]);

if (i != shift_this.length() - 1)
{encrypted_text.push_back('-');}

shuffle(std::begin(user_alphabet), std::end(user_alphabet), std::mt19937(seed));

}
//displaying encrypted message
newline;
std::cout << "_ENCRYPTED MESSAGE_";
newline; newline;
std::cout << encrypted_text;
newline; newline;

}
