#ifndef HUMANO_H
#define HUMANO_H
#include <string>
using namespace std;

template <typename T>

class Humano
{
    public:
        Humano(string="unknowName", string="unknowLast", string="unknowFail", int=15, int=50.3, int=1.50)
        :nombre(nombre), apellido(apellido), apodo(apodo), edad(edad), peso(peso), estatura(estatura){};
        T get(string a)
        {
            if (a=="nombre")
            {
                return nombre;
            }
            else if (a=="apellido")
            {
                return apellido;
            }
            else if (a=="apodo")
            {
                return apodo;
            }
            else if (a=="edad")
            {
                return edad;
            }
            else if (a=="peso")
            {
                return peso;
            }
            else if (a=="estatura")
            {
                return estatura;
            }

    protected:
        string nombre;
        string apellido;
        string apodo;
        short edad, peso, estatura, auxEstatura;

    private:
};

#endif // HUMANO_H
