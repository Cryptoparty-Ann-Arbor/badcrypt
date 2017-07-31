#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int count = 0;
	//vector<string> check= {"", "", "", ""};
	vector<string> words = {"paul", "john", "ringo", "george"};
	sort(words.begin(), words.end());
	
	do {
		//could compare the vector as it permutates to the original vector
		cout << words[0] + words[1] + words[2] + words[3] << endl; count++;
	} while(next_permutation(words.begin(), words.end()));
	
	cout << count << endl;
}