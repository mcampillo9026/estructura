#include <iostream>
#include<string.h>
#include<malloc.h>


using namespace std;

struct Contacto
{
    char nombre[10];
    char telefono[10];
    Contacto *siguiente;
};

Contacto *cabeza, *auxiliar, *auxiliar2;

void registrar()
{
    auxiliar = (struct Contacto *) malloc (sizeof(Contacto));
    cout<<"nombre: ";
    cin>>auxiliar->nombre;
    cout<<"telefono: ";
    cin>>auxiliar->telefono;
    auxiliar->siguiente = NULL;

    if (!cabeza)
    {
        cabeza = auxiliar;
    }else{

        auxiliar2 = cabeza;
        while (auxiliar2->siguiente != NULL)
        {
            auxiliar2 = auxiliar2->siguiente;
        }

        auxiliar2->siguiente = auxiliar;
        auxiliar = auxiliar2 = NULL;
        free(auxiliar);free(auxiliar2);      
        
    }
    
       
}

void mostrar()
{
    auxiliar = cabeza;
    while (auxiliar != NULL)
    {
        cout<<"nombre: "<<auxiliar->nombre<<endl;
        cout<<"telefono: "<<auxiliar->telefono<<endl;
        auxiliar = auxiliar->siguiente;
    }

}

int main()
{
    int opcion;
    do
    {
        cout<<'\t'<<"*****MENU*****"<<endl;
        cout<<"1. insertar Datos"<<'\n'<<"2. mostrar datos"<<'\n'<<"0. salir"<<'\n';
        cin>>opcion;

        switch (opcion)
        {
        case 1:{registrar();}
            break;
        
        case 2:{mostrar();}
            break;
        }
    } while (opcion != 0);

    return 0;
}



