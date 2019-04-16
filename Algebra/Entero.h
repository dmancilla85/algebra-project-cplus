#pragma once

#ifndef ENTERO_H
#define ENTERO_H

#include "Real.h"

class Entero :
	public Real
{
public:
	Entero(void);
	Entero(const long);
	Entero(const Entero&);
	~Entero(void);
	Entero& operator =(const long);
	Entero& operator =(const Entero&);
	Entero operator +(const long);
	Entero operator +(const Entero&);
	Entero operator -(const long);
	Entero operator -(const Entero&);
	Entero operator *(const long);
	Entero operator *(const Entero&);
	Entero operator /(const long);
	Entero operator /(const Entero&);
	
	string toString();

	friend ostream& operator <<(ostream&, const Entero&);

};

#endif

