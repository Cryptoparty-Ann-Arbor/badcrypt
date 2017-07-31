#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>

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

int count(std::string &inName)
{

	std::string cLine = "UNDEF";
	std::string null = "";

	std::ifstream infile(inName + ".txt");

	for (int i = 0; i > -1 ; i++)
	{
		std::getline(infile, cLine);

		if(!(null).compare(cLine))
		{infile.close(); return i;}
	}

}



int main()
{
	
	int lineH;
	std::string null="";
	std::string hLine;
	std::string hashList = "hashlist";

	// cout << "Specify YOUR hash wordlist:"; cin >> hashList;

	lineH = count(hashList);
	
	std::ifstream hashfile(hashList +".txt");
	
			hashfile.clear();
			hashfile.seekg(0, std::ios::beg);

		
		for (int i = 0; i < lineH; i++)
		{	
			std::getline(hashfile, hLine);
			std::cout << std::endl << "**********" << craigs_hash_is_bomb(hLine) << "***********" << std::endl << i;

            if (craigs_hash_is_bomb(hLine) == "3006394608") // ---3006394608
            {
                std::cout << std::endl;
                std::cout << "Password Found: " << hLine; return 0;}
			
			if (!(null).compare(hLine))
			{std::cout << "end of file: "; exit(0);}
			
		
		}
			
		
	}