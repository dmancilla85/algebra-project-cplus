/* (C) Copyright 2010. David A. Mancilla
	Todos los derechos reservados.

	Clase: Natural
	Descripción: Representa los números naturales (1 a N) */

#pragma once

#ifndef NATURAL_H
#define NATURAL_H

#include "Entero.h"

class Natural
{
private:
	double x;
	long double factorial(const long);

public:
	Natural(void);
	Natural(const long);
	Natural(const Natural&);
	~Natural(void);
	Natural& operator =(const long);
	Natural& operator =(const Natural&);
	Natural operator +(const long);
	Natural operator +(const Natural&);
	Natural operator -(const long);
	Natural operator -(const Natural&);
	Natural operator *(const long);
	Natural operator *(const Natural&);
	Natural operator /(const long);
	Natural operator /(const Natural&);
	long double operator !();

	static string fibonacci(int);

	friend ostream& operator <<(ostream&, const Natural&);
};

#endif