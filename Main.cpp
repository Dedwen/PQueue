#include <iostream>
#include "PQueue.h"
using namespace std;

int main() {

	cout << "Prima coada: " << endl;
	PQueue obj1 = 4; // 4 reprezinta numarul de Elemente alocate dinamic
	obj1.Add(1, 1); // Adaugarea unui
	obj1.Add(2, 2); //                nou element
	obj1.Add(3, 3); //                            in coada
	obj1.Display(); // Afisarea elementelor curente din coada
	//obj1.Dell(); // Eliminarea unui element dintr-o coada
	--obj1; // Scade prioritatea cu 1, cele cu prioritatea 0 sunt eliminate din coda
	obj1.Display();
	cout << " Nr. elemente = " << obj1.NrElem() << endl;
	cout << endl;

	cout << "A doua coada : " << endl;
	PQueue obj2 = 4;
	obj2.Add(4, 4);
	obj2.Add(5, 5);
	obj2.Add(6, 6);
	obj2.Display();
	obj2.Dell();
	obj2.Display();
	cout << " Nr. elemente = " << obj2.NrElem() << endl;
	cout << endl;

	cout << "Coada dupa fuziune celorlalte doua: " << endl;
	PQueue obj3 = 8;
	obj3 = obj1 + obj2; // Fuziunea a doua cozi prin supraincarcarea operatorului +
	obj3.Display();

	++obj3; // Cresterea prioritatii cu 1 folosind supraincarcarea operatorului ++
	--obj3; // Scaderea prioritatii cu 1 folosind supraincarcarea operatorului -

	cout << " Elementul maxim este = " << obj3.ElemMax() << endl;
	cout << " Valoarea elementului cu prioritatea maxima = " << obj3.PrioMax() << endl;
	cout << endl;


	// Mai jos avem citirea si afisarea unui vector de obiecte realizat prin supraincarcarea operatorilor << si >>
	// Le-am pus intre comentarii pentru a le rula separat dupa preferinte.
	PQueue newObj4;
	cin >> newObj4;
	cout << " Valoare | Prioritate: " << endl;
	cout << newObj4;


	system("pause");
	return 0;
}



