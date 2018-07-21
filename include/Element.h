#pragma once

#include <iostream>
using namespace std;
#ifndef PQUEUEVAR2_ELEMENT_H
#define PQUEUEVAR2_ELEMENT_H

class Element {

private:
	int val;
	int prio;

public:
	Element(); // constructorul
	Element(int, int); // constructorul are initializeaza Elementul cu valoare si prioritate
	int PrioritatePlus(); // creste prioritatea cu 1
	int PrioritateMinus(); // scade prioritatea cu 1
	int ReturnValoare(); // returneaza valoarea elementului
	int ReturnPrioritate(); // returneaza prioritatea elementului
	Element& operator=(const Element&); // operatorul de egalitate 
	friend ostream& operator<<(ostream&, const Element&); // operatorul de afisare
	friend istream& operator>>(istream&, Element&); // operatorul de citire
	~Element(); // destructorul

};

#endif //PQUEUEVAR2_ELEMENT_H



