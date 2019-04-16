#pragma once

#include <cstdlib>

class Matriz
{
private:
	double *matriz;
	long m, n; // M(Filas) x N(Columnas)

public:
	Matriz(void);
	Matriz(const Matriz&);
	Matriz(const long m, const long n);
	~Matriz(void);

	void setValor(const long, const long, const double);
	Matriz& operator = (const Matriz&);
	Matriz operator *(const Matriz&);
	bool sumaDiagonalSuperior(double*);
	long getDimension();
	bool getTraza(double*);
	bool getTrazaSecundaria(double*);
	bool esDiagonal();
	bool esIdentidad();
	bool esSimetrica();

};

