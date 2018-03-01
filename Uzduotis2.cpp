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
