
#include <iostream>

using namespace std;

class Ksztalt //Abstrakcyjna Klasa Podstawowa 
{
public:
	virtual void rysuj() { // funkcja wirtualna
		cout << "Rysuje ksztalt" << endl;
	}

	void pole() {
		cout << "Licze pole ksztaltu" << endl;
	}
};

class Kolo :public Ksztalt // Klasa dziedzicząca z klasy Ksztalt
{
public:
	 virtual void rysuj() { // Metoda klasy pochodnej zastępuje klasę bazową
		cout << "Rysuje Kolo" << endl;
	}

	void pole() {
		cout << "Licze pole Kola" << endl;
	}

};


int main()
{
	// Wiązanie Statyczne 
	Ksztalt n; // Utworzenie nowego obiektu
	Kolo m;
	n.rysuj();// Przy bezpośrednim odwołaniu się do konkretnej metody obiektu danej klasy 
	m.rysuj();

	// Wiązanie Dynamiczne - wskaźnik można przestawiać na obiekt dowolnej klasy pochodnej
	Ksztalt* wskaznik = &m; // Zmienna wskaznik, która przechowuje adres obiektu klasy Kolo, wskazuje na klasę Ksztalt

	wskaznik->rysuj(); // Dzięki użyciu virtual możemy dostać się do metody klasy dziedziczącej z klasy Ksztalt
	wskaznik->pole();
}