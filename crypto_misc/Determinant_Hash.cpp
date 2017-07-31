#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <armadillo>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <stdlib.h>

using namespace std;
using namespace arma;



int dng(int seed)
{

    mt19937 mt(seed);
    uniform_int_distribution<int> dist(0,999);

    return dist(mt);

}

vector<int> enc(string &pt)
{

    //string pt = plaintext;
    vector<int> pti;
    vector<int> hash;
    

    //cin >> &pt;
    cout << endl;

for (int i=0; i < pt.length(); i++)
{
    pti.push_back(pt[i]);
}

int fm = dng(pti[0]);

for (int i=0; i < (pt.length()*10); i++)
{

pti.push_back(pti[(i%pt.length())]);

}



int ims = 2;
for (int i=2; (i*i)*70 < 2*(pti.size()); i++)
{
    ims = i;
}

//variable for incrementing the seed
int inc = 0;
//variable for seeding the shuffle
int mul = 1;

//calculating those variables

for (int i=0; i < pti.size(); i++)
{
inc = inc + dng(pti[i % pt.length()]);
mul = mul*pti[i % pt.length()]; 
}

while (pti.size() < (ims*ims)*70)
{

    pti.push_back(dng(pti.back()+inc));
    inc++;
    
}


// shuffling the elements of the vector before populating the matrices

auto engine = std::default_random_engine{};
shuffle(std::begin(pti), std::end(pti), engine);


//variable for vector index
int c = 0;

// matrices 0-9 for 30 digit hash
mat w_0(ims,ims);
mat w_1(ims,ims);
mat w_2(ims,ims);
mat w_3(ims,ims);
mat w_4(ims,ims);
mat w_5(ims,ims);
mat w_6(ims,ims);
mat w_7(ims,ims);
mat w_8(ims,ims);
mat w_9(ims,ims);
mat w_10(ims,ims);
mat w_11(ims,ims);
mat w_12(ims,ims);
mat w_13(ims,ims);
mat w_14(ims,ims);
mat w_15(ims,ims);
mat w_16(ims,ims);
mat w_17(ims,ims);
mat w_18(ims,ims);
mat w_19(ims,ims);
mat w_20(ims,ims);
mat w_21(ims,ims);
mat w_22(ims,ims);
mat w_23(ims,ims);
mat w_24(ims,ims);
mat w_25(ims,ims);
mat w_26(ims,ims);
mat w_27(ims,ims);
mat w_28(ims,ims);
mat w_29(ims,ims);
mat w_30(ims,ims);
mat w_31(ims,ims);
mat w_32(ims,ims);
mat w_33(ims,ims);
mat w_34(ims,ims);
mat w_35(ims,ims);
mat w_36(ims,ims);
mat w_37(ims,ims);
mat w_38(ims,ims);
mat w_39(ims,ims);
mat w_40(ims,ims);
mat w_41(ims,ims);
mat w_42(ims,ims);
mat w_43(ims,ims);
mat w_44(ims,ims);
mat w_45(ims,ims);
mat w_46(ims,ims);
mat w_47(ims,ims);
mat w_48(ims,ims);
mat w_49(ims,ims);
mat w_50(ims,ims);
mat w_51(ims,ims);
mat w_52(ims,ims);
mat w_53(ims,ims);
mat w_54(ims,ims);
mat w_55(ims,ims);
mat w_56(ims,ims);
mat w_57(ims,ims);
mat w_58(ims,ims);
mat w_59(ims,ims);
mat w_60(ims,ims);
mat w_61(ims,ims);
mat w_62(ims,ims);
mat w_63(ims,ims);
mat w_64(ims,ims);
mat w_65(ims,ims);
mat w_66(ims,ims);
mat w_67(ims,ims);
mat w_68(ims,ims);
mat w_69(ims,ims);


// for loops for populating vectors

for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_0(i,j) = pti[c] ;
        c++;
       
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_1(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_2(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_3(i,j) = pti[c];
        c++;
    
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_4(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_5(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_6(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_7(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_8(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_9(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_10(i,j) = pti[c] ;
        c++;
       
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_11(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_12(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_13(i,j) = pti[c];
        c++;
    
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_14(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_15(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_16(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_17(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_18(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_19(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_20(i,j) = pti[c] ;
        c++;
       
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_21(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_22(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_23(i,j) = pti[c];
        c++;
    
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_24(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_25(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_26(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_27(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_28(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_29(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_30(i,j) = pti[c] ;
        c++;
       
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_31(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_32(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_33(i,j) = pti[c];
        c++;
    
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_34(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_35(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_36(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_37(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_38(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_39(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_40(i,j) = pti[c] ;
        c++;
       
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_41(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_42(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_43(i,j) = pti[c];
        c++;
    
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_44(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_45(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_46(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_47(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_48(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_49(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_50(i,j) = pti[c] ;
        c++;
       
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_51(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_52(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_53(i,j) = pti[c];
        c++;
    
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_54(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_55(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_56(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_57(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_58(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_59(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_60(i,j) = pti[c] ;
        c++;
       
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_61(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_62(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_63(i,j) = pti[c];
        c++;
    
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_64(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_65(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_66(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_67(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {
        w_68(i,j) = pti[c];
        c++;
    }
 }

 for (int i = 0; i < ims; i++)
{
    for (int j = 0; j < ims; j++)
    {   
        cout << c << " ";
        w_69(i,j) = pti[c];
        c++;
    }
 }




//calculate the hashes by taking the absolute value of the determinant mod fm? check this for collisions!

hash.push_back(fmod(abs(det((w_0))),fm));
hash.push_back(fmod(abs(det((w_1))),fm)); 
hash.push_back(fmod(abs(det((w_2))),fm)); 
hash.push_back(fmod(abs(det((w_3))),fm)); 
hash.push_back(fmod(abs(det((w_4))),fm)); 
hash.push_back(fmod(abs(det((w_5))),fm)); 
hash.push_back(fmod(abs(det((w_6))),fm)); 
hash.push_back(fmod(abs(det((w_7))),fm)); 
hash.push_back(fmod(abs(det((w_8))),fm));
hash.push_back(fmod(abs(det((w_9))),fm));
hash.push_back(fmod(abs(det((w_10))),fm)); 
hash.push_back(fmod(abs(det((w_11))),fm)); 
hash.push_back(fmod(abs(det((w_12))),fm)); 
hash.push_back(fmod(abs(det((w_13))),fm)); 
hash.push_back(fmod(abs(det((w_14))),fm)); 
hash.push_back(fmod(abs(det((w_15))),fm)); 
hash.push_back(fmod(abs(det((w_16))),fm)); 
hash.push_back(fmod(abs(det((w_17))),fm)); 
hash.push_back(fmod(abs(det((w_18))),fm)); 
hash.push_back(fmod(abs(det((w_19))),fm)); 
hash.push_back(fmod(abs(det((w_20))),fm)); 
hash.push_back(fmod(abs(det((w_21))),fm)); 
hash.push_back(fmod(abs(det((w_22))),fm)); 
hash.push_back(fmod(abs(det((w_23))),fm)); 
hash.push_back(fmod(abs(det((w_24))),fm)); 
hash.push_back(fmod(abs(det((w_25))),fm)); 
hash.push_back(fmod(abs(det((w_26))),fm)); 
hash.push_back(fmod(abs(det((w_27))),fm)); 
hash.push_back(fmod(abs(det((w_28))),fm)); 
hash.push_back(fmod(abs(det((w_29))),fm)); 
hash.push_back(fmod(abs(det((w_30))),fm)); 
hash.push_back(fmod(abs(det((w_31))),fm)); 
hash.push_back(fmod(abs(det((w_32))),fm)); 
hash.push_back(fmod(abs(det((w_33))),fm)); 
hash.push_back(fmod(abs(det((w_34))),fm)); 
hash.push_back(fmod(abs(det((w_35))),fm)); 
hash.push_back(fmod(abs(det((w_36))),fm)); 
hash.push_back(fmod(abs(det((w_37))),fm)); 
hash.push_back(fmod(abs(det((w_38))),fm)); 
hash.push_back(fmod(abs(det((w_39))),fm));
hash.push_back(fmod(abs(det((w_40))),fm)); 
hash.push_back(fmod(abs(det((w_41))),fm)); 
hash.push_back(fmod(abs(det((w_42))),fm)); 
hash.push_back(fmod(abs(det((w_43))),fm)); 
hash.push_back(fmod(abs(det((w_44))),fm)); 
hash.push_back(fmod(abs(det((w_45))),fm)); 
hash.push_back(fmod(abs(det((w_46))),fm)); 
hash.push_back(fmod(abs(det((w_47))),fm)); 
hash.push_back(fmod(abs(det((w_48))),fm)); 
hash.push_back(fmod(abs(det((w_49))),fm));
hash.push_back(fmod(abs(det((w_50))),fm)); 
hash.push_back(fmod(abs(det((w_51))),fm)); 
hash.push_back(fmod(abs(det((w_52))),fm)); 
hash.push_back(fmod(abs(det((w_53))),fm)); 
hash.push_back(fmod(abs(det((w_54))),fm)); 
hash.push_back(fmod(abs(det((w_55))),fm)); 
hash.push_back(fmod(abs(det((w_56))),fm)); 
hash.push_back(fmod(abs(det((w_57))),fm)); 
hash.push_back(fmod(abs(det((w_58))),fm)); 
hash.push_back(fmod(abs(det((w_59))),fm));
hash.push_back(fmod(abs(det((w_60))),fm)); 
hash.push_back(fmod(abs(det((w_61))),fm)); 
hash.push_back(fmod(abs(det((w_62))),fm)); 
hash.push_back(fmod(abs(det((w_63))),fm)); 
hash.push_back(fmod(abs(det((w_64))),fm)); 
hash.push_back(fmod(abs(det((w_65))),fm)); 
hash.push_back(fmod(abs(det((w_66))),fm)); 
hash.push_back(fmod(abs(det((w_67))),fm)); 
hash.push_back(fmod(abs(det((w_68))),fm)); 
hash.push_back(fmod(abs(det((w_69))),fm)); 


// code for displaying output

//cout << endl;

//cout << w_0;
//cout << endl;

//cout << w_1;
//cout << endl;

//cout << w_2;
//cout << endl;

//cout << w_3;
//cout << endl;

//cout << w_4;
//cout << endl;

//cout << w_5;
//cout << endl;

//cout << w_6;
//cout << endl;

//cout << w_7;
//cout << endl;

//cout << w_8;
//cout << endl;

//cout << w_9;
//cout << endl;

for (auto x : hash)
{
    cout << x;
}
// end code for displaying output

return hash; 
}






int main()
{

    string cLine = "UNDEF";
	string null = "";
    vector<int> temp;

	vector<string> ptstor;
    vector<vector<int>> hashstor;
    

	ptstor.clear();


	ifstream infile("hashthis.txt");
	infile.clear();
	infile.seekg(0, ios::beg);

    ofstream outfile("outfile.txt");
    outfile.clear();

	for (int i = 0; i > -1 ; i++)
	{
		getline(infile, cLine);

        if(!(null).compare(cLine))
		{infile.close(); break;}

		ptstor.push_back(cLine);
        cout << "-" << cLine << " " << endl;

        temp = enc(cLine);

      outfile << "";
        auto first = true;
        for (float f : temp) 
            { 
                if (!first) { outfile << ""; } 
                first = false; 
                outfile << f; 
            }
            outfile << "" << endl;

         //if (std::find(hashstor.begin(), hashstor.end(), temp) != hashstor.end())
        //{
            //printf("Hit any key to continue> ");
            //getchar();
        //} 
        
        hashstor.push_back(temp);
		
	}

    cout << endl;
	
}




