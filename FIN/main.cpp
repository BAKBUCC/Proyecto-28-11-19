#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "Menu.h"


using namespace std;

int main()
{
    while(true)
    {
        Menu *m= new Menu;
        short puntaje= m->obtenerPuntaje();
        if (puntaje<10)
        {
            cout<<"soy una persona"<<endl;
        }
        else if(puntaje<20)
        {
            cout<<"soy un heroe"<<endl;
        }
        else
        {
            cout<<"soy leyenda"<<endl;
        }
        system("PAUSE");
        system("cls");
        delete &m;
    }
    return 0;
}
