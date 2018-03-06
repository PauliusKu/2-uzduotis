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

void Random()
{
	Mokiniai Mok;
	
	cout << "Mokinio vardas: ";
	cin >> Mok.vardas;
	cout << "Mokinio pavarde: ";
	cin >> Mok.pavarde;
	
	int a = 0;
	int n = 0;
	bool t = true;
	cout << "Pasirinkote: random generavimas. Iveskite, kiek pazymiu norite sugeneruoti" << endl;
	std::random_device rd;
	std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));
	std::uniform_int_distribution<int> dist(1,10);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Mok.Pazymiai.push_back(dist(mt)); //i vektoriu irasomi random pazymiai
	}
	cout << "Mokinio egzamino ivertinimas: ";
	cin >> a;
	Mok.Pazymiai.push_back(a);
	
	
	Mok.galBalVid = Vidurkis(&Mok.Pazymiai);
	std::sort (Mok.Pazymiai.begin(), Mok.Pazymiai.end()-1); //rikiavimas
	Mok.galBalMed = Mediana(Mok.Pazymiai); //skaiciuojama mediana perduodama vidurkio kintamajam del isvesties patogumo
	
	vector<Mokiniai> MokiniaiV{Mok};
	Isvestis(MokiniaiV);
	cout << "Funkcijos pabaiga" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;	
	
	
}	
//----------------------------------------------------------------------------------------	
void Konsole()
{
	Mokiniai Mok;
	
	cout << "Mokinio vardas: ";
	cin >> Mok.vardas;
	cout << "Mokinio pavarde: ";
	cin >> Mok.pavarde;
	
	cout << "Pasirinkote: ivestis per konsole. Noredami pabaigti pazymiu ivedima, iveskite 0" << endl;
	int a = 0;
	bool t = true;
	do{ //ivedimas is konsoles
		cout << Mok.Pazymiai.size()+1 << "-asis pazymys ";
		cin >> a;
		Mok.Pazymiai.push_back(a);
		if (Mok.Pazymiai[Mok.Pazymiai.size()-1] > 10 || Mok.Pazymiai[Mok.Pazymiai.size()-1] < 0) //jei pazymys nera nuo 1 iki 10, jis pasalinamas is vektoriaus
		{
			cout << "Vertinimas turi buti desimtbaleje sistemoje " << endl;
			Mok.Pazymiai.pop_back();
		} else if (Mok.Pazymiai[Mok.Pazymiai.size()-1] == 0) //jei 0, paskutinis vektoriaus elementas pasalinamas
		{
			t = false;
			Mok.Pazymiai.pop_back();
			cout << "Pazymiu ivedimas baigtas" << endl;
		} else {
		}
	}while (t);
	cout << "Mokinio egzamino ivertinimas: ";
	cin >> a;
	Mok.Pazymiai.push_back(a);
	
	Mok.galBalVid = Vidurkis(&Mok.Pazymiai);
	std::sort (Mok.Pazymiai.begin(), Mok.Pazymiai.end()-1); //rikiavimas
	Mok.galBalMed = Mediana(Mok.Pazymiai); //skaiciuojama mediana perduodama vidurkio kintamajam del isvesties patogumo
	
	vector<Mokiniai> MokiniaiV{Mok};
	Isvestis(MokiniaiV);
	cout << "Funkcijos pabaiga" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
}
//----------------------------------------------------------------------------------------
void Rusiuoti(Mokiniai Mok, vector<Mokiniai> &Win, vector<Mokiniai> &Los)
{
	if (Mok.galBalVid >= 6)
	{
		Win.push_back(Mok);
	} else {
		Los.push_back(Mok);
	}
}
//----------------------------------------------------------------------------------------
void Rikiuoti(vector<Mokiniai> &Mok)
{
	Mokiniai in = {};
	for (int i = 0; i < Mok.size(); i++)
	{
		int best = i;
		for (int j = i+1; j < Mok.size(); j++)
		{
			if (Mok[best].pavarde > Mok[j].pavarde)
			{
				best = j;
			}
		}
		in = Mok[i];
		Mok[i] = Mok[best];
		Mok[best] = in;
	}
}
//----------------------------------------------------------------------------------------
void Failas()
{
	vector<Mokiniai> Mok;
	vector<Mokiniai> Win{};
	vector<Mokiniai> Los{};
	try {
    	Nuskaitymas(&Mok);
    	
		//vidurki, mediana ir rusiavimas
		for (int i = 0; i < Mok.size(); i++)
		{
			std::sort (Mok[i].Pazymiai.begin(), Mok[i].Pazymiai.end()-1); //rikiavimas
			Mok[i].galBalVid = Vidurkis(&Mok[i].Pazymiai);
			Mok[i].galBalMed = Mediana(Mok[i].Pazymiai);
			Rusiuoti(Mok[i], Win, Los);
		}
	/*	Isvestis(Mok);
		cout << endl;
		cout << "WINNERS" << endl;
		Isvestis(Win);
		cout << endl;
		cout << "LOSERS" << endl;
		Isvestis(Los);*/
   	}catch (const char* msg) {
    cout << msg << endl;
   	}
	
	
	cout << "Funkcijos pabaiga" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
}
//----------------------------------------------------------------------------------------	
void Nuskaitymas(vector<Mokiniai> *Mok)
{
	std::ifstream inf("Failas.txt"); //nuskaitymo pradzia
	if (inf == NULL)
	{
		throw "Failas nerastas!";
	}
	Mokiniai in;
	for (int i = 0; !inf.eof(); i)
	{
		string input; //ivesties string'as
		inf >> input; //ivestis
		if (input == "")
		{
			if (i == 0)
			{
				throw "Failas tuscias!";
			}
			break;
		}
		if ((input == "1") || (input == "2") || (input == "3") || (input == "4") || (input == "5") || (input == "6") || (input == "7") || (input == "8") || (input == "9") || (input == "10"))
		{	
			in.Pazymiai.push_back(std::stoi (input)); //iraso i vektoriu pazymius
		} else {
			if (i != 0)
			{
				Mok->push_back(in);
			}
			in.pavarde = input; //iveda i vektoriu pavardes
			inf >> input;
			in.vardas = input; //iveda i vektoriu vardus
			i++;
			in.Pazymiai = {};
		}
	}
	Mok->push_back(in);
	inf.close(); //nuskaitymo pabaiga	
}
//----------------------------------------------------------------------------------------
double Vidurkis(vector<int> *Pazymiai)
{
	return double(std::accumulate(Pazymiai->begin(), Pazymiai->end()-1, 0))/(Pazymiai->size()-1)*0.4+Pazymiai->back()*0.6;
}
//----------------------------------------------------------------------------------------
double Mediana(vector<int> &Pazymiai)
{
	if ((Pazymiai.size()-1) % 2 == 0)
	{
		return ((double)(Pazymiai[(Pazymiai.size()-1)/2-1]) + (double)(Pazymiai[(Pazymiai.size()-1)/2]))/2*0.4+Pazymiai[Pazymiai.size()-1]*0.6;
	} else {
		return (Pazymiai[(Pazymiai.size()-1)/2])*0.4+Pazymiai[Pazymiai.size()-1]*0.6;
	}
	
}
//----------------------------------------------------------------------------------------
void Isvestis(vector<Mokiniai> &Mok)
{
	Rikiuoti(Mok);
	int a = 8; int b = 8;
	for (int i = 0; i < Mok.size(); i++)
	{
		if (Mok[i].pavarde.size() > a) //randa ilgiausia pavarde
		{
			a = Mok[i].pavarde.size();
		}
		if (Mok[i].vardas.size() > b) //randa ilgiausia varda
		{
			b = Mok[i].vardas.size();
		}
	}	
	cout << std::setw(a+1) << std::left << "Pavarde";
	cout << std::setw(b+1) << std::left << "Vardas";
	cout << std::fixed;
	cout << std::setw(3) << std::left << "Vid   Med" << endl;
	for (int i = 0; i < a+b+12; i++)
	{
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < Mok.size(); i++)
	{
		cout << i+1 << " ";
		cout << std::setw(a+1) << std::left << Mok[i].pavarde;
		cout << std::setw(b+1) << std::left << Mok[i].vardas;
		cout << std::fixed;
		cout << std::setw(3) << std::left << std::setprecision(2) << Mok[i].galBalVid << "  " << Mok[i].galBalMed << endl;
	}
	for (int i = 0; i < a+b+12; i++)
	{
		cout << "-";
	}
	cout << endl;	
}
//----------------------------------------------------------------------------------------
void GeneruotiFaila()
{
	std::ofstream of("Failas.txt"); //irasymo pradzia
	unsigned int n{}; //ilgis
	cout << "Iveskte, kokio ilgio?" << endl;
	cin >> n;
	
	auto start = std::chrono::high_resolution_clock::now();
	
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
	Failas();
	auto end = std::chrono::high_resolution_clock::now();
	cout << std::chrono::duration<double>(end-start).count() << " sekundes" << endl;
}
