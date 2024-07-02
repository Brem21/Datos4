#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define REGISTRAR_FUNCION(nombre) { \
    FILE *archivo = fopen("funciones.txt", "a"); \
    if (archivo != NULL) { \
        fprintf(archivo, #nombre "\n"); \
        fclose(archivo); \
    } \
}

int main(int argc, char *argv[]) {
    char clientes[5][2][40] = { {"Juan", "1789654123"}, {"", ""}, {"", ""}, {"", ""}, {"", ""} };
    char habitaciones[9][3][40] = { {"1", "simple", "Dan Carlton"}, {"2", "doble", "Dan Carlton"}, {"3", "triple", "Dan Carlton"},
                                    {"4", "simple", "Swissotel"}, {"5", "doble", "Swissotel"}, {"6", "triple", "Swissotel"},
                                    {"7", "simple", "Sheraton"}, {"8", "doble", "Sheraton"}, {"9", "triple", "Sheraton"} };
    double precios[9] = { 90, 120, 160, 65, 100, 140, 85, 110, 150 };
    int reservas[10][4] = { {-1, -1, -1, 0}, {-1, -1, -1, 0}, {-1, -1, -1, 0}, {-1, -1, -1, 0}, {-1, -1, -1, 0},
                            {-1, -1, -1, 0}, {-1, -1, -1, 0}, {-1, -1, -1, 0}, {-1, -1, -1, 0}, {-1, -1, -1, 0} };

    cargarDatos(habitaciones, clientes, reservas, precios); // Cargar datos al inicio

    int opcion, numHabitacion, numReserva;
    FILE *archivo = fopen("funciones.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo!\n");
        return 1;
    }

    REGISTRAR_FUNCION(main)
    fclose(archivo); // Cerrar el archivo después de registrar la función main

    do {
        printf("Escoja una opcion:\n 1.Buscar Habitacion\n 2.Realizar reserva\n 3.Ver reservas\n 4.Pagar Reserva\n>>");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("1.Por tamaño\n2.Por Hotel\n>>");
                scanf("%d", &opcion);
                switch (opcion) {
                    case 1:
                        buscarPorTamano(&numHabitacion, habitaciones, precios);
                        break;
                    case 2:
                        buscarHotel(&numHabitacion, habitaciones, precios);
                    default:
                        break;
                }
                break;
            case 2:
                realizarReserva(numHabitacion, habitaciones, clientes, reservas, precios);
                guardarDatos(habitaciones, clientes, reservas, precios);
                REGISTRAR_FUNCION(realizarReserva)
                break;
            case 3:
                buscarReservaPorCedula(&numReserva, clientes, reservas);
                imprimirReserva(numReserva, reservas, habitaciones, precios);
                break;
            case 4:
                buscarReservaPorCedula(&numReserva, clientes, reservas);
                pagarReserva(numReserva, reservas, habitaciones, precios);
                guardarDatos(habitaciones, clientes, reservas, precios);
                REGISTRAR_FUNCION(pagarReserva)
                break;
            default:
                break;
        }
        printf("Desea elegir otra opcion\n>>");
        scanf("%d", &opcion);
    } while (opcion == 1);

    return 0;
}






