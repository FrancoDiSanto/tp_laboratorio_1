/*
 ============================================================================
 Name        : RP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"
#define TAM 1000


typedef struct{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}eEmployee;

int menu();
int initEmployees(eEmployee employees[], int tam);
int buscarLibreEmpleado(eEmployee employees[], int tam);
int addEmployee(eEmployee employees[], int len, int id, char name[],char lastName[],float salary,int sect);
int printEmployees(eEmployee employees[], int len);
int printEmploye(eEmployee aEmploye);
int findEmployeeById(eEmployee employees[], int tam , int id);
int editEmployee(eEmployee employees[],int index);
int menuModif();
int removeEmployee(eEmployee employees[], int tam, int id);
int sortEmployees(eEmployee employees[], int tam);
int hardcodearEmployees(eEmployee employees[], int len , int cant, int* pId);
int totalSalary(eEmployee employees[], int len , float* tS);
int cobranMucho(eEmployee employees[], int len, float promedio);

int main(void) {
	setbuf(stdout, NULL);
	eEmployee empleados[TAM];
	    initEmployees(empleados, TAM);
	    int flagUno=1;// inicializo en 1 asi me deja empezar sin ingresar a nadie
	    int id=1; // inicializo en 14 porque es el que le sigue al ultimo del harcodeo
	    char nombre[51];
	    char apellido[51];
	    float sueldo;
	    int sector;
	    char seguir = 's';
	    int idModif;
	    int idDelete;
	    float totalSalarios=0;
	    float salarioPromedio;
	    int contadorS=0;
	    int contSalarioAlto;
	    hardcodearEmployees(empleados, TAM, 20, &id );

	    do{

	    switch(menu())
	    {
	    case 1 :
	        printf("ingrese su nombre \n");
	        fflush(stdin);
	        scanf("%s", nombre);

	        printf("ingrese su apellido \n");
	        fflush(stdin);
	        scanf("%[^\n]", apellido);

	        printf("ingrese su sueldo \n");
	        fflush(stdin);
	        scanf("%f", &sueldo);
	        while(sueldo < 1)
	        {
	            printf("reingrese su sueldo \n");
	            fflush(stdin);
	            scanf("%f", &sueldo);

	        }

	        printf("ingrese su sector \n");
	        fflush(stdin);
	        scanf("%d", &sector);
	        while(sector < 1 || sector > 4)
	        {
	            printf("reingrese un sector valido (1 - 4) \n");
	            fflush(stdin);
	            scanf("%d", &sector);
	        }

	        addEmployee(empleados, TAM, id, nombre, apellido, sueldo, sector);
	        id++;

	        flagUno =1;
	        break;
	    case 2 :
	        if(flagUno)
	        {
	            printEmployees(empleados, TAM);
	            printf("ingrese el id del empleado a modificar \n");
	            scanf("%d", &idModif);
	            while(idModif < 1 || idModif > id-1 )
	            {
	                printf("ingrese un id valido");
	                scanf("%d", &idModif);
	            }
	            //findEmployeeById(empleados, TAM, idModif);
	            editEmployee(empleados,findEmployeeById(empleados, TAM, idModif) );
	        }else{
	        printf("primero ingrese algun empleado \n ");
	        }




	        break;
	    case 3 :
	        if(flagUno)
	        {
	            printEmployees(empleados, TAM);
	            printf("ingrese el legajo del empleado a borrar \n");
	            scanf("%d", &idDelete);
	            while(idDelete < 1 || idDelete > id-1 )
	            {
	                printf("ingrese un id valido \n");
	                scanf("%d", &idDelete);
	            }
	            if(removeEmployee(empleados, TAM, idDelete))
	            {
	                printf("empleado borrado con exito \n ");
	            }else{

	                printf("Hubo un error o el usuario cancelo la baja \n");
	            }



	        }else{
	            printf("primero ingrese algun empleado");
	        }
	        break;
	    case 4 :
	        if(flagUno)
	        {
	            contadorS = totalSalary(empleados, TAM, &totalSalarios);
	            salarioPromedio = totalSalarios / contadorS;
	            contSalarioAlto = cobranMucho(empleados, TAM, salarioPromedio);
	            printf("Lista original \n");
	            printEmployees(empleados, TAM);
	            printf("Lista ordenada \n");
	            sortEmployees(empleados, TAM);
	            printEmployees(empleados, TAM);
	            printf("Total salarios : %f \n", totalSalarios);
	            printf("Salario promedio : %.2f \n", salarioPromedio);
	            printf("Por encima del promedio : %d  empleados \n", contSalarioAlto);
	            contadorS=0;
	            totalSalarios=0;
	            salarioPromedio=0;


	        }else{
	            printf("primero ingrese algun empleado");
	        }
	        //printEmploye(empleados[0]);
	        break;
	    case 5 :
	        printf("Presione n para salir");
	        fflush(stdin);
	        scanf("%c", &seguir);
	        break;
	    default:
	        printf("Seleccione una opcion correcta \n");
	        break;

	    }
	    system("pause");
	    system("cls");

	    }while(seguir == 's');


	return EXIT_SUCCESS;
}



int menu()
{
    int opcion;
    printf("MENU DE OPCIONES \n");
    printf("1- Alta \n");
    printf("2- Modificacion  \n");
    printf("3- Baja \n");
    printf("4- Informar \n");
    printf("5- Salir \n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
int initEmployees(eEmployee employees[], int tam)
{
    int todoOk=0;
    if(employees!= NULL && tam > 0)
    {
        for(int i =0; i < tam ; i ++)
        {
            employees[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarLibreEmpleado(eEmployee employees[], int tam)
{
    int r;
    if(employees != NULL && tam > 0)
    {
        for(int i =0; i < tam ; i ++)
        {
            if(employees[i].isEmpty == 1)
            {
                r = i;
                break; // si encontro posicion rompe el for
            }

        }

    }

    return r;
}


int addEmployee(eEmployee employees[], int len, int id, char name[],char lastName[],float salary,int sect)
{
    int todoOk=0;
    int l;
    if(employees != NULL && len > 0 && name != NULL && lastName != NULL)
    {
       l = buscarLibreEmpleado(employees, len);

        employees[l].id = id;
        strcpy(employees[l].name, name);
        strcpy(employees[l].lastName, lastName);
        employees[l].salary = salary;
        employees[l].sector = sect;
        employees[l].isEmpty=0;
        todoOk=1;
    }

    return todoOk;
}

int printEmployees(eEmployee employees[], int len)
{
    printf("id        Nombre         Apeliido           Salario        Sector\n");
    if(employees != NULL && len > 0)
    {
        for(int i =0; i < len ; i ++)
        {
            if(employees[i].isEmpty==0)
            {
                printEmploye(employees[i]);

            }


        }

    }

return 1;
}

int printEmploye(eEmployee aEmploye)
{
    printf("%-4d      %-10s      %-12s     %-10.2f      %-1d\n" ,aEmploye.id
                                                ,aEmploye.name
                                                ,aEmploye.lastName
                                                ,aEmploye.salary
                                                ,aEmploye.sector);

    return 1;

}

int findEmployeeById(eEmployee employees[], int tam , int id)
{
    int r= -1;
    if(employees != NULL && tam > 0)
    {
        for(int i=0; i <tam; i ++)
        {
            if(employees[i].id == id)
            {
                r =i;
                printEmploye(employees[i]);
                system("pause");
                break;
            }

        }

    }


    return r;
}

int menuModif()
{
    int opcion;
    printf("MENU DE MODIFICACIONES \n");
    printf("1- Nombre \n");
    printf("2- Apellido  \n");
    printf("3- Sueldo \n");
    printf("4- Sector \n");
    printf("5- Salir \n");

    printf("Que desea modificar: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

int editEmployee(eEmployee employees[],int index)
{
    int todoOk=0;
    char seguir ='s';
    if(employees != NULL && index != -1)
    {
        todoOk=1;
        do{
        switch(menuModif())
        {
        case 1:
            printf("reingrese nombre \n");
            fflush(stdin);
            scanf("%s", employees[index].name);
            break;
        case 2:
            printf("reingrese apellido \n");
            fflush(stdin);
            scanf("%[^\n]", employees[index].lastName);
            break;
        case 3:
            printf("reingrese sueldo \n");
            scanf("%f", &employees[index].salary);
            break;
        case 4:
            printf("reingrese Sector \n");
            scanf("%d", &employees[index].sector);
            break;
        case 5 :
        printf("Presione n para salir");
        fflush(stdin);
        scanf("%c", &seguir);
        break;

        }



        }while(seguir == 's');

    }


return todoOk;
}

int removeEmployee(eEmployee employees[], int tam, int id)
{
        int todoOk=0;
        int remover;
    if(employees!= NULL && tam >0)
    {
        for(int i =0; i < tam ; i++)
        {

            if(employees[i].id == id )
            {
                printEmploye(employees[i]);
                printf("Desea remover este empleado presione 1 para si 0 para no \n");
                scanf("%d", &remover);
                if(remover)
                {
                    employees[i].isEmpty = 1;
                    todoOk=1;
                    break;
                }else{
                    todoOk=0;
                    break;
                }
            }
        }

    }


    return todoOk;
}

int sortEmployees(eEmployee employees[], int tam)
{
    int todoOk=0;
    eEmployee auxiliar;
    if(employees != NULL && tam > 0)
    {
        for(int i=0; i < tam -1 ; i ++)
        {
            for(int j = i +1 ; j < tam ; j++)
            {
                if(employees[i].sector > employees[j].sector || (employees[i].sector == employees[j].sector && stricmp(employees[i].name, employees[j].name)>0) )
                {



                        auxiliar = employees[i];
                        employees[i] = employees[j];
                        employees[j] = auxiliar;


                }

            }
            todoOk=1;
        }



    }

    return todoOk;
}

int hardcodearEmployees(eEmployee employees[], int len , int cant, int* pId)
{
    int cantidad=0;

    if(employees != NULL && len > 0 && cant >=0 && cant <= len && pId != NULL)
    {
        for(int i =0; i < cant; i ++)
        {
            employees[i].id = *pId;
            (*pId)++;

            strcpy(employees[i].name, nombresDW[i]);
            strcpy(employees[i].lastName, apellidosDW[i]);
            employees[i].salary = sueldosDW[i];
            employees[i].sector = sectoresDW[i];
            employees[i].isEmpty = 0;

            cantidad++;


        }


    }


    return cantidad;
}


int totalSalary(eEmployee employees[], int len , float* tS)
{
    int contador=0;

    if(employees != NULL && len > 0 && tS != NULL)
    {
        for(int i =0; i < len; i++)
        {
            if(employees[i].isEmpty == 0)
            {
                (*tS)+= employees[i].salary;
                contador++;
            }


        }



    }


    return contador;
}

int cobranMucho(eEmployee employees[], int len, float promedio)
{
    int contador=0;
    if(employees != 0 && len > 0)
    {
        for(int i =0; i <len ; i++)
        {
            if(employees[i].isEmpty ==0 && employees[i].salary > promedio)
            {
                contador++;
            }

        }

    }


    return contador;
}

