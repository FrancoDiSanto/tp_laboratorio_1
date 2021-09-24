#include <stdio.h>
#include <stdlib.h>
/*
 * funciones.c
 *
 *  Created on: 24 sep. 2021
 *      Author: franc
 */

int menu(int x, int y, int flaga, int flagb, int rs, int rr, int rm, float rd, int results, int cero, int factA, int factB)
{
    int opcion;
    if(flaga){
    printf("1. Ingresar 1er operando (A=x)\n");
    }else{
        printf("1. Ingresar 1er operando (A= %d)\n", x);
    }
    if(flagb){
    printf("2. Ingresar 2do operando (B=y)\n");
    }else{
        printf("2. Ingresar 2do operando (B= %d)\n",y);
    }


    printf("3. Calcular todas las operaciones\n");
    printf("a) Calcular la suma (A+B)\n");
    printf("b) Calcular la resta (A-B)\n");
    printf("c) Calcular la division (A/B)\n");
    printf("d) Calcular la multiplicacion (A*B)\n");
    printf("e) Calcular el factorial (A!)\n");

    if(results)
    {
        printf("4. Informar resultados\n");
    printf("a) El resultado de A+B es: r\n");
    printf("b) El resultado de A-B es: r \n");
    printf("c) El resultado de A/B es: r o No es posible dividir por cero\n");
    printf("d) El resultado de A*B es: r\n");
    printf("e) El factorial de A es: r1 y El factorial de B es: r2\n\n");
    printf("5. Salir\n");
    }else{

    printf("4. Informar resultados\n");
    printf("a) El resultado de A+B es: %d \n", rs);
    printf("b) El resultado de A-B es: %d \n", rr);
    if(!cero)
    {
        printf("c) El resultado de A/B es: No es posible dividir por cero\n");
    }else{
    printf("c) El resultado de A/B es: %f \n", rd);

    }
    printf("d) El resultado de A*B es: %d \n", rm);
    printf("e) El factorial de A es: %d y El factorial de B es: %d \n\n", factA, factB);
    printf("5. Salir\n");
    }



    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}



int suma(int x, int y, int* r)
{
    int todoOk=0;
    if(r != NULL)
    {
        *r = x + y ;
        todoOk =1;
    }

    return todoOk;
}
int resta(int x, int y, int* r)
{
    int todoOk=0;
    if(r != NULL)
    {
        *r = x - y ;
        todoOk =1;
    }

    return todoOk;
}
int division(int x, int y, float* r)
{

    int todoOk=0;
    if(r != NULL && y != 0)
    {
        *r =(float) x / y ;
        todoOk =1;
    }

    return todoOk;
}
int multiplicacion(int x, int y, int* r)
{
    int todoOk=0;
    if(r != NULL)
    {
        *r = x * y ;
        todoOk =1;
    }

    return todoOk;

}


int factorial(int x)
{
    int fact;

    if(x== 0 || x == 1)
    {
        fact = 1;

    }else{

        fact = x * factorial(x - 1);
    }

    return fact;
}
