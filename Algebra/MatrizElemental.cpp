/* (C) Copyright 2010. David A. Mancilla
	Todos los derechos reservados.

	Clase: MatrizElemental
	Descripción: */

#include "MatrizElemental.h"


// CONSTRUCTORES

MatrizElemental::MatrizElemental(void)
{
	//Complejo aux;
	this->matriz = NULL;
	this->matriz = new Complejo();
	this->n = 1;
	this->m = 1;
}

MatrizElemental::MatrizElemental(int n, int m)
{
	this->matriz = NULL;
	if(n > 0 && m > 0)
	{
			this->matriz = new Complejo[n * m];
			this->n = n;
			this->m = m;
			iniciar(*this);
	}
}

MatrizElemental::MatrizElemental(const MatrizElemental& obj)
{
	int i, j;
	this->matriz = NULL;
	this->matriz = new Complejo[obj.n * obj.m];
	this->n = obj.n;
	this->m = obj.m;

	for(i = 0; i < obj.n; i++)
		for(j = 0; j < obj.m; j++)
			*(this->matriz + this->n * i + j) = *(obj.matriz + obj.n * i + j);  
}

MatrizElemental::~MatrizElemental(void)
{
	int i = 0, j = 0;

	if(this->matriz != NULL)
	{
		for(i = 0; i < this->n; i++)
			for(j = 0; j < this->m; j++)
				(this->matriz + this->n * i + j)->~Complejo();	
	}	
}


// OPERADORES

MatrizElemental& MatrizElemental::operator = (const MatrizElemental& obj)
{
	*(this->matriz) = *(obj.matriz);
	return *this;
}

MatrizElemental MatrizElemental::operator + (const MatrizElemental& obj)
{
	int i, j;
	
	if(this->n == obj.n && this->m == obj.m)
	{
		MatrizElemental aux(obj.n, obj.m);
		for(i = 0; i < obj.n; i++)
			for(j = 0; j < obj.m; j++)
				*(aux.matriz) = *(this->matriz + i * obj.n + j) + *(obj.matriz + i * obj.n + j);
		
		return aux;
	}
	else
		return MatrizElemental();
}

MatrizElemental MatrizElemental::operator * (const double k)
{
	int i, j;
	MatrizElemental aux(this->n, this->m);
	
	for(i = 0; i < this->n; i++)
			for(j = 0; j < this->m; j++)
				*(aux.matriz) = *(this->matriz + i * this->n + j) * k;

	return aux; // el objeto se borra!!
}

MatrizElemental MatrizElemental::operator * (const Complejo& obj)
{
	int i, j;
	MatrizElemental aux(this->n, this->m);
	
	for(i = 0; i < this->n; i++)
			for(j = 0; j < this->m; j++)
				*(aux.matriz) = *(this->matriz + i * this->n + j) * obj;

	return aux;
}

MatrizElemental MatrizElemental::operator * (const MatrizElemental& obj)
{
	MatrizElemental op2(obj);
	MatrizElemental aux(this->n, obj.m);
	if (productoMatriz(this->matriz, op2.matriz, this->n, this->m, obj.n, obj.m, aux.matriz))
		return aux;
		
	return *this;
}

ostream& operator <<(ostream& out, const MatrizElemental& obj)
{
	int i, j;
	for(i = 0; i < obj.n; i++)
	{
		out << endl;
		for(j = 0; j < obj.m; j++)
		{
			if((obj.matriz + i * obj.n + j)->obtenerY() != 0)
				out << *(obj.matriz + i * obj.n + j) << " , ";
			else
				out << /*(Real)*/*(obj.matriz + i * obj.n + j) << " , ";
		}
	}
	return out;
}


// FUNCIONES

void iniciar(MatrizElemental& obj)
{
	register int i, j;

	for(i = 0; i < obj.n; i++)
		for(j = 0; j < obj.m; j++)
			*(obj.matriz + i * obj.n + j) = 0;

}

// Matriz1 N1xM1 * Matriz N2xM2 = Matriz3 N1xM2
bool productoMatriz(Complejo *mat1, Complejo *mat2, const int n1, 
								const int m1, const int n2, const int m2, Complejo *mat3)
{
	
	register int i1 = 0, j1, i2, j2 = 0, i3 = 0, j3 = 0, i, j;
	
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

inline void MatrizElemental::asignaValor(int i, int j, const Complejo& obj)
{
	if(i < this->n && i >= 0 && j < this->m && j >= 0)
		*(this->matriz + i * this->n + j) = obj;
}

void MatrizElemental::asignaValor(int i, int j, const double x)
{
	Complejo obj(x);
	if(i < this->n && i >= 0 && j < this->m && j >= 0)
		*(this->matriz + i * this->n + j) = obj;
}