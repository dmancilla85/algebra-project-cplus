/* (C) Copyright 2010. David A. Mancilla
	Todos los derechos reservados.

	Clase: Real
	Descripción: Representa los números reales. */

#include "Real.h"


//CONSTRUCTORES

Real::Real(void) 
{
	Complejo::Complejo();
}

Real:: Real(const double x)
{
	this->x = x;
}

Real:: Real(const Real& obj)
{
	this->x = obj.x;
}

Real::~Real(void) {}


// OPERADORES

Real& Real:: operator =(const double x)
{
	this->x = x;
	return *this;
}

Real& Real:: operator =(const Real& obj)
{
	this->x = obj.x;

	return *this;
}

Real Real:: operator +(const double x)
{
	Real aux;
	aux.x = this->x + x;

	return aux;
}

Real Real:: operator +(const Real& obj)
{
	Real aux;
	aux.x = this->x + obj.x;

	return aux;
}

Real Real:: operator -(const double x)
{
	Real aux(this->x - x);
	return aux;
}

Real Real:: operator -(const Real& obj)
{
	Real aux(this->x - obj.x);

	return aux;
}

Real Real:: operator *(const double x)
{
	Real aux(this->x * x);
	return aux;
}

Real Real:: operator *(const Real& obj)
{
	Real aux(this->x * obj.x);

	return aux;
}

Real Real:: operator /(const double x)
{
	Real aux;

	if(x == 0)
		aux.x = 0;
	else
		aux.x = this->x / x;
	
	return aux;
}

Real Real:: operator /(const Real& obj)
{
	Real aux;

	if(obj.x == 0)
		aux.x = 0;
	else
		aux.x = this->x / obj.x;
	
	return aux;
}

ostream& operator <<(ostream& out, const Real& obj)
{
	out << obj.x;
	return out;
}