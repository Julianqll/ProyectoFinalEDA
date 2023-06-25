
#pragma once
#include<iostream>
#include "ventanaEstudianteInicio.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


class VentanaMain{
public:
    VentanaMain(){

    }
    bool iniciarSesion(const std::string& nombreUsuario, const std::string& contraseña) {
        std::ifstream archivo("../db/users.txt");  // Abre el archivo en modo lectura

        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo." << std::endl;
            return false;
        }

        std::string linea;
        while (std::getline(archivo, linea)) {  // Lee una línea del archivo
            // Extrae el nombre de usuario y la contraseña de la línea
            std::istringstream iss(linea);
            std::string usuario;
            std::string clave;
            iss >> usuario >> clave;

            // Compara el nombre de usuario y la contraseña con los datos proporcionados
            if (usuario == nombreUsuario && clave == contraseña) {
                archivo.close();  // Cierra el archivo
                return true;  // Inicio de sesión exitoso
            }
        }

        archivo.close();  // Cierra el archivo

        return false;  // Inicio de sesión fallido
    }

    bool iniciarSesionUsuario() {
        std::string nombreUsuario;
        std::string contraseña;

        std::cout << "Ingrese su nombre de usuario: ";
        std::cin >> nombreUsuario;

        std::cout << "Ingrese su contraseña: ";
        std::cin >> contraseña;

        if (iniciarSesion(nombreUsuario, contraseña)) {
            std::cout << "Inicio de sesión exitoso." << std::endl;
            return true;
        }
        std::cout << "Inicio de sesión fallido. Verifique sus credenciales." << std::endl;
        return false;
    }
    void registrarUsuario() {
        std::string nombreUsuario;
        std::string contraseña;

        std::cout << "Ingrese un nombre de usuario: ";
        std::cin >> nombreUsuario;

        std::cout << "Ingrese una contraseña: ";
        std::cin >> contraseña;

        std::ofstream archivo("../db/users.txt", std::ios::app); // Abre el archivo en modo adjuntar

        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo." << std::endl;
            return;
        }

        // Registrar al nuevo usuario
        archivo << nombreUsuario << " " << contraseña << std::endl;
        archivo.close();

        std::cout << "Registro exitoso. El usuario ha sido registrado correctamente." << std::endl;
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
                if (!iniciarSesionUsuario()) {
                    break;
                }
                VentanaEstudianteInicio ventanaEstudiante;
                ventanaEstudiante.Inicio();
            }
            case 2:
                // Aquí puedes agregar la lógica para el registro de usuarios
                cout << "Has seleccionado 'Registrarse'." << endl;
                registrarUsuario();
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