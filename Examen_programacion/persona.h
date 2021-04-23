#pragma once
#include <iostream>
using namespace std;

class persona
{
	protected: string nombres, apellidos, direccion, fecha_nacimiento;
			 int genero=0, telefono=0;
	protected: 
		persona()
		{
		}	
		persona(string nom, string ape, string dir, string fena, int gen, int tel)
		{
			nombres = nom;	apellidos = ape;	direccion = dir;	fecha_nacimiento = fena;
			genero = gen;	telefono = tel;
		}

};

