#include <iostream>
#include<malloc.h>

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

void mostrar()
{
    auxiliar = cabeza;
    int item = 0;
    if(cabeza != NULL)
    {
        cout<<"item"<<'\t'<<"Documentos"<<'\t'<<"Nombre"<<'\t'<<"Destino"<<endl;
        while (auxiliar != NULL)
        {
            item++;
            cout<<item<<'\t';
            cout<<auxiliar->documento<<'\t'<<'\t';
            cout<<auxiliar->nombre<<'\t';
            cout<<auxiliar->destino<<endl;
            auxiliar = auxiliar->siguiente;
        }
        auxiliar = NULL; free(auxiliar);
    }else{cout<<"la lista esta vacia"<<endl;}

}

void ordenar()
{
    if(cabeza != NULL)
    {
        int tmpDestino = 0;
        int tmpDocumento = 0;
        char tmpNombre[10];
        auxiliar2 = cabeza;
        while (auxiliar2 != NULL)
        {
            auxiliar = cabeza;
            while(auxiliar->siguiente != NULL)
            {
                if(auxiliar->destino > auxiliar->siguiente->destino)
                {
                    tmpDestino = auxiliar->destino;
                    tmpDocumento = auxiliar->documento;
                    for(int x = 0; x < 10; x++){tmpNombre[x] = auxiliar->nombre[x];}  
                    

                    auxiliar->destino = auxiliar->siguiente->destino;
                    for(int x = 0; x<10; x++){auxiliar->nombre[x] = auxiliar->siguiente->nombre[x];} 
                    auxiliar->documento = auxiliar->siguiente->documento;


                    auxiliar->siguiente->destino = tmpDestino;                  
                    for(int x = 0; x < 10; x++){auxiliar->siguiente->nombre[x] = tmpNombre[x];} 
                    auxiliar->siguiente->documento = tmpDocumento;
                }

                auxiliar = auxiliar->siguiente;
            }
            auxiliar2 = auxiliar2->siguiente;
        }

        auxiliar = auxiliar2 = NULL;free(auxiliar);free(auxiliar2);
        

    }else{cout<<"la lista esta vacia"<<endl;}
}

int main()
{
    int opcion;
    do
    {
        cout<<'\t'<<"*****MENU*****"<<endl;
        cout<<"1. Ingresar Pasajero"<<'\n'<<"2. Mostrar lista de  Pasajeros"<<'\n'<<"3. Ordenar lista de Pasajeros"<<endl;
        cout<<"0. salir"<<endl;
        cin>>opcion;

        switch (opcion)
        {
        case 1:{registrar();}
            break;
        
        case 2:{mostrar();}
            break;

        case 3:{ordenar();mostrar();}
            break;
        }

    } while (opcion != 0);
        
}