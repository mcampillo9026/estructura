#include<iostream>
#include<malloc.h>
using namespace std;

struct paciente
{
    int nuip, edad = 0;
    char nombre[10];
    paciente *izq, *der = NULL;
};

paciente *raiz, *aux, *padre;

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

void mostrarP(paciente *r)
{        
    if(r->der != NULL)
    {
        mostrarP(r->der);
    }
    cout<<r->nombre<<'\t'<<r->nuip<<'\t'<<r->edad<<endl;   

    if(r->izq != NULL)
    {
        mostrarP(r->izq);
    }
}

void mostrar()
{
    if(!raiz)
    {
        cout<<"no hay pacientes registrados"<<endl;
    }
    else
    {
        cout<<"Nombre"<<'\t'<<"NUIP"<<'\t'<<"edad"<<endl;mostrarP(raiz);
    }
}

int buscarPaciente(paciente *a, int dato)
{
    
    if(a->nuip == dato)
    {
        aux = a;
        return 0;
    }else
    {
        if(a->izq != NULL)
        {
            buscarPaciente(a->izq,dato);            
        }
        if(a->der != NULL)
        {
            buscarPaciente(a->der,dato);
        }
    }
    return 0;
}

void buscar()
{
    if(raiz)
    {
        cout<<"ingrese el NUIP del paciente: ";
        int nuip;
        cin>>nuip;
        buscarPaciente(raiz,nuip);
        if(aux)
        {
            cout<<"nombre: "<<aux->nombre<<'\n'<<"NUIP: "<<aux->nuip<<'\n'<<"Edad: "<<aux->edad<<endl;
        }else
        {
            cout<<"el paciente no existe"<<endl;
        }
    }else
    {
        cout<<"no hay pacientes registrados"<<endl;
    }  
}

int buscarHijos()
{
    if((aux->der == NULL) && (aux->izq == NULL))
    {
        return 0;
    }else
    {
        if((aux->der == NULL) || (aux->izq == NULL))
        {
            return 1;
        }else
        {
            return 2;
        }
    }
}

void buscarPadre(paciente *r)
{
    padre = NULL;
    if(r == aux)
    {
        padre = NULL;
    }else
    {
        if((r->der == aux) || (r->izq == aux))
        {
            padre = r;
        }else
        {
            if(r->izq != NULL)
            {
                buscarPadre(r->izq);
            }

            if(r->der != NULL)
            {
                buscarPadre(r->der);
            }
        }        
    }
}

void eliminarPaciente()
{
    buscar();
    int hijos = buscarHijos();
    buscarPadre(raiz);
    if(!((aux == NULL) || (padre == NULL)))
    {   
        if(hijos == 0)
        {
            if(padre->der == aux)
            {
                padre->der = NULL;
            }else
            {
                padre->izq = NULL;
            }
        }
        aux = NULL; free(aux);
    }
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
        cout<<"4. eliminar pacientes"<<endl;
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
                {mostrar();}
                break;

            case 3:
                {buscar();}
                break;

            case 4:
                {eliminarPaciente();}
                break;

            default:
                break;
        } 
   } while (opcion != 0);
}