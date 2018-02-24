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


struct Sarasas{
	char vardas[255]{};
	char pavarde[255]{};
	vector<int> Ivert {};
	double med{};
	double vid{};
};

void Random();
void Konsole();
void Failas();
double Vid(vector<int> &V, int = 0);

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
	double galBalas = 0.00;
	vector<Sarasas> S {1};
	Sarasas T;
	char line[255];
	char c {};
	char cc {};
	vector <char> V;
	vector <int> I;
	std::ifstream inf("Failas.txt");
	while (true)
	{
		if (inf.eof())
		{
			if (I[I.size()-1] > 10)
			{
				I[I.size()-1] = 10;
			} else I.pop_back();
			break;
		} else {
			inf >> c;
			if ((int)c > 47 && (int)c < 58)
			{
				if ((int)c == 48)
				{
					I[I.size()-1] += 9;
				} else
				{
					I.push_back((int)c-48);
				}
				//cout << I[I.size()-1] << endl;
			} else
			{
				if ((int)cc > 47 && (int)cc < 58)
				{
					I.push_back(0);
				}
				if ((int)c > 64 && (int)c < 91)
				{
					V.push_back('0');
				}
				V.push_back(c);
				//cout << V[V.size()-1];
			}
			cc = c;
		}
	}
	V.push_back('0');
	I.push_back(0);
	inf.close();
	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i];
	}
	cout << endl;
	for (int i = 0; i < I.size(); i++)
	{
		cout << I[i] << " ";
	}
	//isvedimas
	/*int i = 1;
	while(true)
	{
		if (V[i] != '0')
		{
			cout << V[i];
		} else {
			break;
		}
		i++;
	}
	i++;
	cout << " ";
	while(true)
	{
		if (V[i] != '0')
		{
			cout << V[i];
		} else {
			break;
		}
		i++;
	}
	i++;
	cout << " ";
	int j = 0;
	int vid = 0;
	int n = 0;
	while(true)
	{
		if (I[j] != 0)
		{
			n++;
			vid += I[j];
		} else {
			break;
		}
		j++;
	}
	n--;
	vid -= I[j-1];
	galBalas = (double)vid/n*0.4+0.6*I[j-1];
	cout << std::fixed;
	cout << "Mokinio Galutinis ivertinimas: " << std::setprecision(2) << galBalas << endl;*/
	int j = 1;
	int l = 0;
	for(int i = 0; i < S.size(); i++) // tike kiek yra zmoniu
	{	
		if (V[j])
		{
			int j1 = 0;
			while(V[j]!='0') //pavarde
			{
				S[i].pavarde[j1] = V[j];
				j++; j1++;
			}
			int j2 = 0;
			j++;
			while(V[j]!='0') //vardas
			{
				S[i].vardas[j2] = V[j];
				j++; j2++;
			}
			j++;
			S.push_back(T);
			while (I[l] != 0)
			{
				S[i].Ivert.push_back(I[l]);
				l++;
			}
			l++;
			S[i].vid = Vid(S[i].Ivert, -1);
			cout << "vid " << (double)S[i].vid << endl;
		} else S.pop_back();
		
	}
	cout << endl;
	for (int i = 0; i < S.size(); i++)
	{
		cout << S[i].pavarde << endl << S[i].vardas << endl;
		for (int j = 0; j < S[i].Ivert.size(); j++)
		{
			cout << S[i].Ivert[j] << endl;
		}
	}
	
}
double Vid(vector<int> &V, int k)
{
	int sum = 0;
	for (int i = 0; i < V.size(); i++)
	{
		cout << "sum " << sum << endl;
		sum += V[i];
	}
	return (double)sum / V.size();
}
