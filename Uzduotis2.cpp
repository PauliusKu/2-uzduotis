/*!
 *  \brief     Mokinio pazymiu skaiciavimas
 *  \details   Ivedami mokinio pazymiai ir egzamino ivertinimas (random generavimas, ivestis per konsole ir ivestis is failo) ir apskaiciuojamas galutinis ivertinimas (pazymiu vidurkis, mediana).
 *  \author    Paulius
 *  \version   0.3
 *  \date      2018-03-01
 */
 #include <chrono>
#include <iostream>
#include <iomanip>  
#include <vector>
#include <algorithm>
#include <fstream>
#include "Headeris.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

int main()
{
	string ivestis {};
	do //pagrindinisas ciklas kuriame pasirenkamas ivesties tipas
	{
		cout << "Funkcijos: 0 - random generavimas, 1 - ivestis per konsole, 2 - ivestis is failo, 3 - generuoti faila, 4 - testas, 5 iseiti." << endl;
		cin >> ivestis;
		if (ivestis == "0") //random generavimas
		{
			Random<std::list<Mokiniai>>();
			ivestis = "";
		}else if (ivestis == "1") //ivesdimas per konsole
		{
			Konsole();
			ivestis = "";
		}else if (ivestis == "2") //ivedimas is failo
		{
			Failas<std::list<Mokiniai>>();
			ivestis = "";
		}else if (ivestis == "3") //
		{ 
			unsigned int n{};
			cout << "Iveskte, kokio ilgio?" << endl;
			cin >> n;
			GeneruotiFaila(n);
			ivestis = "";
		}else if (ivestis == "4") //ghnh
		{
			cout << "Iveskite dydi x.(10^x): " << endl;
			unsigned int size{};
			cin >> size;
			cout << "-----------------------------------------------------------------------------------" << endl;			
			for (unsigned int i = 2; i <= size; i++)
			{
				GeneruotiFaila(pow(10, i));
				auto start = std::chrono::high_resolution_clock::now();
				Failas<std::vector<Mokiniai>>();
				auto end = std::chrono::high_resolution_clock::now();
				cout << "Vector Dydis: "<< std::setw(8)<< (int)pow(10, i) << "  |  "<< std::chrono::duration<double>(end-start).count() << " sekundes" << endl;
				auto start1 = std::chrono::high_resolution_clock::now();
				Failas<std::deque<Mokiniai>>();
				auto end1 = std::chrono::high_resolution_clock::now();
				cout << "Deque  Dydis: "<< std::setw(8)<< (int)pow(10, i) << "  |  "<< std::chrono::duration<double>(end1-start1).count() << " sekundes" << endl;
				auto start2 = std::chrono::high_resolution_clock::now();
				Failas<std::list<Mokiniai>>();
				auto end2 = std::chrono::high_resolution_clock::now();
				cout << "List   Dydis: "<< std::setw(8)<< (int)pow(10, i) << "  |  "<< std::chrono::duration<double>(end2-start2).count() << " sekundes" << endl;
				cout << "-----------------------------------------------------------------------------------" << endl;
			}
			ivestis = "";
		}else if (ivestis == "5") //
		{
			cout << "Programos pabaiga." << endl;
		} else {
			cout << "ivedete klaidingai" << endl;
			ivestis = "";
		}
	} while (ivestis == "");
	return 0;
}
