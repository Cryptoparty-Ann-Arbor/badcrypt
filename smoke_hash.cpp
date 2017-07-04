// single word hashing example using deterministic number generator mersenne twister
// all random is pseduo random...relax

#include <iostream>
#include <vector>
#include <random>


// deterministic random number generator mersenne twister
int dng(int seed, int min, int max)
{
 
    std::mt19937 mt(seed);
    std::uniform_int_distribution<int> dist(min, max);

    return dist(mt);

}

int main()
{

    std::string pt; //plaintext
    std::vector<int> pt_int; //integer values of characters
    int pt_sum = 0;

    std::cin >> pt;

    for (int i=0; i < pt.length(); i++)
    {

        pt_int.push_back(pt[i]); //filling vector
        pt_sum = pt_sum + pt_int[i]; //sum of character values

    }

    //pre-generated random data 10 entries, of 10 length
    std::vector<std::string> random_data = {"3846870223", "3962687902", "7470852223", "7514179786", "2202953802", "7504486334", "1795029264", "7766294303", "6736111978", "9393656247"};
    //std::vector<long> random_data_long = {3846870223, 3962687902, 7470852223, 7514179786, 2202953802, 7504486334, 1795029264, 7766294303, 6736111978, 9393656247};
    
    int index_i = dng(pt_sum, 0, 9); //determining index 1

    for (int i=0; i < pt.length()*pt_sum; i++) //making hash as big as the length of the plaintext multiplied by the sum of the characters
    {
        
        std::cout << random_data[index_i][dng(pt[i % pt.length()],0,9)]; // see some problems with this? how to improve? I can think of a few!
        index_i = ((index_i + 1) % 10); // to avoid repetition
    }

}
