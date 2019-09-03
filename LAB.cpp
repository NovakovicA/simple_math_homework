#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;



struct Elem {
	string ime;
	Elem* sled;
	Elem(string iime,Elem* s=nullptr) {
		ime = iime;
		sled = s;
	}
};

class Sesir {
	int br;
	Elem* lista;

	void brisi() {
		Elem* stari = nullptr;
		for (Elem* tek = lista; tek != nullptr;) { stari = tek; tek = tek->sled; delete stari; }
	}

public:
	Sesir() {
		lista = nullptr;	
	}

	void dodaj(string ime) {
			br++;
			if (lista == nullptr) lista = new Elem(ime);
			else{
			Elem* tek;
			for (tek = lista; tek->sled != nullptr; tek = tek->sled);
			tek->sled = new Elem(ime);
			}
	}

	string uzmi() {
		if (br == 0) return "";
		int ran = rand() % br;
		Elem* tek;
		Elem* pret = nullptr;
		for (tek = lista; ran > 0; ran--) { pret = tek; tek = tek->sled; }
		if (tek == lista) {
			lista = tek->sled;
		}
		else{
		if (pret != nullptr) {
			pret->sled = tek->sled;
		}
		}
		br--;
		string ime = tek->ime;
		delete tek;
		return ime;
	}

	~Sesir() {
		brisi();
	}
};


int main() {
	srand(time(NULL));
	int n,brizv=0,bruk=0; 
	cout << "\n--Eksperiment izvlacenja nagrada--";
	cout << "\n        Aleksa Novakovic 0305/2017";
	cout << "\n\n\n-----------------------------\n";
	cout << "---Unesite broj ponavljanja:-\n";
	cout << "-----------------------------\n";
	cin >> n;
	bruk = n;
	while (n > 0)
	{
		Sesir s1;
		s1.dodaj("Danijela");
		s1.dodaj("Jovan");
		s1.dodaj("Bratislav");
		s1.dodaj("Marija");
		s1.dodaj("Srdjan");
		s1.dodaj("Tatjana");
		s1.dodaj("Milica");
		s1.dodaj("Branko");
		s1.dodaj("Mirko");
		s1.dodaj("Ivana");
		string n1 = s1.uzmi();
		string n2 = s1.uzmi();
		string n3 = s1.uzmi();
		cout << "-----------------------------\n";
		cout << "Izvlacenje br." << bruk - n + 1 << ":\n";
		cout << "Prva nagrada: " << n1 << "\n";
		cout << "Druga nagrada: " << n2 << "\n";
		cout << "Treca nagrada: " << n3 << "\n";
		if ((n1== "Jovan")  || (n2== "Jovan")|| (n3== "Jovan")) {
			brizv++;
		}
		n--;
	}
	float relfrek = (float)brizv / (float)bruk;
	cout << "-----------------------------\n";
	cout << "-----------------------------\n";
	cout << "---Relativna frekvencija: " << relfrek << ".\n";
	cin >> n;
}