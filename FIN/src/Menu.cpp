#include "Menu.h"

Menu::Menu()
{
    logueado=false;
    administrador=false;
    cout<<"\t\t\t\t\t\t\tBIENVENIDO"<<endl;
    cout<<"\t\t\t\t\t\t\t----------"<<endl;
    cout<<"\t\t\t\t\t\t     A PERSONAL UPDATE"<<endl;
    cout<<"\t\t\t\t\t\t     -----------------"<<endl;
    cout<<endl;
    cout<<endl;
    opciones();
}

void Menu::opciones()
{
    do            //Muestra las opciones de la base datos
    {
            //Muestra las opciones de la base datos
        cout<<"Seleccione una opcion: \n";
        cout<<" (1)Registrarse o Loguearse \n";
        cout<<" (2)Mostrar \n";
        cout<<" (3)Modificar \n";
        cout<<" (4)Eliminar \n";
        cout<<" (5)Buscar \n";
        cout<<" (6)Salir"<<endl;
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
            case 1:
            {
                if (logueado==false)
                {
                    Reg_o_Log();
                    system("PAUSE");
                    system("cls");
                }
                else
                {
                    cout<<"apreta salir para loguearte o registrarte en otra cuenta"<<endl;
                }
                if(administrador==true)
                {
                    cout<<"Administrador"<<endl;
                }
                break;
            }
            case 2:
            {
                if (administrador==true)
                {
                    mostrarDatos(); //registrar un usuario
                    system("PAUSE");
                    system("cls");
                }
                else
                {
                    cout<<"no eres administrador"<<endl;
                    system("PAUSE");
                    system("cls");
                }
                break;
            }
            case 3:
            {
                if (administrador==true)
                {
                    Modificar(); //modificar un usuario
                    system("PAUSE");
                    system("cls");
                }
                else
                {
                    cout<<"no eres administrador"<<endl;
                    system("PAUSE");
                    system("cls");
                }
                break;
            }
            case 4:
            {
                if (administrador==true)
                {
                    Eliminar();
                    system("PAUSE");
                    system("cls");
                }
                else
                {
                    cout<<"no eres administrador"<<endl;
                    system("PAUSE");
                    system("cls");
                }
                break;
            }
            case 5:
            {
                if (administrador==true)
                {
                    buscar();
                    system("PAUSE");
                    system("cls");
                }
                else
                {
                    cout<<"no eres administrador"<<endl;
                    system("PAUSE");
                    system("cls");
                }
                break;
            }
        }
    }while(opcion!=6);
}

void Menu::Reg_o_Log()
{
    cout<<"\t\t*Registrate(REG) o Logueate(LOG)"<<endl;
    cout<<"\t\tElija...";
    cin>>eleccion;
    system("cls");
    if (eleccion=="REG" || eleccion=="Reg" || eleccion=="reg")
    {
        Registrar();
    }
    else if (eleccion=="LOG" || eleccion=="Log" || eleccion=="log")
    {
        Logueate();
    }
}
void Menu::Registrar()
{
    cout<<"Vamos a Registrarte \n";
    ofstream info;
    ifstream verificar;//verifica si ya hay registros con los mismos datos
    repeticion=false;

    info.open("Registrados.txt",ios::out|ios::app);//se abre el archivo y con el ios::app sera capaz de aniadir informacion al archivo, sin perder datos
    verificar.open("Registrados.txt",ios::in);// se usa verificar para leer y comprobar la clave que se ingrese
    if(info.fail())// si no se abre el archivo, manda ese mensaje de error
    {
        cout<<"No se pudo abrir el archivo.";
        exit(1);
    }
    else if(verificar.is_open() && info.is_open())// si ambos archivos se abren, sucede lo siguiente.
    {
        cout<<"Codigo nuevo: ";cin>>auxCodigo;
        verificar>>codigo;//verificar, verifica la clave, si la hay
        while(!verificar.eof())//mientras no se llegue al final del archivo, pasa lo siguiente
        {
            verificar>>nombre>>apellido>>edad>>apodo>>contrasenia>>peso>>estatura>>puntaje;//lectura adelantada de lo demas
            if(codigo==auxCodigo)// se comparan las claves almacenadas que fueron leidas con "verificar", con la auxClave que se ingreso, la funcion strcmp compara caracteres, y si da 0 es que son iguales
            {
                cout<<"Este codigo ya esta registrado en otro usuario."<<endl;
                repeticion=true;// si las claves se repiten, repeticion cambia a true y se corta el programa
                break;
            }
            verificar>>codigo;
        }
        if(repeticion==false)// si se ingreso una nueva clave, se procede a la recoleccion de datos
        {
            cout<<"....DATOS A REGISTRAR...."<<endl;
            cout<<"Nombre: ";cin>>nombre;
            cout<<"Apellido: ";cin>>apellido;
            cout<<"Edad: ";cin>>edad;
            cout<<"Apodo: ";cin>>apodo;
            cout<<"Contrasenia: ";cin>>contrasenia;
            cout<<"Peso: ";cin>>peso;
            cout<<"Estatura: ";cin>>estatura;
            puntaje=0;
            info<<"\n"<<auxCodigo<<" "<<nombre<<" "<<apellido<<" "<<edad<<" "<<apodo<<" "<<contrasenia<<" "<<peso<<" "<<estatura<<" "<<puntaje<<"\n";// En "info se almacenan los datos, siguiendo el orden en el que se pidieron"
            cout<<"Su registro se ha completado. "<<endl;
            cout<<"__________________________________________"<<endl;
        }
    }
    info.close();
    verificar.close();// se cierran ambos archivos
    if (repeticion==false)
    {
        system("PAUSE");
        system("cls");
        Logueate();
    }
    if (repeticion==true)
    {
        system("PAUSE");
        system("cls");
        Reg_o_Log();
    }
}

void Menu::Logueate()
{
    cout<<"Logueate \n";
    ofstream info;
    ifstream verificar;//verifica si ya hay registros con los mismos datos
    repeticion=false;

    info.open("Registrados.txt",ios::out|ios::app);//se abre el archivo y con el ios::app sera capaz de aniadir informacion al archivo, sin perder datos
    verificar.open("Registrados.txt",ios::in);// se usa verificar para leer y comprobar la clave que se ingrese
    if(info.fail())// si no se abre el archivo, manda ese mensaje de error
    {
        cout<<"No se pudo abrir el archivo.";
        exit(1);
    }
    else if(verificar.is_open())// si ambos archivos se abren, sucede lo siguiente.
    {
        cout<<"Codigo: ";cin>>auxCodigo;
        cout<<"Contraseña: ";cin>>auxContrasenia;
        verificar>>codigo;//verificar, verifica la clave, si la hay
        while(!verificar.eof())//mientras no se llegue al final del archivo, pasa lo siguiente
        {
            verificar>>nombre>>apellido>>edad>>apodo>>contrasenia>>peso>>estatura>>puntaje;//lectura adelantada de lo demas
            if(auxCodigo=="191-10-46034" && auxContrasenia=="oyecomova")
            {
                administrador=true;
            }
            if(codigo==auxCodigo && contrasenia==auxContrasenia)// se comparan las claves almacenadas que fueron leidas con "verificar", con la auxClave que se ingreso, la funcion strcmp compara caracteres, y si da 0 es que son iguales
            {
                cout<<"Bienvenido "<<apodo<<endl;
                repeticion=true;// si las claves se repiten, repeticion cambia a true y se corta el programa
                logueado=true;
                break; //se rompe el ciclo
            }
            verificar>>codigo;
        }
        info.close();
        verificar.close();// se cierran ambos archivos
        if(repeticion==false)// si se ingreso una nueva clave, se procede a la recoleccion de datos
        {
            cout<<"Clave o Contrasenia es Incorrecta o no está Registrar"<<endl;
            Reg_o_Log();
        }
    }
}

int Menu::obtenerPuntaje()
{
    return puntaje;
}

void Menu::mostrarDatos()
{
    ifstream info;//archivo de lectura
    info.open("Registrados.txt",ios::out|ios::in);// se abre el archivo y se leera Prueba2

    if(info.fail())//mensaje de error
    {
        cout<<"El archivo no se pudo abrir.";
        exit(1);
    }

    else if(info.is_open()){// si "info" esta abierto:
            cout<<"Registro de usuarios de Personal Update \n"<<endl;
            cout<<"__________________________________________"<<endl;
        info>>codigo;//lectura adelantada comprueba que hay algo para seguir
        while(!info.eof())//mientras info no termine de leer el archivo
        {
            info>>nombre>>apellido>>edad>>apodo>>contrasenia>>peso>>estatura>>puntaje;

            cout<<"Codigo del usuario: "<<codigo<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Apellido: "<<apellido<<endl;
            cout<<"Edad: "<<edad<<endl;
            cout<<"Apodo: "<<apodo<<endl;
            cout<<"Peso: "<<peso<<endl;
            cout<<"Estatura: "<<estatura<<endl;
            cout<<"Puntaje: "<<puntaje<<endl;


            info>>codigo;//otra lectura adelantada
            cout<<"__________________________________________"<<endl;
        }
    }
    info.close();//se cierra el archivo
}

void Menu::Modificar()
{
    ofstream aux;// sera el archivo en el que vayamos a poner los nuevos datos
    ifstream lectura;// archivo que se usara de lectura
    encontrado=false;

    aux.open("Auxiliar.txt",ios::out);//de escritura
    lectura.open("Registrados.txt",ios::in);//de lectura
    if(lectura.fail() || aux.fail())//mensaje de error
    {
        cout<<"No se pudo abrir el archivo.";
        exit(1);
    }
    else if(aux.is_open() && lectura.is_open())//Si ambos archivos estan abiertos, pasa lo siguiente:
    {
        cout<<"Ingresa la Clave del alumno a modificar: ";cin>>auxCodigo;// se pide ingresar una clave
        lectura>>codigo;// lectura adelantada
        while(!lectura.eof())// Mientras no se llegue al final del archivo lectura:
        {
            lectura>>nombre>>apellido>>edad>>apodo>>contrasenia>>peso>>estatura>>puntaje;

            if(codigo==auxCodigo)//Si una clave del archivo lectura es igual a la ingresada
            {
                encontrado=true;
                cout<<"_______________________________"<<endl;// se muestran los datos del usuario encontrado
                cout<<"CODIGO DEL USUARIO: "<<codigo<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Apellido: "<<apellido<<endl;
                cout<<"Edad: "<<edad<<endl;
                cout<<"Apodo: "<<apodo<<endl;
                cout<<"Peso: "<<peso<<endl;
                cout<<"Estatura: "<<estatura<<endl;
                cout<<"Puntaje: "<<puntaje<<endl;
                cout<<"_______________________________"<<endl;

// se vuelve a pedir nuevos datos para su modificacion
                    cout<<"Ingresa la Nueva Codigo : ";cin>>auxCodigo;// auxclave se modifica por que ya se ha verificado que la clave anterior existe
                    cout<<"Ingresa el Nuevo Nombre : ";cin>>auxNombre;
                    cout<<"Ingresa el Nuevo Apellido: ";cin>>auxApellido;
                    cout<<"Ingresa la Nueva Edad: ";cin>>auxEdad;
                    cout<<"Ingresa la Nueva Apodo: ";cin>>auxApodo;
                    cout<<"Ingresa la Nueva Peso: ";cin>>auxPeso;
                    cout<<"Ingresa la Nueva Estatura: ";cin>>auxEstatura;

                    aux<<auxCodigo<<" "<<auxNombre<<" "<<auxApellido<<" "<<auxEdad<<" "<<auxApodo<<" "<<contrasenia<<" "<<auxPeso<<" "<<auxEstatura<<" "<<puntaje<<"\n";// en el archivo aux se guardan los nuevos datos
                    cout<<"Registro modificado. "<<endl;
            }
            else
            {
                aux<<codigo<<" "<<nombre<<" "<<apellido<<" "<<edad<<" "<<apodo<<" "<<contrasenia<<" "<<peso<<" "<<estatura<<" "<<puntaje<<"\n";// si no encuentra, manda lo leido a auxiliar
            }

            lectura>>codigo;//lectura adelantada
        }
    }
    if(encontrado==false)//si no se encontro la clave
    {
        cout<<"No hay usuarios registrados con la clave: "<<auxCodigo<<endl;
    }
    aux.close();
    lectura.close();// se cierran archivos
    remove("Registrados.txt");// se elimina el archivo Prueba2 y el archivo Auxiliar tendra como nuevo nombre Prueba2
    rename("Auxiliar.txt","Registrados.txt");
}

void Menu::Eliminar()
{
    ofstream aux;// sera el archivo en el que vayamos a poner los nuevos datos
    ifstream lectura;// sera un archivo en el que solo se leeran los datos antes de eliminar
    encontrado=false;

    aux.open("Auxiliar.txt",ios::out);//de escritura
    lectura.open("Registrados.txt",ios::in);//de lectura
    if(lectura.fail() || aux.fail())// mensaje de error
    {
        cout<<"No se pudo abrir el archivo.";
        exit(1);
    }
    else if(aux.is_open() && lectura.is_open())// si ambos archivos se abren pasa lo siguiente
    {
        cout<<"Ingresa el Código del usuario a Eliminar: ";cin>>auxCodigo;// en este caso no se pasara al nuevo archivo el alumno seleccionado
        lectura>>codigo;// lectura adelantada
        while(!lectura.eof())//mientras no se termine de leer el archivo:
        {
            lectura>>nombre>>apellido>>edad>>apodo>>contrasenia>>peso>>estatura>>puntaje;

            if(codigo==auxCodigo)// si la clave ingresada coincide con la clave de un usuario, muestra "usuario eliminado", y en el nuevo archivo se envian todos los usuarios menos el usuario seleccionado a traves de la clave
            {
                encontrado=true;
                    cout<<"Usuario Eliminado. "<<endl;

            }
            else
            {
                aux<<codigo<<" "<<nombre<<" "<<apellido<<" "<<edad<<" "<<apodo<<" "<<contrasenia<<" "<<peso<<" "<<estatura<<" "<<puntaje<<"\n";// si no encuentra, manda lo leido a auxiliar
            }

            lectura>>codigo;//lectura adelantada
        }
    }
    if(encontrado==false)//si no se encontro la clave
    {
        cout<<"No hay usuarios registrados con el codigo: "<<auxCodigo<<endl;
    }
    aux.close();
    lectura.close();//se cierran los archivos
    remove("Registrados.txt");//se remueve el archivo Prueba2
    rename("Auxiliar.txt","Registrados.txt");
}

void Menu::buscar()
{
    ifstream info;// info solo leera el archivo
    info.open("Registrados.txt",ios::out|ios::in);//se abre el archivo
    if(info.fail())//mensaje de error
    {
        cout<<"No se pudo abrir el archivo.";
        exit(1);
    }
    else if(info.is_open())// si el archivo se abre:
    {
        cout<<"Ingresa el Codigo del usuario que quieres buscar: ";
        cin>>auxCodigo;// se pide una clave para saber si ya hay una registrada en otro usuario
        info>>codigo; // lectura adelantada

        while(!info.eof())
            {
                info>>nombre>>apellido>>edad>>apodo>>contrasenia>>peso>>estatura>>puntaje;//leyendo info por grupo
                if(auxCodigo==codigo){//funcion que compara strings
                    cout<<"_______________________________"<<endl;// se muestran los datos del usuario encontrado
                    cout<<"CODIGO DEL USUARIO: "<<codigo<<endl;
                    cout<<"Nombre: "<<nombre<<endl;
                    cout<<"Apellido: "<<apellido<<endl;
                    cout<<"Edad: "<<edad<<endl;
                    cout<<"Apodo: "<<apodo<<endl;
                    cout<<"Peso: "<<peso<<endl;
                    cout<<"Estatura: "<<estatura<<endl;
                    cout<<"Puntaje: "<<puntaje<<endl;
                    cout<<"_______________________________"<<endl;
                    encontrado=true;//si entró, se volvio true
                    break;
                }
                info>>codigo;//lectura adelantada
            }


        if(encontrado==false)// si no encuntra similitud entre las claves, no podrá mostrar nada
            {
                cout<<"No hay registros con el Codigo ingresado: "<<auxCodigo<<endl;
            }
        info.close();//se cierra el archivo
    }
}

//void Menu::crearListas()
//{
//    ifstream lectura;// archivo que se usara de lectura
//
//    lectura.open("Registrados.txt",ios::out|ios::in);//de lectura
//    if(lectura.fail())//mensaje de error
//    {
//        cout<<"No se pudo abrir el archivo.";
//        exit(1);
//    }
//    else if(lectura.is_open())//Si ambos archivos estan abiertos, pasa lo siguiente:
//    {
//        lectura>>codigo;// lectura adelantada
//        while(!lectura.eof())// Mientras no se llegue al final del archivo lectura:
//        {
//            lectura>>nombre>>apellido>>edad>>apodo>>contrasenia>>peso>>estatura>>puntaje;
//            lCod+j=codigo;
//            *(lNom+j)=nombre;
//            *(lApell+j)=apellido;
//            *(lEd+j)=edad;
//            *(lApo+j)=apodo;
//            *(lContra+j)=contrasenia;
//            *(lPunt+j)=puntaje;
//            cout<<*(lCod+j)<<","<<*(lNom+j)<<","<<*(lApell+j)<<","<<*(lEd+j)<<","<<*(lApo+j)<<","<<*(lPunt+j)<<endl;
//            j++;
//            lectura>>codigo;//lectura adelantada
//        }
//    }
//    lectura.close();// se cierran archivos
//}
