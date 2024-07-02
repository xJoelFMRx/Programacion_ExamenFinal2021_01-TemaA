#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int RandInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

struct Salidas
{
    int hora;
    int cantidad;
};

void Ventana()
{
    Console::SetWindowSize(120, 40);
    Console::CursorVisible = false;
}

void GenerarArreglo(Salidas* salida, int N)
{
    for (int i = 0; i < N; i++)
    {
        salida[i].hora = 5 + i;
        salida[i].cantidad = RandInt(5, 40);
    }
}

void ImprimirArreglo(Salidas* salida, int N)
{
    cout << "Hora:     ";
    for (int i = 0; i < N; i++)
    {
        cout << "\t" << salida[i].hora;
    }
    cout << endl;
    cout << "Cantidad: ";
    for (int i = 0; i < N; i++)
    {
        cout << "\t" << salida[i].cantidad;
    }
    cout << endl;
}

void HoraMayorSalidas(Salidas* salida, int N)
{
    Salidas mayor = salida[0];
    for (int i = 0; i < N; i++)
    {
        if (mayor.cantidad < salida[i].cantidad)
        {
            mayor.cantidad = salida[i].cantidad;
        }
    }
    cout << endl << "Horas con la mayor cantidad de salidas de buses: ";
    for (int i = 0; i < N; i++)
    {
        if (mayor.cantidad == salida[i].cantidad)
        {
            cout << salida[i].hora << ' ';
        }
    }
}

void PromedioDeSalidasMañana(Salidas* salida, int N)
{
    int ContSalidasMañana = 0;
    int SumaSalidasMañana = 0;
    double PromedioSalidasMañana = 0;

    for (int i = 0; i < N; i++)
    {
        if (salida[i].hora >= 5 && salida[i].hora <= 12)
        {
            ContSalidasMañana++;
            SumaSalidasMañana += salida[i].cantidad;
        }
    }
    if (ContSalidasMañana > 0)
    {
        PromedioSalidasMañana = (SumaSalidasMañana * 1.0) / ContSalidasMañana;
    }
    cout << endl << "Promedio de salidas de buses durante la mañana: " << PromedioSalidasMañana << endl << endl;
}

bool Comparar(Salidas salida1, Salidas salida2)
{
    if (salida1.cantidad < salida2.cantidad)
    {
        return true;
    }
    else if (salida1.cantidad == salida2.cantidad)
    {
        if (salida1.hora > salida2.hora)
        {
            return true;
        }
    }
    return false;
}

void OrdenarArreglo(Salidas* salida, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (Comparar(salida[i], salida[j]))
            {
                Salidas temp = salida[i];
                salida[i] = salida[j];
                salida[j] = temp;
            }
        }
    }
}

//Otra forma de entender el problema
//void OrdenarArregloBaseCantidad(Salidas* salida, int N)
//{
//    for (int i = 0; i < N - 1; i++)
//    {
//        for (int j = i + 1; j < N; j++)
//        {
//            if (salida[i].cantidad < salida[j].cantidad)
//            {
//                Salidas temp = salida[i];
//                salida[i] = salida[j];
//                salida[j] = temp;
//            }
//        }
//    }
//}

//Otra forma de entender el problema
//void OrdenarArregloBaseHora(Salidas* salida, int N)
//{
//    for (int i = 0; i < N - 1; i++)
//    {
//        for (int j = i + 1; j < N; j++)
//        {
//            if (salida[i].hora > salida[j].hora)
//            {
//                Salidas temp = salida[i];
//                salida[i] = salida[j];
//                salida[j] = temp;
//            }
//        }
//    }
//}

int main()
{
    srand(time(nullptr));
    int N = RandInt(10, 19);
    Salidas* salida = new Salidas[N];

    Ventana();
    GenerarArreglo(salida, N);
    ImprimirArreglo(salida, N);
    HoraMayorSalidas(salida, N);
    PromedioDeSalidasMañana(salida, N);
    OrdenarArreglo(salida, N);
    ImprimirArreglo(salida, N);
    /*OrdenarArregloBaseCantidad(salida, N);
    ImprimirArreglo(salida, N);*/
    /*cout << endl;
    OrdenarArregloBaseHora(salida, N);
    ImprimirArreglo(salida, N);*/

    delete[] salida;

    system("pause>0");
    return 0;
}