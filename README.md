# 2-uzduotis
## Programos pagrindinės funkcijos:
  1. Sugeneruoti mokinio pažymius (max 10^6) ir atlikti galutinio balo skaičiavimą (ivestis per konsolę). Ivesesties struktūra:
  2. Įvesti mokinio duomenys ir atlikti galutinio balo skaičiavimą (ivestis per konsolę)    
  3. Įvesti mokinių doumenys iš 'txt' failo ir išvesti mokinių galutinių balų lentelę per konsolę
  4. Sugeneruoti norimo dydžio (1-10^7) mokinių 'txt' failą. Mokinio vardo ir pavardės ilgis bei pažymių kiekis: 3-21 simboliai.
  5. Naudojant 2 skirtingas strategijas testuoti vector deque ir list tipo konteinerius ir pateikti ataskaitą.
## Programos naudojimas
### Meniu pasirinkimai:
    1: random generavimas -> vardas -> pavardė -> kiek norite sugeneruoti -> egzamino įvertinimas ->...
    2: ivestis per konsole -> vardas -> pavardė -> mokinio įverinimai (1-10) -> 0 (pažymių įvesties pabaiga) -> egzamino įvertinimas ->...
    3: ivesti is failo ->...
    4: generuoti faila -> Iveskite, kokio dydzio faila norite sugeneruoti ->...
    5: testas -> Iveskite dydi x (10^x , Max 10^7) ->...
### Išvestis:
![alt text](https://github.com/PauliusKu/2-uzduotisVEC/blob/master/Pav/Isvestis.png)
## Veikimo spartos analizė
### I strategija (su algoritmais)

|Container                    |n = 100    |n = 1000     |n = 10000    |n = 100000   |n = 1000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Vector |0.0009756 s|0.008041 s|0.0741989 s |0.990607  s|10.7395  s|
|Deque |0.0010027 s| 0.0070441 s|0.072219 s |0.933481 s|11.1386 s|
|List |0        s| 0.00603    s|0.0561509 s |0.73796 s|8.16674 s|

### II strategija (su algoritmais)

|Container                    |n = 100    |n = 1000     |n = 10000    |n = 100000   |n = 1000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Vector |0.0009053 s|0.006041 s|0.0787989 s |0.89734857  s|10.0808  s|
|Deque |0.0010524 s| 0.0070259 s|0.071581 s |0.8670571 s|9.67171 s|
|List |0        s| 0.00603    s|0.0502584 s |0.604575 s|6.50328 s|
### Išvados:
Čia pateikti I ir II strategijos su algoritmais spartos rodikliai. Jeigu algoritmų nenaudojame, antrtosios strategijos sparta žymiai sumažėja. Visais atvejais (I, II strategijos, su algoritmais, be algoritmų) greičiausiai veikia programa su List konteineriu.
