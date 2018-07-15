#include <iostream>
#include <cstring>
#include "PQueue.h"
using namespace std;


// Constructorul initializare fara parametru
PQueue::PQueue() {

	// cout << " Mesaj constructor PQueue." << endl;
	N = 5;
}


// Constructor initializare cu parametru
PQueue::PQueue(int n) {
	
	N = n;
}


// Adaugarea unui element in coada
void PQueue::Add(int v, int p) {
	
	Element NewObj(v, p);// apelare constructor cu 2 parametrii care initializeaza in clasa Element
	Nr++;
	Q[Nr] = NewObj;
}


// Stergerea unui element din coada
void PQueue::Dell() {
	
	for (int i = 1; i <= Nr; i++)
		Q[i - 1] = Q[i];
	Nr--;
}


// Stergerea unui element anume din coada
void PQueue::Dell(int e) {

	for (int i = e; i <= Nr ; i++)
		Q[i - 1] = Q[i];
	Nr--;
}



// Afisarea elementelor curente din coada
void PQueue::Display() {
	
	cout << " Elemente PQueue : " << endl;
	for (int i = 1; i <= Nr; i++)
		cout << "   " << Q[i].ReturnValoare() << "  ";
	cout << endl;
}


// Returneaza nr de elemente din coada
int PQueue::NrElem() {

	return Nr;
}


// Supraincarcarea operatorului '=' pt atribuirea tuturor elementelor dintr-o coada in alta 
PQueue& PQueue::operator=(const PQueue& otherObj) {
	
	if (this != &otherObj) {
		Nr = otherObj.Nr;
		for (int i = 1; i <= Nr; i++)
			Q[i] = otherObj.Q[i];
	}
	return (*this);
}


// Supraincarcarea operatorului '+' pentru concatenarea a doua cozi
const PQueue operator+(PQueue& otherObj1, PQueue& otherObj2) {
	
	PQueue newObj;
	int i = 1, j = 1, k = 0;
	while (i <= otherObj1.Nr && j <= otherObj2.Nr) {
		if (otherObj1.Q[i].ReturnPrioritate() < otherObj2.Q[i].ReturnPrioritate()) {
			k++;
			newObj.Q[k] = otherObj1.Q[i];
			i++;
		}
		else {
			k++;
			newObj.Q[k] = otherObj2.Q[j];
			j++;
		}
	}

	if (i <= otherObj1.Nr)
		for (int ii = i; ii <= otherObj1.Nr; ii++) {
			k++;
			newObj.Q[k] = otherObj1.Q[ii];
		}

	if (j <= otherObj2.Nr)
		for (int ii = j; ii <= otherObj2.Nr; ii++) {
			k++;
			newObj.Q[k] = otherObj2.Q[ii];
		}

	newObj.Nr = k;

	return newObj;
}


// Supraincarcarea operatorului "++" pentru cresterea prioritatii cu 1 unitate
PQueue& PQueue::operator++() {

	for (int i = 1; i <= Nr; i++)
		Q[i].PrioritatePlus();
	return *(this);
}


// Supraincarcarea operatorului "--" pentru scaderea prioritatii cu 1 unitate
PQueue& PQueue::operator--() {

	for (int i = 1; i <= Nr; i++) {
		Q[i].PrioritateMinus();
		if (Q[i].ReturnPrioritate() == 0)
			Dell(i);
	}
	return *(this);
}


// Returneaza elementul cu valoarea cea mai mare
int PQueue::ElemMax() {
	int maxI = 1;
	for (int i = 2; i <= Nr; i++)
		if (Q[maxI].ReturnValoare()<Q[i].ReturnValoare())
			maxI = i;

	return Q[maxI].ReturnValoare();
}


// Returneaza elementul cu prioritatea cea mai mare
int PQueue::PrioMax() {
	int maxI = 1;
	for (int i = 2; i <= Nr; i++)
		if (Q[maxI].ReturnPrioritate()<Q[i].ReturnPrioritate())
			maxI = i;
	return Q[maxI].ReturnValoare();
}


// supraincarcarea operatorului ">>"(de citire)
istream& operator >> (istream& in, PQueue& anotherObj) {
	for (int i = 1; i <= anotherObj.N; ++i)
		in >> anotherObj.Q[i];

	return in;
}


// supraincarcarea operatorului "<<"(de afisare)
ostream& operator << (ostream& out, const PQueue& anotherObj) {
	for (int i = 1; i <= anotherObj.N; ++i)
		out <<"        "<< anotherObj.Q[i];
	cout << endl;

	return out;
}


// Destructorul
PQueue::~PQueue() {
	//cout << " Mesaj destructor PQueue." << endl;
}



