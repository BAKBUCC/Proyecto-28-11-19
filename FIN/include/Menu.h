#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cstdint>
#define GetSize(array_enteros) (sizeof(array_enteros)/sizeof(*(array_enteros)))

using namespace std;


class Menu
{
    public:
        Menu();
        void Reg_o_Log();
        void Registrar();
        void Logueate();
        string contenido(ifstream &);
        int obtenerPuntaje();
        void opciones();
        void mostrarDatos();
        void Eliminar();
        void Modificar();
        void buscar();
        void comenzemos();
        void crearListas();
        void Ordenar();
        void printL();
        void OrdenarEnBaase();

    private:
        string nombre, auxNombre, lNom[];
        string apellido, auxApellido, lApell[];
        string apodo,auxApodo, lApo[];
        string contrasenia, lContra[];
        string codigo, auxCodigo, lCod[];
        string auxContrasenia;//buscar
        short edad, auxEdad, lEd[], puntaje, lPunt[], opcion;
        double peso, auxPeso, lPes[], estatura, auxEstatura, lEstat[];
        string eleccion;
        bool encontrado, repeticion;
        bool logueado= new bool;
        bool administrador = new bool;
};

#endif // MENU_H
