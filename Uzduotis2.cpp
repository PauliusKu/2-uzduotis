#include <iostream>
#include <iomanip>  
#include <vector>
#include <algorithm>

int main()
{
	std::string vardas;
	std::string pavarde;
	int n = 0;
	int e = 0;
	double med{};
	double galBalas = 0.00;
	//int* A = new int[n];
	std::vector<int> A;
	
	std::cout << "Mokinio vardas: ";
	std::cin >> vardas;
	std::cout << "Mokinio pavarde: ";
	std::cin >> pavarde;
	
	std::cout << "Norëdami pabaigti pazymiu ivedima, iveskite 0" << std::endl;
	bool t = true;
	int a = 0;
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
	
	std::sort (A.begin(), A.end());
	if (n%2 == 0)
	{
		med = (double)(A[n/2-1] + A[n/2])/2;
	} else med = A[n/2];
	
	galBalas = med*0.4+0.6*e;
	
	std::cout << "Mokinio vardas: " << vardas << std::endl;
	std::cout << "Mokinio pavarde: " << pavarde << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << i+1 << "-asis pazymys " << A[i] << std::endl;
	}
	
	std::cout << "Mokinio egzamino ivertinimas: " << e << std::endl;
	std::cout << std::fixed;
	std::cout << "Mokinio Galutinis ivertinimas: " << std::setprecision(2) << galBalas << std::endl;
	
	return 0;
}
