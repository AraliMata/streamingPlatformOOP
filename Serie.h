#pragma once
#include <string>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Episodio.h"

using namespace std;
class Serie
{
private:
	string id;
	string nombre;
	string genero;
	int numTemporadas;
	int numEpisodios;
	string nombreArchivoEpisodio;
	Episodio* episodios[100];

public:
	Serie();
	Serie(string, string, string, int, int, string);

	void setNombre(string);
	string getNombre();

	void setGenero(string);
	string getGenero();

	void setNumTemporadas(int);
	int getNumTemporadas();

	void setNumEpisodios(int);
	int getNumEpisodios();		

	Episodio* getEpisodio(int);

	void ingresarEpisodios();

};

