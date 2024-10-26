#include<iostream>
#include<malloc.h>

using namespace std;

struct motos
{
    char placa[6];
    int valor;
    motos *siguiente;
};

struct carros
{
    char placa[6];
    int valor;
    carros *siguiente;
};

carros *carTop, *carAux, *carTop2;
motos *motoTop, *motoAux, *motoTop2;

bool compararPlaca(char p1[6], char p2[6])
{
    for (int i = 0; i < 6; i++)
    {
        if (!(p1[i] == p2[i]))
        {
            return false;
        }
        
    }

    return true;
}

void registrarVehiculo()
{
    carAux = (struct carros *) malloc (sizeof(struct carros));
    cout<<"ingrese la placa del vehiculo"<<endl;
    cin>>carAux->placa;
    carAux->valor = 2000;
    if(!carTop)
    {
        carTop = carAux;
        carTop->siguiente = NULL;
        cout<<"placa registrada"<<endl;
    }else
    {      
        carAux->siguiente = carTop;
        carTop = carAux;
        cout<<"placa registrada"<<endl;
    }

    carAux = NULL; free(carAux);
    
    
}

void mostarVehiculos()
{
    int item = 1;
    if(!carTop)
    {
        cout<<"no hay vehiculos en el parqueadero"<<endl;
    }else
    {
        cout<<"item"<<'\t'<<"Placa"<<'\t'<<"saldo"<<endl;
        while (carTop != NULL)
        {
            cout<<item<<'\t'<<carTop->placa<<'\t'<<carTop->valor<<endl;

            if(carTop2 == NULL)
            {
                carTop2 = carTop;
                carTop = carTop->siguiente;
                carTop2->siguiente = NULL;
                item++;
            }else
            {
                carAux = carTop;
                carTop = carTop->siguiente;
                carAux->siguiente = carTop2;
                carTop2 = carAux;
                carAux = NULL;free(carAux);
                item++;
            }
        }
        while (carTop2 != NULL)
        {
            if(carTop == NULL)
            {
                carTop = carTop2;
                carTop2 = carTop2->siguiente;
                carTop->siguiente = NULL;
            }else
            {
                carAux = carTop2;
                carTop2 = carTop2->siguiente;
                carAux->siguiente = carTop;
                carTop = carAux;
                carAux = NULL; free(carAux);
            }
        }
        
    }

}

void retirarVehiculo()
{
    char valor[6];
    int movimiento = 200;

    if (!carTop)
    {
        cout<<"el parqueadero está vacio"<<endl;
        
    }else
    {
        cout<<"ingresar placa del vehiculo a retirar"<<endl;
        cin>>valor;
        while (carTop != NULL)
        {
            if(compararPlaca(valor,carTop->placa))
            {
                carAux = carTop;
                cout<<"el vehiculo que va de salida es: "<<carAux->placa<<endl;
                cout<<"debe: "<<carAux->valor + 100<<endl;
                carTop = carTop->siguiente;
                movimiento = 0;
                carAux = NULL;free(carAux);
            }else
            {
                if(carTop2 == NULL)
                {
                    carTop2 = carTop;
                    carTop2->valor += movimiento;
                    carTop = carTop->siguiente;
                    carTop2->siguiente= NULL;
                }else
                {
                    carAux = carTop;
                    carTop = carTop->siguiente;
                    carAux->valor += movimiento;
                    carAux->siguiente = carTop2;
                    carTop2 = carAux;
                    carAux = NULL;free(carAux);
                }
            }
        }

        while (carTop2 != NULL)
        {
            if (carTop == NULL)
            {
                carTop = carTop2;
                carTop2 = carTop2->siguiente;
                carTop->siguiente = NULL;                
            }else
            {
                carAux = carTop2;
                carTop2 = carTop2->siguiente;
                carAux->siguiente = carTop;
                carTop = carAux;
                carAux = NULL;free(carAux);
            }
            
        }
        
        
    }
    
    
}

void registrarMoto()
{
    motoAux =  (struct motos *) malloc (sizeof(struct motos));
    cout<<"ingrese la placa de la motocicleta"<<endl;
    cin>>motoAux->placa;
    motoAux->valor = 1000;

   if(!motoTop)
    {
        motoTop = motoAux;
        motoTop->siguiente = NULL;
    }else
    {

        motoAux->siguiente = motoTop;
        motoTop = motoAux;
    }
    
    
}

void mostarMotos()
{
    int item = 1;
    if (!motoTop)
    {
        cout<<"no hay motocicletas en el parqueadero"<<endl;
    }else
    {
        cout<<"item"<<'\t'<<"Placa"<<'\t'<<"saldo"<<endl;
        while (motoTop != NULL)
        {
            cout<<item<<'\t'<<motoTop->placa<<'\t'<<motoTop->valor<<endl;
            if(motoTop2 == NULL)
            {
                motoTop2 = motoTop;
                motoTop = motoTop->siguiente;
                motoTop2->siguiente = NULL;
                item++;
            }else
            {
                motoAux = motoTop;
                motoTop = motoTop->siguiente;
                motoAux->siguiente = motoTop2;
                motoTop2 = motoAux;
                motoAux = NULL;free(motoAux);
                item++;
            }
            
        }

        while (motoTop2 != NULL)
        {
            if(motoTop == NULL)
            {
                motoTop = motoTop2;
                motoTop2 = motoTop2->siguiente;
                motoTop->siguiente= NULL;
            }else
            {
                motoAux = motoTop2;
                motoTop2 = motoTop2->siguiente;
                motoAux->siguiente = motoTop;
                motoTop = motoAux;
                motoAux= NULL;free(motoAux);
            }
        }
        
        
    }   

}

void retirarMoto()
{
    char valor[6];
    int movimiento = 200;

    if (!motoTop)
    {
        cout<<"el parqueadero está vacio"<<endl;
        
    }else
    {
        cout<<"ingresar placa de la moto a retirar"<<endl;
        cin>>valor;
        while (motoTop != NULL)
        {
            if(compararPlaca(valor,motoTop->placa))
            {
                motoAux = motoTop;
                cout<<"el vehiculo que va de salida es: "<<motoAux->placa<<endl;
                cout<<"debe: "<<motoAux->valor + 100<<endl;
                motoTop = motoTop->siguiente;
                movimiento = 0;
                motoAux = NULL;free(motoAux);
            }else
            {
                if(motoTop2 == NULL)
                {
                    motoTop2 = motoTop;
                    motoTop2->valor += movimiento;
                    motoTop = motoTop->siguiente;
                    motoTop2->siguiente= NULL;
                }else
                {
                    motoAux = motoTop;
                    motoTop = motoTop->siguiente;
                    motoAux->valor += movimiento;
                    motoAux->siguiente = motoTop2;
                    motoTop2 = motoAux;
                    motoAux = NULL;free(motoAux);
                }
            }
        }

        while (motoTop2 != NULL)
        {
            if (motoTop == NULL)
            {
                motoTop = motoTop2;
                motoTop2 = motoTop2->siguiente;
                motoTop->siguiente = NULL;                
            }else
            {
                motoAux = motoTop2;
                motoTop2 = motoTop2->siguiente;
                motoAux->siguiente = motoTop;
                motoTop = motoAux;
                motoAux = NULL;free(motoAux);
            }
            
        }
        
        
    }
}

int main()
{
    int opcion = 0;
    do{
        cout<<'\t'<<"**menu**"<<'\n'<<"1. ingrear vehiculo"<<'\n'<<"2. ingresar moto"<<'\n'<<"3. Mostrar parqueadero de vehiculos"<<'\n';
        cout<<"4. Mostrar parqueadero de Motos"<<'\n'<<"5. Retirar Vehiculo"<<'\n'<<"6. Retirar Motos"<<'\n';
        cout<<"0. salir"<<endl;
        cin>>opcion;

        switch (opcion)
        {
            case 0:{cout<<"***gracias***"<<endl;}
                break;

            case 1:{registrarVehiculo();}
                break;

            case 2:{registrarMoto();}
                break;

            case 3:{mostarVehiculos();}
                break;

            case 4:{mostarMotos();}
                break;

            case 5:{retirarVehiculo();}
                break;

            case 6:{retirarMoto();}
                break;
            
            default:
                break;
        }
    }while (opcion != 0);
    
    
    return 0;
}