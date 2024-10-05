#include <iostream>

using namespace std;

struct pasajeros 
{
    char nombre[10];
    unsigned int documento;
    int destino;
    pasajeros *siguiente;
};

pasajeros *cabeza, *auxiliar, *auxiliar2;

void registrar()
{
    auxiliar = (struct pasajeros *) malloc (sizeof(pasajeros));

    cout<<"Ingrese el nombre del Pasajero: ";
    cin>>auxiliar->nombre;
    cout<<"Ingrese el Documento del Pasajero: ";
    cin>>auxiliar->documento;
    cout<<"Destinos del pasajero es:"<<'\n';
    cout<<'\t'<<"si es la Bocana marque 1 "<<'\n'<<'\t'<<"si es pianguita marque 2"<<'\n'<<'\t'<<"si es ladrillero marque 3"<<endl;
    cin>>auxiliar->destino;
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

void mostrar(){}

void ordenar(){}

int main()
{
    int opcion;
    do
    {
        cout<<'\t'<<"*****MENU*****"<<endl;
        cout<<"1. Ingresar Pasajero"<<'\n'<<"2. Mostrar lsita de  Pasajeros"<<'\n'<<"3. Ordenar lsita de Pasajeros"<<endl;
        cout<<"0. salir"<<endl;
        cin>>opcion;

        switch (opcion)
        {
        case 1:{registrar();}
            break;
        
        case 2:{mostrar();}
            break;

        case 3:{ordenar();}
            break;
        }

    } while (opcion != 0);
        
}