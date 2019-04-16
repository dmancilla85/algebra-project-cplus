/* (C) Copyright 2010. David A. Mancilla
	Todos los derechos reservados.

	Clase: Complejo
	Descripción: Representa los números complejos ( z = [a; b i] con a,b € R ). */

#pragma once

#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>
using std::ostream;

#include <string>
using std::string;

class Complejo
{	
public:
	Complejo(void);
	Complejo(const double);
	Complejo(const double, const double);
	Complejo(const Complejo&);
	~Complejo(void);
	
	double obtenerX() { return x; }
	double obtenerY() { return y; }

	void establecerX(double x) { this->x = x; } 
	void establecerY(double y) { this->y = y; }

	Complejo& operator =(const double);
	Complejo& operator =(const Complejo&);
	Complejo& operator += (const Complejo&);
	Complejo operator +(const double);
	Complejo operator +(const Complejo&);
	Complejo operator -(const double);
	Complejo operator -(const Complejo&);
	Complejo operator *(const double);
	double operator *(const Complejo&);
	Complejo operator /(const double);
	
	//Complejo operator /(const Complejo&); existe?desarrollar!
	Complejo conjugado();
	string toString();
	string modoPolar();
	string modoExponencial();
	
	friend ostream& operator <<(ostream&, const Complejo&);
	// ostream& modoPolar(); desarrollar! 
	// ostream& modoExponencial(); desarrollar!

protected:
	double x; // Miembro real

private:
	double y; // Miembro imaginario (i)
};

#endif

