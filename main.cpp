#include <iostream>
#include "Plataforma.h"

int main()
{
    Plataforma plataforma;
    plataforma.ingresarPeliculas(0, 7, "peliculas.csv");
    plataforma.ingresarSeries(0, 4, "series.csv");
    plataforma.menu();
}

