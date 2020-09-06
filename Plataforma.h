#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Pelicula.h"
#include  "Serie.h"
class Plataforma
{
private:
	Serie* series[20];
	Pelicula* peliculas[20];

public:
	Plataforma();
	void ingresarSeries(int, int, string);
	void ingresarPeliculas(int, int, string);
	void cargarArchivo();
	void mostrarVideo();
	void mostrarVideosSerie();
	void mostrarPeliculas();
	void calificarVideo();
	void menu();
};

