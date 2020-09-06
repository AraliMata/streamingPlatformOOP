#pragma once
#include "Video.h"
class Episodio :
	public Video
{
private:
	string idSerie;
	int temporada;

public:
	Episodio();
	Episodio(string, string, string, string, float, int);
	
	void setIdSerie(string);
	string getIdSerie();

	void setTemporada(int);
	int getTemporada(int);

	void verVideo(float);
	int cambiarCalificacion(string, float);

	friend ostream& operator<<(ostream& os, const Episodio& episodio)
	{
		os << "			Titulo: " << episodio.getNombre() << " Duracion: " << episodio.getDuracion() << " Calificacion: " << episodio.getCalificacion() << " Temporada: " << episodio.temporada << endl;
		return os;
	}
};

