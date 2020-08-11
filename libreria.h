#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED

//Include libraries
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


/**
*@brief procedimiento para mostrar menu del proyecto
*@param
*@return
**/
void menuPrincipal(){
    system("cls");
    puts("\n\tCALIFICACIONES");
    puts("\n\n1. Mostrar calificaciones.");
    puts("2. Editar.");
    puts("0. Salir");
    printf("Eleccion: ");
}

/**
*@brief procedimiento para mostrar datos de la clase y alumnos
*@param
*@return
**/
void inicio(){
    puts("PROYECTO FINAL");
    puts("\n\nAldrin Hernandez");
    puts("Martin Noboa");

    puts("\nPresione enter para continuar.");
    getchar();
    menuPrincipal();
}


/**
*@brief procedimiento para llamar a las funciones/procedimientos de la edicion
*@param int opcion_edicion: entero para elegir la opcion por parte del usuario
*@return
**/
void eleccionEdicion(int opcion_edicion){
    switch(opcion_edicion){
        case 1: agregarAlumno();
        break;

        case 2:
            system("cls");
            menuPrincipal();
        break;
    }
}

/**
*@brief procediemiento para mostrar el menu de la edicion del archivo
*@param
*@return
* es diferente a menuEditar() ya que este se muestra despues de imprimir el archivo
**/
void menuEditar2(){
    int opcion_edicion = 0;
    puts("1. Agregar alumnos. ");
    puts("2. Regresar.");
    printf("Opcion: ");
    scanf("%i%*c", &opcion_edicion);
    eleccionEdicion(opcion_edicion);
}

/**
*@brief procediemiento para mostrar el menu de la edicion del archivo
*@param
*@return
**/
void menuEditar(){
    int opcion_edicion = 0;
    system("cls");
    puts("\n\tEDITAR CALIFICACIONES\n\n");
    puts("1. Agregar alumnos. ");
    puts("2. Regresar.");
    printf("Opcion: ");
    scanf("%i%*c", &opcion_edicion);
    eleccionEdicion(opcion_edicion);
}

/**
*@brief procedimiento para mostrar el archivo en pantalla
*@param
*@return
**/
void mostrarCalificaciones(){
    system("cls");
    puts("\n\tMOSTRAR CALIFICACIONES\n\n");
    char c;
    FILE * leer = fopen("registro.txt", "r");
    while(!feof(leer)){
        fscanf(leer, "%c", &c);
        printf("%c" , c);
    }
    fclose(leer);
    menuEditar2();
}

/**
*@brief procedimiento para mostrar archivo en pantalla
*@param
*@return
**/
void mostrarCalificaciones2(){

    char c;
    FILE * leer = fopen("registro.txt", "r");
    while(!feof(leer)){
        fscanf(leer, "%c", &c);
        printf("%c" , c);
    }
    fclose(leer);
}


/**
*@brief procedimiento para llamar a los procedimientos/funciones a partir de la eleccion del menu principal
*@param int eleccion: entero ingresado por el usuario y leido en el main().
*@return
**/
void opcionEscogida(int eleccion){
    switch(eleccion){
        case 1: mostrarCalificaciones();
        break;

        case 2: menuEditar();
    }
}

/**
*@brief procedimiento para agregar alumnos al archivo de texto
*@param
*@return
**/
void agregarAlumno(){
    mostrarCalificaciones2();
    FILE * draft = fopen("registro.txt", "a");

    int numeroAlumno = 0;
    printf("\n\nIngrese el numero del alumno: ");
    scanf("%i%*c" , &numeroAlumno);
    char nombreAlumno[50];
    printf("Ingrese el nombre del alumno: ");
    scanf("%s" , &nombreAlumno);
    char apellidoAlumno[50];
    printf("Ingrese el apellido del alumno: ");
    scanf("%s" , &apellidoAlumno);
    char carreraAlumno[50];
    printf("Ingrese la carrera del alumno: ");
    scanf("%s" , &carreraAlumno);
    int primeraCalificacion = 0;
    printf("Ingrese la primera calificacion del alumno: ");
    scanf("%i%*c" , &primeraCalificacion);
    int segundaCalificacion = 0;
    printf("Ingrese la segunda calificacion del alumno: ");
    scanf("%i%*c" , &segundaCalificacion);


    char salto = '\n';
    fprintf(draft, "%i  %s %s       %s               %i    %i %c", numeroAlumno, nombreAlumno, apellidoAlumno, carreraAlumno , primeraCalificacion, segundaCalificacion, salto);
    fclose(draft);
    mostrarCalificaciones2();
    getchar();
    menuEditar();

}

#endif // LIBRERIA_H_INCLUDED
