/*!
 *  \brief     Mokinio pazymiu skaiciavimas
 *  \details   Ivedami mokinio pazymiai ir egzamino ivertinimas (random generavimas, ivestis per konsole ir ivestis is failo) ir apskaiciuojamas galutinis ivertinimas (pazymiu vidurkis, mediana).
 *  \author    Paulius
 *  \version   0.3
 *  \date      2018-03-01
 */
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
			Random();
			ivestis = "";
		}else if (ivestis == "1") //ivesdimas per konsole
		{
			Konsole();
			ivestis = "";
		}else if (ivestis == "2") //ivedimas is failo
		{
			Failas();
			ivestis = "";
		}else if (ivestis == "3") //
		{
			unsigned int n{};
			cout << "Iveskte, kokio ilgio?" << endl;
			cin >> n;
			GeneruotiFaila(n);
			ivestis = "";
		}else if (ivestis == "4") //
		{
			for (unsigned int i = 10; i <= 1000000; i *= 10)
			{
				cout << "Dydis: " << i << endl;
				GeneruotiFaila(i);
				cout << endl;
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
