#include "Plataforma.h"

Plataforma::Plataforma() :
    series{
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie(),
        new Serie()
    },
    peliculas{
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula(),
        new Pelicula()
    }
{
}

void Plataforma::ingresarSeries(int inicial, int numeroSeries, string nombreArchivo)
{
    int numeroEpisodios;
    int numeroTemporadas;
    vector<string> renglon;
    string linea, palabra;

    fstream archivo;

    archivo.open(nombreArchivo, ios::in);

    if (numeroSeries > 16) {
        numeroSeries = 20;
    }


    try {
        if (archivo.fail())
            throw "No fue posible cargar el archivo de series \n\n";

        for (int i = inicial; i < numeroSeries; i++) {

            renglon.clear();

            getline(archivo, linea);

            stringstream s(linea);

            while (getline(s, palabra, ','))
            {
                renglon.push_back(palabra);

            }

            stringstream temporadas(renglon[3]);
            temporadas >> numeroTemporadas;
            stringstream episodios(renglon[4]);
            episodios >> numeroEpisodios;

            series[i] = new Serie(renglon[0], renglon[1], renglon[2], numeroTemporadas, numeroEpisodios, "episodios" + to_string(i + 1) + ".csv");
            if (inicial == 0)
                series[i]->ingresarEpisodios();
            else
                cout << "       Serie " << series[i]->getNombre() << " cargada exitosamente." << endl;

        }
        archivo.close();
    }
    catch (const char* msg)
    {
        std::cerr << msg;
    }
}

void Plataforma::ingresarPeliculas(int inicial, int numeroPeliculas, string nombreArchivo)
{
    float calificacion;
    vector<string> renglon;
    string linea, palabra;

    fstream archivo;

    archivo.open(nombreArchivo, ios::in);

    if (numeroPeliculas > 13) {
        numeroPeliculas = 13;
    }

    try{
        if (archivo.fail())
            throw "No fue posible cargar el archivo de peliculas \n\n";
    
        for (int i = inicial; i < numeroPeliculas; i++) {

            renglon.clear();

            getline(archivo, linea);

            stringstream s(linea);

            while (getline(s, palabra, ','))
            {
                renglon.push_back(palabra);

            }

            stringstream calif(renglon[4]);
            calif >> calificacion;

            peliculas[i] = new Pelicula(renglon[0], renglon[1], renglon[2], renglon[3], calificacion);

            if (inicial != 0)
                cout << "       Pelicula " << peliculas[i]->getNombre() << " cargada exitosamente." << endl;

        }
        archivo.close();
    }
    catch (const char* msg)
    {
        std::cerr << msg;
    }
   
}

void Plataforma::cargarArchivo()
{
    string opcion;
    cout << "   1. Cargar archivo de series" << endl;
    cout << "   2. Cargar archivo de peliculas" << endl;
    cin >> opcion;

    if (opcion == "1") {
        int numeroSeries;
        string nombreArchivo;

        cout << "       El archivo de series debe contener los siguientes datos, separado por comas y sin ningun encabezado: " << endl;
        cout << "       id,nombre,genero,numeroTemporadas,numeroEpisodios       Ejemplo:   20110125,Game of Thrones,Drama,8,73 " << endl << endl;
        cout << "       Ingrese el numero de series en el archivo (el numero de series debe ser menor o igual a 16)" << endl;
        cin >> numeroSeries;
        cout << "       Ingrese el nombre del archivo.          Ejemplo: series.csv" << endl;
        cin >> nombreArchivo;

        this->ingresarSeries(5, numeroSeries + 5, nombreArchivo);
    }
    else if (opcion == "2") {
        int numeroPeliculas;
        string nombreArchivo;

        cout << "       El archivo de peliculas debe contener los siguientes datos, separado por comas y sin ningun encabezado: " << endl;
        cout << "       id,nombre,duracion,genero,calificacion      Ejemplo:   20192345,Ad Astra,02:03,Drama,6.6 " << endl << endl;
        cout << "       Ingrese el numero de peliculas en el archivo (el número de peliculas debe ser menor o igual a 13)" << endl;
        cin >> numeroPeliculas;
        cout << "       Ingrese el nombre del archivo.          Ejemplo: peliculas.csv" << endl;
        cin >> nombreArchivo;

        this->ingresarPeliculas(8, numeroPeliculas + 8, nombreArchivo);
    }
    else {
        cout << "       Opcion no disponible." << endl;
    }
}

void Plataforma::mostrarVideo()
{   
    string opcion;
    string genero;
    float calificacion;
    cout << "   1. Ver video por calificacion" << endl;
    cout << "   2. Ver video por genero" << endl;
    cin >> opcion;
    
    if (opcion == "1") {
        cout << "       Ingrese la calificacion minima que debe tener el video" << endl;
        cin >> calificacion;
        for (int i = 0; i < 7; i++)
            peliculas[i]->verVideo(calificacion);

        for (int i = 0; i < 4; i++) {
            cout << "       Serie: " << series[i]->getNombre() << endl;
            for (int j = 0; j < series[i]->getNumEpisodios(); j++) {
                series[i]->getEpisodio(j)->verVideo(calificacion);
            }
        }
    }
    else if (opcion == "2") {
        cout << "       Ingrese el genero del video" << endl;
        cin >> genero;
        for (int i = 0; i < 7; i++)
            if (peliculas[i]->getGenero() == genero) {
                cout << *peliculas[i];
            }

        for (int i = 0; i < 4; i++) {
            if (series[i]->getGenero() == genero) {
                cout << "       Serie: " << series[i]->getNombre() << endl;
                for (int j = 0; j < series[i]->getNumEpisodios(); j++) {
                    cout << *series[i]->getEpisodio(j);
                }
            }
        }
    }
}

void Plataforma::mostrarVideosSerie()
{
    string nombreSerie;
    float calificacion;
  
    cout << "       Ingrese el nombre de la serie de la cual desea ver episodios " << endl;
    cin.ignore();
    getline(cin, nombreSerie);
    cout << "       Ingrese la calificacion minima que deben tener los episodios a mostrar " << endl;
    cin >> calificacion;

    for (int i = 0; i < 4; i++) {
        if (series[i]->getNombre() == nombreSerie) {
            cout << "       Serie: " << series[i]->getNombre() << endl;
            for (int j = 0; j < series[i]->getNumEpisodios(); j++) {
                series[i]->getEpisodio(j)->verVideo(calificacion);
            }
            break;
        }
        else if (i == 3) {
            cout << "Serie no encontrada" << endl << endl;
        }
    }
}

void Plataforma::mostrarPeliculas()
{
    float calificacion;

    cout << "       Ingrese la calificaciOn minima que debe tener la pelicula" << endl;
    cin >> calificacion;
    for (int i = 0; i < 7; i++)
        peliculas[i]->verVideo(calificacion);

}

void Plataforma::calificarVideo()
{
    string nombreVideo;
    int contador = 1;
    float calificacion = 0;

    cout << "   Introduzca el nombre del video que desea calificar: " << endl;
    cin.ignore();
    getline(cin, nombreVideo);
    cout << "   Introduzca la calificacion que sea ponerle: " << endl;
    cin >> calificacion;

    for (int i = 0; i < 7; i++) {
        contador = peliculas[i]->cambiarCalificacion(nombreVideo, calificacion);
        if (contador == 1) {
            break;
        }
    }

    if (contador != 1) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < series[i]->getNumEpisodios(); j++) {
                contador = series[i]->getEpisodio(j)->cambiarCalificacion(nombreVideo, calificacion);
                if (contador == 1) {
                    cout << "        Perteneciente a la serie: " << series[i]->getNombre() << endl;
                    break;
                }
            }   
            if (contador == 1) {
                break;
            }
        }
    }

    if (contador == 0) {
        cout << "Video no encontrado" << endl << endl;
    }

}

void Plataforma::menu()
{
    int opcion = 1;
    while (opcion != 0) {
        cout << "Elija una de las siguientes opciones: " << endl;
        cout << "1. Cargar archivo de datos" << endl;
        cout << "2. Ver los videos disponibles" << endl;
        cout << "3. Ver los episodios de una determinada serie" << endl;
        cout << "4. Ver las peliculas disponibles" << endl;
        cout << "5. Calificar un video" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
        case 1:
            this->cargarArchivo();
            break;
        case 2:
            this->mostrarVideo();
            break;
        case 3:
            this->mostrarVideosSerie();
            break;
        case 4:
            this->mostrarPeliculas();
            break;
        case 5:
            this->calificarVideo();
            break;
        }
    }
}
