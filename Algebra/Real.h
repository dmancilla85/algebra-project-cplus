/* (C) Copyright 2010. David A. Mancilla
	Todos los derechos reservados.

	Clase: Real
	Descripción: Representa los números reales. */

#pragma once

#ifndef REAL_H
#define REAL_H

#include "Complejo.h"

class Real :
	public Complejo
{
public:
	Real(void);
	Real(const double);
	Real(const Real&);
	~Real(void);
	
	Real& operator =(const double);
	Real& operator =(const Real&);
	Real operator +(const double);
	Real operator +(const Real&);
	Real operator -(const double);
	Real operator -(const Real&);
	Real operator *(const double);
	Real operator *(const Real&);
	Real operator /(const double);
	Real operator /(const Real&);
	friend ostream& operator <<(ostream&, const Real&);

private:
	/* Restrinjo el acceso a estas funciones para el resto de las clases */
	double obtenerY() {return 0; };
	void establecerY(double y) { };
	string modoPolar() { return ""; };
	string modoExponencial() { return ""; };
	
};

#endif