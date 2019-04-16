/* (C) Copyright 2010. David A. Mancilla
	Todos los derechos reservados.

	Clase: MatrizElemental
	Descripción: Matriz que opera con clases de envoltura. */

#pragma once

#include "Real.h"

#include <iostream>
using std::endl;

class MatrizElemental
{
protected:
	Complejo *matriz;
	int n, m;
	friend void iniciar(MatrizElemental&);
	friend bool productoMatriz(Complejo *mat1, Complejo *mat2, const int n1, 
									const int m1, const int n2, const int m2, Complejo *mat3);

public:
	MatrizElemental(void);
	MatrizElemental(int, int);
	MatrizElemental(const MatrizElemental&);
	~MatrizElemental(void);
	MatrizElemental& operator = (const MatrizElemental&);
	MatrizElemental operator + (const MatrizElemental&);
	MatrizElemental operator - (const MatrizElemental&);
	MatrizElemental operator * (const double);
	MatrizElemental operator * (const Complejo&);
	MatrizElemental operator * (const MatrizElemental&);
	void asignaValor(int, int, const Complejo&);
	void asignaValor(int, int, const double); 

	friend ostream& operator <<(ostream&, const MatrizElemental&);
};