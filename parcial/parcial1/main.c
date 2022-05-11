#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "notebooks.h"

#define TAM_NOT 2000
#define TAM_MARCAS 4
#define TAM_TIPOS 4
#define TAM_SERVICIOS 4
#define TAM_TRAB 2000


int main()
{
    eMarca marca[TAM_MARCAS] =
    {
        {1000, "Asus"},
        {1001, "Acer"},
        {1002, "Compaq"},
        {1003, "HP"}
    };
    eTipo tipos[TAM_TIPOS] =
    {
        {5000, "Disenio"},
        {5001, "Gamer"},
        {5002, "Normalita"},
        {5003, "Ultrabook"}
    };
    eServicio servicios[TAM_SERVICIOS] =
    {
        {20000, "Bateria", 2250},
        {20001, "Display", 10300},
        {20002, "Mantenimiento", 4400},
        {20003, "Fuente", 5600}
    };
    eNotebook listaN[TAM_NOT];
    eTrabajo listaT[TAM_TRAB];
    char eleccion;    int opcion;

    int idNotebook = 30000;
    int idTrabajos = 200000;

    inicializarNotebooks(listaN, TAM_NOT);
    inicializarTrabajos(listaT, TAM_TRAB);
    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            printf("Ingreso a alta notebook\n\n");
            altaNotebook(listaN, &idNotebook, TAM_NOT);
            break;
        case 2:
            listarNotebooks(listaN, TAM_NOT, tipos, TAM_TIPOS, marca, TAM_MARCAS);
            printf("Ingreso a modificar notebook\n\n");
            opcion = subMenuModificar();
            modificar(listaN, opcion, TAM_NOT);
            break;
        case 3:
            listarNotebooks(listaN, TAM_NOT, tipos, TAM_TIPOS, marca, TAM_MARCAS);
            printf("Ingreso a baja notebook\n\n");
            bajaNotebook(listaN, TAM_NOT);
            break;
        case 4:
            printf("\nIngreso a listar notebook por marca y precio\n\n");
            listarNotebooksMarcaPrecio(listaN, TAM_NOT, tipos, TAM_TIPOS, marca, TAM_MARCAS);
            listarNotebooks(listaN, TAM_NOT, tipos, TAM_TIPOS, marca, TAM_MARCAS);
            break;
        case 5:
            printf("\nIngreso a listar marcas\n\n");
            listarMarcas(marca, TAM_MARCAS);
            break;
        case 6:
            printf("\nIngreso a listar tipos\n\n");
            listarTipos(tipos, TAM_TIPOS);
            break;
        case 7:
            printf("\nIngreso a listar servicios\n\n");
            listarServicios(servicios, TAM_SERVICIOS);
            break;
        case 8:
            printf("Ingreso a alta trabajo\n\n");
            altaTrabajo(listaT, &idTrabajos, TAM_TRAB);
            break;
        case 9:
            printf("Ingreso a listar trabajos\n\n");
            break;
        case 10:
            printf("\nIngreso a \"SALIR\"");
            confirmaSalida(&eleccion);
            break;
        }
        system("pause");
    }
    while(eleccion != 'S');
    return 0;
}
