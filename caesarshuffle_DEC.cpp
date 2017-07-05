//caesarshuffle decryption

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

//laziness
#define newline std::cout << std::endl;

int main()
{

std::string temp_string;
int temp_int;
int seed;
std::string password;
std::string encrypted_text;
std::string decrypted_text;

std::vector<std::string> default_alphabet = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
std::vector<std::string> user_alphabet = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
std::vector<int> password_int;


std::cout << "enter your password: ";
getline(std::cin, password);

std::cout << "enter your encrypted string: ";
getline(std::cin, encrypted_text);

for (int i = 0; i < password.length(); i++)
{
    password_int.push_back(password[i]);
}

//setting initial alphabet state by password character values
for (int i = 0; i < password.length(); i++)
{
    shuffle(std::begin(user_alphabet), std::end(user_alphabet), std::mt19937(password_int[i]));
}

seed = password[0]; 

//further shuffling
for (int i = 0; i < password.length(); i++)
{
seed = seed*password[i];
shuffle(std::begin(user_alphabet), std::end(user_alphabet), std::mt19937(seed));
}

for (int i = 0; i < encrypted_text.length(); i++)
{

//ignoring dashes
if (encrypted_text[i] == '-')
{continue;}

temp_string = encrypted_text[i];
temp_int = std::distance(user_alphabet.begin(), (std::find(user_alphabet.begin(), user_alphabet.end(), temp_string)));

decrypted_text.append(default_alphabet[temp_int]);

if (i != encrypted_text.length() - 1)
{decrypted_text.push_back('-');}

//using first letter of plaintext as seed
seed = default_alphabet[temp_int][0]; 

shuffle(std::begin(user_alphabet), std::end(user_alphabet), std::mt19937(seed));

}

//displaying decrypted message
newline;
std::cout << "_DECRYPTED MESSAGE_ " + encrypted_text + " : " + password;
newline;
newline;
std::cout << decrypted_text;
newline;
newline;

}