#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "notebooks.h"

int confirmaSalida(char* eleccion)
{
    int todoOk = 0;
    char auxSalida;

    if(eleccion)
    {
        do
        {
            system("cls");
            printf(" ______________________________________ \n");
            printf("|   Ha ingresado a la opcion SALIR     |\n");
            printf("|______________________________________|\n\n");
            printf("Esta seguro que desea salir?\n");
            printf("Ingrese una letra, \"s\" para si: ");
            fflush(stdin);
            scanf("%c", &auxSalida);
            auxSalida = toupper(auxSalida);

        }
        while(!isalpha(auxSalida));
        *eleccion = auxSalida;
        todoOk = 1;
    }
    return todoOk;
}

int validarGets(int tam, char auxCad[100])
{
    int validacion = 0;
    if(tam > 0 && auxCad)
    {
        if(strlen(auxCad) < tam)
        {
            validacion = 1;
        }
    }
    return validacion;
}

int menu()
{
    int opcion;

    system("cls");
    printf("       *** Menu Principal ***         \n\n");
    printf("  1) Darle de alta a la notebook         \n");
    printf("  2) Modificar notebook                \n");
    printf("  3) Darle de baja a la notebook         \n");
    printf("  4) Listar notebook por marca y precio \n");
    printf("  5) Listar marcas\n");
    printf("  6) Listar tipos \n");
    printf("  7) Listar servicios \n");
    printf("  8) Alta trabajo \n");
    printf("  9) Listar trabajos\n");
    printf(" 10) Salir\n\n");

    printf("Ingrese opcion: ");
    fflush(stdin); // Limpio el buff porque si en algun otro menu ingresan un numero seguido de enter, da como erroneo
    scanf("%d", &opcion);

    while(opcion < 1 || opcion > 10 || isalpha(opcion))
    {
        fflush(stdin);      //Limpio el buff de entrada para que en el caso de que arriba ingresen una letra no se rompa el progama
        printf("Se ingreso una opcion erronea, ingrese la opcion nuevamente: ");
        scanf("%d", &opcion);
    }
    return opcion;
}


int altaNotebook(eNotebook* lista, int* pId, int tam)
{
    int todoOk = 0;
    char auxModelo[21];
    int auxIdMarca;
    int auxIdTipo;
    float auxPrecio;
    int i;

    if(lista && pId && tam>0)
    {
        if(buscarPosicionLibre(lista, tam, &i))
        {
            lista[i].id = *pId;
            *pId = *pId + 1;

            printf("Ingrese el modelo de la notebook: ");
            fflush(stdin);
            gets(auxModelo);
            while(!(validarGets(21,auxModelo)))
            {
                printf("Reingrese el modelo de la notebook de un maximo de 20caracteres: ");
                gets(auxModelo);
            }
            strcpy(lista[i].modelo, auxModelo);


            printf("\n\nIngrese el id de la marca de la notebook\n");
            printf("Id 1000 \"Asus\"\nId 1001 \"Acer\"\nId 1002 \"Compaq\"\nId 1003 \"HP\"\nIngrese opcion: ");
            scanf("%d", &auxIdMarca);
            auxIdMarca = toupper(auxIdMarca);
            while(auxIdMarca < 1000 || auxIdMarca > 1003 || isalpha(auxIdMarca))
            {
                fflush(stdin); //Limpio el buff por si se ingreso una letra
                printf("\nReingrese un id valido, \nId 1000 \"Asus\"\nId 1001 \"Acer\"\nId 1002 \"Compaq\"\nId 1003 \"HP\"\nOpcion: ");
                scanf("%d", &auxIdMarca);
            }
            lista[i].idMarca = auxIdMarca;


            printf("\nIngrese el id del tipo de la notebook\n");
            printf("Id 5000 \"Disenio\"\nId 5001 \"Gamer\"\nId 5002 \"Normalita\"\nId 5003 \"Ultrabook\"\nIngrese opcion: ");
            scanf("%d", &auxIdTipo);
            auxIdTipo = toupper(auxIdTipo);
            while(auxIdTipo < 5000 || auxIdTipo > 5003 || isalpha(auxIdTipo))
            {
                fflush(stdin); //Limpio el buff por si se ingreso una letra
                printf("\nReingrese un id valido\nId 5000 \"Disenio\"\nId 5001 \"Gamer\"\nId 5002 \"Normalita\"\nId 5003 \"Ultrabook\"\nIngrese opcion: ");
                scanf("%d", &auxIdTipo);
            }
            lista[i].idTipo = auxIdTipo;



            printf("\nIngrese el precio de la notebook: $");
            scanf("%f", &auxPrecio);
            auxPrecio = toupper(auxPrecio);
            while(isalpha(auxPrecio)==1)
            {
                fflush(stdin); //Limpio el buff por si se ingreso una letra
                printf("\nReingrese el precio de la notebook: $");
                scanf("%f", &auxPrecio);
                auxPrecio = toupper(auxPrecio);
            }
            lista[i].precio = auxPrecio;

            lista[i].isEmpty = 0;
            todoOk = 1;

        }
        else
        {
            printf("\nNo hay mas espacio en el sistema\n");
        }
    }
    return todoOk;
}

int buscarPosicionLibre(eNotebook* vec, int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec && pIndex && tam>0 )
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex = i;
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int buscarPosicionLibreTrabajo(eTrabajo* vec, int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec && pIndex && tam>0 )
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex = i;
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int buscarPosicionPorId(eNotebook* vec, int tam,int id, int* pIndex)
{
    int todoOk = 0;
    if(vec && tam > 0 && pIndex && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(vec[i].isEmpty == 0 && vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int subMenuModificar()
{
    int opcion;
    printf(" ______________________________________ \n");
    printf("|      *** Modificar notebook ***      |\n");
    printf("|______________________________________| \n");
    printf("| Que desea modificar?                 |\n");
    printf("|--------------------------------------| \n");
    printf("| 1) Precio                            |\n");
    printf("| 2) Tipo                              |\n");
    printf("| 3) Salir                             |\n");
    printf("|______________________________________|\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin); // Limpio el buff porque si en algun otro menu ingresan un numero seguido de enter, da como erroneo
    scanf("%d", &opcion);

    while(opcion < 1 || opcion > 3 || isalpha(opcion))
    {
        fflush(stdin);
        printf("Se ingreso una opcion erronea, ingrese la opcion nuevamente: ");
        scanf("%d", &opcion);
    }

    return opcion;
}

int modificar(eNotebook* lista, int opcion, int tam)
{
    int todoOk = 0;
    float auxPrecio;
    int auxIdTipo;
    int i;
    int Id;
    int auxId;


    if(lista && (opcion == 1 || opcion == 2) && tam>0)
    {
        //listarNotebook
        printf("Ingrese id: ");
        scanf("%d", &auxId);
        auxId = toupper(auxId);

        while(auxId<30000 || isalpha(auxId))
        {
            fflush(stdin);
            printf("Reingrese id : ");
            scanf("%d", &auxId);
        }
        Id = auxId;

        if(buscarPosicionPorId(lista, tam, Id, &i))
        {
            if(opcion == 1)
            {
                printf("\nIngrese el nuevo precio de la notebook: $");
                scanf("%f", &auxPrecio);
                auxPrecio = toupper(auxPrecio);
                while(isalpha(auxPrecio)==1)
                {
                    fflush(stdin); //Limpio el buff por si se ingreso una letra
                    printf("\nReingrese el precio de la notebook: $");
                    scanf("%f", &auxPrecio);
                    auxPrecio = toupper(auxPrecio);
                }
                lista[i].precio = auxPrecio;
            }
            else
            {
                printf("\nIngrese el nuevo id del tipo de la notebook\n");
                printf("Id 5000 \"Gamer\"\nId 5001 \"Disenio\"\nId 5002 \"Ultrabook\"\nId 5003 \"Normalita\"\nIngrese opcion: ");
                scanf("%d", &auxIdTipo);
                auxIdTipo = toupper(auxIdTipo);
                while(auxIdTipo < 5000 || auxIdTipo > 5003 || isalpha(auxIdTipo))
                {
                    fflush(stdin); //Limpio el buff por si se ingreso una letra
                    printf("\nReingrese un id valido\nId 5000 \"Gamer\"\nId 5001 \"Disenio\"\nId 5002 \"Ultrabook\"\nId 5003 \"Normalita\"\nIngrese opcion: ");
                    scanf("%d", &auxIdTipo);
                }
                lista[i].idTipo = auxIdTipo;
            }
            todoOk = 1;
        }
        else
        {
            printf("Ese id no se encuentra en el sistema");
        }
    }
    return todoOk;
}

int inicializarNotebooks(eNotebook* vec, int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int inicializarTrabajos(eTrabajo* vec, int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int bajaNotebook(eNotebook* vec, int tam)
{
    int todoOk = 0;
    int indice;
    int auxId;
    int Id;

    if(vec != NULL && tam > 0)
    {
        //listarNotebook
        printf("Ingrese id: ");
        scanf("%d", &auxId);
        auxId = toupper(auxId);

        while(auxId<30000 || isalpha(auxId))
        {
            fflush(stdin);
            printf("Reingrese id : ");
            scanf("%d", &auxId);
        }
        Id = auxId;

        if(buscarPosicionPorId(vec, tam, Id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay Notebooks con ese id");
            }
            else
            {
                vec[indice].isEmpty = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar empleado\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int listarMarcas(eMarca* marcas, int tam)
{
    int todoOk = 0;

    if(marcas && tam>0)
    {
        printf(" ____________________________________________________\n");
        printf("|          Listado de marcas                         |\n");
        printf("|----------------------------------------------------|\n");
        for(int i=0; i<tam; i++)
        {
            printf("|  Id: %4d       |    Marca: %20s   |\n",marcas[i].id, marcas[i].desc);
        }
        printf("|____________________________________________________|\n");
        todoOk = 1;
    }
    return todoOk;
}

int listarTipos(eTipo* tipos, int tam)
{
    int todoOk = 0;

    if(tipos && tam>0)
    {
        printf(" _______________________________________________________________\n");
        printf("|          Listado de tipos de notebook                         |\n");
        printf("|---------------------------------------------------------------|\n");
        for(int i=0; i<tam; i++)
        {
            printf("|  Id: %4d       |    Tipo de notebook: %20s   |\n",tipos[i].id, tipos[i].desc);
        }
        printf("|_______________________________________________________________|\n");
        todoOk = 1;
    }
    return todoOk;
}

int listarServicios(eServicio* servicios, int tam)
{
    int todoOk = 0;

    if(servicios && tam>0)
    {
        printf(" _________________________________________________________________________________________\n");
        printf("|                        Listado de servicios de notebook                                 |\n");
        printf("|-----------------------------------------------------------------------------------------|\n");
        for(int i=0; i<tam; i++)
        {
            printf("|  Id: %4d       |    Tipo de servicio: %20s   |  Precio: $%10.2f   |\n",servicios[i].id, servicios[i].desc, servicios[i].precio);
        }
        printf("|_________________________________________________________________________________________|\n");
        todoOk = 1;
    }
    return todoOk;
}

int buscarDescripcionTipo(eTipo* tipos, int tam, int num, char* descTip)
{
    int todoOk = 0;

    if(tipos && tam>0 && num>0 && descTip)
    {
        for(int i=0; i<tam; i++)
        {
            if(tipos[i].id == num)
            {
                strcpy(descTip, tipos[i].desc);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarDescripcionMarca(eMarca* marcas, int tam, int num, char* descMarc)
{
    int todoOk = 0;

    if(marcas && tam>0 && num>0 && descMarc)
    {
        for(int i=0; i<tam; i++)
        {
            if(marcas[i].id == num)
            {
                strcpy(descMarc, marcas[i].desc);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarNotebooks(eNotebook* notebooks, int tam, eTipo* tipos, int tamTip, eMarca* marcas, int tamMarc)
{
    int todoOk = 0;
    char auxMarca[21];
    char auxTipo[21];

    if(notebooks && tam>0)
    {


        printf(" _________________________________________________________________________________________\n");
        printf("|                                     Listado de notebooks                                \n");
        printf("|-----------------------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!(notebooks[i].isEmpty))
            {

//int buscarDescripcionMarca(eMarca* marcas, int tam, int num, char* descMarc);
                buscarDescripcionMarca(marcas, tamMarc, notebooks[i].idMarca, auxMarca);
                buscarDescripcionTipo(tipos, tamTip, notebooks[i].idTipo, auxTipo);

                printf("|  Id: %4d       |    Modelo: %20s   | Marca: %20s   |  Tipo: %20s   | Precio: $%10.2f   \n", notebooks[i].id, notebooks[i].modelo, auxMarca, auxTipo, notebooks[i].precio);
            }
        }
        printf("|_________________________________________________________________________________________\n");

        todoOk = 1;
    }
    return todoOk;
}

int listarNotebooksMarcaPrecio(eNotebook* notebooks, int tam, eTipo* tipos, int tamTip, eMarca* marcas, int tamMarc)
{
    int todoOk = 0;
    char auxMarca[21];
    char auxTipo[21];
    eNotebook aux;

    if(notebooks && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!(notebooks[i].isEmpty))
            {

//int buscarDescripcionMarca(eMarca* marcas, int tam, int num, char* descMarc);
                buscarDescripcionMarca(marcas, tamMarc, notebooks[i].idMarca, auxMarca);
                buscarDescripcionTipo(tipos, tamTip, notebooks[i].idTipo, auxTipo);
                for(int i=0; i<tam-1; i++)
                {
                    for(int j=i+1; j<tam; j++)
                    {
                        if(!(notebooks[i].isEmpty) && !(notebooks[j].isEmpty))
                        {
                            if((notebooks[i].idMarca == notebooks[j].idMarca &&(notebooks[i].precio < notebooks[j].precio)) ||
                                    (notebooks[i].idMarca != notebooks[j].idMarca && (notebooks[i].idMarca < notebooks[j].idMarca)))
                            {
                                aux = notebooks[i];
                                notebooks[i] = notebooks[j];
                                notebooks[j] = aux;
                            }
                        }
                    }
                }
            }

            todoOk = 1;
        }
    }
    return todoOk;
}

int pedirYValidarFecha(eFecha unaFecha)
{
    int auxDia;
    int auxMes;
    int auxAnio;
    int todoOk = 0;

    printf("Ingrese una fecha (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &auxDia, &auxMes, &auxAnio);

    while(!(auxDia >= 1 && auxDia <=31) || !(auxMes >=1 && auxMes<=12) || !(auxAnio >1999 && auxAnio<2023))
    {
        fflush(stdin); //Por si ingreso una letra
        printf("Reingrese la fecha (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &auxDia, &auxMes, &auxAnio);
    }
    unaFecha.dia = auxDia;
    unaFecha.mes = auxMes;
    unaFecha.anio = auxAnio;
    todoOk = 1;

    return todoOk;
}

    int altaTrabajo(eTrabajo* trabajo, int* pId, int tam)
    {
        int todoOk = 0;
        int idNot;
        int idSer;
        int i;
        eFecha fecha;

        if(trabajo && pId && tam>0)
        {
            if(buscarPosicionLibreTrabajo(trabajo, tam, &i))
            {
                trabajo[i].id = *pId;
                *pId = *pId + 1;

                printf("Ingrese id de la notebook");
                scanf("%d", &idNot);
                idNot = toupper(idNot);

                while(idNot < 30000 || isalpha(idNot))
                {
                    printf("Reingrese el id de la notebook");
                    scanf("%d", &idNot);
                    idNot = toupper(idNot);
                }
                trabajo[i].idNotebook = idNot;

                printf("Ingrese id del servicio");
                scanf("%d", &idSer);
                idSer = toupper(idSer);

                while(idSer < 20000 || idSer >20003 || isalpha(idSer))
                {
                    printf("Reingrese el del servicio");
                    scanf("%d", &idSer);
                    idSer = toupper(idSer);
                }
                 trabajo[i].idNotebook = idSer;

                 pedirYValidarFecha(fecha);
            }
            else
            {
                printf("\nNo hay mas espacio en el sistema\n");
            }
        }
        return todoOk;
    }




