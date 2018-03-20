#include "Headeris.h"
#include <iostream>
#include <iomanip>  
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
		
//----------------------------------------------------------------------------------------
double Vidurkis(vector<int> &Pazymiai)
{
	return double(std::accumulate(Pazymiai.begin(), Pazymiai.end()-1, 0))/(Pazymiai.size()-1)*0.4+Pazymiai.back()*0.6;
}
//----------------------------------------------------------------------------------------
double Mediana(vector<int> &Pazymiai)
{
	std::sort(Pazymiai.begin(), Pazymiai.end()-1);
	if ((Pazymiai.size()-1) % 2 == 0)
	{
		return ((double)(Pazymiai[(Pazymiai.size()-1)/2-1]) + (double)(Pazymiai[(Pazymiai.size()-1)/2]))/2*0.4+Pazymiai[Pazymiai.size()-1]*0.6;
	} else {
		return (Pazymiai[(Pazymiai.size()-1)/2])*0.4+Pazymiai[Pazymiai.size()-1]*0.6;
	}
	
}
//--------------------------------------------------------------------------------------------------------------------------------------
void GeneruotiFaila(unsigned int n)
{
	std::ofstream of("Failas.txt"); //irasymo pradzia
	
	std::random_device rd;
	std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));
	for (unsigned int i = 0; i < n; i++)
	{
		std::uniform_int_distribution<char> dist(97,122);
		of << (char)(dist(mt)-32);
		for (int i = 0; i < (int)dist(mt)-95; i++)
		{
			of << dist(mt);
		}
		of << " ";
		of << (char)(dist(mt)-32);
		for (int i = 0; i < (int)dist(mt)-95; i++)
			{
			of << dist(mt);
		}
		of << " ";
		std::uniform_int_distribution<int> distint(1, 10);
		for (int i = 0; i < (int)dist(mt)-95; i++)
		{
			of << distint(mt) << " ";
		}	
		of << endl;
	}
	of.close();
}
//----------------------------------------------------------------------------------------
bool customCompare(Mokiniai &stud1, Mokiniai &stud2){
    return stud1.pavarde < stud2.pavarde;
}
