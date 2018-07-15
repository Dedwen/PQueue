#include <iostream>
#include "Element.h"
using namespace std;


// Constructor fara parametru
Element::Element() {
	//cout << " Mesaj constructor Element." << endl;
}


// Constructor cu parametrii de initializare a valorii si prioritatii
Element::Element(int vl, int pri) {
	val = vl;
	prio = pri;
	//cout << " Mesaj constructor Element cu parametrii." << endl;
}


// Returneaza valoarea elementului
int Element::ReturnValoare() {

	return val;
}


// Returneaza prioritatea elementului
int Element::ReturnPrioritate() {

	return prio;
}


// Creste prioritatea cu 1 a elementului
int Element::PrioritatePlus() {
	prio++;

	return prio;
}


// Scade prioritatea cu 1 a elementului
int Element::PrioritateMinus() {
	prio--;

	return prio;
}


// Operatorul '=' pentru atribuirea unui Element in alt Element
Element& Element::operator=(const Element& otherObj) {
	val = otherObj.val;
	prio = otherObj.prio;

	return *this;
}


// Citirea unui Element
istream& operator >> (istream& in, Element& anotherObj) {
	cout << "Dati valoarea: ";
	in >> anotherObj.val;
	cout << "Dati prioritatea: ";
	in >> anotherObj.prio;

	return in;
}


// Afisarea unui Element
ostream& operator << (ostream& out, const Element& anotherObj) {
	out << anotherObj.val << " ";
	out << anotherObj.prio << endl;

	return out;
}


// Destructorul
Element::~Element() {
	// cout << " Mesaj destructor Element." << endl;
}


