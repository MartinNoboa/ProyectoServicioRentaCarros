/**
*Tema      :
*@author   : Martin A. Noboa Monar
             Aldrin A. Hernandez
*@date     : Noviembre 12, 2018
*matricula : A01704052
             A01704040
*
**/


#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    int eleccion = 0;
    inicio();
    do {
        scanf("%i%*c" , &eleccion);
        opcionEscogida(eleccion);
    }while (eleccion != 0);

return 0;
}
