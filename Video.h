#pragma once
#include <iostream>

using namespace std;

class Video
{
private:
	string id;
	string nombre;
	string duracion;
	float calificacion;

public:
	Video();
	Video(string, string, string, float);

	void setId(string);
	string getId();

	void setNombre(string);
	string getNombre() const;

	void setDuracion(string);
	string getDuracion() const;

	void setCalificacion(float);
	float getCalificacion() const;

	virtual void verVideo(float);
	virtual int cambiarCalificacion(string, float);

	friend ostream& operator<<(ostream& os, const Video& video)
	{
		os << "Titulo: " << video.nombre << " Duracion: " << video.duracion << " Calificacion: " << video.calificacion << endl;
		return os;
	}
};

