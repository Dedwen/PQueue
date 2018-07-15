#pragma once

#include <iostream>
#include "Element.h"
using namespace std;
#ifndef PQUEUEVAR2_PQUEUE_H
#define PQUEUEVAR2_PQUEUE_H

class PQueue {

private:
	Element Q[100];
	int Nr = 0, N;

public:
	PQueue(); // Construnctor fara parametrii care initializeaza nr de elemente
	PQueue(int ); // Constructor cu parametru care initializeaza nr de elemente
	void Add(int , int ); // Adaugarea unui element in coada dupa valoare si prioritate
	void Dell(); // Stergerea unui element din coada
	void Dell(int e); // Stergerea unui element anume din coada
	int NrElem(); // Returnarea nr de elemente din coada
	void Display(); // Afisarea elementelor din coada
	~PQueue(); // Destructorul
	PQueue& operator=(const PQueue& ); // Operatorul '=' pentru atribuirea elementelor dintr-o coada in alta
	friend const PQueue operator+(PQueue& ,PQueue& ); // Operatorul '+' pentru concatenarea a doua cozi
	PQueue& operator++(); // Operatorul "++" pentru cresterea prioritatii cu 1 unitate
	PQueue& operator--(); // Operatorul "--" pentru scaderea prioritatii cu 1 unitate, daca prioritatea este 0 se elimina 
	int ElemMax(); // Returneaza elementul cu valoarea maxima
	int PrioMax(); // Returneaza elementul cu prioritatea maxima
	friend ostream& operator<<(ostream& , const PQueue& ); // Supraincarcarea operatorului afisare pt coada
	friend istream& operator>>(istream& , PQueue& ); // Supraincarcarea operatorului de citire pt coada

};

#endif //PQUEUEVAR2_PQUEUE_H
