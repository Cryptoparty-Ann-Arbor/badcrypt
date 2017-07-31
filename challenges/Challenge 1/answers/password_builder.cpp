//password_builder for modified smoke_hash

#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

void display_vector(const std::vector<int> &v)
{
    std::copy(v.begin(), v.end(),
        std::ostream_iterator<int>(std::cout, " "));
}


int dng(int seed, int min, int max)
{
 
    std::mt19937 mt(seed);
    std::uniform_int_distribution<int> dist(min, max);

    return dist(mt);

}

int main()
{

std::vector<std::string> random_data = {"3846870223", "3962687902", 
"7470852223", "7514179786", "2202953802", 
"7504486334", "1795029264", "7766294303", "6736111978", "9393656247"};
std::string hash;
std::vector<int> index_1_pos;
std::vector<int> indices_1;
std::vector<int> indices_2;
std::vector<int> pt_sum_pos;
std::vector<int> character_seeds_0;
std::vector<int> character_seeds_1;
std::vector<int> character_seeds_2;
std::vector<int> character_seeds_3;
std::vector<int> character_seeds_4;
std::vector<int> character_seeds_5;
std::vector<int> character_seeds_6;
std::vector<int> character_seeds_7;
std::vector<int> character_seeds_8;
std::vector<int> character_seeds_9;

std::cin >> hash;
std::cout << std::endl;

//checking 3006394608

for (int i = 0; i < 10; i++)
{   
    int count = 0;
    for (int j = i; count < 10; j++)
    {

        j = j % 10;

        if(std::find(random_data[j].begin(), random_data[j].end(), hash[count % hash.length()]) != random_data[j].end()) 
        {} else {std::cout << i << ": Index Not Possible" << std::endl; break;}

        count++;

        if (count == 10)
        {index_1_pos.push_back(i);
        std::cout << i << ": Index Possible" << std::endl;
        break;}
    }
    if (count == 10)
    {continue;}

}

int temp_index = index_1_pos[0]; // taking first possible index

for (int i = 0; i < 10; i++)
{

indices_1.push_back((temp_index + i) % 10);


}


std::cout << std::endl;
std::cout << "Index_1 Possibilities for hash: " << hash;
std::cout << std::endl;
std::cout << "------------------------------------------";
std::cout << std::endl;
display_vector(index_1_pos);
std::cout << std::endl;
std::cout << std::endl;

for (int i = 0; i < 10; i++)
{
int index_2 = std::distance(random_data[indices_1[i]].begin(), (std::find(random_data[indices_1[i]].begin(), random_data[indices_1[i]].end(), hash[i])));

indices_2.push_back(index_2);

}
std::cout << std::endl;
std::cout << "indices for hash";
std::cout << std::endl;
display_vector(indices_2);
std::cout << std::endl;
std::cout << std::endl;

std::cout << "integer values for possible characters";
for (int i = 33; i < 136; i++)
{
    if (dng(i, 0, 9) == indices_2[0])
    {character_seeds_0.push_back(i);}

}

for (int i = 33; i < 136; i++)
{
    if (dng(i, 0, 9) == indices_2[1])
    {character_seeds_1.push_back(i);}

}

for (int i = 33; i < 136; i++)
{
    if (dng(i, 0, 9) == indices_2[2])
    {character_seeds_2.push_back(i);}

}

for (int i = 33; i < 136; i++)
{
    if (dng(i, 0, 9) == indices_2[3])
    {character_seeds_3.push_back(i);}

}

for (int i = 33; i < 136; i++)
{
    if (dng(i, 0, 9) == indices_2[4])
    {character_seeds_4.push_back(i);}

}

for (int i = 33; i < 136; i++)
{
    if (dng(i, 0, 9) == indices_2[5])
    {character_seeds_5.push_back(i);}

}

for (int i = 33; i < 136; i++)
{
    if (dng(i, 0, 9) == indices_2[6])
    {character_seeds_6.push_back(i);}

}

for (int i = 33; i < 136; i++)
{
    if (dng(i, 0, 9) == indices_2[7])
    {character_seeds_7.push_back(i);}

}

for (int i = 33; i < 136; i++)
{
    if (dng(i, 0, 9) == indices_2[8])
    {character_seeds_8.push_back(i);}

}

for (int i = 33; i < 136; i++)
{
    if (dng(i, 0, 9) == indices_2[9])
    {character_seeds_9.push_back(i);}

}


for (int i = 33; i < 136*10; i++)
{
    if (dng(i, 0, 9) == indices_1[0]) // first possible index
    {pt_sum_pos.push_back(i);} //list of possible pt_sums
}


std::cout << std::endl;
display_vector(character_seeds_0);
std::cout << std::endl;

std::cout << std::endl;
display_vector(character_seeds_1);
std::cout << std::endl;

std::cout << std::endl;
display_vector(character_seeds_2);
std::cout << std::endl;

std::cout << std::endl;
display_vector(character_seeds_3);
std::cout << std::endl;

std::cout << std::endl;
display_vector(character_seeds_4);
std::cout << std::endl;

std::cout << std::endl;
display_vector(character_seeds_5);
std::cout << std::endl;

std::cout << std::endl;
display_vector(character_seeds_6);
std::cout << std::endl;

std::cout << std::endl;
display_vector(character_seeds_7);
std::cout << std::endl;

std::cout << std::endl;
display_vector(character_seeds_8);
std::cout << std::endl;

std::cout << std::endl;
display_vector(character_seeds_9);
std::cout << std::endl;

std::cout << std::endl;
std::cout << "integer values for possible plaintext sums";
std::cout << std::endl;
display_vector(pt_sum_pos);
std::cout << std::endl;
std::cout << std::endl;

std::cout << "find a combination of integers that add to a listed plaintext sum, convert the decimal representation to characters to find a valid password";
std::cout << std::endl;


 
}
