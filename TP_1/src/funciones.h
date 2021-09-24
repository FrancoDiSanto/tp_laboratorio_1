/*
 * funciones.h
 *
 *  Created on: 24 sep. 2021
 *      Author: franc
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/**
 * @fn int menu(int, int, int, int, int, int, int, float, int, int, int, int)
 * @brief
 *
 * @param x  numero a
 * @param y  numero b
 * @param flaga bandera para saber si a se ingreso
 * @param flagb bandera para saber si b se ingreso
 * @param rs valor de resultado suma
 * @param rr valor de resultado resta
 * @param rm valor de resultado multiplicacion
 * @param rd valor de resultado division
 * @param results
 * @param cero
 * @param factA valor de resultado de factorial a
 * @param factB valor de resultado de factorial b
 * @return retorna la opcion elegida para entrar en el case correcto
 */
int menu(int x, int y, int flaga, int flagb, int rs, int rr, int rm, float rd, int results, int cero, int factA, int factB);

/**
 * @fn int suma(int, int, int*)
 * @brief
 *
 * @param x numero a
 * @param y numero b
 * @param r carga por referencia el resultado de la suma en la variable resultado de main
 * @return
 */
int suma(int x, int y, int* r);

/**
 * @fn int resta(int, int, int*)
 * @brief
 *
 * @param x numero a
 * @param y numero b
 * @param r carga por referencia el resultado de la resta en la variable resultado de main
 * @return retorna 1 si salio todo bien y 0 si hubo errores
 */
int resta(int x, int y, int* r);

/**
 * @fn int division(int, int, float*)
 * @brief
 *
 * @param x numero a
 * @param y numero b
 * @param r carga por referencia el resultado de la division en la variable resultado de main
 * @return retorna 1 si salio todo bien y 0 si hubo errores
 */
int division(int x, int y, float* r);

/**
 * @fn int multiplicacion(int, int, int*)
 * @brief
 *
 * @param x numero a
 * @param y numero b
 * @param r carga por referencia el resultado de la multiplicacion en la variable resultado de main
 * @return retorna 1 si salio todo bien y 0 si hubo errores
 */
int multiplicacion(int x, int y, int* r);

/**
 * @fn int factorial(int)
 * @brief
 *
 * @param x numero a realizarle el factorial
 * @return retorna el resultado del factorial
 */
int factorial(int x);


#endif /* FUNCIONES_H_ */
