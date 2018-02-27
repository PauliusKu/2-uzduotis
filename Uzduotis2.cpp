/*!
 *  \brief     Mokinio pazymiu skaiciavimas
 *  \details   Ivedami mokinio pazymiai ir egzamino ivertinimas (random generavimas, ivestis per konsole ir ivestis is failo) ir apskaiciuojamas galutinis ivertinimas (pazymiu vidurkis, mediana).
 *  \author    Paulius
 *  \version   1.0
 *  \date      2018-02-27
 */
#include <iostream>
#include <iomanip>  
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

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


int main()
{
	
	cout << "Pasirinkite ivesties tipa: 0 - random generavimas, 1 - ivestis per konsole, 2 - ivestis is failo" << endl;
	string ivestis {};
	do //pagrindinisas ciklas kuriame pasirenkamas ivesties tipas
	{
		cin >> ivestis;
		if (ivestis == "0") //random generavimas
		{
			Random();
		}else if (ivestis == "1") //ivesdimas per konsole
		{
			Konsole();
		}else if (ivestis == "2") //ivedimas is failo
		{
			Failas();
		} else {
			cout << "ivedete klaidingai" << endl;
			ivestis = "";
		}
	} while (ivestis == "");
	return 0;
}
//----------------------------------------------------------------------------------------
void Random()
{
	char vardas[255];
	char pavarde[255];
	
	cout << "Mokinio vardas: ";
	cin >> vardas;
	cout << "Mokinio pavarde: ";
	cin >> pavarde;
	
	double galBalas = 0.00;
	vector<int> A;
	double med{};
	int n = 0; //pazymiu skaicius
	int e = 0; //egzamino ivertinimas
	
	cout << "Pasirinkote: random generavimas. Iveskite, kiek pazymiu norite sugeneruoti" << endl;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1,10);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		A.push_back(dist(mt)); //i vektoriu irasomi random pazymiai
		galBalas += A[i];
	}
	cout << "Iveskite mokinio egzamino ivertinima: ";
	cin >> e;
	
	cout << "Pasirinkite, kaip bus apskaiciuojamas namu darbo balas. 0 - vidurkis, 1 - mediana" << endl;
	int ivestis = -1;
	do{
		cin >> ivestis;
		if (ivestis == 0) //vidurkis
		{
			cout << "Pasirinkta: vidurkis" << endl;
			//galutinio balo skaiciavimas
			galBalas = (galBalas/n*0.4)+0.6*e;
		} else if (ivestis == 1) //mediana
		{
			cout << "Pasirinkta: mediana" << endl;
			//medianos skaiciavimas
			std::sort (A.begin(), A.end());
			if (n%2 == 0)
			{
				med = (double)(A[n/2-1] + A[n/2])/2;
			} else med = A[n/2];
	
			//galutinio balo skaiciavimas
			galBalas = med*0.4+0.6*e;
			
		} else{
			cout << "ivedete klaidingai" << endl;
			ivestis = -1;
		}
	}while (ivestis == -1);
	
	//isvesties pradzia
	cout << "Mokinio duomenys" << endl;
	cout << "Mokinio vardas: " << vardas << endl;
	cout << "Mokinio pavarde: " << pavarde << endl;
	for (int i = 0; i < n; i++) //isveda visus pazymius
	{
		cout << i+1 << "-asis pazymys " << A[i] << endl;
	}
	cout << "Mokinio egzamino ivertinimas: " << e << endl;
	cout << std::fixed;
	cout << "Mokinio Galutinis ivertinimas: " << std::setprecision(2) << galBalas << endl;
	cout << "Programos pabaiga." << endl;
	
	
}	
//----------------------------------------------------------------------------------------	
void Konsole()
{
	char vardas[255];
	char pavarde[255];
	
	cout << "Mokinio vardas: ";
	cin >> vardas;
	cout << "Mokinio pavarde: ";
	cin >> pavarde;
	
	double galBalas = 0.00;
	vector<int> A;
	double med{};
	int n = 0; //pazymiu skaicius
	int e = 0; //egzamino ivertinimas
	
	cout << "Pasirinkote: ivestis per konsole. Noredami pabaigti pazymiu ivedima, iveskite 0" << endl;
	int a = 0;
	
	bool t = true;
	do{ //ivedimas is konsoles
		cout << n+1 << "-asis pazymys ";
		cin >> a;
		A.push_back(a);
		if (A[n] > 10 || A[n] < 0) //jei pazymys nera nuo 1 iki 10, jis pasalinamas is vektoriaus
		{
			cout << "Vertinimas turi buti desimtbaleje sistemoje " << endl;
			A.pop_back();
		} else if (A[n] == 0) //jei 0, paskutinis vektoriaus elementas pasalinamas
		{
			t = false;
			A.pop_back();
			cout << "Pazymiu ivedimas baigtas" << endl;
		} else {
			galBalas += A[n];
			n++;
		}
	}while (t);
	cout << "Mokinio egzamino ivertinimas: ";
	cin >> e;
	
	cout << "Pasirinkite, kaip bus apskaiciuojamas namu darbo balas. 0 - vidurkis, 1 - mediana" << endl;
	int ivestis = -1;
	do{
		cin >> ivestis;
		if (ivestis == 0) //vidurkis
		{
			cout << "Pasirinkta: vidurkis" << endl;
			//galutinio balo skaiciavimas
			galBalas = (galBalas/n*0.4)+0.6*e;
		} else if (ivestis == 1) //mediana
		{
			cout << "Pasirinkta: meidiana" << endl;
			//medianos skaiciavimas
			std::sort (A.begin(), A.end());
			if (n%2 == 0)
			{
				med = (double)(A[n/2-1] + A[n/2])/2;
			} else med = A[n/2];
	
			//galutinio balo skaiciavimas
			galBalas = med*0.4+0.6*e;
			
		} else{
			cout << "ivedete klaidingai" << endl;
			ivestis = -1;
		}
	}while (ivestis == -1);
	
	//isvesties pradzia
	cout << "Mokinio duomenys" << endl;
	cout << "Mokinio vardas: " << vardas << endl;
	cout << "Mokinio pavarde: " << pavarde << endl;
	for (int i = 0; i < n; i++) //isveda visus pazymius
	{
		cout << i+1 << "-asis pazymys " << A[i] << endl;
	}
	cout << "Mokinio egzamino ivertinimas: " << e << endl;
	cout << std::fixed;
	cout << "Mokinio Galutinis ivertinimas: " << std::setprecision(2) << galBalas << endl;
	cout << "Programos pabaiga." << endl;	
}
//----------------------------------------------------------------------------------------
void Failas()
{
	vector<Mokiniai> Mok;
	Nuskaitymas(&Mok);
	//vidurkis
	for (int i = 0; i < Mok.size(); i++)
	{
		Mok[i].galBalVid = Vidurkis(&Mok[i].Pazymiai);
	}
	//isrikiuoja pazymius
	for (int i = 0; i < Mok.size(); i++)
	{
		std::sort (Mok[i].Pazymiai.begin(), Mok[i].Pazymiai.end()-1);
	}
	//mediana
	int a = 0; int b = 0;
	for (int i = 0; i < Mok.size(); i++)
	{
		if ((Mok[i].Pazymiai.size()-1) % 2 == 0)
		{
			Mok[i].galBalMed = (double)(Mok[i].Pazymiai[Mok[i].Pazymiai.size()/2-1] + Mok[i].Pazymiai[Mok[i].Pazymiai.size()/2])/2;
		} else Mok[i].galBalMed = Mok[i].Pazymiai[(Mok[i].Pazymiai.size()-1)/2];
		Mok[i].galBalMed = (Mok[i].galBalMed*0.4)+(Mok[i].Pazymiai[Mok[i].Pazymiai.size()-1]*0.6);
		if (Mok[i].pavarde.size() > a) //randa ilgiausia pavarde
		{
			a = Mok[i].pavarde.size();
		}
		if (Mok[i].vardas.size() > b) //randa ilgiausia varda
		{
			b = Mok[i].vardas.size();
		}
		
	}
	//Mediana
	/*for (int i = 0; i < Mok.size(); i++)
	{
		cout << &Mok[i].Pazymiai << endl;
		Mok[i].galBalMed = Mediana(Mok[i].Pazymiai);
	}*/
	//rikiavimas pagal pavardes
	Mokiniai in = {}; //dar karta naujojama papildoma struktura
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
	
	//i?vestis
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
	cout << "Programos Pabaiga";
}
//----------------------------------------------------------------------------------------	
void Nuskaitymas(vector<Mokiniai> *Mok)
{
	std::ifstream inf("Failas.txt"); //nuskaitymo pradzia
	Mokiniai in;
	for (int i = 0; !inf.eof(); i)
	{
		string input; //ivesties string'as
		inf >> input; //ivestis
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
	if (Pazymiai.size() % 2 == 0)
	{
	//	return ((double(Pazymiai[(Pazymiai.size()-1)/2]) + double(Pazymiai[(Pazymiai.size()-1)/2+1]))/2)*0.4+Pazymiai[Pazymiai.size()-1]*0.6;
	} else {
	//	return (double(Pazymiai[(Pazymiai.size()-1)/2])/2)*0.4+Pazymiai[Pazymiai.size()-1]*0.6;
	}
	return 0;
	
}
