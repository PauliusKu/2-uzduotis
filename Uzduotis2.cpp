/*!
 *  \brief     Mokinio pazymiu skaiciavimas
 *  \details   Ivedami mokinio pazymiai ir egzamino ivertinimas (random generavimas, ivestis per konsole ir ivestis is failo) ir apskaiciuojamas galutinis ivertinimas (pazymiu vidurkis, mediana).
 *  \author    Paulius
 *  \version   1.0
 *  \date      2018-02-26
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

void Random();
void Konsole();
void Failas();

int main()
{
	
	cout << "Pasirinkite ivesties tipa: 0 - random generavimas, 1 - ivestis per konsole, 2 - ivestis is failo" << endl;
	int ivestis = -1;
	do //pagrindinisas ciklas kuriame pasirenkamas ivesties tipas
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
	std::ifstream inf("Failas.txt"); //nuskaitymo pradzia
	vector<string> Pavarde {}; //mokiniu pavardziu vektorius
	vector<string> Vardas {}; //mokiniu vardu vektorius
	vector<double> Vid {}; //galutinis balas (vidurkis)
	vector<double> Med {}; //galutinis balas (pazymiai)
	vector<int> Pazymiai {}; //mokiniu pazymiai
	for (int i = 0; !inf.eof(); i++)
	{
		string input; //ivesties string'as
		inf >> input; //ivestis
		if ((input == "1") || (input == "2") || (input == "3") || (input == "4") || (input == "5") || (input == "6") || (input == "7") || (input == "8") || (input == "9") || (input == "10"))
		{
			i--;			
			Pazymiai.push_back(std::stoi (input)); //iraso i vektoriu pazymius
		} else {
			Pavarde.push_back(input); //iveda i vektoriu pavardes
			inf >> input;
			Vardas.push_back(input); //iveda i vektoriu vardus
		}
		
	}
	inf.close(); //nuskaitymo pabaiga
	
	//vidurkis
	double vid = 0;
	for (int i = 0; i < Pazymiai.size(); i++) //apskaiciuoja kiekvieno mokinio vidurki ir galutini ivertinima
	{
		vid += Pazymiai[i];
		if (i % (Pazymiai.size()/Vardas.size()) == Pazymiai.size()/Vardas.size()-2)
		{
			i++;
			Vid.push_back(double(vid/(Pazymiai.size()/Vardas.size()-1)*0.4)+0.6*Pazymiai[i]);
			vid = 0;
		}
	}
	
	//isrikiuoja mokiniiu pazymius
	for (int i = 0; i < Pazymiai.size(); i+=Pazymiai.size()/Vardas.size())
	{
		std::sort (Pazymiai.begin()+i, Pazymiai.begin()+6+i);
	}
	
	//mediana ir randa ilgiausia varda ir pavarde
	int a = 0; int b = 0;
	for (int i = 0; i < Vardas.size(); i++)
	{
		if ((Pazymiai.size()/Vardas.size()-1)%2 == 0) //apskaiciuoja kiekvieno mokinio pazymiu mediana ir galutini ivertinima
			{
				Med.push_back((double(Pazymiai[(Pazymiai.size()/Vardas.size()-1)/2-1+i*(Pazymiai.size()/Vardas.size())] + Pazymiai[(Pazymiai.size()/Vardas.size()-1)/2+i*(Pazymiai.size()/Vardas.size())]) / 2*0.4)+0.6*Pazymiai[((i+1)*Pazymiai.size()/Vardas.size())-1]); 
			} else Med.push_back((double(Pazymiai[(Pazymiai.size()/Vardas.size()-1)/2+i*(Pazymiai.size()/Vardas.size())]) *0.4)+0.6*Pazymiai[((i+1)*Pazymiai.size()/Vardas.size())-1]);
		if (Pavarde[i].size() > a) //randa ilgiausia pavarde
		{
			a = Pavarde[i].size();
		}
		if (Vardas[i].size() > b) //randa ilgiausia varda
		{
			b = Vardas[i].size();
		}
	}
	
	//rikiavimas pagal pavardes
	int best{};
	for (int i = 0; i < Pavarde.size(); i++)
	{
		string pavarde; //papildomi kintamieji sukeitimui
		string vardas;
		double vid;
		double med;
		best = i;
		for (int j = i; j < Pavarde.size(); j++)
		{
			if (Pavarde[j] < Pavarde[best])
			{
				best = j;
			}
		}
		//sukeitimas
		pavarde = Pavarde[i];
		vardas = Vardas[i];
		vid = Vid[i];
		med = Med[i];
		Pavarde[i] = Pavarde[best];
		Vardas[i] = Vardas[best];
		Vid[i] = Vid[best];
		Med[i] = Med[best];
		Pavarde[best] = pavarde;
		Vardas[best] = vardas;
		Vid[best] = vid;
		Med[best] = med;
	}
	//isvedimas
	cout << std::setw(a+1) << std::left << "Pavarde";
	cout << std::setw(b+1) << std::left << "Vardas";
	cout << std::fixed;
	cout << std::setw(3) << std::left << "Vid   Med" << endl;
	for (int i = 0; i < a+b+12; i++)
	{
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < Vardas.size(); i++)
	{
		cout << std::setw(a+1) << std::left << Pavarde[i];
		cout << std::setw(b+1) << std::left << Vardas[i];
		cout << std::fixed;
		cout << std::setw(3) << std::left << std::setprecision(2) << Vid[i] << "  " << Med[i] << endl;
	}
	for (int i = 0; i < a+b+12; i++)
	{
		cout << "-";
	}
	cout << endl;
	cout << "Programos Pabaiga" << endl;
}
