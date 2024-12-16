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