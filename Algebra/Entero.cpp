#include "Entero.h"


Entero::Entero(void) 
{
	this->x = 0;
}

Entero:: Entero(const long x)
{
	this->x = x;
}

Entero:: Entero(const Entero& obj)
{
	this->x = obj.x;
}

Entero::~Entero(void)
{
}

Entero& Entero:: operator =(const long x)
{
	this->x = x;
	return *this;
}

Entero& Entero:: operator =(const Entero& obj)
{
	this->x = obj.x;

	return *this;
}

Entero Entero:: operator +(const long x)
{
	Entero aux;
	aux.x = this->x + x;

	return aux;
}

Entero Entero:: operator +(const Entero& obj)
{
	Entero aux;
	aux.x = this->x + obj.x;

	return aux;
}

Entero Entero:: operator -(const long x)
{
	Entero aux((long)ceil(this->x - x));
	return aux;
}

Entero Entero:: operator -(const Entero& obj)
{
	Entero aux((long)ceil(this->x - obj.x));

	return aux;
}

Entero Entero:: operator *(const long x)
{
	Entero aux((long)ceil(this->x * x));
	return aux;
}

Entero Entero:: operator *(const Entero& obj)
{
	Entero aux((long)ceil(this->x * obj.x));

	return aux;
}

Entero Entero:: operator /(const long x)
{
	Entero aux;

	// Si intenta realizarse una división por 0 devuelve 0
	if(x <= 0)
		aux.x = 0;
	else
		aux.x = this->x / x;

	return aux;
}

Entero Entero:: operator /(const Entero& obj)
{
	Entero aux;

	if(this->x < obj.x || obj.x == 0)
		aux.x = 0;
	else
		aux.x = this->x / obj.x;
	
	return aux;
}

ostream& operator <<(ostream& out, const Entero& obj)
{
	out << obj.x;
	return out;
}

