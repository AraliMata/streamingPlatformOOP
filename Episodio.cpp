#include "Episodio.h"

Episodio::Episodio(): Video()
{
	idSerie = "";
	temporada = 0;
}

Episodio::Episodio(string idSerieR, string id, string nombre, string duracion, float calificacion, int temporadaR): Video(id, nombre, duracion, calificacion)
{
	idSerie = idSerieR;
	temporada = temporadaR;
}

void Episodio::setIdSerie(string idSerieR)
{
	idSerie = idSerieR;
}

string Episodio::getIdSerie()
{
	return idSerie;
}

void Episodio::setTemporada(int temporadaR)
{
	temporada = temporadaR;
}

int Episodio::getTemporada(int)
{
	return temporada;
}

void Episodio::verVideo(float cal)
{
	if (this->getCalificacion() >= cal) {
		cout << *this;
	}
}

int Episodio::cambiarCalificacion(string nom, float calif)
{
	int c = 0;
	if (nom == this->getNombre()) {
		this->setCalificacion(calif);
		cout << "	La calificacion del episodio " << this->getNombre() << " de la temporada " << temporada <<" fue cambiada exitosamente a " << this->getCalificacion() << endl;
		c = 1;
	}

	return c;
}