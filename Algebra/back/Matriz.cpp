/* (C) Copyright 2010. David A. Mancilla
	Todos los derechos reservados.

	Clase: Matriz
	Descripción: Matriz de números reales. */

#include "Matriz.h"

// CONSTRUCTORES
Matriz::Matriz(void)
{
	this->matriz = new double;
	*(this->matriz) = 0;
	this->n = 1;
	this->m = 1;
}

Matriz::Matriz(int n, int m)
{
	this->matriz = NULL;
	if(n > 0 && m > 0)
	{
			this->matriz = new double[n * m];
			this->n = n;
			this->m = m;
			iniciar(*this);
	}
}

Matriz::Matriz(const Matriz& obj)
{
	int i, j;
	this->matriz = NULL;
	this->matriz = new double[obj.n * obj.m];
	this->n = obj.n;
	this->m = obj.m;

	for(i = 0; i < obj.n; i++)
		for(j = 0; j < obj.m; j++)
			*(this->matriz + this->n * i + j) = *(obj.matriz + obj.n * i + j);  
}

Matriz::~Matriz(void)
{
	delete []this->matriz;
	this->n = this->m = 0;
}

Matriz::~Matriz()
{

}

// OPERADORES

Matriz& Matriz::operator = (const Matriz& obj)
{
	*(this->matriz) = *(obj.matriz);
	return *this;
}

Matriz Matriz::operator + (const Matriz& obj)
{
	int i, j;
	Matriz nula;
	
	if(this->n == obj.n && this->m == obj.m)
	{
		Matriz aux(obj.n, obj.m);
		for(i = 0; i < obj.n; i++)
			for(j = 0; j < obj.m; j++)
				*(aux.matriz) = *(this->matriz + i * obj.n + j) + *(obj.matriz + i * obj.n + j);
		
		return aux;
	}
	else
		return nula;
}

Matriz Matriz::operator * (const double k)
{
	int i, j;
	Matriz aux(this->n, this->m);
	
	for(i = 0; i < this->n; i++)
			for(j = 0; j < this->m; j++)
				*(aux.matriz) = *(this->matriz + i * this->n + j) * k;

	return aux;
}

Matriz Matriz::operator * (const Matriz& obj)
{
	Matriz op2(obj);
	Matriz aux(this->n, obj.m);
	if (productoMatriz(this->matriz, op2.matriz, this->n, this->m, obj.n, obj.m, aux.matriz))
		return aux;
		
	return *this;
}

ostream& operator <<(ostream& out, const Matriz& obj)
{
	return;
}


// FUNCIONES

void iniciar(Matriz& obj)
{
	int i, j;

	for(i = 0; i < obj.n; i++)
		for(j = 0; j < obj.m; j++)
			*(obj.matriz + i * obj.n + j) = 0;

}

// Matriz1 N1xM1 * Matriz N2xM2 = Matriz3 N1xM2
bool productoMatriz(double *mat1, double *mat2, const int n1, 
								const int m1, const int n2, const int m2, double *mat3)
{
	
	int i1 = 0, j1, i2, j2 = 0, i3 = 0, j3 = 0, i, j;
	
	if(m1 != n2)
		return false;

	// Inicializar matriz 3
	for(i = 0; i < n1; i++)
		for(j = 0; j < m2; j++)
			*(mat3  + (m2 * i) + j) = 0;
	
	while(i1 < n1){
		 j1 = i2 = 0;
		 
		 while(j1 < m1 && i2 < n2)
			  *(mat3 + (m2 * i3) + j3) += 
				  *(mat1 + (m1 * i1) + j1++) * (*(mat2 + (m2 * (i2++)) + j2));

		 if(++j2 == m2){
			j2 = 0;
			i1++;
		  }
		  
		  if(++j3 == m2){
			j3 = 0;
			i3++;
		  }
	} 
	return true; 
}

void Matriz::asignaValor(int i, int j, const double x)
{
	if(i < this->n && i >= 0 && j < this->m && j >= 0)
		*(this->matriz + i * this->n + j) = x;
}
