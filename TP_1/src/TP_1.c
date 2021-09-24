/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
	setbuf(stdout,NULL);
		int seguir=1;
	    int flagA=1;
	    int flagB=1;
	    int flagRdos=1;
	    int esCero;
	    int a;
	    int b;
	    int resultadoSuma=0;
	    int resultadoResta=0;
	    float resultadoDivision=0;
	    int resultadoMulti=0;
	    int resultadoFactA=0;
	    int resultadoFactB=0;
	    int flagCuatro=1;
	do{

	    system("cls");

	    switch(menu(a,b,flagA,flagB,resultadoSuma, resultadoResta,resultadoMulti, resultadoDivision, flagCuatro, esCero, resultadoFactA, resultadoFactB))
	    {
	    case 1:
	        if(!flagA)
	        {
	            flagCuatro=1;
	            flagRdos=1;
	        }
	        printf("ingrese su primer operando ");
	        scanf("%d", &a);
	        flagA=0;
	        break;
	    case 2:
	        if(!flagB)
	        {
	            flagCuatro=1;
	            flagRdos=1;
	        }
	        printf("ingrese su segundo operando ");
	        scanf("%d", &b);
	        flagB=0;
	        break;
	    case 3:
	        if(!flagA && !flagB)
	        {
	                suma(a,b, &resultadoSuma);
	                resta(a,b,&resultadoResta);
	                multiplicacion(a,b, &resultadoMulti);
	                esCero = division(a,b, &resultadoDivision);
	                resultadoFactA = factorial(a);
	                resultadoFactB = factorial(b);
	                flagRdos=0;
	                printf("Los calculos fueron realizados con exito \n");
	        }else{

	        printf("ingrese ambos operandos para realizar las cuentas\n");
	        }

	        //flagCuatro=0;
	        break;
	    case 4:
	        if(!flagRdos)
	        {
	            flagCuatro=0;
	            printf("Los resultados se mostraran en el menu \n");
	        }else{
	        printf("para mostrar los resultados primero realiza las cunetas\n");
	        }

	            //flagCuatro=1;
	        break;

	    case 5:
	        printf("DESEA SEGUIR 1-> SI   2-> NO ");
	        scanf("%d", &seguir);
	        break;
	    default:
	        printf("opcion invalida, reingrese opcion \n");
	    break;
	    }

	system("pause");
	}while(seguir);




	return EXIT_SUCCESS;
}
