#include "Video.h"

Video::Video()
{
	id = "0";
	nombre = " ";
	duracion = "0";
	calificacion = 0.0f;
}

Video::Video(string idR, string nombreR, string duracionR, float calificacionR)
{
	id = idR;
	nombre = nombreR;
	duracion = duracionR;
	calificacion = calificacionR;
}

void Video::setId(string idR)
{
	id = idR;
}

string Video::getId()
{
	return id;
}

void Video::setNombre(string nombreR)
{
	nombre = nombreR;
}

string Video::getNombre() const
{
	return nombre;
}

void Video::setDuracion(string duracionR)
{
	duracion = duracionR;
}

string Video::getDuracion() const
{
	return duracion;
}

void Video::setCalificacion(float calificacionR)
{
	calificacion = calificacionR;
}

float Video::getCalificacion() const
{
	return calificacion;
}

void Video::verVideo(float cal)
{
	if (calificacion >= cal) {
		cout << *this;
	}
}

int Video::cambiarCalificacion(string nom, float calif)
{
	int c = 0;
	if (nom == nombre) {
		calificacion = calif;
		cout << "		La calificación de " << nombre << "fue cambiada exitosamente a " << calificacion << endl;
		c = 1;
	}

	return c;
}
