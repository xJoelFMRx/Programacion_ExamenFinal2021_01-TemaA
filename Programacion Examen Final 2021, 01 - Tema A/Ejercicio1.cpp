    #include "pch.h"
    #include "iostream"
    #include "conio.h"

    using namespace System;
    using namespace std;

    int RandInt(int min, int max)
    {
        return rand() % (max - min + 1) + min;
    }

    int DigitosPerm[3] = { 0,2,5 };

    void GenerarValores(int* Mensaje, int N)
    {
        for (int i = 0; i < N; i++)
        {
            Mensaje[i] = DigitosPerm[RandInt(0, 2)];
        }
    }

    void ImprimirMensaje(int* Mensaje, int N)
    {
        cout << "Mensaje generado: " << endl;
        for (int i = 0; i < N; i++)
        {
            cout << Mensaje[i] << ' ';
        }
        cout << endl;
    }

    void PersonasFrio(int* Mensaje, int& ContAbrigo)
    {
        if (Mensaje[0] == 2 && Mensaje[1] == 5 && Mensaje[2] == 2)
        {
            ContAbrigo++;
            cout << "Las personas tienen frio" << endl;
        }
    }

    void PersonasCalor(int* Mensaje, int N, int& ContAgua)
    {
        for (int i = 0; i < N - 4; i++)
        {
            if (Mensaje[i] == 2 && Mensaje[i + 2] == 0 && Mensaje[i + 4] == 2)
            {
                ContAgua++;
                cout << "Las personas tienen calor" << endl;
                break;
            }
        }
    }

    void PersonasHambre(int* Mensaje, int N, int& ContAlimento)
    {
        if (Mensaje[N - 3] == 5 && Mensaje[N - 2] == 0 && Mensaje[N - 1] == 2)
        {
            ContAlimento++;
            cout << "Las personas tienen hambre" << endl;
        }
    }

    void Peligro(int* Mensaje, int N)
    {
        for (int i = 0; i < N - 2; i++)
        {
            if (Mensaje[i] == 0 && Mensaje[i + 1] == 0 && Mensaje[i + 2] == 0)
            {
                cout << "Peligro!" << endl;
                break;
            }
        }
    }

    void MostrarCantidades(int ContMensajesTotales, int ContAbrigo, int ContAlimento, int ContAgua)
    {
        cout << "\n\t\tREPORTE\n";
        cout << "================================================\n";
        cout << "Cantidad de mensajes procesados: " << ContMensajesTotales << endl;
        cout << "Cantidad de veces que se solicito abrigo: " << ContAbrigo << endl;
        cout << "Cantidad de veces que se solicito agua: " << ContAgua << endl;
        cout << "Cantidad de veces que se solicito alimento: " << ContAlimento << endl;
    }

    bool FinalizarBucle()
    {
        if (_kbhit())
        {
            char tecla = _getch();
            if (tecla == 'T' || tecla == 't')
            {
                return true;
            }
        }
        return false;
    }

    int main()
    {
        srand(time(nullptr));
        int ContMensajesTotales = 0;
        int ContAbrigo = 0;
        int ContAgua = 0;
        int ContAlimento = 0;
    
        while (true)
        {
            int N = RandInt(10, 20);
            int* Mensaje = new int[N];
            GenerarValores(Mensaje, N);
            ImprimirMensaje(Mensaje, N);
            PersonasFrio(Mensaje, ContAbrigo);
            PersonasCalor(Mensaje, N, ContAgua);
            PersonasHambre(Mensaje, N, ContAlimento);
            Peligro(Mensaje, N);
            ContMensajesTotales++;

            delete[] Mensaje;
            if (FinalizarBucle())
            {
                break;
            }
        }
        MostrarCantidades(ContMensajesTotales, ContAbrigo, ContAlimento, ContAgua);

        system("pause>0");
        return 0;
    }
