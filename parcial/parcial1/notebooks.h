#ifndef NOTEBOOKS_H_INCLUDED
#define NOTEBOOKS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    char  desc[21];
}eMarca;

typedef struct
{
    int id;
    char desc[21];
}eTipo;

typedef struct
{
    int id;
    char modelo[21];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;

}eNotebook;

typedef struct
{
    int id;
    char desc[26];
    float precio;
}eServicio;

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    int dia;
    int mes;
    int anio;
    int isEmpty;
}eTrabajo;

#endif // NOTEBOOKS_H_INCLUDED

int menu();
int subMenuModificar();

int validarGets(int tam, char auxCad[100]);

int confirmaSalida(char* eleccion);

int inicializarNotebooks(eNotebook* vec, int tam);
int inicializarTrabajos(eTrabajo* vec, int tam);

int buscarPosicionLibre(eNotebook* vec, int tam, int* pIndex);
int buscarPosicionLibreTrabajo(eTrabajo* vec, int tam, int* pIndex);
int buscarPosicionPorId(eNotebook* vec, int tam,int id, int* pIndex);

int altaNotebook(eNotebook* lista, int* pId, int tam);
int altaTrabajo(eTrabajo* trabajo, int* pId, int tam);
int bajaNotebook(eNotebook* vec, int tam);
int modificar(eNotebook* lista, int opcion, int tam);

int listarMarcas(eMarca* marcas, int tam);
int listarTipos(eTipo* tipos, int tam);
int listarServicios(eServicio* servicios, int tam);

int buscarDescripcionMarca(eMarca* marcas, int tam, int num, char* descMarc);
int buscarDescripcionTipo(eTipo* tipos, int tam, int num, char* descTip);

int pedirYValidarFecha(eFecha unaFecha);
