#include "pch.h"
#include "iostream"
const int filasMatriz = 10;
const int columnasMatriz = 15;

using namespace System;
using namespace std;

int RandInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void GenerarValores(int M[][columnasMatriz])
{
    for (int i = 0; i < filasMatriz; i++)
    {
        for (int j = 0; j < columnasMatriz; j++)
        {
            M[i][j] = RandInt(1, 3);
        }
    }
}

void ImprimirValores(int M[][columnasMatriz])
{
    for (int i = 0; i < filasMatriz; i++)
    {
        for (int j = 0; j < columnasMatriz; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

void CultivoMayorYMenorFrecuencia(int M[][columnasMatriz])
{
    int contZ = 0;
    int contB = 0;
    int contN = 0;
    for (int i = 0; i < filasMatriz; i++)
    {
        for (int j = 0; j < columnasMatriz; j++)
        {
            switch (M[i][j])
            {
            case 1:
                contZ++;
                break;
            case 2:
                contB++;
                break;
            case 3:
                contN++;
                break;
            }
        }
    }
    int cultmenorfrec = min(contB, min(contZ, contN));
    int cultmayorfrec = max(contB, max(contZ, contN));
    cout << endl << "El/Los cultivo(s) que tiene(n) la mayor frecuencia es/son: " << endl;
    if (cultmayorfrec == contB) cout << "Berenjenas" << endl;
    if (cultmayorfrec == contZ) cout << "Zanahorias" << endl;
    if (cultmayorfrec == contN) cout << "Nabos" << endl;
    cout << endl;

    cout << endl << "El/Los cultivo(s) que tiene(n) la menor frecuencia es/son: " << endl;
    if (cultmenorfrec == contB) cout << "Berenjenas" << endl;
    if (cultmenorfrec == contZ) cout << "Zanahorias" << endl;
    if (cultmenorfrec == contN) cout << "Nabos" << endl;
    cout << endl;
}

void ExisteGuaridaTopo(int M[][columnasMatriz])
{
    for (int i = 1; i < filasMatriz - 1; i++)
    {
        for (int j = 1; j < columnasMatriz - 1; j++)
        {
            if (M[i - 1][j] == 3 && M[i + 1][j] == 1 && M[i][j - 1] == 2 && M[i][j + 1] == 2)
            {
                M[i][j] = 0;
                cout << endl << "SE ENCONTRO UNA GUARIDA DE TOPO..." << endl;
                cout << "Coordenadas: (" << i + 1 << ", " << j + 1 << ")" << endl;
                cout << endl;
            }
        }
    }
}

int main()
{
    srand(time(nullptr));
    int M[filasMatriz][columnasMatriz];

    GenerarValores(M);
    ImprimirValores(M);
    CultivoMayorYMenorFrecuencia(M);
    ExisteGuaridaTopo(M);
    ImprimirValores(M);

    system("pause>0");
    return 0;
}