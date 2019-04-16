/* (C) Copyright 2010. David A. Mancilla
	Todos los derechos reservados.

	Clase: Natural
	Descripción: Representa los números naturales (1 a N) */

#include "Natural.h"


// CONSTRUCTORES

Natural::Natural(void)
{
	this->x = 1;
}

Natural::Natural(const long x)
{
	if(x > 0 )
		this->x = x;
	else
		this->x = 0;
}

Natural::Natural(const Natural& obj)
{
	this->x = obj.x;
}

Natural::~Natural(void) {}


// OPERADORES

Natural& Natural:: operator =(const long x)
{
	if(x > 0) 
		this->x = x;

	else
		*this = NULL;

	return *this;
}

Natural& Natural:: operator =(const Natural& obj)
{
	this->x = obj.x;

	return *this;
}

Natural Natural:: operator +(const long x)
{
	long x_aux = (long)ceil(this->x + x);
	Natural aux(x_aux);
	return aux;
}

Natural Natural:: operator +(const Natural& obj)
{
	long x_aux = (long)ceil(this->x + obj.x);
	Natural aux(x_aux);
	return aux;
}

Natural Natural:: operator -(const long x)
{
	long x_aux = (long)ceil(this->x - x);
	Natural aux(x_aux);
	return aux;
}

Natural Natural:: operator -(const Natural& obj)
{
	long x_aux = (long)ceil(this->x - obj.x);
	Natural aux(x_aux);
	return aux;
}

Natural Natural:: operator *(const long x)
{	
	long x_aux = (long)ceil(this->x * x);
	Natural aux(x_aux);
	return aux;
}

Natural Natural:: operator *(const Natural& obj)
{
	long x_aux = (long)ceil(this->x * obj.x);
	Natural aux(x_aux);
	return aux;
}

Natural Natural:: operator /(const long x)
{
	Natural aux;

	// Si intenta realizarse una división por 0 devuelve NULL
	if(x <= 0)
		aux.x = 0;
	else
		aux.x = (long)ceil(this->x / x);

	return aux;
}

Natural Natural:: operator /(const Natural& obj)
{
	Natural aux;

	if(x < obj.x || obj.x == 0)
		aux.x = 0;
	else
		aux.x = (long)ceil(this->x / obj.x);

	return aux;
}

long double Natural:: operator !()
{
	return factorial((long)this->x);
}

ostream& operator <<(ostream& out, const Natural& obj)
{
	out << obj.x;
	return out;
}


// FUNCIONES

long double Natural:: factorial(const long x)
{
	// Obtiene el factorial de x (x! = x * (x-1) * ... * (x - n) * ... * 1

	if(x)
		return x * factorial(x - 1);
	return 1;
}

//double Natural:: dameX()
//{
//	return this->x;
//}


