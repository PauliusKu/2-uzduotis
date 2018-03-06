#ifndef HEADERIS_H
#define HEADERIS_H 

#include <string> 
#include <vector>

using std::string;
using std::vector;

struct Mokiniai{
	string pavarde{};
	string vardas{};
	vector<int> Pazymiai;
	double galBalVid{};
	double galBalMed{};	
};

void Random();
void Konsole();
void Failas();
void Nuskaitymas(vector<Mokiniai> *Mok);
double Vidurkis(vector<int> *Pazymiai);
double Mediana(vector<int> &Pazymiai);
void Isvestis(vector<Mokiniai> &Mok);
void Rusiuoti(Mokiniai Mok, vector<Mokiniai> &Win, vector<Mokiniai> &Los);
void Rikiuoti(vector<Mokiniai> &Mok);
void GeneruotiFaila();

#endif
