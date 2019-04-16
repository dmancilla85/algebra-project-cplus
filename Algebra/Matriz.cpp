#include "Matriz.h"


Matriz::Matriz(void)
{
	this->matriz = new double;
	*(this->matriz) = 0.0;
	this->m = 0;
	this->n = 0;	
}

Matriz::Matriz(const Matriz& obj)
{
	register int i, j;
	
	this->matriz = new double[obj.m * obj.n];
	this->m = obj.m;
	this->n = obj.n;

	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			*(matriz + m * i + j) = *(obj.matriz + obj.m * i + j); 

}

Matriz::Matriz(const long n_fila, const long n_col)
{
	this->matriz = new double [n_fila * n_col];
	this->m = n_fila;
	this->n = n_col;
}

Matriz::~Matriz(void)
{
	delete []this->matriz;
}


void Matriz::setValor(const long i, const long j, const double x)
{
	*(matriz + m * i + j) = x; 
}

Matriz& Matriz::operator = (const Matriz& obj)
{
	*(this->matriz) = *(obj.matriz);
	return *this;
}

Matriz Matriz::operator *(const Matriz& obj)
{
	Matriz aux(m, obj.n), nulo;
	long i1 = 0, j1, i2, j2 = 0, i3 = 0, j3 = 0, i, j;
	
	if(n != obj.m)
		return nulo;

	// Inicializar matriz 3
	for(i = 0; i < m; i++)
		for(j = 0; j < obj.n; j++)
			*(aux.matriz + obj.n * i + j) = 0;
	
	while(i1 < m){
		 j1 = i2 = 0;
		 
		 while(j1 < n && i2 < obj.m)
			 *(aux.matriz + obj.n * i3 + j3) += 
				  *(matriz + m * i1 + (j1++)) * *(obj.matriz + obj.n *(i2++) + j2);

		 if(++j2 == obj.m){
			j2 = 0;
			i1++;
		  }
		  
		  if(++j3 == obj.m){
			j3 = 0;
			i3++;
		  }
	} 
	return aux; 
}

bool Matriz::sumaDiagonalSuperior(double *rslt)
{
	long i = 0, j;
	double suma = 0;

	if (m != n) 
		return false;

	while(i < m - 1){
		j = i + 1;
		while(j < n){
			suma += *(matriz + m * i + j);
			j++;
		}
		i++;
	}

	*rslt = suma;
	return true;
}

inline long Matriz::getDimension()
{
	return m * n;
}

bool Matriz::getTraza(double *traza)
{
	long i = 0, j;
	double _traza = 0.0;
	
	if (m != n)
		return false;

	while(i < n)
	{
		j = i;
		_traza += *(matriz + m * i + j);
		i++;
	}

	*traza = _traza;
	return true;
}

bool Matriz::getTrazaSecundaria(double *traza)
{
	long i = 0, j = n - 1;
	double _traza = 0;
	
	if (n != m)
		return false;

	while(i < n && j >= 0)
		_traza += *(matriz + m * i++ + j--);

	*traza = _traza;

	return true;
	
}


bool Matriz::esDiagonal()
{
	long i = 0, j;
	bool diag = true;

	if(n != m)
		return false;

	while(i < n - 1 && diag)
	{
		j = i + 1;

		while(j < n)
		{
			if( *(matriz + n * i + j) != 0 || 
				*(matriz + n * j + i) != 0 || 
				*(matriz + n * i + i) == 0)
				diag = false;
			j++;
		}
		i++;
	}

	return diag && *(matriz + n*i + i) != 0 ? 1 : 0;
	
}

bool Matriz::esIdentidad()
{
	long i = 0, j;
	bool id = true;

	while(i < n - 1 && id)
	{
		j = i + 1;

		while(j < n && id)
		{
			if( *(matriz + n * i + j) != 0 || 
				*(matriz + n * j + i) != 0 || 
				*(matriz + n * i + i) != 1)
				id = false;
			j++;
		}
		i++;
	}

	return id && *(matriz + n*i + i) == 1 ? true : false;
}

bool Matriz::esSimetrica()
{
	long i = 0, j;
	bool sim = true;

	while( i < n-1 && sim)
	{
		j = i + 1;
		while(j < n && sim)
		{
			if(*(matriz + n*i + j) != *(matriz + n*j++ +i))
				sim = false;
		}
		i++;
	}

	return sim;
}