/* (C) Copyright 2010. David A. Mancilla
	Todos los derechos reservados.

	Clase: Complejo
	Descripción: Representa los números complejos. */

#include "Complejo.h"


//CONSTRUCTORES

Complejo::Complejo(void) 
{
	this->y = this->x = 0;
}

Complejo::Complejo(const double x) 
{
	this->x = x;
	this->y = 0;
}

Complejo::Complejo(const double x, const double y) 
{
	this->x = x;
	this->y = y;
}

Complejo::Complejo(const Complejo& obj) 
{
	this->x = obj.x;
	this->y = obj.y;
}

Complejo::~Complejo(void) {}

Complejo& Complejo::operator =(const double x = 0)
{
	this->x = x;
	this->y = 0;
	return *this;
}

Complejo& Complejo::operator =(const Complejo& obj)
{
	this->x = obj.x;
	this->y = obj.y;

	return *this;
}

Complejo& Complejo::operator += (const Complejo& obj)
{
	this->x += obj.x;
	this->y += obj.y;

	return *this;
}

Complejo Complejo::operator +(const double x)
{
	Complejo aux(this->x + x);
	return aux;
}

Complejo Complejo::operator +(const Complejo& obj)
{
	Complejo aux(this->x + obj.x, this->y + obj.y);
	return aux;
}

Complejo Complejo::operator -(const double x)
{
	Complejo aux(this->x - x);
	return aux;
}

Complejo Complejo:: operator -(const Complejo& obj)
{
	Complejo aux(this->x - obj.x, this->y - obj.y);
	return aux;
}

Complejo Complejo::operator *(const double x)
{
	Complejo aux(this->x * x, this->y * x);
	return aux;
}

double Complejo::operator *(const Complejo& obj)
{
	return this->x * obj.x - (this->y * y);
}

//Complejo Complejo:: operator /(const Complejo& obj) {}

ostream& operator <<(ostream& out, const Complejo& obj)
{
	out << "(" << obj.x << "; " << obj.y << "i) ";
	return out;
}

// FUNCIONES

Complejo Complejo::conjugado()
{
	// Obtiene el conjugado ( z = a + b i => Z = a - b i
	
	Complejo aux;
	aux.y *= (-1);

	return aux;
}

