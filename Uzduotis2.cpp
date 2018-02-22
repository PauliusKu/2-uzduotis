#include <iostream>
#include <iomanip>  
#include <vector>
#include <algorithm>
#include <random>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

int main()
{
	//kintamuju deklaracijos
	string vardas;
	string pavarde;
	int n = 0; //pazymiu skaicius
	int e = 0; //egzamino ivertinimas
	double med{}; //mediana
	double galBalas = 0.00; //galutinis ivertinimas
	vector<int> A; //pazymiu vektorius
	
	//ivesties pradzia
	cout << "Mokinio vardas: ";
	cin >> vardas;
	cout << "Mokinio pavarde: ";
	cin >> pavarde;
	cout << "Pasirinkite ivesties tipa: 0 - random generavimas, 1 - ivestis per konsole, 2 - ivestis is failo" << endl;
	int ivestis = -1;
	do //pagrindinis ciklas kuriame pasirenkamas ivesties tipas
	{
		std::cin >> ivestis;
		if (ivestis == 0) //random generavimas
		{
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
		}else if (ivestis == 1)
		{
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
					cout << galBalas << endl;
				}
			}while (t);
			cout << "Mokinio egzamino ivertinimas: ";
			cin >> e;
		}else if (ivestis == 2) //ivedimas is failo
		{
			cout << "Pasirinkote: ivestis is failo" << endl;
		} else {
			cout << "ivedete klaidingai" << endl;
			ivestis = -1;
		}
	} while (ivestis == -1);
	
	cout << "Pasirinkite, kaip bus apskaiciuojamas namu darbo balas. 0 - vidurkis, 1 - mediana" << endl;
	ivestis = -1;
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
	cout << "Mokinio duomenys:" << endl;
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
	return 0;
	//programos pabaiga

}
