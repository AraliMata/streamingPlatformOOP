#include "Pelicula.h"

Pelicula::Pelicula(): Video()
{
	genero = "";
}

Pelicula::Pelicula( string id, string nombre, string duracion, string generoR, float calificacion): Video(id, nombre, duracion, calificacion)
{
	genero = generoR;
}

void Pelicula::setGenero(string generoR)
{
	genero = generoR;
}

string Pelicula::getGenero()
{
	return genero;
}

void Pelicula::verVideo(float cal)
{
	if (this->getCalificacion() >= cal) {
		cout << *this;
	}
}

int Pelicula::cambiarCalificacion(string nom, float calif)
{
	int c = 0;

	if (nom == this->getNombre()) {
		this->setCalificacion(calif);
		cout << "		La calificacion de la pelicula " << this->getNombre() << " fue cambiada exitosamente a " << this->getCalificacion() << endl;
		c = 1;
	}

	return c;
}