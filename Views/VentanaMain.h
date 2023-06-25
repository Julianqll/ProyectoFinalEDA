
#pragma once
#include<iostream>
#include "ventanaEstudianteInicio.h"
using namespace std;


class VentanaMain{
public:
    VentanaMain(){

    }


    void iniciar()
    {
        system("cls");

        cout << "=============================" << endl;
        cout << "      AGENDA ESTUDIANTIL      " << endl;
        cout << "=============================" << endl;
        // Mostrar las opciones
        cout << "1. Iniciar sesión" << endl;
        cout << "2. Registrarse" << endl;
        cout << "3. Salir" << endl;

        // Obtener la opción seleccionada
        int opcion;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        // Procesar la opción seleccionada
        switch (opcion) {
            case 1:{
                // Aquí puedes agregar la lógica para el inicio de sesión
                cout << "Has seleccionado 'Iniciar sesión'." << endl;
                VentanaEstudianteInicio ventanaEstudiante;
                ventanaEstudiante.Inicio();
                break;
            }
            case 2:
                // Aquí puedes agregar la lógica para el registro de usuarios
                cout << "Has seleccionado 'Registrarse'." << endl;
                break;
            case 3:
                cout << "Gracias por utilizar nuestro sistema. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, selecciona una opción válida." << endl;
                break;
        }

    }
};