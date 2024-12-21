#include <iostream>
#include <algorithm> // Para usar std::max
using namespace std;

struct nodo {
    nodo *izq;
    int valor;
    int altura;
    nodo *der;
};

nodo *raiz = NULL;

// Funciones auxiliares
int altura(nodo *n) {
    return n ? n->altura : 0;
}

int calcularEquilibrio(nodo *n) {
    return n ? altura(n->izq) - altura(n->der) : 0;
}

nodo *rotacionDerecha(nodo *y) {
    nodo *x = y->izq;
    nodo *T2 = x->der;

    x->der = y;
    y->izq = T2;

    y->altura = 1 + max(altura(y->izq), altura(y->der));
    x->altura = 1 + max(altura(x->izq), altura(x->der));

    return x;
}

nodo *rotacionIzquierda(nodo *x) {
    nodo *y = x->der;
    nodo *T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = 1 + max(altura(x->izq), altura(x->der));
    y->altura = 1 + max(altura(y->izq), altura(y->der));

    return y;
}

nodo *balancear(nodo *n) {
    int equilibrio = calcularEquilibrio(n);

    if (equilibrio > 1 && calcularEquilibrio(n->izq) >= 0)
        return rotacionDerecha(n);

    if (equilibrio > 1 && calcularEquilibrio(n->izq) < 0) {
        n->izq = rotacionIzquierda(n->izq);
        return rotacionDerecha(n);
    }

    if (equilibrio < -1 && calcularEquilibrio(n->der) <= 0)
        return rotacionIzquierda(n);

    if (equilibrio < -1 && calcularEquilibrio(n->der) > 0) {
        n->der = rotacionDerecha(n->der);
        return rotacionIzquierda(n);
    }

    return n;
}

nodo *insertarNodo(nodo *n, int valor) {
    if (!n) 
    {
        nodo *nuevo = ((struct nodo *) malloc (sizeof(struct nodo)));
        nuevo->valor = valor;
        nuevo->altura = 1;
        return nuevo;
    }

    if (valor > n->valor)
    {
        n->izq = insertarNodo(n->izq, valor);
    }        
    else if (valor < n->valor)
    {
        n->der = insertarNodo(n->der, valor);
    }        
    else
        return n; // Evitar duplicados

    n->altura = 1 + max(altura(n->izq), altura(n->der));

    return balancear(n);
}

nodo *minimoValorNodo(nodo *n) {
    nodo *actual = n;
    while (actual->izq)
        actual = actual->izq;
    return actual;
}

nodo *eliminarNodo(nodo *raiz, int valor) {
    if (!raiz)
        return raiz;

    if (valor > raiz->valor)
        raiz->izq = eliminarNodo(raiz->izq, valor);
    else if (valor < raiz->valor)
        raiz->der = eliminarNodo(raiz->der, valor);
    else {
        if (!raiz->izq || !raiz->der) {
            nodo *temp = raiz->izq ? raiz->izq : raiz->der;
            if (!temp) {
                temp = raiz;
                raiz = NULL;free(raiz);
            } else
                *raiz = *temp;
            temp = NULL; free(temp);
        } else {
            nodo *temp = minimoValorNodo(raiz->der);
            raiz->valor = temp->valor;
            raiz->der = eliminarNodo(raiz->der, temp->valor);
        }
    }

    if (!raiz)
        return raiz;

    raiz->altura = 1 + max(altura(raiz->izq), altura(raiz->der));

    return balancear(raiz);
}

void mostrarArbol(nodo *n, string prefijo = "", bool esIzquierdo = true) {
    if (n) {
        cout << prefijo;
        cout << (esIzquierdo ? "├──" : "└──");
        cout << n->valor << endl;

        mostrarArbol(n->izq, prefijo + (esIzquierdo ? "│   " : "    "), true);
        mostrarArbol(n->der, prefijo + (esIzquierdo ? "│   " : "    "), false);
    }
}

// End Funciones auxiliares

void registrar()
{
    int valor;
    cout<<"Digite el valor del nodo: ";
    cin>>valor;
    raiz = insertarNodo(raiz, valor);
    cout<<"Nodo insertado y balanceado correctamente." << endl;

}

void mostrar()
{
    if(raiz)
    {
        mostrarArbol(raiz);
    }else
    {
        cout<<"no hay nodos registrados"<<endl;
    }
}

void eliminar()
{
    int valor;
    cout << "Digite el valor del nodo a eliminar: ";
    cin >> valor;
    raiz = eliminarNodo(raiz, valor);
    cout << "Nodo eliminado y arbol balanceado." << endl;

}




int main()
{
    int opcion;
    do {
        cout<<'\t'<<"***menu***"<<endl;
        cout<<"1. Insertar un nodo"<<endl;
        cout<<"2. Mostrar el árbo"<<endl;
        cout<<"3. Eliminar un nodo"<<endl;
        cout<<"0. Salir del programa"<<endl;
        cin>>opcion;

        switch (opcion) {

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
                {eliminar();}
                break;

            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
        }
    } while (opcion != 0);

    return 0;
}