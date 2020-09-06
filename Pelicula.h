#pragma once
#include "Video.h"
class Pelicula :public Video
{
private:
	string genero;

public:

	Pelicula();
	Pelicula(string, string, string, string, float);
	
	void setGenero(string);
	string getGenero();

	void verVideo(float);
	int cambiarCalificacion(string, float);
	
	friend ostream& operator<<(ostream& os, const Pelicula& pelicula)
	{
		os << "			Titulo: " << pelicula.getNombre() << " Duracion: " << pelicula.getDuracion() << " Calificacion: " << pelicula.getCalificacion() << " Genero: " << pelicula.genero << endl;
		return os;
	}
};

