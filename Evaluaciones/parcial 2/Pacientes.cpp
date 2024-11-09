#include<iostream>
#include<malloc.h>
using namespace std;

struct paciente
{
    int nuip, edad = 0;
    char nombre[10];
    paciente *izq, *der = NULL;
};

paciente *raiz;

int posicionar(paciente *r , paciente *a)
{
    if (a->edad < r->edad)
    {
        if(r->izq == NULL)
        {
            r->izq = a;
            return 0;
        }
        else
        {
            posicionar(r->izq,a);
        }
    }
    else
    {
        if (r->der == NULL)
        {
            r->der = a;
            return 0;
        }
        else
        {
            posicionar(r->der,a);
        }
        
    }
    return 0;    
}

void registrar()
{
    paciente *nodo = ((struct paciente *) malloc (sizeof(struct paciente)));
    nodo->izq = nodo->der = NULL;

    cout<<"ingrese el nombre del paciente: ";
    cin>>nodo->nombre;
    cout<<"ingrese el Documento del paciente: ";
    cin>>nodo->nuip;
    cout<<"ingrese la edad del paciente: ";
    cin>>nodo->edad;

    if(!raiz)
    {
        raiz = nodo;
        nodo = NULL;
        free(nodo);
    }else
    {
        posicionar(raiz,nodo);
    }
}

void mostrar(paciente *r)
{
        
    if(r->der != NULL)
    {
        mostrar(r->der);
    }
    cout<<r->nombre<<'\t'<<r->nuip<<'\t'<<r->edad<<endl;   

    if(r->izq != NULL)
    {
        mostrar(r->izq);

    }

}

int buscarP(paciente *a, int dato)
{
    
    if(a->nuip == dato)
    {
        cout<<"nombre: "<<a->nombre<<'\n'<<"NUIP: "<<a->nuip<<'\n'<<"Edad: "<<a->edad<<endl;
        return 0;
    }else
    {
        if(a->izq != NULL)
        {
            buscarP(a->izq,dato);            
        }
        if(a->der != NULL)
        {
            buscarP(a->der,dato);
        }
    }
    return 0;
}

void buscar()
{
    cout<<"ingrese el NUIP del paciente: ";
    int nuip;
    cin>>nuip;
    buscarP(raiz,nuip);

}

int main()
{
    int opcion = 0;
    do
    {
        cout<<'\t'<<"***menu***"<<endl;
        cout<<"1. registrar pacientes"<<endl;
        cout<<"2. mostrar pacientes"<<endl;
        cout<<"3. buscar pacientes"<<endl;
        cout<<"0. salir"<<endl;
        cin>>opcion;

        switch (opcion)
        {
            case 0:
                {cout<<'\t'<<"gracias"<<endl; return 0;}
                break;

            case 1:
                {registrar();}
                break;

            case 2:
                {cout<<"Nombre"<<'\t'<<"NUIP"<<'\t'<<"edad"<<endl;mostrar(raiz);}
                break;

            case 3:
                {buscar();}
                break;

            default:
                break;
        } 
   } while (opcion != 0);
}