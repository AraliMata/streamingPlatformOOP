#include "Serie.h"

Serie::Serie()
{
	id = "";
	nombre = "";
	genero = "";
	numTemporadas = 0;
	numEpisodios = 0;
	nombreArchivoEpisodio = "";
}

Serie::Serie(string idR, string nombreR, string generoR, int numTempoeradasR, int numEpisodiosR, string nombreArchivoEpisodioR)
{
	id = idR;
	nombre = nombreR;
	genero = generoR;
	numTemporadas = numTempoeradasR;
	numEpisodios = numEpisodiosR;
	nombreArchivoEpisodio = nombreArchivoEpisodioR;
}


void Serie::setNombre(string nombreR)
{
	nombre = nombreR;
}

string Serie::getNombre()
{
	return nombre;
}


void Serie::setGenero(string generoR)
{
	genero = generoR;
}

string Serie::getGenero()
{
	return genero;
}


void Serie::setNumTemporadas(int numTemporadasR)
{
	numTemporadas = numTemporadasR;
}

int Serie::getNumTemporadas()
{
	return numTemporadas;
}


void Serie::setNumEpisodios(int episodios)
{
	numEpisodios = episodios;
}

int Serie::getNumEpisodios()
{
	return numEpisodios;
}


Episodio* Serie::getEpisodio(int numeroEpisodio)
{
	return episodios[numeroEpisodio];
}

void Serie::ingresarEpisodios()
{
    float calif;
	int temporada;
    vector<string> renglon;
    string linea, palabra;

    fstream archivo;

    archivo.open(nombreArchivoEpisodio, ios::in);


    if (archivo.is_open())
    {
        for (int i = 0; i < numEpisodios; i++) {

            renglon.clear();

            getline(archivo, linea);

            stringstream s(linea);

            while (getline(s, palabra, ','))
            {
                renglon.push_back(palabra);

            }

            stringstream cal(renglon[4]);
            cal >> calif;
			stringstream temp(renglon[5]);
			temp >> temporada;

            episodios[i] = new Episodio(renglon[0], renglon[1], renglon[2], renglon[3], calif, temporada);

        }
        archivo.close();
    }
}
