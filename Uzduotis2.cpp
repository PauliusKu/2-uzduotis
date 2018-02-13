#include <iostream>
#include <string>
#include <iomanip>  

int main()
{
	std::string vardas;
	std::string pavarde;
	int n = 0;
	int e = 0;
	double galBalas = 0.00;
	int* A = new int[n];
	
	std::cout << "Mokinio vardas: ";
	std::cin >> vardas;
	std::cout << "Mokinio pavarde: ";
	std::cin >> pavarde;
	
	std::cout << "Norëdami pabaigti iveskite 0" << std::endl;
	do{
		std::cout << n+1 << "-asis pazymys ";
		std::cin >> A[n];
		std::cout << A[n] << std::endl;
		n++;
		galBalas += A[n];
	}while (A[n-1] != 0);
	
	std::cout << "Mokinio egzamino ivertinimas: ";
	std::cin >> e;
	
	galBalas = (galBalas / n*0.4)+0.6*e;
	
	std::cout << "Mokinio vardas: " << vardas << std::endl;
	std::cout << "Mokinio pavarde: " << pavarde << std::endl;
	for (int i = 0; i < n-1; i++)
	{
		std::cout << i+1 << "-asis pazymys " << A[i] << std::endl;
	}
	
	std::cout << "Mokinio egzamino ivertinimas: " << e << std::endl;
	std::cout << std::fixed;
	std::cout << "Mokinio Galutinis ivertinimas: " << std::setprecision(2) << galBalas << std::endl;
	
	return 0;
}
