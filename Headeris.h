#ifndef HEADERIS_H
#define HEADERIS_H 

#include <typeinfo>
#include <string> 
#include <vector>
#include <deque>
#include <list>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

struct Mokiniai{
	string pavarde{};
	string vardas{};
	vector<int> Pazymiai;
	double galBalVid{};
	double galBalMed{};	
};
template <typename T> void sortContainer(T &);
bool customCompare(Mokiniai &, Mokiniai &);
void Konsole();
double Vidurkis(vector<int> &Pazymiai);
double Mediana(vector<int> &Pazymiai);
template <typename T> void Isvestis(T &Mok)
{
	//Rikiuoti(Mok);
	int a = 8; int b = 8;
	for (auto& v : Mok)
	{
		if (v.pavarde.size() > a) //randa ilgiausia pavarde
		{
			a = v.pavarde.size();
		}
		if (v.vardas.size() > b) //randa ilgiausia varda
		{
			b = v.vardas.size();
		}
	}	
	cout << std::setw(a+1) << std::left << "Pavarde";
	cout << std::setw(b+1) << std::left << "Vardas";
	cout << std::fixed;
	cout << std::setw(3) << std::left << "Vid   Med" << endl;
	for (unsigned int i = 0; i < a+b+12; i++)
	{
		cout << "-";
	}
	cout << endl;
	unsigned int i = 0;
	for (auto& v : Mok)
	{
		i++;
		cout << i << " ";
		cout << std::setw(a+1) << std::left << v.pavarde;
		cout << std::setw(b+1) << std::left << v.vardas;
		cout << std::fixed;
		cout << std::setw(3) << std::left << std::setprecision(2) << v.galBalVid << "  " << v.galBalMed << endl;
	}
	for (unsigned int i = 0; i < a+b+12; i++)
	{
		cout << "-";
	}
	cout << endl;	
}
//------------------------------------------
void GeneruotiFaila(unsigned int n);
template <typename T> void Nuskaitymas(T &Mok)
{
	std::ifstream inf("Failas.txt"); //nuskaitymo pradzia
	if (inf == NULL)
	{
		throw "Failas nerastas!";
	}
	Mokiniai in;
	for (unsigned int i = 0; !inf.eof(); i)
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
				Mok.push_back(in);
			}
			in.pavarde = input; //iveda i vektoriu pavardes
			inf >> input;
			in.vardas = input; //iveda i vektoriu vardus
			i++;
			in.Pazymiai = {};
		}
	}
	Mok.push_back(in);
	inf.close(); //nuskaitymo pabaiga	
}
template <typename T> void Failas()
{
	T Mok;
	T Win{};
	T Los{};
	try {
    	Nuskaitymas(Mok);
    	
		//vidurki, mediana ir rusiavimas
		for (auto& v : Mok)
		{
			switch(v.Pazymiai.size())
			{
				case 1: throw "Truksta nd ivertinimu!";
				case 0: throw "Truksta nd ivertinimu ir egzamino ivertinimu!";
			}
			v.galBalVid = Vidurkis(v.Pazymiai);
			v.galBalMed = Mediana(v.Pazymiai);
			if (v.galBalVid >= 6)
			{
				Win.push_back(v);
			} else {
			Los.push_back(v);
			}
		}
		sortContainer(Mok);
		/*Isvestis(Mok); //visu duomenu isvestis per konsole
		cout << endl;
		cout << "WINNERS" << endl;
		Isvestis(Win);
		cout << endl;
		cout << "LOSERS" << endl;
		Isvestis(Los);*/
   	}catch (const char* msg) {
    std::cout << msg << std::endl;
   	}
	
}
template <> void sortContainer(std::vector<Mokiniai> &stud){
    std::sort(stud.begin(), stud.end(), customCompare);
}
template <> void sortContainer(std::deque<Mokiniai> &stud){
    std::sort(stud.begin(), stud.end(), customCompare);
}
template <> void sortContainer(std::list<Mokiniai> &stud){
    stud.sort(customCompare);
}
template <typename T> void Random()
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
	
	
	Mok.galBalVid = Vidurkis(Mok.Pazymiai);
	Mok.galBalMed = Mediana(Mok.Pazymiai); //skaiciuojama mediana perduodama vidurkio kintamajam del isvesties patogumo
	
	T MokiniaiV{Mok};
	Isvestis(MokiniaiV);
	cout << "Funkcijos pabaiga" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;	
	
	
}
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
	
	Mok.galBalVid = Vidurkis(Mok.Pazymiai);
	std::sort (Mok.Pazymiai.begin(), Mok.Pazymiai.end()-1); //rikiavimas
	Mok.galBalMed = Mediana(Mok.Pazymiai); //skaiciuojama mediana perduodama vidurkio kintamajam del isvesties patogumo
	vector<Mokiniai> MokiniaiV{Mok};
	Isvestis(MokiniaiV);
	cout << "Funkcijos pabaiga" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
}
#endif
