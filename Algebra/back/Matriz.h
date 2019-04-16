/* (C) Copyright 2011. David A. Mancilla
	Todos los derechos reservados.

	Clase: MatrizElemental
	Descripción: Matriz que opera con clases de envoltura. */

#pragma once
#include <iostream>
#include <cstdio>

using namespace std;

class Matriz 
{
protected:
	double* matriz;
	int n, m;

public:
	Matriz(void);
	Matriz(const int, const int);
	Matriz(const Matriz&);
	~Matriz(void);
	Matriz& operator = (const Matriz&);
	Matriz operator + (const Matriz&);
	Matriz operator - (const Matriz&);
	Matriz operator * (const double);
	Matriz operator * (const Matriz&);
	void asignaValor(const int, const int, const double);
	friend void iniciar(Matriz&);
	friend bool productoMatriz(double *mat1, double *mat2, const int n1, 
									const int m1, const int n2, const int m2, double *mat3);
	friend ostream& operator <<(ostream&, const Matriz&);
}
