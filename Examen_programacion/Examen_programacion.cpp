#include <mysql.h>
#include <iostream>
#include "empleados.h"
#include "conection.h"
#include "puestos.h"

using namespace std;


void repetir();

void opciones()
{
	system("cls");
	cout << "_______________ Opciones _______________" << endl;
	cout << "1. Leer registros" << endl;
	cout << "2. Insertar registros" << endl;
	cout << "3. Modificar registros" << endl;
	cout << "4. Eliminar registros" << endl;
}

void menu()
{
	string puesto, nombre, apellido, direccion,dpi,fecha_nacimiento,inicio_labores,fechaingreso;
	int opcion, opcion2, idpuesto,genero, telefono, id_empleado;

	empleados e = empleados();
	puestos p = puestos();

	cout << "_______________ Menu de Tablas _______________" << endl;
	cout << "1. Tabla puestos" << endl;
	cout << "2. Tabla empleados" << endl;
	cout << "ingrese la tabla que desea: "; 
	cin >> opcion;
	cin.ignore();
	if (opcion == 1)
	{
		system("cls");
		cout << "_______________ TABLA DE PUESTOS _______________" << endl;
		opciones();
		cout << "ingrese la opcion que desea: "; 
		cin >> opcion2;
		cin.ignore();
		switch (opcion2)
		{
		case 1:
			system("cls");
			p.leer_puestos();
			repetir();
			break;
		case 2:
			system("cls");
			cout << "ingrese el puesto: ";
			getline(cin, puesto);
			p = puestos(puesto);
			p.insert_puestos();
			repetir();
			break;
		case 3:
			system("cls");
			p.leer_puestos();
			cout << endl << endl;
			cout << "ingrese el id del registro a modificar: ";
			cin >> idpuesto;
			cin.ignore();
			cout << "ingrese el nuevo puesto: ";
			getline(cin, puesto);
			p = puestos(puesto);
			p.update_puestos(idpuesto);
			repetir();
			break;
		case 4:
			system("cls");
			p.leer_puestos();
			cout << endl << endl;
			cout << "ingrese el id del registro a eliminar: ";
			cin >> idpuesto;
			cin.ignore();
			p.eliminar_puestos(idpuesto);
			repetir();
			break;
		}
	}
	if (opcion == 2)
	{
		system("cls");
		cout << "_______________ TABLA DE PUESTOS _______________" << endl;
		opciones();
		cout << "ingrese la opcion que desea: ";
		cin >> opcion2;
		cin.ignore();
		switch (opcion2)
		{
		case 1:
			system("cls");
			e.leer_empleados();
			repetir();
			break;
		case 2:
			system("cls");
			cout << "\nIngrese nombres: ";
			getline(cin, nombre);
			cout << "\nIngrese apellidos: ";
			getline(cin, apellido);
			cout << "\nIngrese direccion: ";
			getline(cin, direccion);
			cout << "\nIngrese telefono: ";
			cin >> telefono;
			cin.ignore();
			cout << "\nIngrese DPI:";
			getline(cin, dpi);
			cout << "\ningrese Genero (0 = mujer, 1= hombre): ";
			cin >> genero;
			cin.ignore();
			cout << "\nIngrese fecha de nacimiento: ";
			getline(cin, fecha_nacimiento);
			cout << "\nIngrese id_puesto:";
			cin >> idpuesto;
			cin.ignore();
			cout << "\nIngrese fecha inicio labores: ";
			getline(cin, inicio_labores);
			cout << "\nIngrese fecha de ingreso (anio/mes/dia hora:minuto:segundo) ";
			getline(cin, fechaingreso);

			e = empleados(nombre, apellido, direccion, fecha_nacimiento, genero, telefono, dpi, inicio_labores, fechaingreso, idpuesto);
			e.insert_empleados();
			repetir();
			break;
		case 3:
			system("cls");
			e.leer_empleados();
			cout << endl << endl;
			cout << "ingrese id empleado del registro a modificar: "; cin >> id_empleado;
			opcion2 = e.datos_modificar();
			if (opcion2 == 1)
			{
				cout << "\ningrese el nuevo nombre: "; getline(cin, nombre);
				e.setnombres(nombre);
			}
			else if (opcion2 == 2)
			{
				cout << "\ningrese el nuevo apellido: "; getline(cin, apellido);
				e.setapellidos(apellido);
			}
			else if (opcion2 == 3)
			{
				cout << "\ningrese la nueva direccion: "; getline(cin, direccion);
				e.setdireccion(direccion);
			}
			else if (opcion2 == 4)
			{
				cout << "\ningrese el nuevo telefono: "; cin >> telefono; cin.ignore();
				e.settelefono(telefono);
			}
			else if (opcion2 == 5)
			{
				cout << "\ningrese el nuevo dpi: "; getline(cin, dpi);
				e.setdpi(dpi);
			}
			else if (opcion2 == 6)
			{
				cout << "\ningrese el nuevo genero  (0 = mujer, 1= hombre): "; cin >> genero; cin.ignore();
				e.setgenero(genero);
			}
			else if (opcion2 == 7)
			{
				cout << "\ningrese la nueva fecha de nacimiento "; getline(cin, fecha_nacimiento);
				e.setfechanacimiento(fecha_nacimiento);
			}
			else if (opcion2 == 8)
			{
				cout << "\ningrese el nuevo id puesto "; cin >> idpuesto; cin.ignore();
				e.setidpuesto(idpuesto);

			}
			else if (opcion2 == 9)
			{
				cout << "\ningrese la nueva fecha de inicio de labores "; getline(cin, inicio_labores);
				e.setiniciolabores(inicio_labores);
			}
			else if (opcion2 == 10)
			{
				cout << "\ningrese la nueva fecha de ingreso (anio/mes/dia hora:minuto:segundo): "; getline(cin, fechaingreso);
				e.setfechaingreso(fechaingreso);
			}
			e.update_empleados(opcion2, id_empleado);
			repetir();
			break;
		case 4:
			system("cls");
			e.leer_empleados();
			cout << endl << endl;
			cout << "ingrese el id empleado del registro que desea eliminar: "; cin >> id_empleado;
			e.eliminar_empleados(id_empleado);
			repetir();
			break;
		}
	}
}


void repetir()
{
	string opc;
	cout << endl << endl << "Desea probar otra opcion (s/n): ";
	cin >> opc;
	cin.ignore();
	if (opc == "S" || opc == "s")
	{
		system("cls");
		menu();
	}
}

int main()
{
	menu();
}


