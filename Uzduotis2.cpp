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


void Random();
void Konsole();
void Failas();

int main()
{
	
	cout << "Pasirinkite ivesties tipa: 0 - random generavimas, 1 - ivestis per konsole, 2 - ivestis is failo" << endl;
	int ivestis = -1;
	do //pagrindinis ciklas kuriame pasirenkamas ivesties tipas
	{
		cin >> ivestis;
		if (ivestis == 0) //random generavimas
		{
			Random();
		}else if (ivestis == 1) //ivesdimas per konsole
		{
			Konsole();
		}else if (ivestis == 2) //ivedimas is failo
		{
			Failas();
		} else {
			cout << "ivedete klaidingai" << endl;
			ivestis = -1;
		}
	} while (ivestis == -1);
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
	
	cout << "Pasirinkote: ivestis per konsole. Norëdami pabaigti pazymiu ivedima, iveskite 0" << endl;
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
	std::ifstream inf("Failas.txt");
	vector<string> Pavarde {};
	vector<string> Vardas {};
	vector<double> Vid {};
	vector<double> Med {};
	vector<int> Pazymiai {};
	for (int i = 0; !inf.eof(); i++)
	{
		string input;
		inf >> input;
		cout << input << endl;
		if ((input == "1") || (input == "2") || (input == "3") || (input == "4") || (input == "5") || (input == "6") || (input == "7") || (input == "8") || (input == "9") || (input == "10"))
		{
			i--;			
			Pazymiai.push_back(std::stoi (input));
		} else {
			Pavarde.push_back(input);
			inf >> input;
			cout << input << endl;
			Vardas.push_back(input);
		}
		
	}
	
	//vidurkis
	double vid = 0;
	cout << Pazymiai.size()/Vardas.size() << endl;
	for (int i = 0; i < Pazymiai.size(); i++)
	{
		vid += Pazymiai[i];
		if (i % (Pazymiai.size()/Vardas.size()) == 5)
		{
			i++;
			Vid.push_back((vid/(Pazymiai.size()/Vardas.size()-1)*0.4)+0.6*Pazymiai[i]);
			cout << Vid[Vid.size()-1] << endl;
			vid = 0;
		}
	}
	
	for (int i = 0; i < Pazymiai.size(); i+=Pazymiai.size()/Vardas.size())
	{
		std::sort (Pazymiai.begin()+i, Pazymiai.begin()+6+i);
	}
	for (int i = 0; i < Pazymiai.size(); i++)
	{
		cout << Pazymiai[i] << " ";
	}
	cout << endl;
	
	//mediana
	for (int i = 0; i < Vardas.size(); i++)
	{
		cout << i << endl;
		if ((Pazymiai.size()/Vardas.size()-1)%2 == 0)
			{
				Med.push_back((double(Pazymiai[(Pazymiai.size()/Vardas.size()-1)/2-1+i*(Pazymiai.size()/Vardas.size())] + Pazymiai[(Pazymiai.size()/Vardas.size()-1)/2+i*(Pazymiai.size()/Vardas.size())]) / 2*0.4)+0.6*Pazymiai[((i+1)*Pazymiai.size()/Vardas.size())-1]); 
			} else Med.push_back((double(Pazymiai[(Pazymiai.size()/Vardas.size()-1)/2+i*(Pazymiai.size()/Vardas.size())]) *0.4)+0.6*Pazymiai[((i+1)*Pazymiai.size()/Vardas.size())-1]);
		cout << "MEd " << Med[i] << endl;
	}
	inf.close();
	//rikiavimas pagal pavardes
}
