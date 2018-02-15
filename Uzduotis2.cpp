#include <iostream>
#include <iomanip>  
#include <vector>
#include <algorithm>
#include <random>

int main()
{
	//kintamuju deklaracijos
	std::string vardas;
	std::string pavarde;
	int n = 0;
	int e = 0;
	double med{};
	double galBalas = 0.00;
	std::vector<int> A;
	
	//ivesties pradzia
	std::cout << "Mokinio vardas: ";
	std::cin >> vardas;
	std::cout << "Mokinio pavarde: ";
	std::cin >> pavarde;
	std::cout << "Pasirinkite ivesties tipa: 0 - random generavimas, 1 - ivestis per konsole, 2 - ivestis is failo" << std::endl;
	int ivestis = -1;
	do
	{
		std::cin >> ivestis;
		if (ivestis == 0)
		{
			std::cout << "Pasirinkote: random generavimas. Iveskite, kiek pazymiu norite sugeneruoti" << std::endl;
			std::random_device rd;
			std::mt19937 mt(rd());
			std::uniform_int_distribution<int> dist(1,10);
			std::cin >> n;
			for (int i = 0; i < n; i++)
			{
				A.push_back(dist(mt));
			}
			std::cout << "Iveskite mokinio egzamino ivertinima: ";
			std::cin >> e;
		}else if (ivestis == 1)
		{
			std::cout << "Pasirinkote: ivestis per konsole. Norëdami pabaigti pazymiu ivedima, iveskite 0" << std::endl;
			int a = 0;

			bool t = true;
			do{
				std::cout << n+1 << "-asis pazymys ";
				std::cin >> a;
				A.push_back(a);
				if (A[n] > 10 || A[n] < 0)
				{
					std::cout << "Vertinimas turi buti desimtbaleje sistemoje " << std::endl;
					A.pop_back();
				} else if (A[n] == 0)
				{
					t = false;
					A.pop_back();
					std::cout << "Pazymiu ivedimas baigtas" << std::endl;
				} else {
					galBalas += A[n];
					n++;
					std::cout << galBalas << std::endl;
				}
			}while (t);
			std::cout << "Mokinio egzamino ivertinimas: ";
			std::cin >> e;
		}else if (ivestis == 2)
		{
			std::cout << "Pasirinkote: ivestis is failo" << std::endl;
		} else {
			std::cout << "ivedete klaidingai" << std::endl;
			ivestis = -1;
		}
	} while (ivestis == -1);
	
	std::cout << "Pasirinkite, kaip bus apskaiciuojamas namu darbo balas. 0 - vidurkis, 1 - mediana" << std::endl;
	ivestis = -1;
	do{
		std::cin >> ivestis;
		if (ivestis == 0)
		{
			std::cout << "Pasirinkta: vidurkis" << std::endl;
			//galutinio balo skaiciavimas
			galBalas = (galBalas/n*0.4)+0.6*e;
		} else if (ivestis == 1)
		{
			std::cout << "Pasirinkta: meidiana" << std::endl;
			//medianos skaiciavimas
			std::sort (A.begin(), A.end());
			if (n%2 == 0)
			{
				med = (double)(A[n/2-1] + A[n/2])/2;
			} else med = A[n/2];
	
			//galutinio balo skaiciavimas
			galBalas = med*0.4+0.6*e;
			
		} else{
			std::cout << "ivedete klaidingai" << std::endl;
			ivestis = -1;
		}
	}while (ivestis == -1);
	
	//isvesties pradzia
	std::cout << "Mokinio duomenys:" << std::endl;
	std::cout << "Mokinio vardas: " << vardas << std::endl;
	std::cout << "Mokinio pavarde: " << pavarde << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << i+1 << "-asis pazymys " << A[i] << std::endl;
	}
	
	std::cout << "Mokinio egzamino ivertinimas: " << e << std::endl;
	std::cout << std::fixed;
	std::cout << "Mokinio Galutinis ivertinimas: " << std::setprecision(2) << galBalas << std::endl;
	std::cout << "Programos pabaiga." << std::endl;
	return 0;
}
